/*
 * LCD_CFG.h
 *
 *  Created on: Feb 22, 2020
 *      Author: Anwar
 */
#include "DIO_INT.h"
#ifndef DIO_INT_H
#warning "DIO interface not include before LCD_CFG"
#endif
#define LCD_DATA_PORT PORTD //lazm ykon l data pins kolhm 3ala nfs l port
#define LCD_CTR_PORT  PORTA //lama a3ml kda hast5dmha f func DIO setpinval a3dr a8yr l port b shola
#define RS_PIN	      PIN0 	//lw el pin m7tag a8yrha btshl 3alya l hwar :D
#define RW_PIN 	      PIN1
#define E_PIN  	      PIN2



