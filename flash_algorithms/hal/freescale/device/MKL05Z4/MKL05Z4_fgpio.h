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
#ifndef __HW_FGPIO_REGISTERS_H__
#define __HW_FGPIO_REGISTERS_H__

#include "regs.h"

/*
 * MKL05Z4 FGPIO
 *
 * General Purpose Input/Output
 *
 * Registers defined in this header file:
 * - HW_FGPIO_PDOR - Port Data Output Register
 * - HW_FGPIO_PSOR - Port Set Output Register
 * - HW_FGPIO_PCOR - Port Clear Output Register
 * - HW_FGPIO_PTOR - Port Toggle Output Register
 * - HW_FGPIO_PDIR - Port Data Input Register
 * - HW_FGPIO_PDDR - Port Data Direction Register
 *
 * - hw_fgpio_t - Struct containing all module registers.
 */

//! @name Module base addresses
//@{
#ifndef REGS_FGPIO_BASE
#define HW_FGPIO_INSTANCE_COUNT (2U) //!< Number of instances of the FGPIO module.
#define HW_FPTA (0U) //!< Instance number for FPTA.
#define HW_FPTB (1U) //!< Instance number for FPTB.
#define REGS_FPTA_BASE (0xF80FF000U) //!< Base address for FPTA.
#define REGS_FPTB_BASE (0xF80FF040U) //!< Base address for FPTB.

//! @brief Table of base addresses for FGPIO instances.
static const uint32_t __g_regs_FGPIO_base_addresses[] = {
        REGS_FPTA_BASE,
        REGS_FPTB_BASE,
    };

//! @brief Get the base address of FGPIO by instance number.
//! @param x FGPIO instance number, from 0 through 1.
#define REGS_FGPIO_BASE(x) (__g_regs_FGPIO_base_addresses[(x)])

//! @brief Get the instance number given a base address.
//! @param b Base address for an instance of FGPIO.
#define REGS_FGPIO_INSTANCE(b) ((b) == REGS_FPTA_BASE ? HW_FPTA : (b) == REGS_FPTB_BASE ? HW_FPTB : 0)
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_FGPIO_PDOR - Port Data Output Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FGPIO_PDOR - Port Data Output Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * This register configures the logic levels that are driven on each
 * general-purpose output pins.
 */
typedef union _hw_fgpio_pdor
{
    uint32_t U;
    struct _hw_fgpio_pdor_bitfields
    {
        uint32_t PDO : 32;             //!< [31:0] Port Data Output
    } B;
} hw_fgpio_pdor_t;
#endif

/*!
 * @name Constants and macros for entire FGPIO_PDOR register
 */
//@{
#define HW_FGPIO_PDOR_ADDR(x)    (REGS_FGPIO_BASE(x) + 0x0U)

#ifndef __LANGUAGE_ASM__
#define HW_FGPIO_PDOR(x)         (*(__IO hw_fgpio_pdor_t *) HW_FGPIO_PDOR_ADDR(x))
#define HW_FGPIO_PDOR_RD(x)      (HW_FGPIO_PDOR(x).U)
#define HW_FGPIO_PDOR_WR(x, v)   (HW_FGPIO_PDOR(x).U = (v))
#define HW_FGPIO_PDOR_SET(x, v)  (HW_FGPIO_PDOR_WR(x, HW_FGPIO_PDOR_RD(x) |  (v)))
#define HW_FGPIO_PDOR_CLR(x, v)  (HW_FGPIO_PDOR_WR(x, HW_FGPIO_PDOR_RD(x) & ~(v)))
#define HW_FGPIO_PDOR_TOG(x, v)  (HW_FGPIO_PDOR_WR(x, HW_FGPIO_PDOR_RD(x) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual FGPIO_PDOR bitfields
 */

/*!
 * @name Register FGPIO_PDOR, field PDO[31:0] (RW)
 *
 * Unimplemented pins for a particular device read as zero.
 *
 * Values:
 * - 0 - Logic level 0 is driven on pin, provided pin is configured for
 *     general-purpose output.
 * - 1 - Logic level 1 is driven on pin, provided pin is configured for
 *     general-purpose output.
 */
