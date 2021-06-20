/*******************************************************************************
* File Name: RSU_PM.c
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

#include "RSU.h"

/* Check for removal by optimization */
#if !defined(RSU_Sync_ctrl_reg__REMOVED)

static RSU_BACKUP_STRUCT  RSU_backup = {0u};

    
/*******************************************************************************
* Function Name: RSU_SaveConfig
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
void RSU_SaveConfig(void) 
{
    RSU_backup.controlState = RSU_Control;
}


/*******************************************************************************
* Function Name: RSU_RestoreConfig
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
void RSU_RestoreConfig(void) 
{
     RSU_Control = RSU_backup.controlState;
}


/*******************************************************************************
* Function Name: RSU_Sleep
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
void RSU_Sleep(void) 
{
    RSU_SaveConfig();
}


/*******************************************************************************
* Function Name: RSU_Wakeup
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
void RSU_Wakeup(void)  
{
    RSU_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
