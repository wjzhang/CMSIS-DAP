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
#ifndef __HW_DMAMUX_REGISTERS_H__
#define __HW_DMAMUX_REGISTERS_H__

#include "regs.h"

/*
 * MK22F51212 DMAMUX
 *
 * DMA channel multiplexor
 *
 * Registers defined in this header file:
 * - HW_DMAMUX_CHCFGn - Channel Configuration register
 *
 * - hw_dmamux_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_DMAMUX_BASE
#define HW_DMAMUX_INSTANCE_COUNT (1U) //!< Number of instances of the DMAMUX module.
#define HW_DMAMUX0 (0U) //!< Instance number for DMAMUX.
#define REGS_DMAMUX0_BASE (0x40021000U) //!< Base address for DMAMUX.

//! @brief Table of base addresses for DMAMUX instances.
static const uint32_t __g_regs_DMAMUX_base_addresses[] = {
        REGS_DMAMUX0_BASE,
    };

//! @brief Get the base address of DMAMUX by instance number.
//! @param x DMAMUX instance number, from 0 through 0.
#define REGS_DMAMUX_BASE(x) (__g_regs_DMAMUX_base_addresses[(x)])

//! @brief Get the instance number given a base address.
//! @param b Base address for an instance of DMAMUX.
#define REGS_DMAMUX_INSTANCE(b) ((b) == REGS_DMAMUX0_BASE ? HW_DMAMUX0 : 0)
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_DMAMUX_CHCFGn - Channel Configuration register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_DMAMUX_CHCFGn - Channel Configuration register (RW)
 *
 * Reset value: 0x00U
 *
 * Each of the DMA channels can be independently enabled/disabled and associated
 * with one of the DMA slots (peripheral slots or always-on slots) in the
 * system. Setting multiple CHCFG registers with the same source value will result in
 * unpredictable behavior. Before changing the trigger or source settings, a DMA
 * channel must be disabled via CHCFGn[ENBL].
 */
typedef union _hw_dmamux_chcfgn
{
    uint8_t U;
    struct _hw_dmamux_chcfgn_bitfields
    {
        uint8_t SOURCE : 6;            //!< [5:0] DMA Channel Source (Slot)
        uint8_t TRIG : 1;              //!< [6] DMA Channel Trigger Enable
        uint8_t ENBL : 1;              //!< [7] DMA Channel Enable
    } B;
} hw_dmamux_chcfgn_t;
#endif

/*!
 * @name Constants and macros for entire DMAMUX_CHCFGn register
 */
//@{
#define HW_DMAMUX_CHCFGn_COUNT (16U)

#define HW_DMAMUX_CHCFGn_ADDR(x, n) (REGS_DMAMUX_BASE(x) + 0x0U + (0x1U * n))

#ifndef __LANGUAGE_ASM__
#define HW_DMAMUX_CHCFGn(x, n)   (*(__IO hw_dmamux_chcfgn_t *) HW_DMAMUX_CHCFGn_ADDR(x, n))
#define HW_DMAMUX_CHCFGn_RD(x, n) (HW_DMAMUX_CHCFGn(x, n).U)
#define HW_DMAMUX_CHCFGn_WR(x, n, v) (HW_DMAMUX_CHCFGn(x, n).U = (v))
#define HW_DMAMUX_CHCFGn_SET(x, n, v) (HW_DMAMUX_CHCFGn_WR(x, n, HW_DMAMUX_CHCFGn_RD(x, n) |  (v)))
#define HW_DMAMUX_CHCFGn_CLR(x, n, v) (HW_DMAMUX_CHCFGn_WR(x, n, HW_DMAMUX_CHCFGn_RD(x, n) & ~(v)))
#define HW_DMAMUX_CHCFGn_TOG(x, n, v) (HW_DMAMUX_CHCFGn_WR(x, n, HW_DMAMUX_CHCFGn_RD(x, n) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual DMAMUX_CHCFGn bitfields
 */

/*!
 * @name Register DMAMUX_CHCFGn, field SOURCE[5:0] (RW)
 *
 * Specifies which DMA source, if any, is routed to a particular DMA channel.
 * See your device's chip configuration details for information about the
 * peripherals and their slot numbers.
 */
//@{
#define BP_DMAMUX_CHCFGn_SOURCE (0U)       //!< Bit position for DMAMUX_CHCFGn_SOURCE.
#define BM_DMAMUX_CHCFGn_SOURCE (0x3FU)    //!< Bit mask for DMAMUX_CHCFGn_SOURCE.
#define BS_DMAMUX_CHCFGn_SOURCE (6U)       //!< Bit field size in bits for DMAMUX_CHCFGn_SOURCE.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DMAMUX_CHCFGn_SOURCE field.
#define BR_DMAMUX_CHCFGn_SOURCE(x, n) (HW_DMAMUX_CHCFGn(x, n).B.SOURCE)
#endif