//@{
#define BP_FGPIO_PDOR_PDO    (0U)          //!< Bit position for FGPIO_PDOR_PDO.
#define BM_FGPIO_PDOR_PDO    (0xFFFFFFFFU) //!< Bit mask for FGPIO_PDOR_PDO.
#define BS_FGPIO_PDOR_PDO    (32U)         //!< Bit field size in bits for FGPIO_PDOR_PDO.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the FGPIO_PDOR_PDO field.
#define BR_FGPIO_PDOR_PDO(x) (HW_FGPIO_PDOR(x).B.PDO)
#endif

//! @brief Format value for bitfield FGPIO_PDOR_PDO.
#define BF_FGPIO_PDOR_PDO(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_FGPIO_PDOR_PDO), uint32_t) & BM_FGPIO_PDOR_PDO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDO field to a new value.
#define BW_FGPIO_PDOR_PDO(x, v) (HW_FGPIO_PDOR_WR(x, (HW_FGPIO_PDOR_RD(x) & ~BM_FGPIO_PDOR_PDO) | BF_FGPIO_PDOR_PDO(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_FGPIO_PSOR - Port Set Output Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FGPIO_PSOR - Port Set Output Register (WO)
 *
 * Reset value: 0x00000000U
 *
 * This register configures whether to set the fields of the PDOR.
 */
typedef union _hw_fgpio_psor
{
    uint32_t U;
    struct _hw_fgpio_psor_bitfields
    {
        uint32_t PTSO : 32;            //!< [31:0] Port Set Output
    } B;
} hw_fgpio_psor_t;
#endif

/*!
 * @name Constants and macros for entire FGPIO_PSOR register
 */
//@{
#define HW_FGPIO_PSOR_ADDR(x)    (REGS_FGPIO_BASE(x) + 0x4U)

#ifndef __LANGUAGE_ASM__
#define HW_FGPIO_PSOR(x)         (*(__O hw_fgpio_psor_t *) HW_FGPIO_PSOR_ADDR(x))
#define HW_FGPIO_PSOR_WR(x, v)   (HW_FGPIO_PSOR(x).U = (v))
#endif
//@}

/*
 * Constants & macros for individual FGPIO_PSOR bitfields
 */

/*!
 * @name Register FGPIO_PSOR, field PTSO[31:0] (WORZ)
 *
 * Writing to this register will update the contents of the corresponding bit in
 * the PDOR as follows:
 *
 * Values:
 * - 0 - Corresponding bit in PDORn does not change.
 * - 1 - Corresponding bit in PDORn is set to logic 1.
 */
//@{
#define BP_FGPIO_PSOR_PTSO   (0U)          //!< Bit position for FGPIO_PSOR_PTSO.
#define BM_FGPIO_PSOR_PTSO   (0xFFFFFFFFU) //!< Bit mask for FGPIO_PSOR_PTSO.
#define BS_FGPIO_PSOR_PTSO   (32U)         //!< Bit field size in bits for FGPIO_PSOR_PTSO.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the FGPIO_PSOR_PTSO field.
#define BR_FGPIO_PSOR_PTSO(x) (HW_FGPIO_PSOR(x).B.PTSO)
#endif

//! @brief Format value for bitfield FGPIO_PSOR_PTSO.
#define BF_FGPIO_PSOR_PTSO(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_FGPIO_PSOR_PTSO), uint32_t) & BM_FGPIO_PSOR_PTSO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PTSO field to a new value.
#define BW_FGPIO_PSOR_PTSO(x, v) (HW_FGPIO_PSOR_WR(x, (HW_FGPIO_PSOR_RD(x) & ~BM_FGPIO_PSOR_PTSO) | BF_FGPIO_PSOR_PTSO(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_FGPIO_PCOR - Port Clear Output Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FGPIO_PCOR - Port Clear Output Register (WO)
 *
 * Reset value: 0x00000000U
 *
 * This register configures whether to clear the fields of PDOR.
 */
