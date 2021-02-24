/*
 * LCD_PROG.c
 *
 *  Created on: Feb 22, 2020
 *      Author: Anwar
 */
#define F_CPU 8000000UL
#include"STD_TYPES.h"
#include"DIO_PRIV.h"
#include "DIO_INT.h"
#include "LCD_CFG.h"
#include "LCD_INT.h"
#include <avr/delay.h>

void LCD_VidSendInst(u8 u8Inst)
{
	DIO_vidSetPinVal(LCD_CTR_PORT,RS_PIN,LOW);
	DIO_vidSetPinVal(LCD_CTR_PORT,RW_PIN,LOW);
	DIO_vidSetPinVal(LCD_CTR_PORT,E_PIN,HIGH);
	DIO_vidSetPortVal(LCD_DATA_PORT,u8Inst);
	_delay_ms(2);
	DIO_vidSetPinVal(LCD_CTR_PORT,E_PIN,LOW);
}
void LCD_VidInit(void)
{
	DIO_vidSetPinDir(LCD_CTR_PORT,RS_PIN,OUTPUT);
	DIO_vidSetPinDir(LCD_CTR_PORT,RW_PIN,OUTPUT);
	DIO_vidSetPinDir(LCD_CTR_PORT,E_PIN,OUTPUT);
	DIO_vidSetPortDir(LCD_DATA_PORT,OUTPUT);

	LCD_VidSendInst(LCD_FUNC_SET);
	_delay_ms(1);
	LCD_VidSendInst(LCD_DISP_CBON);
	_delay_ms(1);
	LCD_VidSendInst(LCD_CLR_DISP);
	_delay_ms(1);

}


void LCD_VidSendData(u8 u8Data)
{
DIO_vidSetPinVal(LCD_CTR_PORT,RS_PIN,HIGH);
DIO_vidSetPinVal(LCD_CTR_PORT,RW_PIN,LOW);
DIO_vidSetPinVal(LCD_CTR_PORT,E_PIN,HIGH);
DIO_vidSetPortVal(LCD_DATA_PORT,u8Data);
DIO_vidSetPinVal(LCD_CTR_PORT,E_PIN,LOW);
_delay_ms(1);
DIO_vidSetPinVal(LCD_CTR_PORT,E_PIN,HIGH);
}

void LCD_VidWriteString(u8* Pu8Data)
{
	u8 u8LoopCtr=0;
	while(Pu8Data[u8LoopCtr] !=0)//fakt l gomla dy *(Pu8DAta+u8loopctr) da nzakr pointer aw c ya man b2a
	{
		LCD_VidSendData(Pu8Data[u8LoopCtr]);
		u8LoopCtr++;
		if(u8LoopCtr==16)
		{
			LCD_VidGoToXY(ROW1,COL0);
		}
	}
}

void LCD_VidGoToXY(u8 u8Row,u8 u8Col)
{
	u8 u8Inst= u8Col;
	if(u8Row == ROW1)
	{
		u8Inst|=0x40;
	}
	u8Inst|=0x80;
	LCD_VidSendInst(u8Inst);
}

void LCD_VidWriteNumber(u16 u16Num)
{
	u16 u16NumRange=1;
	while((u16Num/u16NumRange)!=0)
	{
		u16NumRange*=10;
	}
	while(u16NumRange!=1)
	{
		u16NumRange/=10;
		LCD_VidSendData((u16Num/u16NumRange)+48);
		u16Num%=u16NumRange;
	}
}
