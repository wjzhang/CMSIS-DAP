/*
 * Copyright (c) 2014, Freescale Semiconductor, Inc.
 * All rights reserved.
 *
 * THIS SOFTWARE IS PROVIDED BY FREESCALE "AS IS" AND ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT
 * SHALL FREESCALE BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
 * OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
 * OF SUCH DAMAGE.
 */
/*
 * WARNING! DO NOT EDIT THIS FILE DIRECTLY!
 *
 * This file was generated automatically and any changes may be lost.
 */
#ifndef __HW_DAC_REGISTERS_H__
#define __HW_DAC_REGISTERS_H__

#include "regs.h"

/*
 * MK22F51212 DAC
 *
 * 12-Bit Digital-to-Analog Converter
 *
 * Registers defined in this header file:
 * - HW_DAC_DATnL - DAC Data Low Register
 * - HW_DAC_DATnH - DAC Data High Register
 * - HW_DAC_SR - DAC Status Register
 * - HW_DAC_C0 - DAC Control Register
 * - HW_DAC_C1 - DAC Control Register 1
 * - HW_DAC_C2 - DAC Control Register 2
 *
 * - hw_dac_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_DAC_BASE
#define HW_DAC_INSTANCE_COUNT (2U) //!< Number of instances of the DAC module.
#define HW_DAC0 (0U) //!< Instance number for DAC0.
#define HW_DAC1 (1U) //!< Instance number for DAC1.
#define REGS_DAC0_BASE (0x4003F000U) //!< Base address for DAC0.
#define REGS_DAC1_BASE (0x40028000U) //!< Base address for DAC1.

//! @brief Table of base addresses for DAC instances.
static const uint32_t __g_regs_DAC_base_addresses[] = {
        REGS_DAC0_BASE,
        REGS_DAC1_BASE,
    };

//! @brief Get the base address of DAC by instance number.
//! @param x DAC instance number, from 0 through 1.
#define REGS_DAC_BASE(x) (__g_regs_DAC_base_addresses[(x)])

//! @brief Get the instance number given a base address.
//! @param b Base address for an instance of DAC.
#define REGS_DAC_INSTANCE(b) ((b) == REGS_DAC0_BASE ? HW_DAC0 : (b) == REGS_DAC1_BASE ? HW_DAC1 : 0)
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_DAC_DATnL - DAC Data Low Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DAC_DATnL - DAC Data Low Register (RW)
 *
 * Reset value: 0x00U
 */
typedef union _hw_dac_datnl
{
    uint8_t U;
    struct _hw_dac_datnl_bitfields
    {
        uint8_t DATA0 : 8;             //!< [7:0]
    } B;
} hw_dac_datnl_t;
#endif

/*!
 * @name Constants and macros for entire DAC_DATnL register
 */
//@{
#define HW_DAC_DATnL_COUNT (16U)

#define HW_DAC_DATnL_ADDR(x, n)  (REGS_DAC_BASE(x) + 0x0U + (0x2U * n))

#ifndef __LANGUAGE_ASM__
#define HW_DAC_DATnL(x, n)       (*(__IO hw_dac_datnl_t *) HW_DAC_DATnL_ADDR(x, n))
#define HW_DAC_DATnL_RD(x, n)    (HW_DAC_DATnL(x, n).U)
#define HW_DAC_DATnL_WR(x, n, v) (HW_DAC_DATnL(x, n).U = (v))
#define HW_DAC_DATnL_SET(x, n, v) (HW_DAC_DATnL_WR(x, n, HW_DAC_DATnL_RD(x, n) |  (v)))
#define HW_DAC_DATnL_CLR(x, n, v) (HW_DAC_DATnL_WR(x, n, HW_DAC_DATnL_RD(x, n) & ~(v)))
#define HW_DAC_DATnL_TOG(x, n, v) (HW_DAC_DATnL_WR(x, n, HW_DAC_DATnL_RD(x, n) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual DAC_DATnL bitfields
 */

/*!
 * @name Register DAC_DATnL, field DATA0[7:0] (RW)
 *
 * When the DAC buffer is not enabled, DATA[11:0] controls the output voltage
 * based on the following formula: V out = V in * (1 + DACDAT0[11:0])/4096 When the
 * DAC buffer is enabled, DATA is mapped to the 16-word buffer.
 */
//@{
#define BP_DAC_DATnL_DATA0   (0U)          //!< Bit position for DAC_DATnL_DATA0.
#define BM_DAC_DATnL_DATA0   (0xFFU)       //!< Bit mask for DAC_DATnL_DATA0.
#define BS_DAC_DATnL_DATA0   (8U)          //!< Bit field size in bits for DAC_DATnL_DATA0.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_DATnL_DATA0 field.
#define BR_DAC_DATnL_DATA0(x, n) (HW_DAC_DATnL(x, n).B.DATA0)
#endif

