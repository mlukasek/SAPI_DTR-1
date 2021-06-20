/*******************************************************************************
* File Name: nWAIT.h  
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

#if !defined(CY_PINS_nWAIT_H) /* Pins nWAIT_H */
#define CY_PINS_nWAIT_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "nWAIT_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 nWAIT__PORT == 15 && ((nWAIT__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    nWAIT_Write(uint8 value);
void    nWAIT_SetDriveMode(uint8 mode);
uint8   nWAIT_ReadDataReg(void);
uint8   nWAIT_Read(void);
void    nWAIT_SetInterruptMode(uint16 position, uint16 mode);
uint8   nWAIT_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the nWAIT_SetDriveMode() function.
     *  @{
     */
        #define nWAIT_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define nWAIT_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define nWAIT_DM_RES_UP          PIN_DM_RES_UP
        #define nWAIT_DM_RES_DWN         PIN_DM_RES_DWN
        #define nWAIT_DM_OD_LO           PIN_DM_OD_LO
        #define nWAIT_DM_OD_HI           PIN_DM_OD_HI
        #define nWAIT_DM_STRONG          PIN_DM_STRONG
        #define nWAIT_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define nWAIT_MASK               nWAIT__MASK
#define nWAIT_SHIFT              nWAIT__SHIFT
#define nWAIT_WIDTH              1u

/* Interrupt constants */
#if defined(nWAIT__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in nWAIT_SetInterruptMode() function.
     *  @{
     */
        #define nWAIT_INTR_NONE      (uint16)(0x0000u)
        #define nWAIT_INTR_RISING    (uint16)(0x0001u)
        #define nWAIT_INTR_FALLING   (uint16)(0x0002u)
        #define nWAIT_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define nWAIT_INTR_MASK      (0x01u) 
#endif /* (nWAIT__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define nWAIT_PS                     (* (reg8 *) nWAIT__PS)
/* Data Register */
#define nWAIT_DR                     (* (reg8 *) nWAIT__DR)
/* Port Number */
#define nWAIT_PRT_NUM                (* (reg8 *) nWAIT__PRT) 
/* Connect to Analog Globals */                                                  
#define nWAIT_AG                     (* (reg8 *) nWAIT__AG)                       
/* Analog MUX bux enable */
#define nWAIT_AMUX                   (* (reg8 *) nWAIT__AMUX) 
/* Bidirectional Enable */                                                        
#define nWAIT_BIE                    (* (reg8 *) nWAIT__BIE)
/* Bit-mask for Aliased Register Access */
#define nWAIT_BIT_MASK               (* (reg8 *) nWAIT__BIT_MASK)
/* Bypass Enable */
#define nWAIT_BYP                    (* (reg8 *) nWAIT__BYP)
/* Port wide control signals */                                                   
#define nWAIT_CTL                    (* (reg8 *) nWAIT__CTL)
/* Drive Modes */
#define nWAIT_DM0                    (* (reg8 *) nWAIT__DM0) 
#define nWAIT_DM1                    (* (reg8 *) nWAIT__DM1)
#define nWAIT_DM2                    (* (reg8 *) nWAIT__DM2) 
/* Input Buffer Disable Override */
#define nWAIT_INP_DIS                (* (reg8 *) nWAIT__INP_DIS)
/* LCD Common or Segment Drive */
#define nWAIT_LCD_COM_SEG            (* (reg8 *) nWAIT__LCD_COM_SEG)
/* Enable Segment LCD */
#define nWAIT_LCD_EN                 (* (reg8 *) nWAIT__LCD_EN)
/* Slew Rate Control */
#define nWAIT_SLW                    (* (reg8 *) nWAIT__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define nWAIT_PRTDSI__CAPS_SEL       (* (reg8 *) nWAIT__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define nWAIT_PRTDSI__DBL_SYNC_IN    (* (reg8 *) nWAIT__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define nWAIT_PRTDSI__OE_SEL0        (* (reg8 *) nWAIT__PRTDSI__OE_SEL0) 
#define nWAIT_PRTDSI__OE_SEL1        (* (reg8 *) nWAIT__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define nWAIT_PRTDSI__OUT_SEL0       (* (reg8 *) nWAIT__PRTDSI__OUT_SEL0) 
#define nWAIT_PRTDSI__OUT_SEL1       (* (reg8 *) nWAIT__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define nWAIT_PRTDSI__SYNC_OUT       (* (reg8 *) nWAIT__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(nWAIT__SIO_CFG)
    #define nWAIT_SIO_HYST_EN        (* (reg8 *) nWAIT__SIO_HYST_EN)
    #define nWAIT_SIO_REG_HIFREQ     (* (reg8 *) nWAIT__SIO_REG_HIFREQ)
    #define nWAIT_SIO_CFG            (* (reg8 *) nWAIT__SIO_CFG)
    #define nWAIT_SIO_DIFF           (* (reg8 *) nWAIT__SIO_DIFF)
#endif /* (nWAIT__SIO_CFG) */

/* Interrupt Registers */
#if defined(nWAIT__INTSTAT)
    #define nWAIT_INTSTAT            (* (reg8 *) nWAIT__INTSTAT)
    #define nWAIT_SNAP               (* (reg8 *) nWAIT__SNAP)
    
	#define nWAIT_0_INTTYPE_REG 		(* (reg8 *) nWAIT__0__INTTYPE)
#endif /* (nWAIT__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_nWAIT_H */


/* [] END OF FILE */
