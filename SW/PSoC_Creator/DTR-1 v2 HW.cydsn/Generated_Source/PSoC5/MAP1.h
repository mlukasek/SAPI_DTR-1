/*******************************************************************************
* File Name: MAP1.h  
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

#if !defined(CY_PINS_MAP1_H) /* Pins MAP1_H */
#define CY_PINS_MAP1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MAP1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MAP1__PORT == 15 && ((MAP1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MAP1_Write(uint8 value);
void    MAP1_SetDriveMode(uint8 mode);
uint8   MAP1_ReadDataReg(void);
uint8   MAP1_Read(void);
void    MAP1_SetInterruptMode(uint16 position, uint16 mode);
uint8   MAP1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MAP1_SetDriveMode() function.
     *  @{
     */
        #define MAP1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MAP1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MAP1_DM_RES_UP          PIN_DM_RES_UP
        #define MAP1_DM_RES_DWN         PIN_DM_RES_DWN
        #define MAP1_DM_OD_LO           PIN_DM_OD_LO
        #define MAP1_DM_OD_HI           PIN_DM_OD_HI
        #define MAP1_DM_STRONG          PIN_DM_STRONG
        #define MAP1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MAP1_MASK               MAP1__MASK
#define MAP1_SHIFT              MAP1__SHIFT
#define MAP1_WIDTH              1u

/* Interrupt constants */
#if defined(MAP1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MAP1_SetInterruptMode() function.
     *  @{
     */
        #define MAP1_INTR_NONE      (uint16)(0x0000u)
        #define MAP1_INTR_RISING    (uint16)(0x0001u)
        #define MAP1_INTR_FALLING   (uint16)(0x0002u)
        #define MAP1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MAP1_INTR_MASK      (0x01u) 
#endif /* (MAP1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MAP1_PS                     (* (reg8 *) MAP1__PS)
/* Data Register */
#define MAP1_DR                     (* (reg8 *) MAP1__DR)
/* Port Number */
#define MAP1_PRT_NUM                (* (reg8 *) MAP1__PRT) 
/* Connect to Analog Globals */                                                  
#define MAP1_AG                     (* (reg8 *) MAP1__AG)                       
/* Analog MUX bux enable */
#define MAP1_AMUX                   (* (reg8 *) MAP1__AMUX) 
/* Bidirectional Enable */                                                        
#define MAP1_BIE                    (* (reg8 *) MAP1__BIE)
/* Bit-mask for Aliased Register Access */
#define MAP1_BIT_MASK               (* (reg8 *) MAP1__BIT_MASK)
/* Bypass Enable */
#define MAP1_BYP                    (* (reg8 *) MAP1__BYP)
/* Port wide control signals */                                                   
#define MAP1_CTL                    (* (reg8 *) MAP1__CTL)
/* Drive Modes */
#define MAP1_DM0                    (* (reg8 *) MAP1__DM0) 
#define MAP1_DM1                    (* (reg8 *) MAP1__DM1)
#define MAP1_DM2                    (* (reg8 *) MAP1__DM2) 
/* Input Buffer Disable Override */
#define MAP1_INP_DIS                (* (reg8 *) MAP1__INP_DIS)
/* LCD Common or Segment Drive */
#define MAP1_LCD_COM_SEG            (* (reg8 *) MAP1__LCD_COM_SEG)
/* Enable Segment LCD */
#define MAP1_LCD_EN                 (* (reg8 *) MAP1__LCD_EN)
/* Slew Rate Control */
#define MAP1_SLW                    (* (reg8 *) MAP1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MAP1_PRTDSI__CAPS_SEL       (* (reg8 *) MAP1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MAP1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MAP1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MAP1_PRTDSI__OE_SEL0        (* (reg8 *) MAP1__PRTDSI__OE_SEL0) 
#define MAP1_PRTDSI__OE_SEL1        (* (reg8 *) MAP1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MAP1_PRTDSI__OUT_SEL0       (* (reg8 *) MAP1__PRTDSI__OUT_SEL0) 
#define MAP1_PRTDSI__OUT_SEL1       (* (reg8 *) MAP1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MAP1_PRTDSI__SYNC_OUT       (* (reg8 *) MAP1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MAP1__SIO_CFG)
    #define MAP1_SIO_HYST_EN        (* (reg8 *) MAP1__SIO_HYST_EN)
    #define MAP1_SIO_REG_HIFREQ     (* (reg8 *) MAP1__SIO_REG_HIFREQ)
    #define MAP1_SIO_CFG            (* (reg8 *) MAP1__SIO_CFG)
    #define MAP1_SIO_DIFF           (* (reg8 *) MAP1__SIO_DIFF)
#endif /* (MAP1__SIO_CFG) */

/* Interrupt Registers */
#if defined(MAP1__INTSTAT)
    #define MAP1_INTSTAT            (* (reg8 *) MAP1__INTSTAT)
    #define MAP1_SNAP               (* (reg8 *) MAP1__SNAP)
    
	#define MAP1_0_INTTYPE_REG 		(* (reg8 *) MAP1__0__INTTYPE)
#endif /* (MAP1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MAP1_H */


/* [] END OF FILE */