typedef union _hw_fgpio_pcor
{
    uint32_t U;
    struct _hw_fgpio_pcor_bitfields
    {
        uint32_t PTCO : 32;            //!< [31:0] Port Clear Output
    } B;
} hw_fgpio_pcor_t;
#endif

/*!
 * @name Constants and macros for entire FGPIO_PCOR register
 */
//@{
#define HW_FGPIO_PCOR_ADDR(x)    (REGS_FGPIO_BASE(x) + 0x8U)

#ifndef __LANGUAGE_ASM__
#define HW_FGPIO_PCOR(x)         (*(__O hw_fgpio_pcor_t *) HW_FGPIO_PCOR_ADDR(x))
#define HW_FGPIO_PCOR_WR(x, v)   (HW_FGPIO_PCOR(x).U = (v))
#endif
//@}

/*
 * Constants & macros for individual FGPIO_PCOR bitfields
 */

/*!
 * @name Register FGPIO_PCOR, field PTCO[31:0] (WORZ)
 *
 * Writing to this register will update the contents of the corresponding bit in
 * the Port Data Output Register (PDOR) as follows:
 *
 * Values:
 * - 0 - Corresponding bit in PDORn does not change.
 * - 1 - Corresponding bit in PDORn is cleared to logic 0.
 */
//@{
#define BP_FGPIO_PCOR_PTCO   (0U)          //!< Bit position for FGPIO_PCOR_PTCO.
#define BM_FGPIO_PCOR_PTCO   (0xFFFFFFFFU) //!< Bit mask for FGPIO_PCOR_PTCO.
#define BS_FGPIO_PCOR_PTCO   (32U)         //!< Bit field size in bits for FGPIO_PCOR_PTCO.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the FGPIO_PCOR_PTCO field.
#define BR_FGPIO_PCOR_PTCO(x) (HW_FGPIO_PCOR(x).B.PTCO)
#endif

//! @brief Format value for bitfield FGPIO_PCOR_PTCO.
#define BF_FGPIO_PCOR_PTCO(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_FGPIO_PCOR_PTCO), uint32_t) & BM_FGPIO_PCOR_PTCO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PTCO field to a new value.
#define BW_FGPIO_PCOR_PTCO(x, v) (HW_FGPIO_PCOR_WR(x, (HW_FGPIO_PCOR_RD(x) & ~BM_FGPIO_PCOR_PTCO) | BF_FGPIO_PCOR_PTCO(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_FGPIO_PTOR - Port Toggle Output Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FGPIO_PTOR - Port Toggle Output Register (WO)
 *
 * Reset value: 0x00000000U
 */
typedef union _hw_fgpio_ptor
{
    uint32_t U;
    struct _hw_fgpio_ptor_bitfields
    {
        uint32_t PTTO : 32;            //!< [31:0] Port Toggle Output
    } B;
} hw_fgpio_ptor_t;
#endif

/*!
 * @name Constants and macros for entire FGPIO_PTOR register
 */
//@{
#define HW_FGPIO_PTOR_ADDR(x)    (REGS_FGPIO_BASE(x) + 0xCU)

#ifndef __LANGUAGE_ASM__
#define HW_FGPIO_PTOR(x)         (*(__O hw_fgpio_ptor_t *) HW_FGPIO_PTOR_ADDR(x))
#define HW_FGPIO_PTOR_WR(x, v)   (HW_FGPIO_PTOR(x).U = (v))
#endif
//@}

/*
 * Constants & macros for individual FGPIO_PTOR bitfields
 */

/*!
 * @name Register FGPIO_PTOR, field PTTO[31:0] (WORZ)
 *
 * Writing to this register will update the contents of the corresponding bit in
 * the PDOR as follows:
 *
 * Values:
 * - 0 - Corresponding bit in PDORn does not change.
 * - 1 - Corresponding bit in PDORn is set to the inverse of its existing logic
 *     state.
 */
