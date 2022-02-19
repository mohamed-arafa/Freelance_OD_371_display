/* 
 * File:   OD_371_Display.h
 * Author: Mohamed_Arafa
 *
 * Created on February 12, 2022, 7:44 AM
 */
#include "mcc_generated_files/mcc.h"
#ifndef OD_371_DISPLAY_H
#define	OD_371_DISPLAY_H


#define CommonCathod    0
#define CommonAnode     1


/************ User Defined **************/
#define OD_Type     CommonCathod        

#define OD_GPIO              LATA 
#define COM1                 LATBbits.LATB2
#define COM2                 LATBbits.LATB3

#define COM1_DataDirection      TRISBbits.TRISB2
#define COM2_DataDirection      TRISBbits.TRISB3


#define LE_LowRegister       LATBbits.LATB0
#define LE_HighRegister      LATBbits.LATB1

#define OD_DataDirection                  TRISA
#define LE_LowRegisterDataDirection       TRISBbits.TRISB0
#define LE_HighRegisterDataDirection      TRISBbits.TRISB1

/*******functions *********/
void OD_initialize(void);
void OD_Display_SetTime(
unsigned char * minutes_local,unsigned char * seconds_local
);
void OD_Display();
void OD_Display_phase1(unsigned char minutes,unsigned char seconds);
void OD_Display_phase2(unsigned char minutes,unsigned char seconds);

 
void PWM_Generate(void);
/***********Data to be sent**************/
//LOW byte
unsigned char display1Phase1L[10]={
0XA0,
0XA0,
0XA0,
0XA0,
0XA0,
0XA0,
0XA0,
0XA0,
0XA0,
0XA0
};
unsigned char display1Phase2L[10]={
0xf1,
0xf1,
0xf1,
0xf1,
0xf1,
0xf1,
0xf1,
0xf1,
0xf1,
0xf1
};
unsigned char display2Phase1L[10]={
0x1A,
0X02,
0X1C,
0X16,
0X06,
0X16,
0X1E,
0X02,
0X1E,
0X16
};
unsigned char display2Phase2L[10]={
0X0F,
0X03,
0X07,
0X07,
0X0B,
0X0D,
0X0D,
0X07,
0X0F,
0X0F
};
unsigned char display3Phase1L[10]={
0X00,
0X00,
0X00,
0X00,
0X00,
0X00,
0X00,
0X00,
0X00,
0X00
};
unsigned char display3Phase2L[10]={
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01
};
unsigned char display4Phase1L[10]={
0X01,
0X00,
0X01,
0X01,
0X00,
0X01,
0X01,
0X00,
0X01,
0X01
};
unsigned char display4Phase2L[10]={
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01

};

//HIGH byte
unsigned char display1Phase1H[10]={
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01
};
unsigned char display1Phase2H[10]={
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01,
0x01
};
unsigned char display2Phase1H[10]={
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01
};
unsigned char display2Phase2H[10]={
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01,
0X01
};
unsigned char display3Phase1H[10]={
0XB1,
0X21,
0XD1,
0X71,
0X61,
0X71,
0XF1,
0X21,
0XF1,
0X71
};
unsigned char display3Phase2H[10]={
0XE1,
0X21,
0X61,
0X61,
0XA1,
0XC1,
0XC1,
0X61,
0XE1,
0XE1
};
unsigned char display4Phase1H[10]={
0X0B,
0X03,
0X0D,
0X07,
0X07,
0X07,
0X0F,
0X03,
0X0F,
0X07,
};
unsigned char display4Phase2H[10]={
0X0F,
0X03,
0X07,
0X07,
0X0B,
0X0D,
0X0D,
0X07,
0X0F,
0X0F
};



#endif	/* OD_371_DISPLAY_H */

