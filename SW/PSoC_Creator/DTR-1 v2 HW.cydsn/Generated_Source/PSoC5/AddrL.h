/*******************************************************************************
* File Name: AddrL.h  
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

#if !defined(CY_PINS_AddrL_H) /* Pins AddrL_H */
#define CY_PINS_AddrL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "AddrL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 AddrL__PORT == 15 && ((AddrL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    AddrL_Write(uint8 value);
void    AddrL_SetDriveMode(uint8 mode);
uint8   AddrL_ReadDataReg(void);
uint8   AddrL_Read(void);
void    AddrL_SetInterruptMode(uint16 position, uint16 mode);
uint8   AddrL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the AddrL_SetDriveMode() function.
     *  @{
     */
        #define AddrL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define AddrL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define AddrL_DM_RES_UP          PIN_DM_RES_UP
        #define AddrL_DM_RES_DWN         PIN_DM_RES_DWN
        #define AddrL_DM_OD_LO           PIN_DM_OD_LO
        #define AddrL_DM_OD_HI           PIN_DM_OD_HI
        #define AddrL_DM_STRONG          PIN_DM_STRONG
        #define AddrL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define AddrL_MASK               AddrL__MASK
#define AddrL_SHIFT              AddrL__SHIFT
#define AddrL_WIDTH              8u

/* Interrupt constants */
#if defined(AddrL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in AddrL_SetInterruptMode() function.
     *  @{
     */
        #define AddrL_INTR_NONE      (uint16)(0x0000u)
        #define AddrL_INTR_RISING    (uint16)(0x0001u)
        #define AddrL_INTR_FALLING   (uint16)(0x0002u)
        #define AddrL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define AddrL_INTR_MASK      (0x01u) 
#endif /* (AddrL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define AddrL_PS                     (* (reg8 *) AddrL__PS)
/* Data Register */
#define AddrL_DR                     (* (reg8 *) AddrL__DR)
/* Port Number */
#define AddrL_PRT_NUM                (* (reg8 *) AddrL__PRT) 
/* Connect to Analog Globals */                                                  
#define AddrL_AG                     (* (reg8 *) AddrL__AG)                       
/* Analog MUX bux enable */
#define AddrL_AMUX                   (* (reg8 *) AddrL__AMUX) 
/* Bidirectional Enable */                                                        
#define AddrL_BIE                    (* (reg8 *) AddrL__BIE)
/* Bit-mask for Aliased Register Access */
#define AddrL_BIT_MASK               (* (reg8 *) AddrL__BIT_MASK)
/* Bypass Enable */
#define AddrL_BYP                    (* (reg8 *) AddrL__BYP)
/* Port wide control signals */                                                   
#define AddrL_CTL                    (* (reg8 *) AddrL__CTL)
/* Drive Modes */
#define AddrL_DM0                    (* (reg8 *) AddrL__DM0) 
#define AddrL_DM1                    (* (reg8 *) AddrL__DM1)
#define AddrL_DM2                    (* (reg8 *) AddrL__DM2) 
/* Input Buffer Disable Override */
#define AddrL_INP_DIS                (* (reg8 *) AddrL__INP_DIS)
/* LCD Common or Segment Drive */
#define AddrL_LCD_COM_SEG            (* (reg8 *) AddrL__LCD_COM_SEG)
/* Enable Segment LCD */
#define AddrL_LCD_EN                 (* (reg8 *) AddrL__LCD_EN)
/* Slew Rate Control */
#define AddrL_SLW                    (* (reg8 *) AddrL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define AddrL_PRTDSI__CAPS_SEL       (* (reg8 *) AddrL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define AddrL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) AddrL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define AddrL_PRTDSI__OE_SEL0        (* (reg8 *) AddrL__PRTDSI__OE_SEL0) 
#define AddrL_PRTDSI__OE_SEL1        (* (reg8 *) AddrL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define AddrL_PRTDSI__OUT_SEL0       (* (reg8 *) AddrL__PRTDSI__OUT_SEL0) 
#define AddrL_PRTDSI__OUT_SEL1       (* (reg8 *) AddrL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define AddrL_PRTDSI__SYNC_OUT       (* (reg8 *) AddrL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(AddrL__SIO_CFG)
    #define AddrL_SIO_HYST_EN        (* (reg8 *) AddrL__SIO_HYST_EN)
    #define AddrL_SIO_REG_HIFREQ     (* (reg8 *) AddrL__SIO_REG_HIFREQ)
    #define AddrL_SIO_CFG            (* (reg8 *) AddrL__SIO_CFG)
    #define AddrL_SIO_DIFF           (* (reg8 *) AddrL__SIO_DIFF)
#endif /* (AddrL__SIO_CFG) */

/* Interrupt Registers */
#if defined(AddrL__INTSTAT)
    #define AddrL_INTSTAT            (* (reg8 *) AddrL__INTSTAT)
    #define AddrL_SNAP               (* (reg8 *) AddrL__SNAP)
    
	#define AddrL_0_INTTYPE_REG 		(* (reg8 *) AddrL__0__INTTYPE)
	#define AddrL_1_INTTYPE_REG 		(* (reg8 *) AddrL__1__INTTYPE)
	#define AddrL_2_INTTYPE_REG 		(* (reg8 *) AddrL__2__INTTYPE)
	#define AddrL_3_INTTYPE_REG 		(* (reg8 *) AddrL__3__INTTYPE)
	#define AddrL_4_INTTYPE_REG 		(* (reg8 *) AddrL__4__INTTYPE)
	#define AddrL_5_INTTYPE_REG 		(* (reg8 *) AddrL__5__INTTYPE)
	#define AddrL_6_INTTYPE_REG 		(* (reg8 *) AddrL__6__INTTYPE)
	#define AddrL_7_INTTYPE_REG 		(* (reg8 *) AddrL__7__INTTYPE)
#endif /* (AddrL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_AddrL_H */


/* [] END OF FILE */
