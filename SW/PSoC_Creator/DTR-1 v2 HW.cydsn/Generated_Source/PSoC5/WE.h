/*******************************************************************************
* File Name: WE.h  
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

#if !defined(CY_PINS_WE_H) /* Pins WE_H */
#define CY_PINS_WE_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "WE_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 WE__PORT == 15 && ((WE__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    WE_Write(uint8 value);
void    WE_SetDriveMode(uint8 mode);
uint8   WE_ReadDataReg(void);
uint8   WE_Read(void);
void    WE_SetInterruptMode(uint16 position, uint16 mode);
uint8   WE_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the WE_SetDriveMode() function.
     *  @{
     */
        #define WE_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define WE_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define WE_DM_RES_UP          PIN_DM_RES_UP
        #define WE_DM_RES_DWN         PIN_DM_RES_DWN
        #define WE_DM_OD_LO           PIN_DM_OD_LO
        #define WE_DM_OD_HI           PIN_DM_OD_HI
        #define WE_DM_STRONG          PIN_DM_STRONG
        #define WE_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define WE_MASK               WE__MASK
#define WE_SHIFT              WE__SHIFT
#define WE_WIDTH              1u

/* Interrupt constants */
#if defined(WE__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in WE_SetInterruptMode() function.
     *  @{
     */
        #define WE_INTR_NONE      (uint16)(0x0000u)
        #define WE_INTR_RISING    (uint16)(0x0001u)
        #define WE_INTR_FALLING   (uint16)(0x0002u)
        #define WE_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define WE_INTR_MASK      (0x01u) 
#endif /* (WE__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define WE_PS                     (* (reg8 *) WE__PS)
/* Data Register */
#define WE_DR                     (* (reg8 *) WE__DR)
/* Port Number */
#define WE_PRT_NUM                (* (reg8 *) WE__PRT) 
/* Connect to Analog Globals */                                                  
#define WE_AG                     (* (reg8 *) WE__AG)                       
/* Analog MUX bux enable */
#define WE_AMUX                   (* (reg8 *) WE__AMUX) 
/* Bidirectional Enable */                                                        
#define WE_BIE                    (* (reg8 *) WE__BIE)
/* Bit-mask for Aliased Register Access */
#define WE_BIT_MASK               (* (reg8 *) WE__BIT_MASK)
/* Bypass Enable */
#define WE_BYP                    (* (reg8 *) WE__BYP)
/* Port wide control signals */                                                   
#define WE_CTL                    (* (reg8 *) WE__CTL)
/* Drive Modes */
#define WE_DM0                    (* (reg8 *) WE__DM0) 
#define WE_DM1                    (* (reg8 *) WE__DM1)
#define WE_DM2                    (* (reg8 *) WE__DM2) 
/* Input Buffer Disable Override */
#define WE_INP_DIS                (* (reg8 *) WE__INP_DIS)
/* LCD Common or Segment Drive */
#define WE_LCD_COM_SEG            (* (reg8 *) WE__LCD_COM_SEG)
/* Enable Segment LCD */
#define WE_LCD_EN                 (* (reg8 *) WE__LCD_EN)
/* Slew Rate Control */
#define WE_SLW                    (* (reg8 *) WE__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define WE_PRTDSI__CAPS_SEL       (* (reg8 *) WE__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define WE_PRTDSI__DBL_SYNC_IN    (* (reg8 *) WE__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define WE_PRTDSI__OE_SEL0        (* (reg8 *) WE__PRTDSI__OE_SEL0) 
#define WE_PRTDSI__OE_SEL1        (* (reg8 *) WE__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define WE_PRTDSI__OUT_SEL0       (* (reg8 *) WE__PRTDSI__OUT_SEL0) 
#define WE_PRTDSI__OUT_SEL1       (* (reg8 *) WE__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define WE_PRTDSI__SYNC_OUT       (* (reg8 *) WE__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(WE__SIO_CFG)
    #define WE_SIO_HYST_EN        (* (reg8 *) WE__SIO_HYST_EN)
    #define WE_SIO_REG_HIFREQ     (* (reg8 *) WE__SIO_REG_HIFREQ)
    #define WE_SIO_CFG            (* (reg8 *) WE__SIO_CFG)
    #define WE_SIO_DIFF           (* (reg8 *) WE__SIO_DIFF)
#endif /* (WE__SIO_CFG) */

/* Interrupt Registers */
#if defined(WE__INTSTAT)
    #define WE_INTSTAT            (* (reg8 *) WE__INTSTAT)
    #define WE_SNAP               (* (reg8 *) WE__SNAP)
    
	#define WE_0_INTTYPE_REG 		(* (reg8 *) WE__0__INTTYPE)
#endif /* (WE__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_WE_H */


/* [] END OF FILE */
