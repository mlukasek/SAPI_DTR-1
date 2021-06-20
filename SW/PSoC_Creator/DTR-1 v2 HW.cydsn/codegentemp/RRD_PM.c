/*******************************************************************************
* File Name: RRD_PM.c
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

#include "RRD.h"

/* Check for removal by optimization */
#if !defined(RRD_Sync_ctrl_reg__REMOVED)

static RRD_BACKUP_STRUCT  RRD_backup = {0u};

    
/*******************************************************************************
* Function Name: RRD_SaveConfig
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
void RRD_SaveConfig(void) 
{
    RRD_backup.controlState = RRD_Control;
}


/*******************************************************************************
* Function Name: RRD_RestoreConfig
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
void RRD_RestoreConfig(void) 
{
     RRD_Control = RRD_backup.controlState;
}


/*******************************************************************************
* Function Name: RRD_Sleep
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
void RRD_Sleep(void) 
{
    RRD_SaveConfig();
}


/*******************************************************************************
* Function Name: RRD_Wakeup
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
void RRD_Wakeup(void)  
{
    RRD_RestoreConfig();
}

#endif /* End check for removal by optimization */


/* [] END OF FILE */