//! @brief Format value for bitfield DAC_DATnL_DATA0.
#define BF_DAC_DATnL_DATA0(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_DATnL_DATA0), uint8_t) & BM_DAC_DATnL_DATA0)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA0 field to a new value.
#define BW_DAC_DATnL_DATA0(x, n, v) (HW_DAC_DATnL_WR(x, n, (HW_DAC_DATnL_RD(x, n) & ~BM_DAC_DATnL_DATA0) | BF_DAC_DATnL_DATA0(v)))
#endif
//@}
//-------------------------------------------------------------------------------------------
// HW_DAC_DATnH - DAC Data High Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DAC_DATnH - DAC Data High Register (RW)
 *
 * Reset value: 0x00U
 */
typedef union _hw_dac_datnh
{
    uint8_t U;
    struct _hw_dac_datnh_bitfields
    {
        uint8_t DATA1 : 4;             //!< [3:0]
        uint8_t RESERVED0 : 4;         //!< [7:4]
    } B;
} hw_dac_datnh_t;
#endif

/*!
 * @name Constants and macros for entire DAC_DATnH register
 */
//@{
#define HW_DAC_DATnH_COUNT (16U)

#define HW_DAC_DATnH_ADDR(x, n)  (REGS_DAC_BASE(x) + 0x1U + (0x2U * n))

#ifndef __LANGUAGE_ASM__
#define HW_DAC_DATnH(x, n)       (*(__IO hw_dac_datnh_t *) HW_DAC_DATnH_ADDR(x, n))
#define HW_DAC_DATnH_RD(x, n)    (HW_DAC_DATnH(x, n).U)
#define HW_DAC_DATnH_WR(x, n, v) (HW_DAC_DATnH(x, n).U = (v))
#define HW_DAC_DATnH_SET(x, n, v) (HW_DAC_DATnH_WR(x, n, HW_DAC_DATnH_RD(x, n) |  (v)))
#define HW_DAC_DATnH_CLR(x, n, v) (HW_DAC_DATnH_WR(x, n, HW_DAC_DATnH_RD(x, n) & ~(v)))
#define HW_DAC_DATnH_TOG(x, n, v) (HW_DAC_DATnH_WR(x, n, HW_DAC_DATnH_RD(x, n) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual DAC_DATnH bitfields
 */

/*!
 * @name Register DAC_DATnH, field DATA1[3:0] (RW)
 *
 * When the DAC Buffer is not enabled, DATA[11:0] controls the output voltage
 * based on the following formula. V out = V in * (1 + DACDAT0[11:0])/4096 When the
 * DAC buffer is enabled, DATA[11:0] is mapped to the 16-word buffer.
 */
//@{
#define BP_DAC_DATnH_DATA1   (0U)          //!< Bit position for DAC_DATnH_DATA1.
#define BM_DAC_DATnH_DATA1   (0x0FU)       //!< Bit mask for DAC_DATnH_DATA1.
#define BS_DAC_DATnH_DATA1   (4U)          //!< Bit field size in bits for DAC_DATnH_DATA1.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_DATnH_DATA1 field.
#define BR_DAC_DATnH_DATA1(x, n) (HW_DAC_DATnH(x, n).B.DATA1)
#endif

//! @brief Format value for bitfield DAC_DATnH_DATA1.
#define BF_DAC_DATnH_DATA1(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_DATnH_DATA1), uint8_t) & BM_DAC_DATnH_DATA1)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DATA1 field to a new value.
#define BW_DAC_DATnH_DATA1(x, n, v) (HW_DAC_DATnH_WR(x, n, (HW_DAC_DATnH_RD(x, n) & ~BM_DAC_DATnH_DATA1) | BF_DAC_DATnH_DATA1(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_DAC_SR - DAC Status Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DAC_SR - DAC Status Register (RW)
 *
 * Reset value: 0x02U
 *
 * If DMA is enabled, the flags can be cleared automatically by DMA when the DMA
 * request is done. Writing 0 to a field clears it whereas writing 1 has no
 * effect. After reset, DACBFRPTF is set and can be cleared by software, if needed.
 * The flags are set only when the data buffer status is changed.
 */
typedef union _hw_dac_sr
{
    uint8_t U;
    struct _hw_dac_sr_bitfields
    {
        uint8_t DACBFRPBF : 1;         //!< [0] DAC Buffer Read Pointer Bottom
                                       //! Position Flag
        uint8_t DACBFRPTF : 1;         //!< [1] DAC Buffer Read Pointer Top Position
                                       //! Flag
        uint8_t DACBFWMF : 1;          //!< [2] DAC Buffer Watermark Flag
        uint8_t RESERVED0 : 5;         //!< [7:3]
    } B;
} hw_dac_sr_t;
#endif

/*!
 * @name Constants and macros for entire DAC_SR register
 */
//@{
#define HW_DAC_SR_ADDR(x)        (REGS_DAC_BASE(x) + 0x20U)

