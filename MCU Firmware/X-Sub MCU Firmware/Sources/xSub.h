/*
 * xSub.h
 *
 *  Created on: Jun 11, 2015
 *      Author: ddtdanilo
 */

#ifndef XSUB_H_
#define XSUB_H_

/*
 * Variables Globales
 */
extern bool led0x00; //0x00 sMCU_OK Led
extern bool led0x01; //0x01 sCom_In Led
extern bool led0x02; //0x02 sPC_OK  Led
extern bool led0x03; //0x03
extern bool led0x04; //0x04
extern bool led0x05; //0x05
extern bool led0x06; //0x06
extern bool led0x07; //0x07
//Se encarga de inicializar el xSub
void initMxSub();

//Activa a sMCU_OK
void sMCU_OK_W();
//Desactiva a sMCU_OK
void sMCU_OK_NW();
//Muestra titilando a sPC_OK
void sCom_In_W();
//Muestra titilando a sPC_OK
void sCom_In_NW();
//Muestra titilando a sPC_OK
void sPC_OK_W();
//Muestra titilando a sPC_OK
void sPC_OK_NW();



#endif /* XSUB_H_ */
