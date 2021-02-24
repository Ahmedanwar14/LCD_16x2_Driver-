/*
 * LCD_INT.h
 *
 *  Created on: Feb 22, 2020
 *      Author: Anwar
 */

#define LCD_CLR_DISP 			0x01
#define LCD_RET_HOME 			0x02
#define LCD_ENTRY_MODE_INC 		0X06 //WITHOUT SHIFT AND INCREMENT
#define LCD_ENTRY_MODE_DEC 		0X04 //WITHOUT SHIFT AND DECREMENT
#define LCD_DISP_ON				0X0C
#define LCD_DISP_CON			0X0E
#define LCD_DISP_CBON			0X0F
#define LCD_FUNC_SET			0x38
#define LCD_SHFT_CURSR			0x14
#define LCD_SHFT_CURSL			0x10
#define LCD_SHFT_DISR			0X05
#define LCD_SHFT_DISL			0X07
#define LCD_1stLINE_STRT		0x80
#define LCD_2ndLINE_STRT		0xc0
#define ROW0					0x00
#define ROW1					0x01
#define COL0					0x00
#define COL1					0x01
#define COL2					0x02
#define COL3					0x03
#define COL4					0x04
#define COL5					0x05
#define COL6					0x06
#define COL7					0x07
#define COL8					0x08
#define COL9					0x09
#define COL10					0x0A
#define COL11					0x0B
#define COL12					0x0C
#define COL13					0x0D
#define COL14					0x0E
#define COL15					0x0F

void LCD_VidInit(void);
void LCD_VidSendData(u8 u8Data);
void LCD_VidWriteString(u8* Pu8Data); /*Pu8=Pointer to u8 w l string daymn a5erha null terminator w 3mlnaha b pointer 3shan dy lazam t point gwa l array l gwah l string*/
void LCD_VidSendInst(u8 u8Inst);
void LCD_VidGoToXY(u8 u8Row,u8 u8Col);
void LCD_VidWriteNumber(u16 u16Num);
