
#if defined(DBG_NRF51822) || defined(DBG_STM32F103RC) || defined(DBG_STM32F051)

#include <string.h>
#include <absacc.h>
#include "ihex.h"
#include "target_flash.h"


#if defined(DBG_STM32F103RC) || defined(DBG_STM32F051)
#define PAGE_SIZE   512
#else
#define PAGE_SIZE   FLASH_SECTOR_SIZE
#endif

#define LINE_SIZE   64

#define IHEX_RECORD_MAX_DATA    32

typedef enum {
	DATA_RECORD = 0x00,
	EOF_RECORD  = 0x01, /* End Of File */
	ESA_RECORD  = 0x02, /* Extended Segment Address */
	SSA_RECORD  = 0x03, /* Start Segment Address */
	ELA_RECORD  = 0x04, /* Extended Linear Address */
	SLA_RECORD  = 0x05  /* Start Linear Address */
} ihex_record_type_t;

/* Represents an Intel .hex record. */
typedef struct {
	uint8_t byte_count;
	uint16_t address;
	uint8_t record_type;
	uint8_t data[IHEX_RECORD_MAX_DATA];
	uint8_t checksum;
} ihex_record_t;

typedef enum {
	/* None error */
	IHEX_ERROR_NONE,

	/* Miscellaneous format error. */
	IHEX_ERROR_INVALID_FORMAT,

	/* Invalid hexadecimal character encountered (other than line endings and
	 * record-delimiting colon (':') characters). Unable to extract meaningful
	 * data. */
	IHEX_ERROR_NON_HEX_CHARACTER,

	/* Individual record checksum failure. */
	IHEX_ERROR_INVALID_CHECKSUM,
} ihex_error_t;

uint8_t *page_data = 0;
uint16_t page_size = 0;
uint16_t page_data_index = 0;

char line_buffer[LINE_SIZE] = {0};
int  line_len = 0;

ihex_record_t r;

#if defined(DBG_STM32F103RC) || defined(DBG_STM32F051)
uint8_t  bin_buffer[PAGE_SIZE] __at(0x20000000 + 512);		//usb_buffer at [0x20000000, 0x2000200]
#else
uint8_t  bin_buffer[PAGE_SIZE] __at(0x20000000 + PAGE_SIZE);
#endif

uint16_t bin_data_index   = 0;
uint32_t bin_low_address  = 0;
uint32_t bin_high_address = 0;

static int ihex_read_line(void);
static int ihex_process_data_record(ihex_record_t *r);
static ihex_error_t ihex_decode_record(char *line, int len, ihex_record_t *r);
static ihex_error_t ihex_get_byte(char *src, uint8_t *dst, uint8_t *checksum);
static ihex_error_t ihex_get_2bytes(char *src, uint16_t *dst, uint8_t *checksum);
static ihex_error_t ihex_get_nbytes(char *src, uint8_t *dst, uint8_t nbytes, uint8_t *checksum);

/**
 * Initialize global variables used by intel hex parser
 */
void ihex_init()
{
    line_len = 0;
    page_data_index = 0;
    bin_data_index = 0;
    bin_low_address  = 0;
    bin_high_address = 0;
    
    flash_is_erase_all = 0;
}

/**
 * flash binary data to target
 * @return  0   success
 *          1   SWD error
 */
int ihex_flash_bin()
{
    uint32_t address = bin_low_address + bin_high_address;

    if (bin_data_index == 0) {
        return 0;
    }

    if (!target_flash_program_page(address, (uint8_t *)bin_buffer, bin_data_index)) {
        return 1;
    }

    memset(bin_buffer, 0xFF, sizeof(bin_buffer));
    bin_data_index = 0;

    return 0;
}

/**
 * parse a hex page
 * @param   buf     intel hex data
 * @param   len     length of data
 * @return  1       finish a intel hex file, drag-n-drop is done
 *          0       complete a page, ready to parse next page
 *          -1      invalid intel hex data
 *          -2      SWD error
 */
int ihex_parse_hex_page(uint8_t *buf, int len)
{
    int get_a_line;
    
    page_data = buf;
    page_size = len;
    page_data_index = 0;
    do {
        ihex_error_t error;
        
        get_a_line = ihex_read_line();
        if (get_a_line <= 0) {
            if (get_a_line < 0) {
                return -1;
            } else {
                break;
            }
        }

        error = ihex_decode_record(line_buffer, line_len, &r);

        if (IHEX_ERROR_NONE != error) {
            return 11;
        }

        if (DATA_RECORD == r.record_type) {
            if (ihex_process_data_record(&r)) {
                return -2;
            }
        } else {
            if (ihex_flash_bin()) {
                return 2;
            }
            
            if (ELA_RECORD == r.record_type) {
                bin_high_address = ((r.data[0] << 8) + r.data[1]) << 16;
            } else if (ESA_RECORD == r.record_type) {
                bin_high_address = ((r.data[0] << 8) + r.data[1]) << 4;
            }else if (EOF_RECORD == r.record_type) {
                return 1;
            }
        }

        line_len = 0;
    } while (1);
    
    return 0; 
}