//! @brief Format value for bitfield DMAMUX_CHCFGn_SOURCE.
#define BF_DMAMUX_CHCFGn_SOURCE(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DMAMUX_CHCFGn_SOURCE), uint8_t) & BM_DMAMUX_CHCFGn_SOURCE)

#ifndef __LANGUAGE_ASM__
//! @brief Set the SOURCE field to a new value.
#define BW_DMAMUX_CHCFGn_SOURCE(x, n, v) (HW_DMAMUX_CHCFGn_WR(x, n, (HW_DMAMUX_CHCFGn_RD(x, n) & ~BM_DMAMUX_CHCFGn_SOURCE) | BF_DMAMUX_CHCFGn_SOURCE(v)))
#endif
//@}

/*!
 * @name Register DMAMUX_CHCFGn, field TRIG[6] (RW)
 *
 * Enables the periodic trigger capability for the triggered DMA channel.
 *
 * Values:
 * - 0 - Triggering is disabled. If triggering is disabled and ENBL is set, the
 *     DMA Channel will simply route the specified source to the DMA channel.
 *     (Normal mode)
 * - 1 - Triggering is enabled. If triggering is enabled and ENBL is set, the
 *     DMAMUX is in Periodic Trigger mode.
 */
//@{
#define BP_DMAMUX_CHCFGn_TRIG (6U)         //!< Bit position for DMAMUX_CHCFGn_TRIG.
#define BM_DMAMUX_CHCFGn_TRIG (0x40U)      //!< Bit mask for DMAMUX_CHCFGn_TRIG.
#define BS_DMAMUX_CHCFGn_TRIG (1U)         //!< Bit field size in bits for DMAMUX_CHCFGn_TRIG.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DMAMUX_CHCFGn_TRIG field.
#define BR_DMAMUX_CHCFGn_TRIG(x, n) (BITBAND_ACCESS8(HW_DMAMUX_CHCFGn_ADDR(x, n), BP_DMAMUX_CHCFGn_TRIG))
#endif

//! @brief Format value for bitfield DMAMUX_CHCFGn_TRIG.
#define BF_DMAMUX_CHCFGn_TRIG(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DMAMUX_CHCFGn_TRIG), uint8_t) & BM_DMAMUX_CHCFGn_TRIG)

#ifndef __LANGUAGE_ASM__
//! @brief Set the TRIG field to a new value.
#define BW_DMAMUX_CHCFGn_TRIG(x, n, v) (BITBAND_ACCESS8(HW_DMAMUX_CHCFGn_ADDR(x, n), BP_DMAMUX_CHCFGn_TRIG) = (v))
#endif
//@}

/*!
 * @name Register DMAMUX_CHCFGn, field ENBL[7] (RW)
 *
 * Enables the DMA channel.
 *
 * Values:
 * - 0 - DMA channel is disabled. This mode is primarily used during
 *     configuration of the DMAMux. The DMA has separate channel enables/disables, which
 *     should be used to disable or reconfigure a DMA channel.
 * - 1 - DMA channel is enabled
 */
//@{
#define BP_DMAMUX_CHCFGn_ENBL (7U)         //!< Bit position for DMAMUX_CHCFGn_ENBL.
#define BM_DMAMUX_CHCFGn_ENBL (0x80U)      //!< Bit mask for DMAMUX_CHCFGn_ENBL.
#define BS_DMAMUX_CHCFGn_ENBL (1U)         //!< Bit field size in bits for DMAMUX_CHCFGn_ENBL.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the DMAMUX_CHCFGn_ENBL field.
#define BR_DMAMUX_CHCFGn_ENBL(x, n) (BITBAND_ACCESS8(HW_DMAMUX_CHCFGn_ADDR(x, n), BP_DMAMUX_CHCFGn_ENBL))
#endif

//! @brief Format value for bitfield DMAMUX_CHCFGn_ENBL.
#define BF_DMAMUX_CHCFGn_ENBL(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint8_t) << BP_DMAMUX_CHCFGn_ENBL), uint8_t) & BM_DMAMUX_CHCFGn_ENBL)

#ifndef __LANGUAGE_ASM__
//! @brief Set the ENBL field to a new value.
#define BW_DMAMUX_CHCFGn_ENBL(x, n, v) (BITBAND_ACCESS8(HW_DMAMUX_CHCFGn_ADDR(x, n), BP_DMAMUX_CHCFGn_ENBL) = (v))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_dmamux_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All DMAMUX module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_dmamux
{
    __IO hw_dmamux_chcfgn_t CHCFGn[16];    //!< [0x0] Channel Configuration register
} hw_dmamux_t;
#pragma pack()

//! @brief Macro to access all DMAMUX registers.
//! @param x DMAMUX instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_DMAMUX(0)</code>.
#define HW_DMAMUX(x)   (*(hw_dmamux_t *) REGS_DMAMUX_BASE(x))
#endif

#endif // __HW_DMAMUX_REGISTERS_H__
// v22/130726/0.9
// EOF
