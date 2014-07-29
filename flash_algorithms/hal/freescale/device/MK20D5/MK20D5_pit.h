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
#ifndef __HW_PIT_REGISTERS_H__
#define __HW_PIT_REGISTERS_H__

#include "regs.h"

/*
 * MK20D5 PIT
 *
 * Periodic Interrupt Timer
 *
 * Registers defined in this header file:
 * - HW_PIT_MCR - PIT Module Control Register
 * - HW_PIT_LDVALn - Timer Load Value Register
 * - HW_PIT_CVALn - Current Timer Value Register
 * - HW_PIT_TCTRLn - Timer Control Register
 * - HW_PIT_TFLGn - Timer Flag Register
 *
 * - hw_pit_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_PIT_BASE
#define HW_PIT_INSTANCE_COUNT (1U) //!< Number of instances of the PIT module.
#define REGS_PIT_BASE (0x40037000U) //!< Base address for PIT.
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_PIT_MCR - PIT Module Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PIT_MCR - PIT Module Control Register (RW)
 *
 * Reset value: 0x00000002U
 *
 * This register controls whether the timer clocks should be enabled and whether
 * the timers should run in debug mode.
 */
typedef union _hw_pit_mcr
{
    uint32_t U;
    struct _hw_pit_mcr_bitfields
    {
        uint32_t FRZ : 1;              //!< [0] Freeze
        uint32_t MDIS : 1;             //!< [1] Module Disable
        uint32_t RESERVED0 : 30;       //!< [31:2]
    } B;
} hw_pit_mcr_t;
#endif

/*!
 * @name Constants and macros for entire PIT_MCR register
 */
//@{
#define HW_PIT_MCR_ADDR          (REGS_PIT_BASE + 0x0U)

#ifndef __LANGUAGE_ASM__
#define HW_PIT_MCR               (*(__IO hw_pit_mcr_t *) HW_PIT_MCR_ADDR)
#define HW_PIT_MCR_RD()          (HW_PIT_MCR.U)
#define HW_PIT_MCR_WR(v)         (HW_PIT_MCR.U = (v))
#define HW_PIT_MCR_SET(v)        (HW_PIT_MCR_WR(HW_PIT_MCR_RD() |  (v)))
#define HW_PIT_MCR_CLR(v)        (HW_PIT_MCR_WR(HW_PIT_MCR_RD() & ~(v)))
#define HW_PIT_MCR_TOG(v)        (HW_PIT_MCR_WR(HW_PIT_MCR_RD() ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual PIT_MCR bitfields
 */

/*!
 * @name Register PIT_MCR, field FRZ[0] (RW)
 *
 * Allows the timers to be stopped when the device enters debug mode.
 *
 * Values:
 * - 0 - Timers continue to run in debug mode.
 * - 1 - Timers are stopped in debug mode.
 */
//@{
#define BP_PIT_MCR_FRZ       (0U)          //!< Bit position for PIT_MCR_FRZ.
#define BM_PIT_MCR_FRZ       (0x00000001U) //!< Bit mask for PIT_MCR_FRZ.
#define BS_PIT_MCR_FRZ       (1U)          //!< Bit field size in bits for PIT_MCR_FRZ.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the PIT_MCR_FRZ field.
#define BR_PIT_MCR_FRZ       (BITBAND_ACCESS32(HW_PIT_MCR_ADDR, BP_PIT_MCR_FRZ))
#endif

//! @brief Format value for bitfield PIT_MCR_FRZ.
#define BF_PIT_MCR_FRZ(v)    (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_PIT_MCR_FRZ), uint32_t) & BM_PIT_MCR_FRZ)

#ifndef __LANGUAGE_ASM__
//! @brief Set the FRZ field to a new value.
#define BW_PIT_MCR_FRZ(v)    (BITBAND_ACCESS32(HW_PIT_MCR_ADDR, BP_PIT_MCR_FRZ) = (v))
#endif
//@}

/*!
 * @name Register PIT_MCR, field MDIS[1] (RW)
 *
 * This is used to disable the module clock. This bit must be enabled before any
 * other setup is done.
 *
 * Values:
 * - 0 - Clock for PIT Timers is enabled.
 * - 1 - Clock for PIT Timers is disabled.
 */
//@{
#define BP_PIT_MCR_MDIS      (1U)          //!< Bit position for PIT_MCR_MDIS.
#define BM_PIT_MCR_MDIS      (0x00000002U) //!< Bit mask for PIT_MCR_MDIS.
#define BS_PIT_MCR_MDIS      (1U)          //!< Bit field size in bits for PIT_MCR_MDIS.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the PIT_MCR_MDIS field.
#define BR_PIT_MCR_MDIS      (BITBAND_ACCESS32(HW_PIT_MCR_ADDR, BP_PIT_MCR_MDIS))
#endif

