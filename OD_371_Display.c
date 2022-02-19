
#include "OD_371_Display.h"

unsigned char * minutes;
unsigned char * seconds;

    /****mechanism
     A) Phase_1
     * 1- logic 1 to LE1 and 0 to LE2 
     * 2- HighBytePhase1 to IC1
     * 3- logic 0 to LE1 and 1 to LE2 
     * 4- HighBytePhase1 to IC2
     * 5-COM1 high  COM2Low
     * 6-DElay 
     * 7- Repeat the operations for phase 2
     * 
     * 
     * 
    ****/

void OD_initialize(void)
{
    OD_DataDirection=0x00;      // output
    LE_HighRegisterDataDirection = 0 ;
    LE_LowRegisterDataDirection  = 0 ;
    COM1_DataDirection=0;
    COM2_DataDirection=0;
    
    OD_GPIO = 0X00;             // initial value
    LE_HighRegister = 0 ;
    LE_LowRegister  = 0 ;
    TMR0_SetInterruptHandler(OD_Display);       //set as a callBack function
    
}

void OD_Display_SetTime(
unsigned char * minutes_local,unsigned char * seconds_local
)
{
    minutes=minutes_local;
    seconds=seconds_local;
}

/*this function is passed to callback function*/
void OD_Display(void)
{
    
    static unsigned char phase =1;
    if(1==phase){
        OD_Display_phase1(*minutes,*seconds);
        phase=2;
    }
    else if(2==phase){ 
        OD_Display_phase2(*minutes,*seconds);
        phase=1;
    }
    
}

void OD_Display_phase1(unsigned char minutes,unsigned char seconds) 
{
    
    unsigned char HighBytePhase1=0;
    unsigned char LowBytePhase1 =0;
    
    unsigned char Display1=0;
    unsigned char Display2=0;
    unsigned char Display3=0;
    unsigned char Display4=0;

    
    Display1 = minutes / 10;
    Display2 = minutes % 10;
    Display3 = seconds / 10;
    Display4 = seconds % 10;
    
    
    HighBytePhase1= display1Phase1H[Display1] | display2Phase1H[Display2] | display3Phase1H[Display3] | display4Phase1H[Display4];
    LowBytePhase1 = display1Phase1L[Display1] | display2Phase1L[Display2] | display3Phase1L[Display3] | display4Phase1L[Display4];
    
#if OD_Type==CommonAnode
    HighBytePhase1 = ~HighBytePhase1;
    LowBytePhase1  = ~LowBytePhase1 ;
#endif
    
    
    /***filling the 2 REgisters****/
    OD_GPIO = HighBytePhase1;
    LE_HighRegister=1;          //High Register enabled to take input
    LE_LowRegister =0;
    __delay_us(10);
    
    OD_GPIO = LowBytePhase1;
    LE_HighRegister=0;
    LE_LowRegister =1;          //Low Register enabled to take input
    __delay_us(10);
    
    /*** display ***/
    COM1=0;
    COM2=1;
    
    
}

void OD_Display_phase2(unsigned char minutes,unsigned char seconds) 
{

    unsigned char HighBytePhase2=0;
    unsigned char LowBytePhase2 =0;
    
    unsigned char Display1=0;
    unsigned char Display2=0;
    unsigned char Display3=0;
    unsigned char Display4=0;

    
    Display1 = minutes / 10;
    Display2 = minutes % 10;
    Display3 = seconds / 10;
    Display4 = seconds % 10;
    
    HighBytePhase2= display1Phase2H[Display1] | display2Phase2H[Display2] | display3Phase2H[Display3] | display4Phase2H[Display4];
    LowBytePhase2 = display1Phase2L[Display1] | display2Phase2L[Display2] | display3Phase2L[Display3] | display4Phase2L[Display4];
    
    
#if OD_Type==CommonAnode
    HighBytePhase2 = ~HighBytePhase2;
    LowBytePhase2  = ~LowBytePhase2 ;
#endif
    
    /***filling the 2 REgisters****/
    OD_GPIO = HighBytePhase2;
    LE_HighRegister=1;          // High register enabled to take input
    LE_LowRegister =0;
    __delay_us(10);
    
    OD_GPIO = LowBytePhase2;    
    LE_HighRegister=0;          
    LE_LowRegister =1;          //Low Register enabled to take input
    __delay_us(10);
    
    /*** display ***/
    COM1=1;
    COM2=0;
    
    
}
 

