/*******************************************************************************
* File Name: RTL.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_RTL_H) /* Pins RTL_H */
#define CY_PINS_RTL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RTL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RTL__PORT == 15 && ((RTL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RTL_Write(uint8 value);
void    RTL_SetDriveMode(uint8 mode);
uint8   RTL_ReadDataReg(void);
uint8   RTL_Read(void);
void    RTL_SetInterruptMode(uint16 position, uint16 mode);
uint8   RTL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RTL_SetDriveMode() function.
     *  @{
     */
        #define RTL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RTL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RTL_DM_RES_UP          PIN_DM_RES_UP
        #define RTL_DM_RES_DWN         PIN_DM_RES_DWN
        #define RTL_DM_OD_LO           PIN_DM_OD_LO
        #define RTL_DM_OD_HI           PIN_DM_OD_HI
        #define RTL_DM_STRONG          PIN_DM_STRONG
        #define RTL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RTL_MASK               RTL__MASK
#define RTL_SHIFT              RTL__SHIFT
#define RTL_WIDTH              1u

/* Interrupt constants */
#if defined(RTL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RTL_SetInterruptMode() function.
     *  @{
     */
        #define RTL_INTR_NONE      (uint16)(0x0000u)
        #define RTL_INTR_RISING    (uint16)(0x0001u)
        #define RTL_INTR_FALLING   (uint16)(0x0002u)
        #define RTL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RTL_INTR_MASK      (0x01u) 
#endif /* (RTL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RTL_PS                     (* (reg8 *) RTL__PS)
/* Data Register */
#define RTL_DR                     (* (reg8 *) RTL__DR)
/* Port Number */
#define RTL_PRT_NUM                (* (reg8 *) RTL__PRT) 
/* Connect to Analog Globals */                                                  
#define RTL_AG                     (* (reg8 *) RTL__AG)                       
/* Analog MUX bux enable */
#define RTL_AMUX                   (* (reg8 *) RTL__AMUX) 
/* Bidirectional Enable */                                                        
#define RTL_BIE                    (* (reg8 *) RTL__BIE)
/* Bit-mask for Aliased Register Access */
#define RTL_BIT_MASK               (* (reg8 *) RTL__BIT_MASK)
/* Bypass Enable */
#define RTL_BYP                    (* (reg8 *) RTL__BYP)
/* Port wide control signals */                                                   
#define RTL_CTL                    (* (reg8 *) RTL__CTL)
/* Drive Modes */
#define RTL_DM0                    (* (reg8 *) RTL__DM0) 
#define RTL_DM1                    (* (reg8 *) RTL__DM1)
#define RTL_DM2                    (* (reg8 *) RTL__DM2) 
/* Input Buffer Disable Override */
#define RTL_INP_DIS                (* (reg8 *) RTL__INP_DIS)
/* LCD Common or Segment Drive */
#define RTL_LCD_COM_SEG            (* (reg8 *) RTL__LCD_COM_SEG)
/* Enable Segment LCD */
#define RTL_LCD_EN                 (* (reg8 *) RTL__LCD_EN)
/* Slew Rate Control */
#define RTL_SLW                    (* (reg8 *) RTL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RTL_PRTDSI__CAPS_SEL       (* (reg8 *) RTL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RTL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RTL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RTL_PRTDSI__OE_SEL0        (* (reg8 *) RTL__PRTDSI__OE_SEL0) 
#define RTL_PRTDSI__OE_SEL1        (* (reg8 *) RTL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RTL_PRTDSI__OUT_SEL0       (* (reg8 *) RTL__PRTDSI__OUT_SEL0) 
#define RTL_PRTDSI__OUT_SEL1       (* (reg8 *) RTL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RTL_PRTDSI__SYNC_OUT       (* (reg8 *) RTL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RTL__SIO_CFG)
    #define RTL_SIO_HYST_EN        (* (reg8 *) RTL__SIO_HYST_EN)
    #define RTL_SIO_REG_HIFREQ     (* (reg8 *) RTL__SIO_REG_HIFREQ)
    #define RTL_SIO_CFG            (* (reg8 *) RTL__SIO_CFG)
    #define RTL_SIO_DIFF           (* (reg8 *) RTL__SIO_DIFF)
#endif /* (RTL__SIO_CFG) */

/* Interrupt Registers */
#if defined(RTL__INTSTAT)
    #define RTL_INTSTAT            (* (reg8 *) RTL__INTSTAT)
    #define RTL_SNAP               (* (reg8 *) RTL__SNAP)
    
	#define RTL_0_INTTYPE_REG 		(* (reg8 *) RTL__0__INTTYPE)
#endif /* (RTL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RTL_H */


/* [] END OF FILE */