#ifndef __LANGUAGE_ASM__
#define HW_DAC_SR(x)             (*(__IO hw_dac_sr_t *) HW_DAC_SR_ADDR(x))
#define HW_DAC_SR_RD(x)          (HW_DAC_SR(x).U)
#define HW_DAC_SR_WR(x, v)       (HW_DAC_SR(x).U = (v))
#define HW_DAC_SR_SET(x, v)      (HW_DAC_SR_WR(x, HW_DAC_SR_RD(x) |  (v)))
#define HW_DAC_SR_CLR(x, v)      (HW_DAC_SR_WR(x, HW_DAC_SR_RD(x) & ~(v)))
#define HW_DAC_SR_TOG(x, v)      (HW_DAC_SR_WR(x, HW_DAC_SR_RD(x) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual DAC_SR bitfields
 */

/*!
 * @name Register DAC_SR, field DACBFRPBF[0] (RW)
 *
 * In FIFO mode, it is FIFO FULL status bit. It means FIFO read pointer equals
 * Write Pointer because of Write Pointer increase. If this bit is set, any write
 * to FIFO from either DMA or CPU is ignored by DAC. It is cleared if there is
 * any DAC trigger making the DAC read pointer increase. Write to this bit is
 * ignored in FIFO mode.
 *
 * Values:
 * - 0 - The DAC buffer read pointer is not equal to C2[DACBFUP].
 * - 1 - The DAC buffer read pointer is equal to C2[DACBFUP].
 */
//@{
#define BP_DAC_SR_DACBFRPBF  (0U)          //!< Bit position for DAC_SR_DACBFRPBF.
#define BM_DAC_SR_DACBFRPBF  (0x01U)       //!< Bit mask for DAC_SR_DACBFRPBF.
#define BS_DAC_SR_DACBFRPBF  (1U)          //!< Bit field size in bits for DAC_SR_DACBFRPBF.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_SR_DACBFRPBF field.
#define BR_DAC_SR_DACBFRPBF(x) (BITBAND_ACCESS8(HW_DAC_SR_ADDR(x), BP_DAC_SR_DACBFRPBF))
#endif

//! @brief Format value for bitfield DAC_SR_DACBFRPBF.
#define BF_DAC_SR_DACBFRPBF(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_SR_DACBFRPBF), uint8_t) & BM_DAC_SR_DACBFRPBF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFRPBF field to a new value.
#define BW_DAC_SR_DACBFRPBF(x, v) (BITBAND_ACCESS8(HW_DAC_SR_ADDR(x), BP_DAC_SR_DACBFRPBF) = (v))
#endif
//@}

/*!
 * @name Register DAC_SR, field DACBFRPTF[1] (RW)
 *
 * In FIFO mode, it is FIFO nearly empty flag. It is set when only one data
 * remains in FIFO. Any DAC trigger does not increase the Read Pointer if this bit is
 * set to avoid any possible glitch or abrupt change at DAC output. It is
 * cleared automatically if FIFO is not empty.
 *
 * Values:
 * - 0 - The DAC buffer read pointer is not zero.
 * - 1 - The DAC buffer read pointer is zero.
 */
//@{
#define BP_DAC_SR_DACBFRPTF  (1U)          //!< Bit position for DAC_SR_DACBFRPTF.
#define BM_DAC_SR_DACBFRPTF  (0x02U)       //!< Bit mask for DAC_SR_DACBFRPTF.
#define BS_DAC_SR_DACBFRPTF  (1U)          //!< Bit field size in bits for DAC_SR_DACBFRPTF.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_SR_DACBFRPTF field.
#define BR_DAC_SR_DACBFRPTF(x) (BITBAND_ACCESS8(HW_DAC_SR_ADDR(x), BP_DAC_SR_DACBFRPTF))
#endif

//! @brief Format value for bitfield DAC_SR_DACBFRPTF.
#define BF_DAC_SR_DACBFRPTF(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_SR_DACBFRPTF), uint8_t) & BM_DAC_SR_DACBFRPTF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFRPTF field to a new value.
#define BW_DAC_SR_DACBFRPTF(x, v) (BITBAND_ACCESS8(HW_DAC_SR_ADDR(x), BP_DAC_SR_DACBFRPTF) = (v))
#endif
//@}

/*!
 * @name Register DAC_SR, field DACBFWMF[2] (RW)
 *
 * This bit is set if the remaining FIFO data is less than the watermark
 * setting. It is cleared automatically by writing data into FIFO by DMA or CPU. Write
 * to this bit is ignored in FIFO mode.
 *
 * Values:
 * - 0 - The DAC buffer read pointer has not reached the watermark level.
 * - 1 - The DAC buffer read pointer has reached the watermark level.
 */
//@{
#define BP_DAC_SR_DACBFWMF   (2U)          //!< Bit position for DAC_SR_DACBFWMF.
#define BM_DAC_SR_DACBFWMF   (0x04U)       //!< Bit mask for DAC_SR_DACBFWMF.
#define BS_DAC_SR_DACBFWMF   (1U)          //!< Bit field size in bits for DAC_SR_DACBFWMF.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_SR_DACBFWMF field.
#define BR_DAC_SR_DACBFWMF(x) (BITBAND_ACCESS8(HW_DAC_SR_ADDR(x), BP_DAC_SR_DACBFWMF))
#endif

