/*******************************************************************************
* File Name: IOR.h  
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

#if !defined(CY_PINS_IOR_H) /* Pins IOR_H */
#define CY_PINS_IOR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "IOR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 IOR__PORT == 15 && ((IOR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    IOR_Write(uint8 value);
void    IOR_SetDriveMode(uint8 mode);
uint8   IOR_ReadDataReg(void);
uint8   IOR_Read(void);
void    IOR_SetInterruptMode(uint16 position, uint16 mode);
uint8   IOR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the IOR_SetDriveMode() function.
     *  @{
     */
        #define IOR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define IOR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define IOR_DM_RES_UP          PIN_DM_RES_UP
        #define IOR_DM_RES_DWN         PIN_DM_RES_DWN
        #define IOR_DM_OD_LO           PIN_DM_OD_LO
        #define IOR_DM_OD_HI           PIN_DM_OD_HI
        #define IOR_DM_STRONG          PIN_DM_STRONG
        #define IOR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define IOR_MASK               IOR__MASK
#define IOR_SHIFT              IOR__SHIFT
#define IOR_WIDTH              1u

/* Interrupt constants */
#if defined(IOR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in IOR_SetInterruptMode() function.
     *  @{
     */
        #define IOR_INTR_NONE      (uint16)(0x0000u)
        #define IOR_INTR_RISING    (uint16)(0x0001u)
        #define IOR_INTR_FALLING   (uint16)(0x0002u)
        #define IOR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define IOR_INTR_MASK      (0x01u) 
#endif /* (IOR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define IOR_PS                     (* (reg8 *) IOR__PS)
/* Data Register */
#define IOR_DR                     (* (reg8 *) IOR__DR)
/* Port Number */
#define IOR_PRT_NUM                (* (reg8 *) IOR__PRT) 
/* Connect to Analog Globals */                                                  
#define IOR_AG                     (* (reg8 *) IOR__AG)                       
/* Analog MUX bux enable */
#define IOR_AMUX                   (* (reg8 *) IOR__AMUX) 
/* Bidirectional Enable */                                                        
#define IOR_BIE                    (* (reg8 *) IOR__BIE)
/* Bit-mask for Aliased Register Access */
#define IOR_BIT_MASK               (* (reg8 *) IOR__BIT_MASK)
/* Bypass Enable */
#define IOR_BYP                    (* (reg8 *) IOR__BYP)
/* Port wide control signals */                                                   
#define IOR_CTL                    (* (reg8 *) IOR__CTL)
/* Drive Modes */
#define IOR_DM0                    (* (reg8 *) IOR__DM0) 
#define IOR_DM1                    (* (reg8 *) IOR__DM1)
#define IOR_DM2                    (* (reg8 *) IOR__DM2) 
/* Input Buffer Disable Override */
#define IOR_INP_DIS                (* (reg8 *) IOR__INP_DIS)
/* LCD Common or Segment Drive */
#define IOR_LCD_COM_SEG            (* (reg8 *) IOR__LCD_COM_SEG)
/* Enable Segment LCD */
#define IOR_LCD_EN                 (* (reg8 *) IOR__LCD_EN)
/* Slew Rate Control */
#define IOR_SLW                    (* (reg8 *) IOR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define IOR_PRTDSI__CAPS_SEL       (* (reg8 *) IOR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define IOR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) IOR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define IOR_PRTDSI__OE_SEL0        (* (reg8 *) IOR__PRTDSI__OE_SEL0) 
#define IOR_PRTDSI__OE_SEL1        (* (reg8 *) IOR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define IOR_PRTDSI__OUT_SEL0       (* (reg8 *) IOR__PRTDSI__OUT_SEL0) 
#define IOR_PRTDSI__OUT_SEL1       (* (reg8 *) IOR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define IOR_PRTDSI__SYNC_OUT       (* (reg8 *) IOR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(IOR__SIO_CFG)
    #define IOR_SIO_HYST_EN        (* (reg8 *) IOR__SIO_HYST_EN)
    #define IOR_SIO_REG_HIFREQ     (* (reg8 *) IOR__SIO_REG_HIFREQ)
    #define IOR_SIO_CFG            (* (reg8 *) IOR__SIO_CFG)
    #define IOR_SIO_DIFF           (* (reg8 *) IOR__SIO_DIFF)
#endif /* (IOR__SIO_CFG) */

/* Interrupt Registers */
#if defined(IOR__INTSTAT)
    #define IOR_INTSTAT            (* (reg8 *) IOR__INTSTAT)
    #define IOR_SNAP               (* (reg8 *) IOR__SNAP)
    
	#define IOR_0_INTTYPE_REG 		(* (reg8 *) IOR__0__INTTYPE)
#endif /* (IOR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_IOR_H */


/* [] END OF FILE */
