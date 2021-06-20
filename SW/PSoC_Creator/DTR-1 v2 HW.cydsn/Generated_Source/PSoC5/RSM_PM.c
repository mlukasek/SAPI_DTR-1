/*******************************************************************************
* File Name: RSM_PM.c
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

#include "RSM.h"

/* Check for removal by optimization */
#if !defined(RSM_Sync_ctrl_reg__REMOVED)

static RSM_BACKUP_STRUCT  RSM_backup = {0u};

    
/*******************************************************************************
* Function Name: RSM_SaveConfig
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
void RSM_SaveConfig(void) 
{
    RSM_backup.controlState = RSM_Control;
}


/*******************************************************************************
* Function Name: RSM_RestoreConfig
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
void RSM_RestoreConfig(void) 
{
     RSM_Control = RSM_backup.controlState;
}


/*******************************************************************************
* Function Name: RSM_Sleep
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
void RSM_Sleep(void) 
{
    RSM_SaveConfig();
}


/*******************************************************************************
* Function Name: RSM_Wakeup
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
void RSM_Wakeup(void)  
{
    RSM_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