//! @brief Format value for bitfield DAC_SR_DACBFWMF.
#define BF_DAC_SR_DACBFWMF(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_SR_DACBFWMF), uint8_t) & BM_DAC_SR_DACBFWMF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFWMF field to a new value.
#define BW_DAC_SR_DACBFWMF(x, v) (BITBAND_ACCESS8(HW_DAC_SR_ADDR(x), BP_DAC_SR_DACBFWMF) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_DAC_C0 - DAC Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DAC_C0 - DAC Control Register (RW)
 *
 * Reset value: 0x00U
 */
typedef union _hw_dac_c0
{
    uint8_t U;
    struct _hw_dac_c0_bitfields
    {
        uint8_t DACBBIEN : 1;          //!< [0] DAC Buffer Read Pointer Bottom Flag
                                       //! Interrupt Enable
        uint8_t DACBTIEN : 1;          //!< [1] DAC Buffer Read Pointer Top Flag
                                       //! Interrupt Enable
        uint8_t DACBWIEN : 1;          //!< [2] DAC Buffer Watermark Interrupt Enable
        uint8_t LPEN : 1;              //!< [3] DAC Low Power Control
        uint8_t DACSWTRG : 1;          //!< [4] DAC Software Trigger
        uint8_t DACTRGSEL : 1;         //!< [5] DAC Trigger Select
        uint8_t DACRFS : 1;            //!< [6] DAC Reference Select
        uint8_t DACEN : 1;             //!< [7] DAC Enable
    } B;
} hw_dac_c0_t;
#endif

/*!
 * @name Constants and macros for entire DAC_C0 register
 */
//@{
#define HW_DAC_C0_ADDR(x)        (REGS_DAC_BASE(x) + 0x21U)

#ifndef __LANGUAGE_ASM__
#define HW_DAC_C0(x)             (*(__IO hw_dac_c0_t *) HW_DAC_C0_ADDR(x))
#define HW_DAC_C0_RD(x)          (HW_DAC_C0(x).U)
#define HW_DAC_C0_WR(x, v)       (HW_DAC_C0(x).U = (v))
#define HW_DAC_C0_SET(x, v)      (HW_DAC_C0_WR(x, HW_DAC_C0_RD(x) |  (v)))
#define HW_DAC_C0_CLR(x, v)      (HW_DAC_C0_WR(x, HW_DAC_C0_RD(x) & ~(v)))
#define HW_DAC_C0_TOG(x, v)      (HW_DAC_C0_WR(x, HW_DAC_C0_RD(x) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual DAC_C0 bitfields
 */

/*!
 * @name Register DAC_C0, field DACBBIEN[0] (RW)
 *
 * Values:
 * - 0 - The DAC buffer read pointer bottom flag interrupt is disabled.
 * - 1 - The DAC buffer read pointer bottom flag interrupt is enabled.
 */
//@{
#define BP_DAC_C0_DACBBIEN   (0U)          //!< Bit position for DAC_C0_DACBBIEN.
#define BM_DAC_C0_DACBBIEN   (0x01U)       //!< Bit mask for DAC_C0_DACBBIEN.
#define BS_DAC_C0_DACBBIEN   (1U)          //!< Bit field size in bits for DAC_C0_DACBBIEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_DACBBIEN field.
#define BR_DAC_C0_DACBBIEN(x) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACBBIEN))
#endif

//! @brief Format value for bitfield DAC_C0_DACBBIEN.
#define BF_DAC_C0_DACBBIEN(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_DACBBIEN), uint8_t) & BM_DAC_C0_DACBBIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBBIEN field to a new value.
#define BW_DAC_C0_DACBBIEN(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACBBIEN) = (v))
#endif
//@}

/*!
 * @name Register DAC_C0, field DACBTIEN[1] (RW)
 *
 * Values:
 * - 0 - The DAC buffer read pointer top flag interrupt is disabled.
 * - 1 - The DAC buffer read pointer top flag interrupt is enabled.
 */
//@{
#define BP_DAC_C0_DACBTIEN   (1U)          //!< Bit position for DAC_C0_DACBTIEN.
#define BM_DAC_C0_DACBTIEN   (0x02U)       //!< Bit mask for DAC_C0_DACBTIEN.
#define BS_DAC_C0_DACBTIEN   (1U)          //!< Bit field size in bits for DAC_C0_DACBTIEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_DACBTIEN field.
#define BR_DAC_C0_DACBTIEN(x) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACBTIEN))
#endif

//! @brief Format value for bitfield DAC_C0_DACBTIEN.
#define BF_DAC_C0_DACBTIEN(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_DACBTIEN), uint8_t) & BM_DAC_C0_DACBTIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBTIEN field to a new value.
#define BW_DAC_C0_DACBTIEN(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACBTIEN) = (v))
#endif
//@}

