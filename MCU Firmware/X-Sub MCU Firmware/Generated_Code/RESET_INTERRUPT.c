/* ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL. DO NOT MODIFY IT.
**     Filename    : RESET_INTERRUPT.c
**     Project     : X-Sub MCU Firmware
**     Processor   : MCF51QE128CLK
**     Component   : ExtInt
**     Version     : Component 02.105, Driver 01.24, CPU db: 3.00.078
**     Compiler    : CodeWarrior ColdFireV1 C Compiler
**     Date/Time   : 2015-06-28, 18:42, # CodeGen: 22
**     Abstract    :
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
**     Settings    :
**         Interrupt name              : Virq
**         User handling procedure     : RESET_INTERRUPT_OnInterrupt
**
**         Used pin                    :
**             ----------------------------------------------------
**                Number (on package)  |    Name
**             ----------------------------------------------------
**                       79            |  PTA5_IRQ_TPM1CLK_RESET
**             ----------------------------------------------------
**
**         Port name                   : PTA
**
**         Bit number (in port)        : 5
**         Bit mask of the port        : 0x0020
**
**         Signal edge/level           : falling
**         Priority                    : 735
**         Pull option                 : up
**         Initial state               : Enabled
**
**         Edge register               : IRQSC     [0xFFFF800F]
**         Enable register             : IRQSC     [0xFFFF800F]
**         Request register            : IRQSC     [0xFFFF800F]
**
**         Port data register          : PTAD      [0xFFFF8000]
**         Port control register       : PTADD     [0xFFFF8001]
**     Contents    :
**         GetVal - bool RESET_INTERRUPT_GetVal(void);
**
**     Copyright : 1997 - 2014 Freescale Semiconductor, Inc. 
**     All Rights Reserved.
**     
**     Redistribution and use in source and binary forms, with or without modification,
**     are permitted provided that the following conditions are met:
**     
**     o Redistributions of source code must retain the above copyright notice, this list
**       of conditions and the following disclaimer.
**     
**     o Redistributions in binary form must reproduce the above copyright notice, this
**       list of conditions and the following disclaimer in the documentation and/or
**       other materials provided with the distribution.
**     
**     o Neither the name of Freescale Semiconductor, Inc. nor the names of its
**       contributors may be used to endorse or promote products derived from this
**       software without specific prior written permission.
**     
**     THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
**     ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
**     WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
**     DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
**     ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
**     (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
**     LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
**     ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
**     (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
**     SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
**     
**     http: www.freescale.com
**     mail: support@freescale.com
** ###################################################################*/
/*!
** @file RESET_INTERRUPT.c
** @version 01.24
** @brief
**         This component "ExtInt" implements an external 
**         interrupt, its control methods and interrupt/event 
**         handling procedure.
**         The component uses one pin which generates interrupt on 
**         selected edge.
*/         
/*!
**  @addtogroup RESET_INTERRUPT_module RESET_INTERRUPT module documentation
**  @{
*/         

#include "RESET_INTERRUPT.h"

/*Including shared modules, which are used for all project*/

#include "Events.h"
#include "Cpu.h"


/*
** ===================================================================
**     Method      :  RESET_INTERRUPT_Interrupt (component ExtInt)
**
**     Description :
**         The method services the interrupt of the selected peripheral(s)
**         and eventually invokes the components event(s).
**         This method is internal. It is used by Processor Expert only.
** ===================================================================
*/
ISR(RESET_INTERRUPT_Interrupt)
{
  /* IRQSC: IRQACK=1 */
  setReg8Bits(IRQSC, 0x04U);           /* Clear the interrupt flag */ 
  RESET_INTERRUPT_OnInterrupt();       /* Invoke user event */
}

/*
** ===================================================================
**     Method      :  RESET_INTERRUPT_GetVal (component ExtInt)
**     Description :
**         Returns the actual value of the input pin of the component.
**     Parameters  : None
**     Returns     :
**         ---             - Returned input value. Possible values:
**                           <false> - logical "0" (Low level) <true> -
**                           logical "1" (High level)
** ===================================================================
*/
/*
bool RESET_INTERRUPT_GetVal(void)

**      This method is implemented as macro. See RESET_INTERRUPT.h file.      **
*/

/*!
** @}
*/
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.3 [05.09]
**     for the Freescale ColdFireV1 series of microcontrollers.
**
** ###################################################################
*/