//! @brief Format value for bitfield PIT_MCR_MDIS.
#define BF_PIT_MCR_MDIS(v)   (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_PIT_MCR_MDIS), uint32_t) & BM_PIT_MCR_MDIS)

#ifndef __LANGUAGE_ASM__
//! @brief Set the MDIS field to a new value.
#define BW_PIT_MCR_MDIS(v)   (BITBAND_ACCESS32(HW_PIT_MCR_ADDR, BP_PIT_MCR_MDIS) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_PIT_LDVALn - Timer Load Value Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PIT_LDVALn - Timer Load Value Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * These registers select the timeout period for the timer interrupts.
 */
typedef union _hw_pit_ldvaln
{
    uint32_t U;
    struct _hw_pit_ldvaln_bitfields
    {
        uint32_t TSV : 32;             //!< [31:0] Timer Start Value Bits
    } B;
} hw_pit_ldvaln_t;
#endif

/*!
 * @name Constants and macros for entire PIT_LDVALn register
 */
//@{
#define HW_PIT_LDVALn_COUNT (4U)

#define HW_PIT_LDVALn_ADDR(n)    (REGS_PIT_BASE + 0x100U + (0x10U * n))

#ifndef __LANGUAGE_ASM__
#define HW_PIT_LDVALn(n)         (*(__IO hw_pit_ldvaln_t *) HW_PIT_LDVALn_ADDR(n))
#define HW_PIT_LDVALn_RD(n)      (HW_PIT_LDVALn(n).U)
#define HW_PIT_LDVALn_WR(n, v)   (HW_PIT_LDVALn(n).U = (v))
#define HW_PIT_LDVALn_SET(n, v)  (HW_PIT_LDVALn_WR(n, HW_PIT_LDVALn_RD(n) |  (v)))
#define HW_PIT_LDVALn_CLR(n, v)  (HW_PIT_LDVALn_WR(n, HW_PIT_LDVALn_RD(n) & ~(v)))
#define HW_PIT_LDVALn_TOG(n, v)  (HW_PIT_LDVALn_WR(n, HW_PIT_LDVALn_RD(n) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual PIT_LDVALn bitfields
 */

/*!
 * @name Register PIT_LDVALn, field TSV[31:0] (RW)
 */
//@{
#define BP_PIT_LDVALn_TSV    (0U)          //!< Bit position for PIT_LDVALn_TSV.
#define BM_PIT_LDVALn_TSV    (0xFFFFFFFFU) //!< Bit mask for PIT_LDVALn_TSV.
#define BS_PIT_LDVALn_TSV    (32U)         //!< Bit field size in bits for PIT_LDVALn_TSV.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the PIT_LDVALn_TSV field.
#define BR_PIT_LDVALn_TSV(n) (HW_PIT_LDVALn(n).B.TSV)
#endif

//! @brief Format value for bitfield PIT_LDVALn_TSV.
#define BF_PIT_LDVALn_TSV(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_PIT_LDVALn_TSV), uint32_t) & BM_PIT_LDVALn_TSV)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TSV field to a new value.
#define BW_PIT_LDVALn_TSV(n, v) (HW_PIT_LDVALn_WR(n, (HW_PIT_LDVALn_RD(n) & ~BM_PIT_LDVALn_TSV) | BF_PIT_LDVALn_TSV(v)))
#endif
//@}
//-------------------------------------------------------------------------------------------
// HW_PIT_CVALn - Current Timer Value Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PIT_CVALn - Current Timer Value Register (RO)
 *
 * Reset value: 0x00000000U
 *
 * These registers indicate the current timer position.
 */
typedef union _hw_pit_cvaln
{
    uint32_t U;
    struct _hw_pit_cvaln_bitfields
    {
        uint32_t TVL : 32;             //!< [31:0] Current Timer Value
    } B;
} hw_pit_cvaln_t;
#endif

/*!
 * @name Constants and macros for entire PIT_CVALn register
 */
//@{
#define HW_PIT_CVALn_COUNT (4U)

#define HW_PIT_CVALn_ADDR(n)     (REGS_PIT_BASE + 0x104U + (0x10U * n))

#ifndef __LANGUAGE_ASM__
#define HW_PIT_CVALn(n)          (*(__I hw_pit_cvaln_t *) HW_PIT_CVALn_ADDR(n))
#define HW_PIT_CVALn_RD(n)       (HW_PIT_CVALn(n).U)
#endif
//@}

