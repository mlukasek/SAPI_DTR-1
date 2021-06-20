/*******************************************************************************
* File Name: BUSRQ.h  
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

#if !defined(CY_PINS_BUSRQ_H) /* Pins BUSRQ_H */
#define CY_PINS_BUSRQ_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BUSRQ_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BUSRQ__PORT == 15 && ((BUSRQ__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BUSRQ_Write(uint8 value);
void    BUSRQ_SetDriveMode(uint8 mode);
uint8   BUSRQ_ReadDataReg(void);
uint8   BUSRQ_Read(void);
void    BUSRQ_SetInterruptMode(uint16 position, uint16 mode);
uint8   BUSRQ_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BUSRQ_SetDriveMode() function.
     *  @{
     */
        #define BUSRQ_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BUSRQ_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BUSRQ_DM_RES_UP          PIN_DM_RES_UP
        #define BUSRQ_DM_RES_DWN         PIN_DM_RES_DWN
        #define BUSRQ_DM_OD_LO           PIN_DM_OD_LO
        #define BUSRQ_DM_OD_HI           PIN_DM_OD_HI
        #define BUSRQ_DM_STRONG          PIN_DM_STRONG
        #define BUSRQ_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BUSRQ_MASK               BUSRQ__MASK
#define BUSRQ_SHIFT              BUSRQ__SHIFT
#define BUSRQ_WIDTH              1u

/* Interrupt constants */
#if defined(BUSRQ__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BUSRQ_SetInterruptMode() function.
     *  @{
     */
        #define BUSRQ_INTR_NONE      (uint16)(0x0000u)
        #define BUSRQ_INTR_RISING    (uint16)(0x0001u)
        #define BUSRQ_INTR_FALLING   (uint16)(0x0002u)
        #define BUSRQ_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BUSRQ_INTR_MASK      (0x01u) 
#endif /* (BUSRQ__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BUSRQ_PS                     (* (reg8 *) BUSRQ__PS)
/* Data Register */
#define BUSRQ_DR                     (* (reg8 *) BUSRQ__DR)
/* Port Number */
#define BUSRQ_PRT_NUM                (* (reg8 *) BUSRQ__PRT) 
/* Connect to Analog Globals */                                                  
#define BUSRQ_AG                     (* (reg8 *) BUSRQ__AG)                       
/* Analog MUX bux enable */
#define BUSRQ_AMUX                   (* (reg8 *) BUSRQ__AMUX) 
/* Bidirectional Enable */                                                        
#define BUSRQ_BIE                    (* (reg8 *) BUSRQ__BIE)
/* Bit-mask for Aliased Register Access */
#define BUSRQ_BIT_MASK               (* (reg8 *) BUSRQ__BIT_MASK)
/* Bypass Enable */
#define BUSRQ_BYP                    (* (reg8 *) BUSRQ__BYP)
/* Port wide control signals */                                                   
#define BUSRQ_CTL                    (* (reg8 *) BUSRQ__CTL)
/* Drive Modes */
#define BUSRQ_DM0                    (* (reg8 *) BUSRQ__DM0) 
#define BUSRQ_DM1                    (* (reg8 *) BUSRQ__DM1)
#define BUSRQ_DM2                    (* (reg8 *) BUSRQ__DM2) 
/* Input Buffer Disable Override */
#define BUSRQ_INP_DIS                (* (reg8 *) BUSRQ__INP_DIS)
/* LCD Common or Segment Drive */
#define BUSRQ_LCD_COM_SEG            (* (reg8 *) BUSRQ__LCD_COM_SEG)
/* Enable Segment LCD */
#define BUSRQ_LCD_EN                 (* (reg8 *) BUSRQ__LCD_EN)
/* Slew Rate Control */
#define BUSRQ_SLW                    (* (reg8 *) BUSRQ__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BUSRQ_PRTDSI__CAPS_SEL       (* (reg8 *) BUSRQ__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BUSRQ_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BUSRQ__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BUSRQ_PRTDSI__OE_SEL0        (* (reg8 *) BUSRQ__PRTDSI__OE_SEL0) 
#define BUSRQ_PRTDSI__OE_SEL1        (* (reg8 *) BUSRQ__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BUSRQ_PRTDSI__OUT_SEL0       (* (reg8 *) BUSRQ__PRTDSI__OUT_SEL0) 
#define BUSRQ_PRTDSI__OUT_SEL1       (* (reg8 *) BUSRQ__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BUSRQ_PRTDSI__SYNC_OUT       (* (reg8 *) BUSRQ__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BUSRQ__SIO_CFG)
    #define BUSRQ_SIO_HYST_EN        (* (reg8 *) BUSRQ__SIO_HYST_EN)
    #define BUSRQ_SIO_REG_HIFREQ     (* (reg8 *) BUSRQ__SIO_REG_HIFREQ)
    #define BUSRQ_SIO_CFG            (* (reg8 *) BUSRQ__SIO_CFG)
    #define BUSRQ_SIO_DIFF           (* (reg8 *) BUSRQ__SIO_DIFF)
#endif /* (BUSRQ__SIO_CFG) */

/* Interrupt Registers */
#if defined(BUSRQ__INTSTAT)
    #define BUSRQ_INTSTAT            (* (reg8 *) BUSRQ__INTSTAT)
    #define BUSRQ_SNAP               (* (reg8 *) BUSRQ__SNAP)
    
	#define BUSRQ_0_INTTYPE_REG 		(* (reg8 *) BUSRQ__0__INTTYPE)
#endif /* (BUSRQ__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BUSRQ_H */


/* [] END OF FILE */
