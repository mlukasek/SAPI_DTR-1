/*******************************************************************************
* File Name: RCM_Int.h
* Version 1.71
*
*  Description:
*   Provides the function definitions for the Interrupt Controller.
*
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/
#if !defined(CY_ISR_RCM_Int_H)
#define CY_ISR_RCM_Int_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void RCM_Int_Start(void);
void RCM_Int_StartEx(cyisraddress address);
void RCM_Int_Stop(void);

CY_ISR_PROTO(RCM_Int_Interrupt);

void RCM_Int_SetVector(cyisraddress address);
cyisraddress RCM_Int_GetVector(void);

void RCM_Int_SetPriority(uint8 priority);
uint8 RCM_Int_GetPriority(void);

void RCM_Int_Enable(void);
uint8 RCM_Int_GetState(void);
void RCM_Int_Disable(void);

void RCM_Int_SetPending(void);
void RCM_Int_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the RCM_Int ISR. */
#define RCM_Int_INTC_VECTOR            ((reg32 *) RCM_Int__INTC_VECT)

/* Address of the RCM_Int ISR priority. */
#define RCM_Int_INTC_PRIOR             ((reg8 *) RCM_Int__INTC_PRIOR_REG)

/* Priority of the RCM_Int interrupt. */
#define RCM_Int_INTC_PRIOR_NUMBER      RCM_Int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable RCM_Int interrupt. */
#define RCM_Int_INTC_SET_EN            ((reg32 *) RCM_Int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the RCM_Int interrupt. */
#define RCM_Int_INTC_CLR_EN            ((reg32 *) RCM_Int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the RCM_Int interrupt state to pending. */
#define RCM_Int_INTC_SET_PD            ((reg32 *) RCM_Int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the RCM_Int interrupt. */
#define RCM_Int_INTC_CLR_PD            ((reg32 *) RCM_Int__INTC_CLR_PD_REG)


#endif /* CY_ISR_RCM_Int_H */


/* [] END OF FILE */
