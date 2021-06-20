/*******************************************************************************
* File Name: Dta.h  
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

#if !defined(CY_PINS_Dta_ALIASES_H) /* Pins Dta_ALIASES_H */
#define CY_PINS_Dta_ALIASES_H

#include "cytypes.h"
#include "cyfitter.h"


/***************************************
*              Constants        
***************************************/
#define Dta_0			(Dta__0__PC)
#define Dta_0_INTR	((uint16)((uint16)0x0001u << Dta__0__SHIFT))

#define Dta_1			(Dta__1__PC)
#define Dta_1_INTR	((uint16)((uint16)0x0001u << Dta__1__SHIFT))

#define Dta_2			(Dta__2__PC)
#define Dta_2_INTR	((uint16)((uint16)0x0001u << Dta__2__SHIFT))

#define Dta_3			(Dta__3__PC)
#define Dta_3_INTR	((uint16)((uint16)0x0001u << Dta__3__SHIFT))

#define Dta_4			(Dta__4__PC)
#define Dta_4_INTR	((uint16)((uint16)0x0001u << Dta__4__SHIFT))

#define Dta_5			(Dta__5__PC)
#define Dta_5_INTR	((uint16)((uint16)0x0001u << Dta__5__SHIFT))

#define Dta_6			(Dta__6__PC)
#define Dta_6_INTR	((uint16)((uint16)0x0001u << Dta__6__SHIFT))

#define Dta_7			(Dta__7__PC)
#define Dta_7_INTR	((uint16)((uint16)0x0001u << Dta__7__SHIFT))

#define Dta_INTR_ALL	 ((uint16)(Dta_0_INTR| Dta_1_INTR| Dta_2_INTR| Dta_3_INTR| Dta_4_INTR| Dta_5_INTR| Dta_6_INTR| Dta_7_INTR))

#endif /* End Pins Dta_ALIASES_H */


/* [] END OF FILE */
