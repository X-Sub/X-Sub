/*
 * xSub.c
 *
 *  Created on: Jun 11, 2015
 *      Author: ddtdanilo
 */

/*Includes*/
#include "Cpu.h"
#include "Events.h"
#include "M1_ESC.h"
#include "M2_ESC.h"
#include "M3_ESC.h"
#include "M4_ESC.h"
/* Include shared modules, which are used for whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"

/*Mis includes*/
#include "xSub.h"



void initMxSub(){
	M1_ESC_Enable();
	M2_ESC_Enable();
	M3_ESC_Enable();
	M4_ESC_Enable();
}

