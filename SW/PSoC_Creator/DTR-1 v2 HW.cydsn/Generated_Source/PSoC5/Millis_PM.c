/*******************************************************************************
* File Name: Millis_PM.c  
* Version 3.0
*
*  Description:
*    This file provides the power management source code to API for the
*    Counter.  
*
*   Note:
*     None
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#include "Millis.h"

static Millis_backupStruct Millis_backup;


/*******************************************************************************
* Function Name: Millis_SaveConfig
********************************************************************************
* Summary:
*     Save the current user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Millis_backup:  Variables of this global structure are modified to 
*  store the values of non retention configuration registers when Sleep() API is 
*  called.
*
*******************************************************************************/
void Millis_SaveConfig(void) 
{
    #if (!Millis_UsingFixedFunction)

        Millis_backup.CounterUdb = Millis_ReadCounter();

        #if(!Millis_ControlRegRemoved)
            Millis_backup.CounterControlRegister = Millis_ReadControlRegister();
        #endif /* (!Millis_ControlRegRemoved) */

    #endif /* (!Millis_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Millis_RestoreConfig
********************************************************************************
*
* Summary:
*  Restores the current user configuration.
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Millis_backup:  Variables of this global structure are used to 
*  restore the values of non retention registers on wakeup from sleep mode.
*
*******************************************************************************/
void Millis_RestoreConfig(void) 
{      
    #if (!Millis_UsingFixedFunction)

       Millis_WriteCounter(Millis_backup.CounterUdb);

        #if(!Millis_ControlRegRemoved)
            Millis_WriteControlRegister(Millis_backup.CounterControlRegister);
        #endif /* (!Millis_ControlRegRemoved) */

    #endif /* (!Millis_UsingFixedFunction) */
}


/*******************************************************************************
* Function Name: Millis_Sleep
********************************************************************************
* Summary:
*     Stop and Save the user configuration
*
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Millis_backup.enableState:  Is modified depending on the enable 
*  state of the block before entering sleep mode.
*
*******************************************************************************/
void Millis_Sleep(void) 
{
    #if(!Millis_ControlRegRemoved)
        /* Save Counter's enable state */
        if(Millis_CTRL_ENABLE == (Millis_CONTROL & Millis_CTRL_ENABLE))
        {
            /* Counter is enabled */
            Millis_backup.CounterEnableState = 1u;
        }
        else
        {
            /* Counter is disabled */
            Millis_backup.CounterEnableState = 0u;
        }
    #else
        Millis_backup.CounterEnableState = 1u;
        if(Millis_backup.CounterEnableState != 0u)
        {
            Millis_backup.CounterEnableState = 0u;
        }
    #endif /* (!Millis_ControlRegRemoved) */
    
    Millis_Stop();
    Millis_SaveConfig();
}


/*******************************************************************************
* Function Name: Millis_Wakeup
********************************************************************************
*
* Summary:
*  Restores and enables the user configuration
*  
* Parameters:  
*  void
*
* Return: 
*  void
*
* Global variables:
*  Millis_backup.enableState:  Is used to restore the enable state of 
*  block on wakeup from sleep mode.
*
*******************************************************************************/
void Millis_Wakeup(void) 
{
    Millis_RestoreConfig();
    #if(!Millis_ControlRegRemoved)
        if(Millis_backup.CounterEnableState == 1u)
        {
            /* Enable Counter's operation */
            Millis_Enable();
        } /* Do nothing if Counter was disabled before */    
    #endif /* (!Millis_ControlRegRemoved) */
    
}


/* [] END OF FILE */
