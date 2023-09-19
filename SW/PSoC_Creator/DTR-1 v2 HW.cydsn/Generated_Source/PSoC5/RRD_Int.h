/*******************************************************************************
* File Name: RRD_Int.h
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
#if !defined(CY_ISR_RRD_Int_H)
#define CY_ISR_RRD_Int_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void RRD_Int_Start(void);
void RRD_Int_StartEx(cyisraddress address);
void RRD_Int_Stop(void);

CY_ISR_PROTO(RRD_Int_Interrupt);

void RRD_Int_SetVector(cyisraddress address);
cyisraddress RRD_Int_GetVector(void);

void RRD_Int_SetPriority(uint8 priority);
uint8 RRD_Int_GetPriority(void);

void RRD_Int_Enable(void);
uint8 RRD_Int_GetState(void);
void RRD_Int_Disable(void);

void RRD_Int_SetPending(void);
void RRD_Int_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the RRD_Int ISR. */
#define RRD_Int_INTC_VECTOR            ((reg32 *) RRD_Int__INTC_VECT)

/* Address of the RRD_Int ISR priority. */
#define RRD_Int_INTC_PRIOR             ((reg8 *) RRD_Int__INTC_PRIOR_REG)

/* Priority of the RRD_Int interrupt. */
#define RRD_Int_INTC_PRIOR_NUMBER      RRD_Int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable RRD_Int interrupt. */
#define RRD_Int_INTC_SET_EN            ((reg32 *) RRD_Int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the RRD_Int interrupt. */
#define RRD_Int_INTC_CLR_EN            ((reg32 *) RRD_Int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the RRD_Int interrupt state to pending. */
#define RRD_Int_INTC_SET_PD            ((reg32 *) RRD_Int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the RRD_Int interrupt. */
#define RRD_Int_INTC_CLR_PD            ((reg32 *) RRD_Int__INTC_CLR_PD_REG)


#endif /* CY_ISR_RRD_Int_H */


/* [] END OF FILE */
