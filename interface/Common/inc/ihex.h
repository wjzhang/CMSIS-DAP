
#ifndef __IHEX_H__
#define __IHEX_H__

#include <stdint.h>

void ihex_init(void);

/**
 * parse a hex page
 * @param   buf     intel hex data
 * @param   len     length of data
 * @return  1       finish a intel hex file, drag-n-drop is done
 *          0       complete a page, ready to parse next page
 *          -1      invalid intel hex data
 *          -2      SWD error
 */
int ihex_parse_hex_page(uint8_t *buf, int len);

#endif // __IHEX_H__