/*
 * Constants & macros for individual PIT_CVALn bitfields
 */

/*!
 * @name Register PIT_CVALn, field TVL[31:0] (RO)
 */
//@{
#define BP_PIT_CVALn_TVL     (0U)          //!< Bit position for PIT_CVALn_TVL.
#define BM_PIT_CVALn_TVL     (0xFFFFFFFFU) //!< Bit mask for PIT_CVALn_TVL.
#define BS_PIT_CVALn_TVL     (32U)         //!< Bit field size in bits for PIT_CVALn_TVL.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the PIT_CVALn_TVL field.
#define BR_PIT_CVALn_TVL(n)  (HW_PIT_CVALn(n).B.TVL)
#endif
//@}
//-------------------------------------------------------------------------------------------
// HW_PIT_TCTRLn - Timer Control Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PIT_TCTRLn - Timer Control Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * These register contain the control bits for each timer.
 */
typedef union _hw_pit_tctrln
{
    uint32_t U;
    struct _hw_pit_tctrln_bitfields
    {
        uint32_t TEN : 1;              //!< [0] Timer Enable Bit.
        uint32_t TIE : 1;              //!< [1] Timer Interrupt Enable Bit.
        uint32_t RESERVED0 : 30;       //!< [31:2]
    } B;
} hw_pit_tctrln_t;
#endif

/*!
 * @name Constants and macros for entire PIT_TCTRLn register
 */
//@{
#define HW_PIT_TCTRLn_COUNT (4U)

#define HW_PIT_TCTRLn_ADDR(n)    (REGS_PIT_BASE + 0x108U + (0x10U * n))

#ifndef __LANGUAGE_ASM__
#define HW_PIT_TCTRLn(n)         (*(__IO hw_pit_tctrln_t *) HW_PIT_TCTRLn_ADDR(n))
#define HW_PIT_TCTRLn_RD(n)      (HW_PIT_TCTRLn(n).U)
#define HW_PIT_TCTRLn_WR(n, v)   (HW_PIT_TCTRLn(n).U = (v))
#define HW_PIT_TCTRLn_SET(n, v)  (HW_PIT_TCTRLn_WR(n, HW_PIT_TCTRLn_RD(n) |  (v)))
#define HW_PIT_TCTRLn_CLR(n, v)  (HW_PIT_TCTRLn_WR(n, HW_PIT_TCTRLn_RD(n) & ~(v)))
#define HW_PIT_TCTRLn_TOG(n, v)  (HW_PIT_TCTRLn_WR(n, HW_PIT_TCTRLn_RD(n) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual PIT_TCTRLn bitfields
 */

/*!
 * @name Register PIT_TCTRLn, field TEN[0] (RW)
 *
 * Values:
 * - 0 - Timer n is disabled.
 * - 1 - Timer n is active.
 */
//@{
#define BP_PIT_TCTRLn_TEN    (0U)          //!< Bit position for PIT_TCTRLn_TEN.
#define BM_PIT_TCTRLn_TEN    (0x00000001U) //!< Bit mask for PIT_TCTRLn_TEN.
#define BS_PIT_TCTRLn_TEN    (1U)          //!< Bit field size in bits for PIT_TCTRLn_TEN.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the PIT_TCTRLn_TEN field.
#define BR_PIT_TCTRLn_TEN(n) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(n), BP_PIT_TCTRLn_TEN))
#endif

//! @brief Format value for bitfield PIT_TCTRLn_TEN.
#define BF_PIT_TCTRLn_TEN(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_PIT_TCTRLn_TEN), uint32_t) & BM_PIT_TCTRLn_TEN)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TEN field to a new value.
#define BW_PIT_TCTRLn_TEN(n, v) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(n), BP_PIT_TCTRLn_TEN) = (v))
#endif
//@}

/*!
 * @name Register PIT_TCTRLn, field TIE[1] (RW)
 *
 * Values:
 * - 0 - Interrupt requests from Timer n are disabled.
 * - 1 - Interrupt will be requested whenever TIF is set.
 */
//@{
#define BP_PIT_TCTRLn_TIE    (1U)          //!< Bit position for PIT_TCTRLn_TIE.
#define BM_PIT_TCTRLn_TIE    (0x00000002U) //!< Bit mask for PIT_TCTRLn_TIE.
#define BS_PIT_TCTRLn_TIE    (1U)          //!< Bit field size in bits for PIT_TCTRLn_TIE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the PIT_TCTRLn_TIE field.
#define BR_PIT_TCTRLn_TIE(n) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(n), BP_PIT_TCTRLn_TIE))
#endif

