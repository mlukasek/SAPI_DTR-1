/*******************************************************************************
* File Name: Dta.h  
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

#if !defined(CY_PINS_Dta_H) /* Pins Dta_H */
#define CY_PINS_Dta_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Dta_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Dta__PORT == 15 && ((Dta__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Dta_Write(uint8 value);
void    Dta_SetDriveMode(uint8 mode);
uint8   Dta_ReadDataReg(void);
uint8   Dta_Read(void);
void    Dta_SetInterruptMode(uint16 position, uint16 mode);
uint8   Dta_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Dta_SetDriveMode() function.
     *  @{
     */
        #define Dta_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Dta_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Dta_DM_RES_UP          PIN_DM_RES_UP
        #define Dta_DM_RES_DWN         PIN_DM_RES_DWN
        #define Dta_DM_OD_LO           PIN_DM_OD_LO
        #define Dta_DM_OD_HI           PIN_DM_OD_HI
        #define Dta_DM_STRONG          PIN_DM_STRONG
        #define Dta_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Dta_MASK               Dta__MASK
#define Dta_SHIFT              Dta__SHIFT
#define Dta_WIDTH              8u

/* Interrupt constants */
#if defined(Dta__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Dta_SetInterruptMode() function.
     *  @{
     */
        #define Dta_INTR_NONE      (uint16)(0x0000u)
        #define Dta_INTR_RISING    (uint16)(0x0001u)
        #define Dta_INTR_FALLING   (uint16)(0x0002u)
        #define Dta_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Dta_INTR_MASK      (0x01u) 
#endif /* (Dta__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Dta_PS                     (* (reg8 *) Dta__PS)
/* Data Register */
#define Dta_DR                     (* (reg8 *) Dta__DR)
/* Port Number */
#define Dta_PRT_NUM                (* (reg8 *) Dta__PRT) 
/* Connect to Analog Globals */                                                  
#define Dta_AG                     (* (reg8 *) Dta__AG)                       
/* Analog MUX bux enable */
#define Dta_AMUX                   (* (reg8 *) Dta__AMUX) 
/* Bidirectional Enable */                                                        
#define Dta_BIE                    (* (reg8 *) Dta__BIE)
/* Bit-mask for Aliased Register Access */
#define Dta_BIT_MASK               (* (reg8 *) Dta__BIT_MASK)
/* Bypass Enable */
#define Dta_BYP                    (* (reg8 *) Dta__BYP)
/* Port wide control signals */                                                   
#define Dta_CTL                    (* (reg8 *) Dta__CTL)
/* Drive Modes */
#define Dta_DM0                    (* (reg8 *) Dta__DM0) 
#define Dta_DM1                    (* (reg8 *) Dta__DM1)
#define Dta_DM2                    (* (reg8 *) Dta__DM2) 
/* Input Buffer Disable Override */
#define Dta_INP_DIS                (* (reg8 *) Dta__INP_DIS)
/* LCD Common or Segment Drive */
#define Dta_LCD_COM_SEG            (* (reg8 *) Dta__LCD_COM_SEG)
/* Enable Segment LCD */
#define Dta_LCD_EN                 (* (reg8 *) Dta__LCD_EN)
/* Slew Rate Control */
#define Dta_SLW                    (* (reg8 *) Dta__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Dta_PRTDSI__CAPS_SEL       (* (reg8 *) Dta__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Dta_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Dta__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Dta_PRTDSI__OE_SEL0        (* (reg8 *) Dta__PRTDSI__OE_SEL0) 
#define Dta_PRTDSI__OE_SEL1        (* (reg8 *) Dta__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Dta_PRTDSI__OUT_SEL0       (* (reg8 *) Dta__PRTDSI__OUT_SEL0) 
#define Dta_PRTDSI__OUT_SEL1       (* (reg8 *) Dta__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Dta_PRTDSI__SYNC_OUT       (* (reg8 *) Dta__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Dta__SIO_CFG)
    #define Dta_SIO_HYST_EN        (* (reg8 *) Dta__SIO_HYST_EN)
    #define Dta_SIO_REG_HIFREQ     (* (reg8 *) Dta__SIO_REG_HIFREQ)
    #define Dta_SIO_CFG            (* (reg8 *) Dta__SIO_CFG)
    #define Dta_SIO_DIFF           (* (reg8 *) Dta__SIO_DIFF)
#endif /* (Dta__SIO_CFG) */

/* Interrupt Registers */
#if defined(Dta__INTSTAT)
    #define Dta_INTSTAT            (* (reg8 *) Dta__INTSTAT)
    #define Dta_SNAP               (* (reg8 *) Dta__SNAP)
    
	#define Dta_0_INTTYPE_REG 		(* (reg8 *) Dta__0__INTTYPE)
	#define Dta_1_INTTYPE_REG 		(* (reg8 *) Dta__1__INTTYPE)
	#define Dta_2_INTTYPE_REG 		(* (reg8 *) Dta__2__INTTYPE)
	#define Dta_3_INTTYPE_REG 		(* (reg8 *) Dta__3__INTTYPE)
	#define Dta_4_INTTYPE_REG 		(* (reg8 *) Dta__4__INTTYPE)
	#define Dta_5_INTTYPE_REG 		(* (reg8 *) Dta__5__INTTYPE)
	#define Dta_6_INTTYPE_REG 		(* (reg8 *) Dta__6__INTTYPE)
	#define Dta_7_INTTYPE_REG 		(* (reg8 *) Dta__7__INTTYPE)
#endif /* (Dta__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Dta_H */


/* [] END OF FILE */