/*!
 * @name Register DAC_C0, field DACBWIEN[2] (RW)
 *
 * Values:
 * - 0 - The DAC buffer watermark interrupt is disabled.
 * - 1 - The DAC buffer watermark interrupt is enabled.
 */
//@{
#define BP_DAC_C0_DACBWIEN   (2U)          //!< Bit position for DAC_C0_DACBWIEN.
#define BM_DAC_C0_DACBWIEN   (0x04U)       //!< Bit mask for DAC_C0_DACBWIEN.
#define BS_DAC_C0_DACBWIEN   (1U)          //!< Bit field size in bits for DAC_C0_DACBWIEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_DACBWIEN field.
#define BR_DAC_C0_DACBWIEN(x) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACBWIEN))
#endif

//! @brief Format value for bitfield DAC_C0_DACBWIEN.
#define BF_DAC_C0_DACBWIEN(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_DACBWIEN), uint8_t) & BM_DAC_C0_DACBWIEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBWIEN field to a new value.
#define BW_DAC_C0_DACBWIEN(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACBWIEN) = (v))
#endif
//@}

/*!
 * @name Register DAC_C0, field LPEN[3] (RW)
 *
 * See the 12-bit DAC electrical characteristics of the device data sheet for
 * details on the impact of the modes below.
 *
 * Values:
 * - 0 - High-Power mode
 * - 1 - Low-Power mode
 */
//@{
#define BP_DAC_C0_LPEN       (3U)          //!< Bit position for DAC_C0_LPEN.
#define BM_DAC_C0_LPEN       (0x08U)       //!< Bit mask for DAC_C0_LPEN.
#define BS_DAC_C0_LPEN       (1U)          //!< Bit field size in bits for DAC_C0_LPEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_LPEN field.
#define BR_DAC_C0_LPEN(x)    (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_LPEN))
#endif

//! @brief Format value for bitfield DAC_C0_LPEN.
#define BF_DAC_C0_LPEN(v)    (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_LPEN), uint8_t) & BM_DAC_C0_LPEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the LPEN field to a new value.
#define BW_DAC_C0_LPEN(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_LPEN) = (v))
#endif
//@}

/*!
 * @name Register DAC_C0, field DACSWTRG[4] (WORZ)
 *
 * Active high. This is a write-only field, which always reads 0. If DAC
 * software trigger is selected and buffer is enabled, writing 1 to this field will
 * advance the buffer read pointer once.
 *
 * Values:
 * - 0 - The DAC soft trigger is not valid.
 * - 1 - The DAC soft trigger is valid.
 */
//@{
#define BP_DAC_C0_DACSWTRG   (4U)          //!< Bit position for DAC_C0_DACSWTRG.
#define BM_DAC_C0_DACSWTRG   (0x10U)       //!< Bit mask for DAC_C0_DACSWTRG.
#define BS_DAC_C0_DACSWTRG   (1U)          //!< Bit field size in bits for DAC_C0_DACSWTRG.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_DACSWTRG field.
#define BR_DAC_C0_DACSWTRG(x) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACSWTRG))
#endif

//! @brief Format value for bitfield DAC_C0_DACSWTRG.
#define BF_DAC_C0_DACSWTRG(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_DACSWTRG), uint8_t) & BM_DAC_C0_DACSWTRG)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACSWTRG field to a new value.
#define BW_DAC_C0_DACSWTRG(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACSWTRG) = (v))
#endif
//@}

/*!
 * @name Register DAC_C0, field DACTRGSEL[5] (RW)
 *
 * Values:
 * - 0 - The DAC hardware trigger is selected.
 * - 1 - The DAC software trigger is selected.
 */
//@{
#define BP_DAC_C0_DACTRGSEL  (5U)          //!< Bit position for DAC_C0_DACTRGSEL.
#define BM_DAC_C0_DACTRGSEL  (0x20U)       //!< Bit mask for DAC_C0_DACTRGSEL.
#define BS_DAC_C0_DACTRGSEL  (1U)          //!< Bit field size in bits for DAC_C0_DACTRGSEL.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_DACTRGSEL field.
#define BR_DAC_C0_DACTRGSEL(x) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACTRGSEL))
#endif

//! @brief Format value for bitfield DAC_C0_DACTRGSEL.
#define BF_DAC_C0_DACTRGSEL(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_DACTRGSEL), uint8_t) & BM_DAC_C0_DACTRGSEL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACTRGSEL field to a new value.
#define BW_DAC_C0_DACTRGSEL(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACTRGSEL) = (v))
#endif
//@}

/*!
 * @name Register DAC_C0, field DACRFS[6] (RW)
 *
 * Values:
 * - 0 - The DAC selects DACREF_1 as the reference voltage.
 * - 1 - The DAC selects DACREF_2 as the reference voltage.
 */
//@{
#define BP_DAC_C0_DACRFS     (6U)          //!< Bit position for DAC_C0_DACRFS.
#define BM_DAC_C0_DACRFS     (0x40U)       //!< Bit mask for DAC_C0_DACRFS.
#define BS_DAC_C0_DACRFS     (1U)          //!< Bit field size in bits for DAC_C0_DACRFS.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_DACRFS field.
#define BR_DAC_C0_DACRFS(x)  (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACRFS))
#endif

