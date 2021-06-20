/*******************************************************************************
* File Name: BUSAK.h  
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

#if !defined(CY_PINS_BUSAK_H) /* Pins BUSAK_H */
#define CY_PINS_BUSAK_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "BUSAK_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 BUSAK__PORT == 15 && ((BUSAK__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    BUSAK_Write(uint8 value);
void    BUSAK_SetDriveMode(uint8 mode);
uint8   BUSAK_ReadDataReg(void);
uint8   BUSAK_Read(void);
void    BUSAK_SetInterruptMode(uint16 position, uint16 mode);
uint8   BUSAK_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the BUSAK_SetDriveMode() function.
     *  @{
     */
        #define BUSAK_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define BUSAK_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define BUSAK_DM_RES_UP          PIN_DM_RES_UP
        #define BUSAK_DM_RES_DWN         PIN_DM_RES_DWN
        #define BUSAK_DM_OD_LO           PIN_DM_OD_LO
        #define BUSAK_DM_OD_HI           PIN_DM_OD_HI
        #define BUSAK_DM_STRONG          PIN_DM_STRONG
        #define BUSAK_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define BUSAK_MASK               BUSAK__MASK
#define BUSAK_SHIFT              BUSAK__SHIFT
#define BUSAK_WIDTH              1u

/* Interrupt constants */
#if defined(BUSAK__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in BUSAK_SetInterruptMode() function.
     *  @{
     */
        #define BUSAK_INTR_NONE      (uint16)(0x0000u)
        #define BUSAK_INTR_RISING    (uint16)(0x0001u)
        #define BUSAK_INTR_FALLING   (uint16)(0x0002u)
        #define BUSAK_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define BUSAK_INTR_MASK      (0x01u) 
#endif /* (BUSAK__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define BUSAK_PS                     (* (reg8 *) BUSAK__PS)
/* Data Register */
#define BUSAK_DR                     (* (reg8 *) BUSAK__DR)
/* Port Number */
#define BUSAK_PRT_NUM                (* (reg8 *) BUSAK__PRT) 
/* Connect to Analog Globals */                                                  
#define BUSAK_AG                     (* (reg8 *) BUSAK__AG)                       
/* Analog MUX bux enable */
#define BUSAK_AMUX                   (* (reg8 *) BUSAK__AMUX) 
/* Bidirectional Enable */                                                        
#define BUSAK_BIE                    (* (reg8 *) BUSAK__BIE)
/* Bit-mask for Aliased Register Access */
#define BUSAK_BIT_MASK               (* (reg8 *) BUSAK__BIT_MASK)
/* Bypass Enable */
#define BUSAK_BYP                    (* (reg8 *) BUSAK__BYP)
/* Port wide control signals */                                                   
#define BUSAK_CTL                    (* (reg8 *) BUSAK__CTL)
/* Drive Modes */
#define BUSAK_DM0                    (* (reg8 *) BUSAK__DM0) 
#define BUSAK_DM1                    (* (reg8 *) BUSAK__DM1)
#define BUSAK_DM2                    (* (reg8 *) BUSAK__DM2) 
/* Input Buffer Disable Override */
#define BUSAK_INP_DIS                (* (reg8 *) BUSAK__INP_DIS)
/* LCD Common or Segment Drive */
#define BUSAK_LCD_COM_SEG            (* (reg8 *) BUSAK__LCD_COM_SEG)
/* Enable Segment LCD */
#define BUSAK_LCD_EN                 (* (reg8 *) BUSAK__LCD_EN)
/* Slew Rate Control */
#define BUSAK_SLW                    (* (reg8 *) BUSAK__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define BUSAK_PRTDSI__CAPS_SEL       (* (reg8 *) BUSAK__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define BUSAK_PRTDSI__DBL_SYNC_IN    (* (reg8 *) BUSAK__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define BUSAK_PRTDSI__OE_SEL0        (* (reg8 *) BUSAK__PRTDSI__OE_SEL0) 
#define BUSAK_PRTDSI__OE_SEL1        (* (reg8 *) BUSAK__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define BUSAK_PRTDSI__OUT_SEL0       (* (reg8 *) BUSAK__PRTDSI__OUT_SEL0) 
#define BUSAK_PRTDSI__OUT_SEL1       (* (reg8 *) BUSAK__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define BUSAK_PRTDSI__SYNC_OUT       (* (reg8 *) BUSAK__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(BUSAK__SIO_CFG)
    #define BUSAK_SIO_HYST_EN        (* (reg8 *) BUSAK__SIO_HYST_EN)
    #define BUSAK_SIO_REG_HIFREQ     (* (reg8 *) BUSAK__SIO_REG_HIFREQ)
    #define BUSAK_SIO_CFG            (* (reg8 *) BUSAK__SIO_CFG)
    #define BUSAK_SIO_DIFF           (* (reg8 *) BUSAK__SIO_DIFF)
#endif /* (BUSAK__SIO_CFG) */

/* Interrupt Registers */
#if defined(BUSAK__INTSTAT)
    #define BUSAK_INTSTAT            (* (reg8 *) BUSAK__INTSTAT)
    #define BUSAK_SNAP               (* (reg8 *) BUSAK__SNAP)
    
	#define BUSAK_0_INTTYPE_REG 		(* (reg8 *) BUSAK__0__INTTYPE)
#endif /* (BUSAK__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_BUSAK_H */


/* [] END OF FILE */