//! @brief Format value for bitfield PIT_TCTRLn_TIE.
#define BF_PIT_TCTRLn_TIE(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_PIT_TCTRLn_TIE), uint32_t) & BM_PIT_TCTRLn_TIE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIE field to a new value.
#define BW_PIT_TCTRLn_TIE(n, v) (BITBAND_ACCESS32(HW_PIT_TCTRLn_ADDR(n), BP_PIT_TCTRLn_TIE) = (v))
#endif
//@}
//-------------------------------------------------------------------------------------------
// HW_PIT_TFLGn - Timer Flag Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_PIT_TFLGn - Timer Flag Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * These registers hold the PIT interrupt flags.
 */
typedef union _hw_pit_tflgn
{
    uint32_t U;
    struct _hw_pit_tflgn_bitfields
    {
        uint32_t TIF : 1;              //!< [0] Timer Interrupt Flag.
        uint32_t RESERVED0 : 31;       //!< [31:1]
    } B;
} hw_pit_tflgn_t;
#endif

/*!
 * @name Constants and macros for entire PIT_TFLGn register
 */
//@{
#define HW_PIT_TFLGn_COUNT (4U)

#define HW_PIT_TFLGn_ADDR(n)     (REGS_PIT_BASE + 0x10CU + (0x10U * n))

#ifndef __LANGUAGE_ASM__
#define HW_PIT_TFLGn(n)          (*(__IO hw_pit_tflgn_t *) HW_PIT_TFLGn_ADDR(n))
#define HW_PIT_TFLGn_RD(n)       (HW_PIT_TFLGn(n).U)
#define HW_PIT_TFLGn_WR(n, v)    (HW_PIT_TFLGn(n).U = (v))
#define HW_PIT_TFLGn_SET(n, v)   (HW_PIT_TFLGn_WR(n, HW_PIT_TFLGn_RD(n) |  (v)))
#define HW_PIT_TFLGn_CLR(n, v)   (HW_PIT_TFLGn_WR(n, HW_PIT_TFLGn_RD(n) & ~(v)))
#define HW_PIT_TFLGn_TOG(n, v)   (HW_PIT_TFLGn_WR(n, HW_PIT_TFLGn_RD(n) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual PIT_TFLGn bitfields
 */

/*!
 * @name Register PIT_TFLGn, field TIF[0] (W1C)
 *
 * Values:
 * - 0 - Time-out has not yet occurred.
 * - 1 - Time-out has occurred.
 */
//@{
#define BP_PIT_TFLGn_TIF     (0U)          //!< Bit position for PIT_TFLGn_TIF.
#define BM_PIT_TFLGn_TIF     (0x00000001U) //!< Bit mask for PIT_TFLGn_TIF.
#define BS_PIT_TFLGn_TIF     (1U)          //!< Bit field size in bits for PIT_TFLGn_TIF.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the PIT_TFLGn_TIF field.
#define BR_PIT_TFLGn_TIF(n)  (BITBAND_ACCESS32(HW_PIT_TFLGn_ADDR(n), BP_PIT_TFLGn_TIF))
#endif

//! @brief Format value for bitfield PIT_TFLGn_TIF.
#define BF_PIT_TFLGn_TIF(v)  (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_PIT_TFLGn_TIF), uint32_t) & BM_PIT_TFLGn_TIF)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TIF field to a new value.
#define BW_PIT_TFLGn_TIF(n, v) (BITBAND_ACCESS32(HW_PIT_TFLGn_ADDR(n), BP_PIT_TFLGn_TIF) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_pit_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All PIT module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_pit
{
    __IO hw_pit_mcr_t MCR;                 //!< [0x0] PIT Module Control Register
    uint8_t _reserved0[252];
    struct {
        __IO hw_pit_ldvaln_t LDVALn;       //!< [0x100] Timer Load Value Register
        __I hw_pit_cvaln_t CVALn;          //!< [0x104] Current Timer Value Register
        __IO hw_pit_tctrln_t TCTRLn;       //!< [0x108] Timer Control Register
        __IO hw_pit_tflgn_t TFLGn;         //!< [0x10C] Timer Flag Register
    } CHANNEL[4];
} hw_pit_t;
#pragma pack()

//! @brief Macro to access all PIT registers.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_PIT</code>.
#define HW_PIT         (*(hw_pit_t *) REGS_PIT_BASE)
#endif

#endif // __HW_PIT_REGISTERS_H__
// v22/130726/0.9
// EOF