//! @brief Format value for bitfield DAC_C0_DACRFS.
#define BF_DAC_C0_DACRFS(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_DACRFS), uint8_t) & BM_DAC_C0_DACRFS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACRFS field to a new value.
#define BW_DAC_C0_DACRFS(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACRFS) = (v))
#endif
//@}

/*!
 * @name Register DAC_C0, field DACEN[7] (RW)
 *
 * Starts the Programmable Reference Generator operation.
 *
 * Values:
 * - 0 - The DAC system is disabled.
 * - 1 - The DAC system is enabled.
 */
//@{
#define BP_DAC_C0_DACEN      (7U)          //!< Bit position for DAC_C0_DACEN.
#define BM_DAC_C0_DACEN      (0x80U)       //!< Bit mask for DAC_C0_DACEN.
#define BS_DAC_C0_DACEN      (1U)          //!< Bit field size in bits for DAC_C0_DACEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C0_DACEN field.
#define BR_DAC_C0_DACEN(x)   (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACEN))
#endif

//! @brief Format value for bitfield DAC_C0_DACEN.
#define BF_DAC_C0_DACEN(v)   (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C0_DACEN), uint8_t) & BM_DAC_C0_DACEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACEN field to a new value.
#define BW_DAC_C0_DACEN(x, v) (BITBAND_ACCESS8(HW_DAC_C0_ADDR(x), BP_DAC_C0_DACEN) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_DAC_C1 - DAC Control Register 1
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DAC_C1 - DAC Control Register 1 (RW)
 *
 * Reset value: 0x00U
 */
typedef union _hw_dac_c1
{
    uint8_t U;
    struct _hw_dac_c1_bitfields
    {
        uint8_t DACBFEN : 1;           //!< [0] DAC Buffer Enable
        uint8_t DACBFMD : 2;           //!< [2:1] DAC Buffer Work Mode Select
        uint8_t DACBFWM : 2;           //!< [4:3] DAC Buffer Watermark Select
        uint8_t RESERVED0 : 2;         //!< [6:5]
        uint8_t DMAEN : 1;             //!< [7] DMA Enable Select
    } B;
} hw_dac_c1_t;
#endif

/*!
 * @name Constants and macros for entire DAC_C1 register
 */
//@{
#define HW_DAC_C1_ADDR(x)        (REGS_DAC_BASE(x) + 0x22U)

#ifndef __LANGUAGE_ASM__
#define HW_DAC_C1(x)             (*(__IO hw_dac_c1_t *) HW_DAC_C1_ADDR(x))
#define HW_DAC_C1_RD(x)          (HW_DAC_C1(x).U)
#define HW_DAC_C1_WR(x, v)       (HW_DAC_C1(x).U = (v))
#define HW_DAC_C1_SET(x, v)      (HW_DAC_C1_WR(x, HW_DAC_C1_RD(x) |  (v)))
#define HW_DAC_C1_CLR(x, v)      (HW_DAC_C1_WR(x, HW_DAC_C1_RD(x) & ~(v)))
#define HW_DAC_C1_TOG(x, v)      (HW_DAC_C1_WR(x, HW_DAC_C1_RD(x) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual DAC_C1 bitfields
 */

/*!
 * @name Register DAC_C1, field DACBFEN[0] (RW)
 *
 * Values:
 * - 0 - Buffer read pointer is disabled. The converted data is always the first
 *     word of the buffer.
 * - 1 - Buffer read pointer is enabled. The converted data is the word that the
 *     read pointer points to. It means converted data can be from any word of
 *     the buffer.
 */
//@{
#define BP_DAC_C1_DACBFEN    (0U)          //!< Bit position for DAC_C1_DACBFEN.
#define BM_DAC_C1_DACBFEN    (0x01U)       //!< Bit mask for DAC_C1_DACBFEN.
#define BS_DAC_C1_DACBFEN    (1U)          //!< Bit field size in bits for DAC_C1_DACBFEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C1_DACBFEN field.
#define BR_DAC_C1_DACBFEN(x) (BITBAND_ACCESS8(HW_DAC_C1_ADDR(x), BP_DAC_C1_DACBFEN))
#endif

//! @brief Format value for bitfield DAC_C1_DACBFEN.
#define BF_DAC_C1_DACBFEN(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C1_DACBFEN), uint8_t) & BM_DAC_C1_DACBFEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFEN field to a new value.
#define BW_DAC_C1_DACBFEN(x, v) (BITBAND_ACCESS8(HW_DAC_C1_ADDR(x), BP_DAC_C1_DACBFEN) = (v))
#endif
//@}

/*!
 * @name Register DAC_C1, field DACBFMD[2:1] (RW)
 *
 * Values:
 * - 00 - Normal mode
 * - 01 - Swing mode
 * - 10 - One-Time Scan mode
 * - 11 - FIFO mode
 */
