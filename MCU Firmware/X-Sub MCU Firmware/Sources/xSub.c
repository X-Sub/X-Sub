/*
 * xSub.c
 *
 *  Created on: Jun 11, 2015
 *      Author: ddtdanilo
 */

/*Includes*/
#include "Cpu.h"
#include "Events.h"
//#include "M1_ESC.h"
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




//Cambia el Status de un LED
//Hace que se mantenga encendido o titilando si est� activo.
void lStatus(byte nLed, bool status)
{
	switch(nLed)
	{
		case 0x00:
			led0x00 = status;
			break;
			
		case 0x01:
			led0x01 = status;		
			break;
			
		case 0x02:
			led0x02 = status;				
			break;
		
		case 0x03:
			led0x03 = status;				
			break;
			
		case 0x04:
			led0x04 = status;				
			break;
		
		case 0x05:
			led0x05 = status;		
			break;
					
		case 0x06:
			led0x06 = status;				
			break;
			
		case 0x07:
			led0x07 = status;						
			break;
				
	}
}

//Activa a sMCU_OK
void sMCU_OK_W()
{
	sMCU_OK_ClrVal();
}

//Desactiva a sMCU_OK
void sMCU_OK_NW()
{
	sMCU_OK_SetVal();
}

//Muestra titilando a sPC_OK
void sCom_In_W()
{
	lStatus(0x01,TRUE);
}

//Muestra titilando a sPC_OK
void sCom_In_NW()
{
	lStatus(0x01,FALSE);
}

//Muestra titilando a sPC_OK
void sPC_OK_W()
{
	lStatus(0x02,TRUE);
}

//Muestra titilando a sPC_OK
void sPC_OK_NW()
{
	lStatus(0x02,FALSE);
}

//paraliza el MCU por el tiempo time en ms
void delay(word time)
{
	sPC_OK_W();
	Cpu_Delay100US(time*10);
}


//Inicializa los motores
void initMxSub(){
	word spDC;
	
	//M1_ESC_Enable();
	M2_ESC_Enable();
	M3_ESC_Enable();
	M4_ESC_Enable();
	
	tMotor = 0;
	
	//spDC = 0x13DC;//0x13DC = 7.76%
	spDC = 0xFFFF;
	//M1_ESC_SetRatio16(spDC);
	M2_ESC_SetRatio16(spDC);
	M3_ESC_SetRatio16(spDC);
	M4_ESC_SetRatio16(spDC);
	delay(2000);
	spDC = 0x0000;
	//M1_ESC_SetRatio16(spDC);
	M2_ESC_SetRatio16(spDC);
	M3_ESC_SetRatio16(spDC);
	M4_ESC_SetRatio16(spDC);
	delay(2000);

}

//Coloca un DC a todos los motores
void setDC(word Speed)
{
 //(void)M1_ESC_SetRatio16(Speed);
 (void)M2_ESC_SetRatio16(Speed);
 (void)M3_ESC_SetRatio16(Speed);
 (void)M4_ESC_SetRatio16(Speed);
}

//MAPEA
double map(double in, double minA,double maxA,double minB, double maxB){
	return ((maxB-minB)/(maxA-minA))*in;
}











