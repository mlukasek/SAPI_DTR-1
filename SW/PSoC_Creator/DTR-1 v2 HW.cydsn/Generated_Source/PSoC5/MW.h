/*******************************************************************************
* File Name: MW.h  
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

#if !defined(CY_PINS_MW_H) /* Pins MW_H */
#define CY_PINS_MW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MW__PORT == 15 && ((MW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MW_Write(uint8 value);
void    MW_SetDriveMode(uint8 mode);
uint8   MW_ReadDataReg(void);
uint8   MW_Read(void);
void    MW_SetInterruptMode(uint16 position, uint16 mode);
uint8   MW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MW_SetDriveMode() function.
     *  @{
     */
        #define MW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MW_DM_RES_UP          PIN_DM_RES_UP
        #define MW_DM_RES_DWN         PIN_DM_RES_DWN
        #define MW_DM_OD_LO           PIN_DM_OD_LO
        #define MW_DM_OD_HI           PIN_DM_OD_HI
        #define MW_DM_STRONG          PIN_DM_STRONG
        #define MW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MW_MASK               MW__MASK
#define MW_SHIFT              MW__SHIFT
#define MW_WIDTH              1u

/* Interrupt constants */
#if defined(MW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MW_SetInterruptMode() function.
     *  @{
     */
        #define MW_INTR_NONE      (uint16)(0x0000u)
        #define MW_INTR_RISING    (uint16)(0x0001u)
        #define MW_INTR_FALLING   (uint16)(0x0002u)
        #define MW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MW_INTR_MASK      (0x01u) 
#endif /* (MW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MW_PS                     (* (reg8 *) MW__PS)
/* Data Register */
#define MW_DR                     (* (reg8 *) MW__DR)
/* Port Number */
#define MW_PRT_NUM                (* (reg8 *) MW__PRT) 
/* Connect to Analog Globals */                                                  
#define MW_AG                     (* (reg8 *) MW__AG)                       
/* Analog MUX bux enable */
#define MW_AMUX                   (* (reg8 *) MW__AMUX) 
/* Bidirectional Enable */                                                        
#define MW_BIE                    (* (reg8 *) MW__BIE)
/* Bit-mask for Aliased Register Access */
#define MW_BIT_MASK               (* (reg8 *) MW__BIT_MASK)
/* Bypass Enable */
#define MW_BYP                    (* (reg8 *) MW__BYP)
/* Port wide control signals */                                                   
#define MW_CTL                    (* (reg8 *) MW__CTL)
/* Drive Modes */
#define MW_DM0                    (* (reg8 *) MW__DM0) 
#define MW_DM1                    (* (reg8 *) MW__DM1)
#define MW_DM2                    (* (reg8 *) MW__DM2) 
/* Input Buffer Disable Override */
#define MW_INP_DIS                (* (reg8 *) MW__INP_DIS)
/* LCD Common or Segment Drive */
#define MW_LCD_COM_SEG            (* (reg8 *) MW__LCD_COM_SEG)
/* Enable Segment LCD */
#define MW_LCD_EN                 (* (reg8 *) MW__LCD_EN)
/* Slew Rate Control */
#define MW_SLW                    (* (reg8 *) MW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MW_PRTDSI__CAPS_SEL       (* (reg8 *) MW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MW_PRTDSI__OE_SEL0        (* (reg8 *) MW__PRTDSI__OE_SEL0) 
#define MW_PRTDSI__OE_SEL1        (* (reg8 *) MW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MW_PRTDSI__OUT_SEL0       (* (reg8 *) MW__PRTDSI__OUT_SEL0) 
#define MW_PRTDSI__OUT_SEL1       (* (reg8 *) MW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MW_PRTDSI__SYNC_OUT       (* (reg8 *) MW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MW__SIO_CFG)
    #define MW_SIO_HYST_EN        (* (reg8 *) MW__SIO_HYST_EN)
    #define MW_SIO_REG_HIFREQ     (* (reg8 *) MW__SIO_REG_HIFREQ)
    #define MW_SIO_CFG            (* (reg8 *) MW__SIO_CFG)
    #define MW_SIO_DIFF           (* (reg8 *) MW__SIO_DIFF)
#endif /* (MW__SIO_CFG) */

/* Interrupt Registers */
#if defined(MW__INTSTAT)
    #define MW_INTSTAT            (* (reg8 *) MW__INTSTAT)
    #define MW_SNAP               (* (reg8 *) MW__SNAP)
    
	#define MW_0_INTTYPE_REG 		(* (reg8 *) MW__0__INTTYPE)
#endif /* (MW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MW_H */


/* [] END OF FILE */
