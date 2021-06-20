/*******************************************************************************
* File Name: CER.h  
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

#if !defined(CY_PINS_CER_H) /* Pins CER_H */
#define CY_PINS_CER_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "CER_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 CER__PORT == 15 && ((CER__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    CER_Write(uint8 value);
void    CER_SetDriveMode(uint8 mode);
uint8   CER_ReadDataReg(void);
uint8   CER_Read(void);
void    CER_SetInterruptMode(uint16 position, uint16 mode);
uint8   CER_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the CER_SetDriveMode() function.
     *  @{
     */
        #define CER_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define CER_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define CER_DM_RES_UP          PIN_DM_RES_UP
        #define CER_DM_RES_DWN         PIN_DM_RES_DWN
        #define CER_DM_OD_LO           PIN_DM_OD_LO
        #define CER_DM_OD_HI           PIN_DM_OD_HI
        #define CER_DM_STRONG          PIN_DM_STRONG
        #define CER_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define CER_MASK               CER__MASK
#define CER_SHIFT              CER__SHIFT
#define CER_WIDTH              1u

/* Interrupt constants */
#if defined(CER__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in CER_SetInterruptMode() function.
     *  @{
     */
        #define CER_INTR_NONE      (uint16)(0x0000u)
        #define CER_INTR_RISING    (uint16)(0x0001u)
        #define CER_INTR_FALLING   (uint16)(0x0002u)
        #define CER_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define CER_INTR_MASK      (0x01u) 
#endif /* (CER__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define CER_PS                     (* (reg8 *) CER__PS)
/* Data Register */
#define CER_DR                     (* (reg8 *) CER__DR)
/* Port Number */
#define CER_PRT_NUM                (* (reg8 *) CER__PRT) 
/* Connect to Analog Globals */                                                  
#define CER_AG                     (* (reg8 *) CER__AG)                       
/* Analog MUX bux enable */
#define CER_AMUX                   (* (reg8 *) CER__AMUX) 
/* Bidirectional Enable */                                                        
#define CER_BIE                    (* (reg8 *) CER__BIE)
/* Bit-mask for Aliased Register Access */
#define CER_BIT_MASK               (* (reg8 *) CER__BIT_MASK)
/* Bypass Enable */
#define CER_BYP                    (* (reg8 *) CER__BYP)
/* Port wide control signals */                                                   
#define CER_CTL                    (* (reg8 *) CER__CTL)
/* Drive Modes */
#define CER_DM0                    (* (reg8 *) CER__DM0) 
#define CER_DM1                    (* (reg8 *) CER__DM1)
#define CER_DM2                    (* (reg8 *) CER__DM2) 
/* Input Buffer Disable Override */
#define CER_INP_DIS                (* (reg8 *) CER__INP_DIS)
/* LCD Common or Segment Drive */
#define CER_LCD_COM_SEG            (* (reg8 *) CER__LCD_COM_SEG)
/* Enable Segment LCD */
#define CER_LCD_EN                 (* (reg8 *) CER__LCD_EN)
/* Slew Rate Control */
#define CER_SLW                    (* (reg8 *) CER__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define CER_PRTDSI__CAPS_SEL       (* (reg8 *) CER__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define CER_PRTDSI__DBL_SYNC_IN    (* (reg8 *) CER__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define CER_PRTDSI__OE_SEL0        (* (reg8 *) CER__PRTDSI__OE_SEL0) 
#define CER_PRTDSI__OE_SEL1        (* (reg8 *) CER__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define CER_PRTDSI__OUT_SEL0       (* (reg8 *) CER__PRTDSI__OUT_SEL0) 
#define CER_PRTDSI__OUT_SEL1       (* (reg8 *) CER__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define CER_PRTDSI__SYNC_OUT       (* (reg8 *) CER__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(CER__SIO_CFG)
    #define CER_SIO_HYST_EN        (* (reg8 *) CER__SIO_HYST_EN)
    #define CER_SIO_REG_HIFREQ     (* (reg8 *) CER__SIO_REG_HIFREQ)
    #define CER_SIO_CFG            (* (reg8 *) CER__SIO_CFG)
    #define CER_SIO_DIFF           (* (reg8 *) CER__SIO_DIFF)
#endif /* (CER__SIO_CFG) */

/* Interrupt Registers */
#if defined(CER__INTSTAT)
    #define CER_INTSTAT            (* (reg8 *) CER__INTSTAT)
    #define CER_SNAP               (* (reg8 *) CER__SNAP)
    
	#define CER_0_INTTYPE_REG 		(* (reg8 *) CER__0__INTTYPE)
#endif /* (CER__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_CER_H */


/* [] END OF FILE */
