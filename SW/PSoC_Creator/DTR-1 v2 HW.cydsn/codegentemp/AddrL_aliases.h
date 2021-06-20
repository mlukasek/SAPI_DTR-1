/*******************************************************************************
* File Name: AddrL.h  
* Version 2.20
*
* Description:
*  This file contains the Alias definitions for Per-Pin APIs in cypins.h. 
*  Information on using these APIs can be found in the System Reference Guide.
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_AddrL_ALIASES_H) /* Pins AddrL_ALIASES_H */
#define CY_PINS_AddrL_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define AddrL_0			(AddrL__0__PC)
#define AddrL_0_INTR	((uint16)((uint16)0x0001u << AddrL__0__SHIFT))

#define AddrL_1			(AddrL__1__PC)
#define AddrL_1_INTR	((uint16)((uint16)0x0001u << AddrL__1__SHIFT))

#define AddrL_2			(AddrL__2__PC)
#define AddrL_2_INTR	((uint16)((uint16)0x0001u << AddrL__2__SHIFT))

#define AddrL_3			(AddrL__3__PC)
#define AddrL_3_INTR	((uint16)((uint16)0x0001u << AddrL__3__SHIFT))

#define AddrL_4			(AddrL__4__PC)
#define AddrL_4_INTR	((uint16)((uint16)0x0001u << AddrL__4__SHIFT))

#define AddrL_5			(AddrL__5__PC)
#define AddrL_5_INTR	((uint16)((uint16)0x0001u << AddrL__5__SHIFT))

#define AddrL_6			(AddrL__6__PC)
#define AddrL_6_INTR	((uint16)((uint16)0x0001u << AddrL__6__SHIFT))

#define AddrL_7			(AddrL__7__PC)
#define AddrL_7_INTR	((uint16)((uint16)0x0001u << AddrL__7__SHIFT))

#define AddrL_INTR_ALL	 ((uint16)(AddrL_0_INTR| AddrL_1_INTR| AddrL_2_INTR| AddrL_3_INTR| AddrL_4_INTR| AddrL_5_INTR| AddrL_6_INTR| AddrL_7_INTR))

#endif /* End Pins AddrL_ALIASES_H */


/* [] END OF FILE */