//@{
#define BP_FGPIO_PTOR_PTTO   (0U)          //!< Bit position for FGPIO_PTOR_PTTO.
#define BM_FGPIO_PTOR_PTTO   (0xFFFFFFFFU) //!< Bit mask for FGPIO_PTOR_PTTO.
#define BS_FGPIO_PTOR_PTTO   (32U)         //!< Bit field size in bits for FGPIO_PTOR_PTTO.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the FGPIO_PTOR_PTTO field.
#define BR_FGPIO_PTOR_PTTO(x) (HW_FGPIO_PTOR(x).B.PTTO)
#endif

//! @brief Format value for bitfield FGPIO_PTOR_PTTO.
#define BF_FGPIO_PTOR_PTTO(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_FGPIO_PTOR_PTTO), uint32_t) & BM_FGPIO_PTOR_PTTO)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PTTO field to a new value.
#define BW_FGPIO_PTOR_PTTO(x, v) (HW_FGPIO_PTOR_WR(x, (HW_FGPIO_PTOR_RD(x) & ~BM_FGPIO_PTOR_PTTO) | BF_FGPIO_PTOR_PTTO(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_FGPIO_PDIR - Port Data Input Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FGPIO_PDIR - Port Data Input Register (RO)
 *
 * Reset value: 0x00000000U
 */
typedef union _hw_fgpio_pdir
{
    uint32_t U;
    struct _hw_fgpio_pdir_bitfields
    {
        uint32_t PDI : 32;             //!< [31:0] Port Data Input
    } B;
} hw_fgpio_pdir_t;
#endif

/*!
 * @name Constants and macros for entire FGPIO_PDIR register
 */
//@{
#define HW_FGPIO_PDIR_ADDR(x)    (REGS_FGPIO_BASE(x) + 0x10U)

#ifndef __LANGUAGE_ASM__
#define HW_FGPIO_PDIR(x)         (*(__I hw_fgpio_pdir_t *) HW_FGPIO_PDIR_ADDR(x))
#define HW_FGPIO_PDIR_RD(x)      (HW_FGPIO_PDIR(x).U)
#endif
//@}

/*
 * Constants & macros for individual FGPIO_PDIR bitfields
 */

/*!
 * @name Register FGPIO_PDIR, field PDI[31:0] (RO)
 *
 * Reads 0 at the unimplemented pins for a particular device. Pins that are not
 * configured for a digital function read 0. If the Port Control and Interrupt
 * module is disabled, then the corresponding bit in PDIR does not update.
 *
 * Values:
 * - 0 - Pin logic level is logic 0, or is not configured for use by digital
 *     function.
 * - 1 - Pin logic level is logic 1.
 */
//@{
#define BP_FGPIO_PDIR_PDI    (0U)          //!< Bit position for FGPIO_PDIR_PDI.
#define BM_FGPIO_PDIR_PDI    (0xFFFFFFFFU) //!< Bit mask for FGPIO_PDIR_PDI.
#define BS_FGPIO_PDIR_PDI    (32U)         //!< Bit field size in bits for FGPIO_PDIR_PDI.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the FGPIO_PDIR_PDI field.
#define BR_FGPIO_PDIR_PDI(x) (HW_FGPIO_PDIR(x).B.PDI)
#endif
//@}

//-------------------------------------------------------------------------------------------
// HW_FGPIO_PDDR - Port Data Direction Register
//-------------------------------------------------------------------------------------------

#ifndef __LANGUAGE_ASM__
/*!
 * @brief HW_FGPIO_PDDR - Port Data Direction Register (RW)
 *
 * Reset value: 0x00000000U
 *
 * The PDDR configures the individual port pins for input or output.
 */
typedef union _hw_fgpio_pddr
{
    uint32_t U;
    struct _hw_fgpio_pddr_bitfields
    {
        uint32_t PDD : 32;             //!< [31:0] Port Data Direction
    } B;
} hw_fgpio_pddr_t;
#endif

/*!
 * @name Constants and macros for entire FGPIO_PDDR register
 */
//@{
#define HW_FGPIO_PDDR_ADDR(x)    (REGS_FGPIO_BASE(x) + 0x14U)

