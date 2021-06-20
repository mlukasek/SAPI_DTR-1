/*******************************************************************************
* File Name: MSEL.h  
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

#if !defined(CY_PINS_MSEL_H) /* Pins MSEL_H */
#define CY_PINS_MSEL_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MSEL_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MSEL__PORT == 15 && ((MSEL__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MSEL_Write(uint8 value);
void    MSEL_SetDriveMode(uint8 mode);
uint8   MSEL_ReadDataReg(void);
uint8   MSEL_Read(void);
void    MSEL_SetInterruptMode(uint16 position, uint16 mode);
uint8   MSEL_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MSEL_SetDriveMode() function.
     *  @{
     */
        #define MSEL_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MSEL_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MSEL_DM_RES_UP          PIN_DM_RES_UP
        #define MSEL_DM_RES_DWN         PIN_DM_RES_DWN
        #define MSEL_DM_OD_LO           PIN_DM_OD_LO
        #define MSEL_DM_OD_HI           PIN_DM_OD_HI
        #define MSEL_DM_STRONG          PIN_DM_STRONG
        #define MSEL_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MSEL_MASK               MSEL__MASK
#define MSEL_SHIFT              MSEL__SHIFT
#define MSEL_WIDTH              1u

/* Interrupt constants */
#if defined(MSEL__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MSEL_SetInterruptMode() function.
     *  @{
     */
        #define MSEL_INTR_NONE      (uint16)(0x0000u)
        #define MSEL_INTR_RISING    (uint16)(0x0001u)
        #define MSEL_INTR_FALLING   (uint16)(0x0002u)
        #define MSEL_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MSEL_INTR_MASK      (0x01u) 
#endif /* (MSEL__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MSEL_PS                     (* (reg8 *) MSEL__PS)
/* Data Register */
#define MSEL_DR                     (* (reg8 *) MSEL__DR)
/* Port Number */
#define MSEL_PRT_NUM                (* (reg8 *) MSEL__PRT) 
/* Connect to Analog Globals */                                                  
#define MSEL_AG                     (* (reg8 *) MSEL__AG)                       
/* Analog MUX bux enable */
#define MSEL_AMUX                   (* (reg8 *) MSEL__AMUX) 
/* Bidirectional Enable */                                                        
#define MSEL_BIE                    (* (reg8 *) MSEL__BIE)
/* Bit-mask for Aliased Register Access */
#define MSEL_BIT_MASK               (* (reg8 *) MSEL__BIT_MASK)
/* Bypass Enable */
#define MSEL_BYP                    (* (reg8 *) MSEL__BYP)
/* Port wide control signals */                                                   
#define MSEL_CTL                    (* (reg8 *) MSEL__CTL)
/* Drive Modes */
#define MSEL_DM0                    (* (reg8 *) MSEL__DM0) 
#define MSEL_DM1                    (* (reg8 *) MSEL__DM1)
#define MSEL_DM2                    (* (reg8 *) MSEL__DM2) 
/* Input Buffer Disable Override */
#define MSEL_INP_DIS                (* (reg8 *) MSEL__INP_DIS)
/* LCD Common or Segment Drive */
#define MSEL_LCD_COM_SEG            (* (reg8 *) MSEL__LCD_COM_SEG)
/* Enable Segment LCD */
#define MSEL_LCD_EN                 (* (reg8 *) MSEL__LCD_EN)
/* Slew Rate Control */
#define MSEL_SLW                    (* (reg8 *) MSEL__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MSEL_PRTDSI__CAPS_SEL       (* (reg8 *) MSEL__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MSEL_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MSEL__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MSEL_PRTDSI__OE_SEL0        (* (reg8 *) MSEL__PRTDSI__OE_SEL0) 
#define MSEL_PRTDSI__OE_SEL1        (* (reg8 *) MSEL__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MSEL_PRTDSI__OUT_SEL0       (* (reg8 *) MSEL__PRTDSI__OUT_SEL0) 
#define MSEL_PRTDSI__OUT_SEL1       (* (reg8 *) MSEL__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MSEL_PRTDSI__SYNC_OUT       (* (reg8 *) MSEL__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MSEL__SIO_CFG)
    #define MSEL_SIO_HYST_EN        (* (reg8 *) MSEL__SIO_HYST_EN)
    #define MSEL_SIO_REG_HIFREQ     (* (reg8 *) MSEL__SIO_REG_HIFREQ)
    #define MSEL_SIO_CFG            (* (reg8 *) MSEL__SIO_CFG)
    #define MSEL_SIO_DIFF           (* (reg8 *) MSEL__SIO_DIFF)
#endif /* (MSEL__SIO_CFG) */

/* Interrupt Registers */
#if defined(MSEL__INTSTAT)
    #define MSEL_INTSTAT            (* (reg8 *) MSEL__INTSTAT)
    #define MSEL_SNAP               (* (reg8 *) MSEL__SNAP)
    
	#define MSEL_0_INTTYPE_REG 		(* (reg8 *) MSEL__0__INTTYPE)
#endif /* (MSEL__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MSEL_H */


/* [] END OF FILE */
