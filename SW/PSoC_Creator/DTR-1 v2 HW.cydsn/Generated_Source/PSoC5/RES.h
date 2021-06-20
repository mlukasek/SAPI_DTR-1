/*******************************************************************************
* File Name: RES.h  
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

#if !defined(CY_PINS_RES_H) /* Pins RES_H */
#define CY_PINS_RES_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "RES_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 RES__PORT == 15 && ((RES__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    RES_Write(uint8 value);
void    RES_SetDriveMode(uint8 mode);
uint8   RES_ReadDataReg(void);
uint8   RES_Read(void);
void    RES_SetInterruptMode(uint16 position, uint16 mode);
uint8   RES_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the RES_SetDriveMode() function.
     *  @{
     */
        #define RES_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define RES_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define RES_DM_RES_UP          PIN_DM_RES_UP
        #define RES_DM_RES_DWN         PIN_DM_RES_DWN
        #define RES_DM_OD_LO           PIN_DM_OD_LO
        #define RES_DM_OD_HI           PIN_DM_OD_HI
        #define RES_DM_STRONG          PIN_DM_STRONG
        #define RES_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define RES_MASK               RES__MASK
#define RES_SHIFT              RES__SHIFT
#define RES_WIDTH              1u

/* Interrupt constants */
#if defined(RES__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in RES_SetInterruptMode() function.
     *  @{
     */
        #define RES_INTR_NONE      (uint16)(0x0000u)
        #define RES_INTR_RISING    (uint16)(0x0001u)
        #define RES_INTR_FALLING   (uint16)(0x0002u)
        #define RES_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define RES_INTR_MASK      (0x01u) 
#endif /* (RES__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define RES_PS                     (* (reg8 *) RES__PS)
/* Data Register */
#define RES_DR                     (* (reg8 *) RES__DR)
/* Port Number */
#define RES_PRT_NUM                (* (reg8 *) RES__PRT) 
/* Connect to Analog Globals */                                                  
#define RES_AG                     (* (reg8 *) RES__AG)                       
/* Analog MUX bux enable */
#define RES_AMUX                   (* (reg8 *) RES__AMUX) 
/* Bidirectional Enable */                                                        
#define RES_BIE                    (* (reg8 *) RES__BIE)
/* Bit-mask for Aliased Register Access */
#define RES_BIT_MASK               (* (reg8 *) RES__BIT_MASK)
/* Bypass Enable */
#define RES_BYP                    (* (reg8 *) RES__BYP)
/* Port wide control signals */                                                   
#define RES_CTL                    (* (reg8 *) RES__CTL)
/* Drive Modes */
#define RES_DM0                    (* (reg8 *) RES__DM0) 
#define RES_DM1                    (* (reg8 *) RES__DM1)
#define RES_DM2                    (* (reg8 *) RES__DM2) 
/* Input Buffer Disable Override */
#define RES_INP_DIS                (* (reg8 *) RES__INP_DIS)
/* LCD Common or Segment Drive */
#define RES_LCD_COM_SEG            (* (reg8 *) RES__LCD_COM_SEG)
/* Enable Segment LCD */
#define RES_LCD_EN                 (* (reg8 *) RES__LCD_EN)
/* Slew Rate Control */
#define RES_SLW                    (* (reg8 *) RES__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define RES_PRTDSI__CAPS_SEL       (* (reg8 *) RES__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define RES_PRTDSI__DBL_SYNC_IN    (* (reg8 *) RES__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define RES_PRTDSI__OE_SEL0        (* (reg8 *) RES__PRTDSI__OE_SEL0) 
#define RES_PRTDSI__OE_SEL1        (* (reg8 *) RES__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define RES_PRTDSI__OUT_SEL0       (* (reg8 *) RES__PRTDSI__OUT_SEL0) 
#define RES_PRTDSI__OUT_SEL1       (* (reg8 *) RES__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define RES_PRTDSI__SYNC_OUT       (* (reg8 *) RES__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(RES__SIO_CFG)
    #define RES_SIO_HYST_EN        (* (reg8 *) RES__SIO_HYST_EN)
    #define RES_SIO_REG_HIFREQ     (* (reg8 *) RES__SIO_REG_HIFREQ)
    #define RES_SIO_CFG            (* (reg8 *) RES__SIO_CFG)
    #define RES_SIO_DIFF           (* (reg8 *) RES__SIO_DIFF)
#endif /* (RES__SIO_CFG) */

/* Interrupt Registers */
#if defined(RES__INTSTAT)
    #define RES_INTSTAT            (* (reg8 *) RES__INTSTAT)
    #define RES_SNAP               (* (reg8 *) RES__SNAP)
    
	#define RES_0_INTTYPE_REG 		(* (reg8 *) RES__0__INTTYPE)
#endif /* (RES__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_RES_H */


/* [] END OF FILE */