#ifndef __LANGUAGE_ASM__
#define HW_FGPIO_PDDR(x)         (*(__IO hw_fgpio_pddr_t *) HW_FGPIO_PDDR_ADDR(x))
#define HW_FGPIO_PDDR_RD(x)      (HW_FGPIO_PDDR(x).U)
#define HW_FGPIO_PDDR_WR(x, v)   (HW_FGPIO_PDDR(x).U = (v))
#define HW_FGPIO_PDDR_SET(x, v)  (HW_FGPIO_PDDR_WR(x, HW_FGPIO_PDDR_RD(x) |  (v)))
#define HW_FGPIO_PDDR_CLR(x, v)  (HW_FGPIO_PDDR_WR(x, HW_FGPIO_PDDR_RD(x) & ~(v)))
#define HW_FGPIO_PDDR_TOG(x, v)  (HW_FGPIO_PDDR_WR(x, HW_FGPIO_PDDR_RD(x) ^  (v)))
#endif
//@}

/*
 * Constants & macros for individual FGPIO_PDDR bitfields
 */

/*!
 * @name Register FGPIO_PDDR, field PDD[31:0] (RW)
 *
 * Configures individual port pins for input or output.
 *
 * Values:
 * - 0 - Pin is configured as general-purpose input, for the GPIO function.
 * - 1 - Pin is configured as general-purpose output, for the GPIO function.
 */
//@{
#define BP_FGPIO_PDDR_PDD    (0U)          //!< Bit position for FGPIO_PDDR_PDD.
#define BM_FGPIO_PDDR_PDD    (0xFFFFFFFFU) //!< Bit mask for FGPIO_PDDR_PDD.
#define BS_FGPIO_PDDR_PDD    (32U)         //!< Bit field size in bits for FGPIO_PDDR_PDD.

#ifndef __LANGUAGE_ASM__
//! @brief Read current value of the FGPIO_PDDR_PDD field.
#define BR_FGPIO_PDDR_PDD(x) (HW_FGPIO_PDDR(x).B.PDD)
#endif

//! @brief Format value for bitfield FGPIO_PDDR_PDD.
#define BF_FGPIO_PDDR_PDD(v) (__REG_VALUE_TYPE((__REG_VALUE_TYPE((v), uint32_t) << BP_FGPIO_PDDR_PDD), uint32_t) & BM_FGPIO_PDDR_PDD)

#ifndef __LANGUAGE_ASM__
//! @brief Set the PDD field to a new value.
#define BW_FGPIO_PDDR_PDD(x, v) (HW_FGPIO_PDDR_WR(x, (HW_FGPIO_PDDR_RD(x) & ~BM_FGPIO_PDDR_PDD) | BF_FGPIO_PDDR_PDD(v)))
#endif
//@}

//-------------------------------------------------------------------------------------------
// hw_fgpio_t - module struct
//-------------------------------------------------------------------------------------------
/*!
 * @brief All FGPIO module registers.
 */
#ifndef __LANGUAGE_ASM__
#pragma pack(1)
typedef struct _hw_fgpio
{
    __IO hw_fgpio_pdor_t PDOR;             //!< [0x0] Port Data Output Register
    __O hw_fgpio_psor_t PSOR;              //!< [0x4] Port Set Output Register
    __O hw_fgpio_pcor_t PCOR;              //!< [0x8] Port Clear Output Register
    __O hw_fgpio_ptor_t PTOR;              //!< [0xC] Port Toggle Output Register
    __I hw_fgpio_pdir_t PDIR;              //!< [0x10] Port Data Input Register
    __IO hw_fgpio_pddr_t PDDR;             //!< [0x14] Port Data Direction Register
} hw_fgpio_t;
#pragma pack()

//! @brief Macro to access all FGPIO registers.
//! @param x FGPIO instance number.
//! @return Reference (not a pointer) to the registers struct. To get a pointer to the struct,
//!     use the '&' operator, like <code>&HW_FGPIO(0)</code>.
#define HW_FGPIO(x)    (*(hw_fgpio_t *) REGS_FGPIO_BASE(x))
#endif

#endif // __HW_FGPIO_REGISTERS_H__
// v22/130726/0.9
// EOF
