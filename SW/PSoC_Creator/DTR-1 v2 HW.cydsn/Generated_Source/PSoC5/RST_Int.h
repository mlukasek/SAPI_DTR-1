/*******************************************************************************
* File Name: RST_Int.h
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
#if !defined(CY_ISR_RST_Int_H)
#define CY_ISR_RST_Int_H


#include <cytypes.h>
#include <cyfitter.h>

/* Interrupt Controller API. */
void RST_Int_Start(void);
void RST_Int_StartEx(cyisraddress address);
void RST_Int_Stop(void);

CY_ISR_PROTO(RST_Int_Interrupt);

void RST_Int_SetVector(cyisraddress address);
cyisraddress RST_Int_GetVector(void);

void RST_Int_SetPriority(uint8 priority);
uint8 RST_Int_GetPriority(void);

void RST_Int_Enable(void);
uint8 RST_Int_GetState(void);
void RST_Int_Disable(void);

void RST_Int_SetPending(void);
void RST_Int_ClearPending(void);


/* Interrupt Controller Constants */

/* Address of the INTC.VECT[x] register that contains the Address of the RST_Int ISR. */
#define RST_Int_INTC_VECTOR            ((reg32 *) RST_Int__INTC_VECT)

/* Address of the RST_Int ISR priority. */
#define RST_Int_INTC_PRIOR             ((reg8 *) RST_Int__INTC_PRIOR_REG)

/* Priority of the RST_Int interrupt. */
#define RST_Int_INTC_PRIOR_NUMBER      RST_Int__INTC_PRIOR_NUM

/* Address of the INTC.SET_EN[x] byte to bit enable RST_Int interrupt. */
#define RST_Int_INTC_SET_EN            ((reg32 *) RST_Int__INTC_SET_EN_REG)

/* Address of the INTC.CLR_EN[x] register to bit clear the RST_Int interrupt. */
#define RST_Int_INTC_CLR_EN            ((reg32 *) RST_Int__INTC_CLR_EN_REG)

/* Address of the INTC.SET_PD[x] register to set the RST_Int interrupt state to pending. */
#define RST_Int_INTC_SET_PD            ((reg32 *) RST_Int__INTC_SET_PD_REG)

/* Address of the INTC.CLR_PD[x] register to clear the RST_Int interrupt. */
#define RST_Int_INTC_CLR_PD            ((reg32 *) RST_Int__INTC_CLR_PD_REG)


#endif /* CY_ISR_RST_Int_H */


/* [] END OF FILE */
