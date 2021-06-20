/*******************************************************************************
* File Name: A16.h  
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

#if !defined(CY_PINS_A16_H) /* Pins A16_H */
#define CY_PINS_A16_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "A16_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 A16__PORT == 15 && ((A16__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    A16_Write(uint8 value);
void    A16_SetDriveMode(uint8 mode);
uint8   A16_ReadDataReg(void);
uint8   A16_Read(void);
void    A16_SetInterruptMode(uint16 position, uint16 mode);
uint8   A16_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the A16_SetDriveMode() function.
     *  @{
     */
        #define A16_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define A16_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define A16_DM_RES_UP          PIN_DM_RES_UP
        #define A16_DM_RES_DWN         PIN_DM_RES_DWN
        #define A16_DM_OD_LO           PIN_DM_OD_LO
        #define A16_DM_OD_HI           PIN_DM_OD_HI
        #define A16_DM_STRONG          PIN_DM_STRONG
        #define A16_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define A16_MASK               A16__MASK
#define A16_SHIFT              A16__SHIFT
#define A16_WIDTH              1u

/* Interrupt constants */
#if defined(A16__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in A16_SetInterruptMode() function.
     *  @{
     */
        #define A16_INTR_NONE      (uint16)(0x0000u)
        #define A16_INTR_RISING    (uint16)(0x0001u)
        #define A16_INTR_FALLING   (uint16)(0x0002u)
        #define A16_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define A16_INTR_MASK      (0x01u) 
#endif /* (A16__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define A16_PS                     (* (reg8 *) A16__PS)
/* Data Register */
#define A16_DR                     (* (reg8 *) A16__DR)
/* Port Number */
#define A16_PRT_NUM                (* (reg8 *) A16__PRT) 
/* Connect to Analog Globals */                                                  
#define A16_AG                     (* (reg8 *) A16__AG)                       
/* Analog MUX bux enable */
#define A16_AMUX                   (* (reg8 *) A16__AMUX) 
/* Bidirectional Enable */                                                        
#define A16_BIE                    (* (reg8 *) A16__BIE)
/* Bit-mask for Aliased Register Access */
#define A16_BIT_MASK               (* (reg8 *) A16__BIT_MASK)
/* Bypass Enable */
#define A16_BYP                    (* (reg8 *) A16__BYP)
/* Port wide control signals */                                                   
#define A16_CTL                    (* (reg8 *) A16__CTL)
/* Drive Modes */
#define A16_DM0                    (* (reg8 *) A16__DM0) 
#define A16_DM1                    (* (reg8 *) A16__DM1)
#define A16_DM2                    (* (reg8 *) A16__DM2) 
/* Input Buffer Disable Override */
#define A16_INP_DIS                (* (reg8 *) A16__INP_DIS)
/* LCD Common or Segment Drive */
#define A16_LCD_COM_SEG            (* (reg8 *) A16__LCD_COM_SEG)
/* Enable Segment LCD */
#define A16_LCD_EN                 (* (reg8 *) A16__LCD_EN)
/* Slew Rate Control */
#define A16_SLW                    (* (reg8 *) A16__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define A16_PRTDSI__CAPS_SEL       (* (reg8 *) A16__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define A16_PRTDSI__DBL_SYNC_IN    (* (reg8 *) A16__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define A16_PRTDSI__OE_SEL0        (* (reg8 *) A16__PRTDSI__OE_SEL0) 
#define A16_PRTDSI__OE_SEL1        (* (reg8 *) A16__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define A16_PRTDSI__OUT_SEL0       (* (reg8 *) A16__PRTDSI__OUT_SEL0) 
#define A16_PRTDSI__OUT_SEL1       (* (reg8 *) A16__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define A16_PRTDSI__SYNC_OUT       (* (reg8 *) A16__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(A16__SIO_CFG)
    #define A16_SIO_HYST_EN        (* (reg8 *) A16__SIO_HYST_EN)
    #define A16_SIO_REG_HIFREQ     (* (reg8 *) A16__SIO_REG_HIFREQ)
    #define A16_SIO_CFG            (* (reg8 *) A16__SIO_CFG)
    #define A16_SIO_DIFF           (* (reg8 *) A16__SIO_DIFF)
#endif /* (A16__SIO_CFG) */

/* Interrupt Registers */
#if defined(A16__INTSTAT)
    #define A16_INTSTAT            (* (reg8 *) A16__INTSTAT)
    #define A16_SNAP               (* (reg8 *) A16__SNAP)
    
	#define A16_0_INTTYPE_REG 		(* (reg8 *) A16__0__INTTYPE)
#endif /* (A16__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_A16_H */


/* [] END OF FILE */
