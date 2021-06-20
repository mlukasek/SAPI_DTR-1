/*******************************************************************************
* File Name: IOW.h  
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

#if !defined(CY_PINS_IOW_H) /* Pins IOW_H */
#define CY_PINS_IOW_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IOW_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IOW__PORT == 15 && ((IOW__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IOW_Write(uint8 value);
void    IOW_SetDriveMode(uint8 mode);
uint8   IOW_ReadDataReg(void);
uint8   IOW_Read(void);
void    IOW_SetInterruptMode(uint16 position, uint16 mode);
uint8   IOW_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IOW_SetDriveMode() function.
     *  @{
     */
        #define IOW_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IOW_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IOW_DM_RES_UP          PIN_DM_RES_UP
        #define IOW_DM_RES_DWN         PIN_DM_RES_DWN
        #define IOW_DM_OD_LO           PIN_DM_OD_LO
        #define IOW_DM_OD_HI           PIN_DM_OD_HI
        #define IOW_DM_STRONG          PIN_DM_STRONG
        #define IOW_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IOW_MASK               IOW__MASK
#define IOW_SHIFT              IOW__SHIFT
#define IOW_WIDTH              1u

/* Interrupt constants */
#if defined(IOW__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IOW_SetInterruptMode() function.
     *  @{
     */
        #define IOW_INTR_NONE      (uint16)(0x0000u)
        #define IOW_INTR_RISING    (uint16)(0x0001u)
        #define IOW_INTR_FALLING   (uint16)(0x0002u)
        #define IOW_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IOW_INTR_MASK      (0x01u) 
#endif /* (IOW__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IOW_PS                     (* (reg8 *) IOW__PS)
/* Data Register */
#define IOW_DR                     (* (reg8 *) IOW__DR)
/* Port Number */
#define IOW_PRT_NUM                (* (reg8 *) IOW__PRT) 
/* Connect to Analog Globals */                                                  
#define IOW_AG                     (* (reg8 *) IOW__AG)                       
/* Analog MUX bux enable */
#define IOW_AMUX                   (* (reg8 *) IOW__AMUX) 
/* Bidirectional Enable */                                                        
#define IOW_BIE                    (* (reg8 *) IOW__BIE)
/* Bit-mask for Aliased Register Access */
#define IOW_BIT_MASK               (* (reg8 *) IOW__BIT_MASK)
/* Bypass Enable */
#define IOW_BYP                    (* (reg8 *) IOW__BYP)
/* Port wide control signals */                                                   
#define IOW_CTL                    (* (reg8 *) IOW__CTL)
/* Drive Modes */
#define IOW_DM0                    (* (reg8 *) IOW__DM0) 
#define IOW_DM1                    (* (reg8 *) IOW__DM1)
#define IOW_DM2                    (* (reg8 *) IOW__DM2) 
/* Input Buffer Disable Override */
#define IOW_INP_DIS                (* (reg8 *) IOW__INP_DIS)
/* LCD Common or Segment Drive */
#define IOW_LCD_COM_SEG            (* (reg8 *) IOW__LCD_COM_SEG)
/* Enable Segment LCD */
#define IOW_LCD_EN                 (* (reg8 *) IOW__LCD_EN)
/* Slew Rate Control */
#define IOW_SLW                    (* (reg8 *) IOW__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IOW_PRTDSI__CAPS_SEL       (* (reg8 *) IOW__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IOW_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IOW__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IOW_PRTDSI__OE_SEL0        (* (reg8 *) IOW__PRTDSI__OE_SEL0) 
#define IOW_PRTDSI__OE_SEL1        (* (reg8 *) IOW__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IOW_PRTDSI__OUT_SEL0       (* (reg8 *) IOW__PRTDSI__OUT_SEL0) 
#define IOW_PRTDSI__OUT_SEL1       (* (reg8 *) IOW__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IOW_PRTDSI__SYNC_OUT       (* (reg8 *) IOW__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IOW__SIO_CFG)
    #define IOW_SIO_HYST_EN        (* (reg8 *) IOW__SIO_HYST_EN)
    #define IOW_SIO_REG_HIFREQ     (* (reg8 *) IOW__SIO_REG_HIFREQ)
    #define IOW_SIO_CFG            (* (reg8 *) IOW__SIO_CFG)
    #define IOW_SIO_DIFF           (* (reg8 *) IOW__SIO_DIFF)
#endif /* (IOW__SIO_CFG) */

/* Interrupt Registers */
#if defined(IOW__INTSTAT)
    #define IOW_INTSTAT            (* (reg8 *) IOW__INTSTAT)
    #define IOW_SNAP               (* (reg8 *) IOW__SNAP)
    
	#define IOW_0_INTTYPE_REG 		(* (reg8 *) IOW__0__INTTYPE)
#endif /* (IOW__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IOW_H */


/* [] END OF FILE */