//@{
#define BP_DAC_C1_DACBFMD    (1U)          //!< Bit position for DAC_C1_DACBFMD.
#define BM_DAC_C1_DACBFMD    (0x06U)       //!< Bit mask for DAC_C1_DACBFMD.
#define BS_DAC_C1_DACBFMD    (2U)          //!< Bit field size in bits for DAC_C1_DACBFMD.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C1_DACBFMD field.
#define BR_DAC_C1_DACBFMD(x) (HW_DAC_C1(x).B.DACBFMD)
#endif

//! @brief Format value for bitfield DAC_C1_DACBFMD.
#define BF_DAC_C1_DACBFMD(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C1_DACBFMD), uint8_t) & BM_DAC_C1_DACBFMD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFMD field to a new value.
#define BW_DAC_C1_DACBFMD(x, v) (HW_DAC_C1_WR(x, (HW_DAC_C1_RD(x) & ~BM_DAC_C1_DACBFMD) | BF_DAC_C1_DACBFMD(v)))
#endif
//@}

/*!
 * @name Register DAC_C1, field DACBFWM[4:3] (RW)
 *
 * In normal mode it controls when SR[DACBFWMF] is set. When the DAC buffer read
 * pointer reaches the word defined by this field, which is 1-4 words away from
 * the upper limit (DACBUP), SR[DACBFWMF] will be set. This allows user
 * configuration of the watermark interrupt. In FIFO mode, it is FIFO watermark select
 * field.
 *
 * Values:
 * - 00 - In normal mode, 1 word . In FIFO mode, 2 or less than 2 data remaining
 *     in FIFO will set watermark status bit.
 * - 01 - In normal mode, 2 words . In FIFO mode, Max/4 or less than Max/4 data
 *     remaining in FIFO will set watermark status bit.
 * - 10 - In normal mode, 3 words . In FIFO mode, Max/2 or less than Max/2 data
 *     remaining in FIFO will set watermark status bit.
 * - 11 - In normal mode, 4 words . In FIFO mode, Max-2 or less than Max-2 data
 *     remaining in FIFO will set watermark status bit.
 */
//@{
#define BP_DAC_C1_DACBFWM    (3U)          //!< Bit position for DAC_C1_DACBFWM.
#define BM_DAC_C1_DACBFWM    (0x18U)       //!< Bit mask for DAC_C1_DACBFWM.
#define BS_DAC_C1_DACBFWM    (2U)          //!< Bit field size in bits for DAC_C1_DACBFWM.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C1_DACBFWM field.
#define BR_DAC_C1_DACBFWM(x) (HW_DAC_C1(x).B.DACBFWM)
#endif

//! @brief Format value for bitfield DAC_C1_DACBFWM.
#define BF_DAC_C1_DACBFWM(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C1_DACBFWM), uint8_t) & BM_DAC_C1_DACBFWM)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFWM field to a new value.
#define BW_DAC_C1_DACBFWM(x, v) (HW_DAC_C1_WR(x, (HW_DAC_C1_RD(x) & ~BM_DAC_C1_DACBFWM) | BF_DAC_C1_DACBFWM(v)))
#endif
//@}

/*!
 * @name Register DAC_C1, field DMAEN[7] (RW)
 *
 * Values:
 * - 0 - DMA is disabled.
 * - 1 - DMA is enabled. When DMA is enabled, the DMA request will be generated
 *     by original interrupts. The interrupts will not be presented on this
 *     module at the same time.
 */
//@{
#define BP_DAC_C1_DMAEN      (7U)          //!< Bit position for DAC_C1_DMAEN.
#define BM_DAC_C1_DMAEN      (0x80U)       //!< Bit mask for DAC_C1_DMAEN.
#define BS_DAC_C1_DMAEN      (1U)          //!< Bit field size in bits for DAC_C1_DMAEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C1_DMAEN field.
#define BR_DAC_C1_DMAEN(x)   (BITBAND_ACCESS8(HW_DAC_C1_ADDR(x), BP_DAC_C1_DMAEN))
#endif

//! @brief Format value for bitfield DAC_C1_DMAEN.
#define BF_DAC_C1_DMAEN(v)   (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C1_DMAEN), uint8_t) & BM_DAC_C1_DMAEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DMAEN field to a new value.
#define BW_DAC_C1_DMAEN(x, v) (BITBAND_ACCESS8(HW_DAC_C1_ADDR(x), BP_DAC_C1_DMAEN) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_DAC_C2 - DAC Control Register 2
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DAC_C2 - DAC Control Register 2 (RW)
 *
 * Reset value: 0x0FU
 */
typedef union _hw_dac_c2
{
    uint8_t U;
    struct _hw_dac_c2_bitfields
    {
        uint8_t DACBFUP : 4;           //!< [3:0] DAC Buffer Upper Limit
        uint8_t DACBFRP : 4;           //!< [7:4] DAC Buffer Read Pointer
    } B;
} hw_dac_c2_t;
#endif

