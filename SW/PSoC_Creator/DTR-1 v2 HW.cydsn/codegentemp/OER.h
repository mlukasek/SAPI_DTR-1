/*******************************************************************************
* File Name: OER.h  
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

#if !defined(CY_PINS_OER_H) /* Pins OER_H */
#define CY_PINS_OER_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "OER_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 OER__PORT == 15 && ((OER__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    OER_Write(uint8 value);
void    OER_SetDriveMode(uint8 mode);
uint8   OER_ReadDataReg(void);
uint8   OER_Read(void);
void    OER_SetInterruptMode(uint16 position, uint16 mode);
uint8   OER_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the OER_SetDriveMode() function.
     *  @{
     */
        #define OER_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define OER_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define OER_DM_RES_UP          PIN_DM_RES_UP
        #define OER_DM_RES_DWN         PIN_DM_RES_DWN
        #define OER_DM_OD_LO           PIN_DM_OD_LO
        #define OER_DM_OD_HI           PIN_DM_OD_HI
        #define OER_DM_STRONG          PIN_DM_STRONG
        #define OER_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define OER_MASK               OER__MASK
#define OER_SHIFT              OER__SHIFT
#define OER_WIDTH              1u

/* Interrupt constants */
#if defined(OER__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in OER_SetInterruptMode() function.
     *  @{
     */
        #define OER_INTR_NONE      (uint16)(0x0000u)
        #define OER_INTR_RISING    (uint16)(0x0001u)
        #define OER_INTR_FALLING   (uint16)(0x0002u)
        #define OER_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define OER_INTR_MASK      (0x01u) 
#endif /* (OER__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define OER_PS                     (* (reg8 *) OER__PS)
/* Data Register */
#define OER_DR                     (* (reg8 *) OER__DR)
/* Port Number */
#define OER_PRT_NUM                (* (reg8 *) OER__PRT) 
/* Connect to Analog Globals */                                                  
#define OER_AG                     (* (reg8 *) OER__AG)                       
/* Analog MUX bux enable */
#define OER_AMUX                   (* (reg8 *) OER__AMUX) 
/* Bidirectional Enable */                                                        
#define OER_BIE                    (* (reg8 *) OER__BIE)
/* Bit-mask for Aliased Register Access */
#define OER_BIT_MASK               (* (reg8 *) OER__BIT_MASK)
/* Bypass Enable */
#define OER_BYP                    (* (reg8 *) OER__BYP)
/* Port wide control signals */                                                   
#define OER_CTL                    (* (reg8 *) OER__CTL)
/* Drive Modes */
#define OER_DM0                    (* (reg8 *) OER__DM0) 
#define OER_DM1                    (* (reg8 *) OER__DM1)
#define OER_DM2                    (* (reg8 *) OER__DM2) 
/* Input Buffer Disable Override */
#define OER_INP_DIS                (* (reg8 *) OER__INP_DIS)
/* LCD Common or Segment Drive */
#define OER_LCD_COM_SEG            (* (reg8 *) OER__LCD_COM_SEG)
/* Enable Segment LCD */
#define OER_LCD_EN                 (* (reg8 *) OER__LCD_EN)
/* Slew Rate Control */
#define OER_SLW                    (* (reg8 *) OER__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define OER_PRTDSI__CAPS_SEL       (* (reg8 *) OER__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define OER_PRTDSI__DBL_SYNC_IN    (* (reg8 *) OER__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define OER_PRTDSI__OE_SEL0        (* (reg8 *) OER__PRTDSI__OE_SEL0) 
#define OER_PRTDSI__OE_SEL1        (* (reg8 *) OER__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define OER_PRTDSI__OUT_SEL0       (* (reg8 *) OER__PRTDSI__OUT_SEL0) 
#define OER_PRTDSI__OUT_SEL1       (* (reg8 *) OER__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define OER_PRTDSI__SYNC_OUT       (* (reg8 *) OER__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(OER__SIO_CFG)
    #define OER_SIO_HYST_EN        (* (reg8 *) OER__SIO_HYST_EN)
    #define OER_SIO_REG_HIFREQ     (* (reg8 *) OER__SIO_REG_HIFREQ)
    #define OER_SIO_CFG            (* (reg8 *) OER__SIO_CFG)
    #define OER_SIO_DIFF           (* (reg8 *) OER__SIO_DIFF)
#endif /* (OER__SIO_CFG) */

/* Interrupt Registers */
#if defined(OER__INTSTAT)
    #define OER_INTSTAT            (* (reg8 *) OER__INTSTAT)
    #define OER_SNAP               (* (reg8 *) OER__SNAP)
    
	#define OER_0_INTTYPE_REG 		(* (reg8 *) OER__0__INTTYPE)
#endif /* (OER__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_OER_H */


/* [] END OF FILE */
