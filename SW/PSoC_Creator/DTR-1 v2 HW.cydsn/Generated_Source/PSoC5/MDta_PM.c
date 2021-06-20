/*******************************************************************************
* File Name: MDta_PM.c
* Version 1.80
*
* Description:
*  This file contains the setup, control, and status commands to support 
*  the component operation in the low power mode. 
*
* Note:
*
********************************************************************************
* Copyright 2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "MDta.h"

/* Check for removal by optimization */
#if !defined(MDta_Sync_ctrl_reg__REMOVED)

static MDta_BACKUP_STRUCT  MDta_backup = {0u};

    
/*******************************************************************************
* Function Name: MDta_SaveConfig
********************************************************************************
*
* Summary:
*  Saves the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MDta_SaveConfig(void) 
{
    MDta_backup.controlState = MDta_Control;
}


/*******************************************************************************
* Function Name: MDta_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the control register value.
*
* Parameters:
*  None
*
* Return:
*  None
*
*
*******************************************************************************/
void MDta_RestoreConfig(void) 
{
     MDta_Control = MDta_backup.controlState;
}


/*******************************************************************************
* Function Name: MDta_Sleep
********************************************************************************
*
* Summary:
*  Prepares the component for entering the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MDta_Sleep(void) 
{
    MDta_SaveConfig();
}


/*******************************************************************************
* Function Name: MDta_Wakeup
********************************************************************************
*
* Summary:
*  Restores the component after waking up from the low power mode.
*
* Parameters:
*  None
*
* Return:
*  None
*
*******************************************************************************/
void MDta_Wakeup(void)  
{
    MDta_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
