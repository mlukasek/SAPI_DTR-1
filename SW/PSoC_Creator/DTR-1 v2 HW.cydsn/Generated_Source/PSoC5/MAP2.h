/*******************************************************************************
* File Name: MAP2.h  
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

#if !defined(CY_PINS_MAP2_H) /* Pins MAP2_H */
#define CY_PINS_MAP2_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MAP2_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MAP2__PORT == 15 && ((MAP2__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MAP2_Write(uint8 value);
void    MAP2_SetDriveMode(uint8 mode);
uint8   MAP2_ReadDataReg(void);
uint8   MAP2_Read(void);
void    MAP2_SetInterruptMode(uint16 position, uint16 mode);
uint8   MAP2_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MAP2_SetDriveMode() function.
     *  @{
     */
        #define MAP2_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MAP2_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MAP2_DM_RES_UP          PIN_DM_RES_UP
        #define MAP2_DM_RES_DWN         PIN_DM_RES_DWN
        #define MAP2_DM_OD_LO           PIN_DM_OD_LO
        #define MAP2_DM_OD_HI           PIN_DM_OD_HI
        #define MAP2_DM_STRONG          PIN_DM_STRONG
        #define MAP2_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MAP2_MASK               MAP2__MASK
#define MAP2_SHIFT              MAP2__SHIFT
#define MAP2_WIDTH              1u

/* Interrupt constants */
#if defined(MAP2__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MAP2_SetInterruptMode() function.
     *  @{
     */
        #define MAP2_INTR_NONE      (uint16)(0x0000u)
        #define MAP2_INTR_RISING    (uint16)(0x0001u)
        #define MAP2_INTR_FALLING   (uint16)(0x0002u)
        #define MAP2_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MAP2_INTR_MASK      (0x01u) 
#endif /* (MAP2__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MAP2_PS                     (* (reg8 *) MAP2__PS)
/* Data Register */
#define MAP2_DR                     (* (reg8 *) MAP2__DR)
/* Port Number */
#define MAP2_PRT_NUM                (* (reg8 *) MAP2__PRT) 
/* Connect to Analog Globals */                                                  
#define MAP2_AG                     (* (reg8 *) MAP2__AG)                       
/* Analog MUX bux enable */
#define MAP2_AMUX                   (* (reg8 *) MAP2__AMUX) 
/* Bidirectional Enable */                                                        
#define MAP2_BIE                    (* (reg8 *) MAP2__BIE)
/* Bit-mask for Aliased Register Access */
#define MAP2_BIT_MASK               (* (reg8 *) MAP2__BIT_MASK)
/* Bypass Enable */
#define MAP2_BYP                    (* (reg8 *) MAP2__BYP)
/* Port wide control signals */                                                   
#define MAP2_CTL                    (* (reg8 *) MAP2__CTL)
/* Drive Modes */
#define MAP2_DM0                    (* (reg8 *) MAP2__DM0) 
#define MAP2_DM1                    (* (reg8 *) MAP2__DM1)
#define MAP2_DM2                    (* (reg8 *) MAP2__DM2) 
/* Input Buffer Disable Override */
#define MAP2_INP_DIS                (* (reg8 *) MAP2__INP_DIS)
/* LCD Common or Segment Drive */
#define MAP2_LCD_COM_SEG            (* (reg8 *) MAP2__LCD_COM_SEG)
/* Enable Segment LCD */
#define MAP2_LCD_EN                 (* (reg8 *) MAP2__LCD_EN)
/* Slew Rate Control */
#define MAP2_SLW                    (* (reg8 *) MAP2__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MAP2_PRTDSI__CAPS_SEL       (* (reg8 *) MAP2__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MAP2_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MAP2__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MAP2_PRTDSI__OE_SEL0        (* (reg8 *) MAP2__PRTDSI__OE_SEL0) 
#define MAP2_PRTDSI__OE_SEL1        (* (reg8 *) MAP2__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MAP2_PRTDSI__OUT_SEL0       (* (reg8 *) MAP2__PRTDSI__OUT_SEL0) 
#define MAP2_PRTDSI__OUT_SEL1       (* (reg8 *) MAP2__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MAP2_PRTDSI__SYNC_OUT       (* (reg8 *) MAP2__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MAP2__SIO_CFG)
    #define MAP2_SIO_HYST_EN        (* (reg8 *) MAP2__SIO_HYST_EN)
    #define MAP2_SIO_REG_HIFREQ     (* (reg8 *) MAP2__SIO_REG_HIFREQ)
    #define MAP2_SIO_CFG            (* (reg8 *) MAP2__SIO_CFG)
    #define MAP2_SIO_DIFF           (* (reg8 *) MAP2__SIO_DIFF)
#endif /* (MAP2__SIO_CFG) */

/* Interrupt Registers */
#if defined(MAP2__INTSTAT)
    #define MAP2_INTSTAT            (* (reg8 *) MAP2__INTSTAT)
    #define MAP2_SNAP               (* (reg8 *) MAP2__SNAP)
    
	#define MAP2_0_INTTYPE_REG 		(* (reg8 *) MAP2__0__INTTYPE)
#endif /* (MAP2__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MAP2_H */


/* [] END OF FILE */
