/*******************************************************************************
* File Name: AddrH.h  
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

#if !defined(CY_PINS_AddrH_ALIASES_H) /* Pins AddrH_ALIASES_H */
#define CY_PINS_AddrH_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define AddrH_0			(AddrH__0__PC)
#define AddrH_0_INTR	((uint16)((uint16)0x0001u << AddrH__0__SHIFT))

#define AddrH_1			(AddrH__1__PC)
#define AddrH_1_INTR	((uint16)((uint16)0x0001u << AddrH__1__SHIFT))

#define AddrH_2			(AddrH__2__PC)
#define AddrH_2_INTR	((uint16)((uint16)0x0001u << AddrH__2__SHIFT))

#define AddrH_3			(AddrH__3__PC)
#define AddrH_3_INTR	((uint16)((uint16)0x0001u << AddrH__3__SHIFT))

#define AddrH_4			(AddrH__4__PC)
#define AddrH_4_INTR	((uint16)((uint16)0x0001u << AddrH__4__SHIFT))

#define AddrH_5			(AddrH__5__PC)
#define AddrH_5_INTR	((uint16)((uint16)0x0001u << AddrH__5__SHIFT))

#define AddrH_6			(AddrH__6__PC)
#define AddrH_6_INTR	((uint16)((uint16)0x0001u << AddrH__6__SHIFT))

#define AddrH_7			(AddrH__7__PC)
#define AddrH_7_INTR	((uint16)((uint16)0x0001u << AddrH__7__SHIFT))

#define AddrH_INTR_ALL	 ((uint16)(AddrH_0_INTR| AddrH_1_INTR| AddrH_2_INTR| AddrH_3_INTR| AddrH_4_INTR| AddrH_5_INTR| AddrH_6_INTR| AddrH_7_INTR))

#endif /* End Pins AddrH_ALIASES_H */


/* [] END OF FILE */