/**
 * read a line from a page
 * @return  1   success
 * @return  0   get a incomplete line, need data from the next page
 * @return  -1  line buffer is not enough, probably intel hex data is not valid
 */
static int ihex_read_line()
{
    while (page_data_index < page_size) {
        char c = *(page_data + page_data_index);
        page_data_index++;

        if (('\n' == c) || ('\r' == c)) {
            if (line_len != 0) {
                return 1;
            }

            continue;
        } else if ('\0' != c) {
            *(line_buffer + line_len) = c;
            line_len++;
            if (line_len >= sizeof(line_buffer)) {
                return -1;
            }
        } else {
            return 0;
        }
    }
    
    memset(page_data, 0x00, page_size);
    return 0;
}

/**
 * put data record into bin_buffer, if bin_buffer is full, then flash bin_buffer to target
 * @return  0   OK
 *          1   SWD error
 */
static int ihex_process_data_record(ihex_record_t *r)
{
    int i;
    uint8_t *src;
    uint8_t bytes;

    if (bin_data_index == 0) {
        bin_low_address = r->address;
    } else if (((bin_low_address + bin_data_index) & 0xFFFF) != r->address) {
        ihex_flash_bin();
        bin_low_address = r->address;
    }

    src = r->data;
    bytes = r->byte_count;
    for (i = 0; i < bytes; i++) {
        *(bin_buffer + bin_data_index) = *src;
        src++;

        bin_data_index++;
        if (bin_data_index >= sizeof(bin_buffer)) {
            if (ihex_flash_bin()) {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * decode a intel hex record from a line
 * @param   line    line buffer
 * @param   len     length of the line
 * @param   r       intel hex record
 * @return
 */
ihex_error_t ihex_decode_record(char *line, int len, ihex_record_t *r)
{
    uint8_t checksum = 0;
    char *ptr = line;
    
    if (*ptr != ':') {
        return IHEX_ERROR_INVALID_FORMAT;
    }
    ptr++;
    
    ihex_get_byte(ptr, &(r->byte_count), &checksum);
    if (len != (11 + 2 * r->byte_count)) {       // 1 + 2 + 4 + 2 + 2 * n + 2
        return IHEX_ERROR_INVALID_FORMAT;
    }  
    ptr += 2;

    
    ihex_get_2bytes(ptr, &(r->address), &checksum);   
    ptr += 4;
    
    ihex_get_byte(ptr, &(r->record_type), &checksum);
    ptr += 2;
    
    ihex_get_nbytes(ptr, (uint8_t *)&(r->data), r->byte_count, &checksum);
    ptr+= 2 * r->byte_count;
    
    ihex_get_byte(ptr, &(r->checksum), &checksum);
    if (0 == checksum) {
        return IHEX_ERROR_NONE;
    } else {
        return IHEX_ERROR_INVALID_CHECKSUM;
    }
}

static ihex_error_t ihex_get_byte(char *src, uint8_t *dst, uint8_t *checksum)
{
    uint8_t digital;
    uint8_t result;
    

    digital = *src - '0';
    if (digital < 10) {
        result = digital << 4;
    } else {
        digital = *src - 'A';
        if (digital < 6) {
            result = (digital + 10) << 4;
        } else {
            return IHEX_ERROR_NON_HEX_CHARACTER;
        }
    }
    
    src++;
    digital = *src - '0';
    if (digital < 10) {
        result += digital;
    } else {
        digital = *src - 'A';
        if (digital < 6) {
            result += (digital + 10);
        } else {
            return IHEX_ERROR_NON_HEX_CHARACTER;
        }
    }
    
    *dst = result;
    *checksum += result;
    
    return IHEX_ERROR_NONE;
}

static ihex_error_t ihex_get_2bytes(char *src, uint16_t *dst, uint8_t *checksum)
{
    ihex_error_t err;
    uint8_t b1, b2;
    
    err = ihex_get_byte(src, &b1, checksum);
    if (IHEX_ERROR_NONE == err) {
		err = ihex_get_byte(src + 2, &b2, checksum);
		if (IHEX_ERROR_NONE == err) {
			*dst = (b1 << 8) + b2;
		}
	}
	
	return err;
}

static ihex_error_t ihex_get_nbytes(char *src, uint8_t *dst, uint8_t nbytes, uint8_t *checksum)
{
	ihex_error_t err = IHEX_ERROR_NONE;
	int i;

	for (i = 0; i < nbytes; i++) {
		err = ihex_get_byte(src + 2 * i, dst + i, checksum);
		if (IHEX_ERROR_NONE != err) {
			break;
		}
	}

	return err;
}

#endif