/*!
 * @name Constants and macros for entire DAC_C2 register
 */
//@{
#define HW_DAC_C2_ADDR(x)        (REGS_DAC_BASE(x) + 0x23U)

#ifndef __LANGUAGE_ASM__
#define HW_DAC_C2(x)             (*(__IO hw_dac_c2_t *) HW_DAC_C2_ADDR(x))
#define HW_DAC_C2_RD(x)          (HW_DAC_C2(x).U)
#define HW_DAC_C2_WR(x, v)       (HW_DAC_C2(x).U = (v))
#define HW_DAC_C2_SET(x, v)      (HW_DAC_C2_WR(x, HW_DAC_C2_RD(x) |  (v)))
#define HW_DAC_C2_CLR(x, v)      (HW_DAC_C2_WR(x, HW_DAC_C2_RD(x) & ~(v)))
#define HW_DAC_C2_TOG(x, v)      (HW_DAC_C2_WR(x, HW_DAC_C2_RD(x) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual DAC_C2 bitfields
 */

/*!
 * @name Register DAC_C2, field DACBFUP[3:0] (RW)
 *
 * In normal mode it selects the upper limit of the DAC buffer. The buffer read
 * pointer cannot exceed it. In FIFO mode it is the FIFO write pointer. User
 * cannot set Buffer Up limit in FIFO mode. In Normal mode its reset value is MAX.
 * When IP is configured to FIFO mode, this register becomes Write_Pointer, and its
 * value is initially set to equal READ_POINTER automatically, and the FIFO
 * status is empty. It is writable and user can configure it to the same address to
 * reset FIFO as empty.
 */
//@{
#define BP_DAC_C2_DACBFUP    (0U)          //!< Bit position for DAC_C2_DACBFUP.
#define BM_DAC_C2_DACBFUP    (0x0FU)       //!< Bit mask for DAC_C2_DACBFUP.
#define BS_DAC_C2_DACBFUP    (4U)          //!< Bit field size in bits for DAC_C2_DACBFUP.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C2_DACBFUP field.
#define BR_DAC_C2_DACBFUP(x) (HW_DAC_C2(x).B.DACBFUP)
#endif

//! @brief Format value for bitfield DAC_C2_DACBFUP.
#define BF_DAC_C2_DACBFUP(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C2_DACBFUP), uint8_t) & BM_DAC_C2_DACBFUP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFUP field to a new value.
#define BW_DAC_C2_DACBFUP(x, v) (HW_DAC_C2_WR(x, (HW_DAC_C2_RD(x) & ~BM_DAC_C2_DACBFUP) | BF_DAC_C2_DACBFUP(v)))
#endif
//@}

/*!
 * @name Register DAC_C2, field DACBFRP[7:4] (RW)
 *
 * In normal mode it keeps the current value of the buffer read pointer. FIFO
 * mode, it is the FIFO read pointer. It is writable in FIFO mode. User can
 * configure it to same address to reset FIFO as empty.
 */
//@{
#define BP_DAC_C2_DACBFRP    (4U)          //!< Bit position for DAC_C2_DACBFRP.
#define BM_DAC_C2_DACBFRP    (0xF0U)       //!< Bit mask for DAC_C2_DACBFRP.
#define BS_DAC_C2_DACBFRP    (4U)          //!< Bit field size in bits for DAC_C2_DACBFRP.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DAC_C2_DACBFRP field.
#define BR_DAC_C2_DACBFRP(x) (HW_DAC_C2(x).B.DACBFRP)
#endif

//! @brief Format value for bitfield DAC_C2_DACBFRP.
#define BF_DAC_C2_DACBFRP(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DAC_C2_DACBFRP), uint8_t) & BM_DAC_C2_DACBFRP)

#ifndef __LANGUAGE_ASM__
//! @brief Set the DACBFRP field to a new value.
#define BW_DAC_C2_DACBFRP(x, v) (HW_DAC_C2_WR(x, (HW_DAC_C2_RD(x) & ~BM_DAC_C2_DACBFRP) | BF_DAC_C2_DACBFRP(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_dac_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All DAC module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_dac
{
    struct {
        __IO hw_dac_datnl_t DATnL;         //!< [0x0] DAC Data Low Register
        __IO hw_dac_datnh_t DATnH;         //!< [0x1] DAC Data High Register
    } DAT[16];
    __IO hw_dac_sr_t SR;                   //!< [0x20] DAC Status Register
    __IO hw_dac_c0_t C0;                   //!< [0x21] DAC Control Register
    __IO hw_dac_c1_t C1;                   //!< [0x22] DAC Control Register 1
    __IO hw_dac_c2_t C2;                   //!< [0x23] DAC Control Register 2
} hw_dac_t;
#pragma pack()

//! @brief Macro to access all DAC registers.
//! @param x DAC instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_DAC(0)</code>.
#define HW_DAC(x)      (*(hw_dac_t *) REGS_DAC_BASE(x))
#endif

#endif // __HW_DAC_REGISTERS_H__
// v22/130726/0.9
// EOF
