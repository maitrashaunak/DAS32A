/* DAS32A V4
 * Date - 12-01-2021
 * Modified from WF Controller Unit V47.00
 * AOUT2 is used for Load Cell & AOUT1 is for Tacho
 * Author : Shaunak Maitra
 * 
 ******************************************************************************************/


#pragma config POSCMOD=XT, FNOSC=PRIPLL
#pragma config FPLLIDIV=DIV_2, FPLLMUL=MUL_18, FPLLODIV=DIV_1
#pragma config FPBDIV=DIV_2, FWDTEN=ON, WDTPS = PS4096, CP=ON, BWP=OFF

#include <p32xxxx.h>
#include "LCD.h"
#include <plib.h>
#include "ADC.h"
#include "libSPI.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "DAS32A.h"
#include "hal_timer_pic32mx360f512l.h"



#define ClrWdt() (WDTCONSET = _WDTCON_WDTCLR_MASK)



//Digital I/O


#define DIN4             _RA9                    //Tacho Pulse Input
#define TachoIn           DIN4




//////////////All Global Variables Here ///////////////////////////////

uint32_t timer_count_value = 0;
float WT;
uint32_t WarningWord=0;
const uint32_t WeightFilter =5;
const uint32_t SpeedFilter = 5;
const float StaticAmpGain = 316.4556;
const int DigitalMax = 59535;
uint32_t LoadCellFlag = 1;
float b_current[10];
float b_array_dummy[10];
float b_array[10];
float b_stage_array[10];
float b_stage_array_2[10];
float b_stage_array_3[10];
float b_stage_array_4[10];
float mVFloat = 0.0;
uint32_t TachoCount = 0;
float HzFloat = 0.00;
float Hz_array[10];
float Hz_Array_Stage_1[10];
float Hz_Array_Stage_2[10];
float Hz_Array_Stage_3[10];
float Hz_Array_Stage_4[10];
float Hz_Dummy_Array_F[10];
float Hz_Array_Dummy[10];



            



/////////////////////////////////////////////////////////////////////////







void initHW(void)
{
 mJTAGPortEnable(0);
SYSTEMConfigPerformance(72000000L);
mOSCSetPBDIV(OSC_PB_DIV_2);
mPORTASetPinsDigitalIn(BIT_9) ; //TachoIn
mPORTDSetPinsDigitalOut(BIT_0 | BIT_2 |BIT_8 | BIT_9 | BIT_10| BIT_11);
mPORTCSetPinsDigitalOut(BIT_1 | BIT_2 |BIT_3 | BIT_4); 
mPORTASetPinsDigitalOut(BIT_14 | BIT_15) ; 
Delayus(10);
initADC(AINPUTS);
Delayus(10);

}



void initT45(int period)
{
    timer_config_t t45;
    t45.timer_clock_source = M_PBC;
    t45.timer_on_off = M_ON;
    t45.timer_period = period;//140624;// 140624 for 1 secs. //70312;//140624;//0x000112A8; //70312 = 0x000112A8 for 500ms Delay
    t45.timer_pre_scalar = 0b111;
    t45.timer_start_value = 0;
    t45.timer_type = M_T32;
    t45.timer_number = timer_T45;
    hal_config_timer(T45,&t45);
}
////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////
void initT32(void)
{
/* T2CONbits.ON = 0;           //Timer disabled

T2CON = 0;      //Stop any 16/32-bit Timer2 operation
T3CON = 0;      //Stop any 16-bit Timer3 operation

T2CONbits.T32 = 1;          //32 bit mode on, tmr2 + tmr3
T2CONbits.TCKPS = 0b111;    //Prescaler 1:256
T2CONbits.TCS = 0;          //Select internal peripheral clock
PR2 = 0x0003FF70; //almost (1.863 seconds) 2 seconds
//PR3 = 0;

TMR2 = 0;                   //Clear contents of TMR2 and TMR3

T2CONbits.ON = 1;           //Timer enable
  */
    timer_config_t t32;
    t32.timer_clock_source = M_PBC;
    t32.timer_on_off = M_ON;
    t32.timer_period = 0x0003FFFF;
    t32.timer_pre_scalar = 0b111;
    t32.timer_start_value = 0;
    t32.timer_type = M_T32;
    t32.timer_number = timer_T23;
    hal_config_timer(T23,&t32);



}
void stop_T32(void)
{
  /*T2CONbits.ON = 0; //stop timer
   IFS0bits.T3IF = 0; //clear the flag
  TMR2 = 0; //reset the timer
    */
  hal_config_timer_on_off(T23,M_OFF);
  hal_timer_clear_it_flag(timer_T3);
  hal_timer_write_TMR(T23,0);

}

void start_T32(void)
{
    initT32();


}
uint32_t restart_T32(void)
{
  timer_count_value = hal_timer_read_TMR(T23);
  initT32();
  return timer_count_value;
}
////////////////////////////////////////////////////////////////

void LoadCellAndTacho(void)
{
    float b_current = 0.00;
    int i,a,b,count;
    uint32_t count1,count2;
    float b_stage_1,b_stage_2,b_stage_3,b_stage_4;
    float Hz_stage_1,Hz_stage_2,Hz_stage_3,Hz_stage_4;
           
         a=0;
            for(count=0;count<25;count++)
            {
            a+= readADC(LCValue);
            Delayms(5);
            }

            b_current = (float)(a/25.00);


          if((b_current >= 0) && (b_current <= 1024))  // as 10 bit ADC
         {
         //******************************************/
          
             b_array[0] = b_array[1];
             b_array[1] = b_array[2];
             b_array[2] = b_array[3];
             b_array[3] = b_array[4];
             b_array[4] = b_current;

             for(i=0;i<5;i++)
                 b_array_dummy[i] = b_array[i];
             qsortf(b_array_dummy,0,4);

             b_stage_1 = (float)((b_array_dummy[1] + b_array_dummy[2] + b_array_dummy[3])/3.00);

             b_stage_array[0] = b_stage_array[1];
             b_stage_array[1] = b_stage_array[2];
             b_stage_array[2] = b_stage_array[3];
             b_stage_array[3] = b_stage_array[4];
             b_stage_array[4] = b_stage_1;
             for(i=0;i<5;i++)
                 b_array_dummy[i] = b_stage_array[i];
             qsortf(b_array_dummy,0,4);
             b_stage_2 = (float)((b_array_dummy[1] + b_array_dummy[2] + b_array_dummy[3])/3.00);

             b_stage_array_2[0] = b_stage_array_2[1];
             b_stage_array_2[1] = b_stage_array_2[2];
             b_stage_array_2[2] = b_stage_array_2[3];
             b_stage_array_2[3] = b_stage_array_2[4];
             b_stage_array_2[4] = b_stage_2;
             for(i=0;i<5;i++)
                 b_array_dummy[i] = b_stage_array_2[i];
             qsortf(b_array_dummy,0,4);


             b_stage_3 = (float)((b_array_dummy[1] + b_array_dummy[2] + b_array_dummy[3])/3.00);

             b_stage_array_3[0] = b_stage_array_3[1];
             b_stage_array_3[1] = b_stage_array_3[2];
             b_stage_array_3[2] = b_stage_array_3[3];
             b_stage_array_3[3] = b_stage_array_3[4];
             b_stage_array_3[4] = b_stage_3;
             for(i=0;i<5;i++)
                 b_array_dummy[i] = b_stage_array_3[i];
             qsortf(b_array_dummy,0,4);


             b_stage_4 = (float)((b_array_dummy[1] + b_array_dummy[2] + b_array_dummy[3])/3.00);

             b_stage_array_4[0] = b_stage_array_4[1];
             b_stage_array_4[1] = b_stage_array_4[2];
             b_stage_array_4[2] = b_stage_array_4[3];
             b_stage_array_4[3] = b_stage_array_4[4];
             b_stage_array_4[4] = b_stage_4;
             for(i=0;i<5;i++)
                 b_array_dummy[i] = b_stage_array_4[i];
             qsortf(b_array_dummy,0,4);


             b = (float)((b_array_dummy[1] + b_array_dummy[2] + b_array_dummy[3])/3.00);
           
          
            mVFloat = (float)((b*3.125)/StaticAmpGain);
            FourToTwenty2(mVFloat,10.00,DigitalMax);
         
         
        
        }
        
//////////////////////////////////TACHO SECTION STARTS HERE --24-07-19--/////////////////////////////////
     
          count1 = 0;
          count2 = 0;
          initT45(70312);
          do
          {
             if(TachoIn)
             {
                 do
                 {
                    if(IFS0bits.T5IF == 1) break;
                 }while(TachoIn);
                 count1++;
                 Delayus(10); //to stabilize
             }
             if(!TachoIn)
             {
                 do
                 {
                   if(IFS0bits.T5IF == 1) break;
                 }while(!TachoIn);
                 count2++;
               Delayus(10); //to stabilize
             }

          }while(IFS0bits.T5IF == 0); //till timer not expires...
         hal_config_timer_on_off(T45,M_OFF);
         hal_timer_clear_it_flag(timer_T45);
         if((count1<=1) || (count2<=1)) //zero speed lss than or equals to 2 Hz
         {
           TachoCount++;
           if(TachoCount > 10) //no pulse for more that 5 secs roughly
           {
            HzFloat = 0.00;
            memset(Hz_array, 0, sizeof(Hz_array));
            memset(Hz_Array_Stage_1, 0, sizeof(Hz_array));
            memset(Hz_Array_Stage_2, 0, sizeof(Hz_array));
            memset(Hz_Array_Stage_3, 0, sizeof(Hz_array));
            memset(Hz_Array_Stage_4, 0, sizeof(Hz_array));
            FourToTwenty1(0.00,500.00,DigitalMax);
          }

         }

         else if((count1 < 300) || (count2 < 300)) //with in range calculate speed
         {
                          
             Hz_array[0] = Hz_array[1];
             Hz_array[1] = Hz_array[2];
             Hz_array[2] = Hz_array[3];
             Hz_array[3] = Hz_array[4];
             Hz_array[4] = (count1+count2); //As time peroid is 500mS thus T1+T2 will give frequency in Hz.
            for(i=0;i<5;i++)
                 Hz_Array_Dummy[i] = Hz_array[i];
             qsorti(Hz_Array_Dummy,0,4);

             Hz_stage_1 = (float)((Hz_Array_Dummy[1] + Hz_Array_Dummy[2] + Hz_Array_Dummy[3])/3.00);

             Hz_Array_Stage_1[0] = Hz_Array_Stage_1[1];
             Hz_Array_Stage_1[1] = Hz_Array_Stage_1[2];
             Hz_Array_Stage_1[2] = Hz_Array_Stage_1[3];
             Hz_Array_Stage_1[3] = Hz_Array_Stage_1[4];
             Hz_Array_Stage_1[4] = Hz_stage_1;
             for(i=0;i<5;i++)
                 Hz_Dummy_Array_F[i] = Hz_Array_Stage_1[i];
             qsortf(Hz_Dummy_Array_F,0,4);
             Hz_stage_2 = (float)((Hz_Dummy_Array_F[1] + Hz_Dummy_Array_F[2] + Hz_Dummy_Array_F[3])/3.00);

             Hz_Array_Stage_2[0] = Hz_Array_Stage_2[1];
             Hz_Array_Stage_2[1] = Hz_Array_Stage_2[2];
             Hz_Array_Stage_2[2] = Hz_Array_Stage_2[3];
             Hz_Array_Stage_2[3] = Hz_Array_Stage_2[4];
             Hz_Array_Stage_2[4] = Hz_stage_2;

             for(i=0;i<5;i++)
                 Hz_Dummy_Array_F[i] = Hz_Array_Stage_2[i];
             qsortf(Hz_Dummy_Array_F,0,4);
             Hz_stage_3 = (float)((Hz_Dummy_Array_F[1] + Hz_Dummy_Array_F[2] + Hz_Dummy_Array_F[3])/3.00);
             Hz_Array_Stage_3[0] = Hz_Array_Stage_3[1];
             Hz_Array_Stage_3[1] = Hz_Array_Stage_3[2];
             Hz_Array_Stage_3[2] = Hz_Array_Stage_3[3];
             Hz_Array_Stage_3[3] = Hz_Array_Stage_3[4];
             Hz_Array_Stage_3[4] = Hz_stage_3;
             for(i=0;i<5;i++)
                 Hz_Dummy_Array_F[i] = Hz_Array_Stage_3[i];
             qsortf(Hz_Dummy_Array_F,0,4);
             Hz_stage_4 = (float)((Hz_Dummy_Array_F[1] + Hz_Dummy_Array_F[2] + Hz_Dummy_Array_F[3])/3.00);
            Hz_Array_Stage_4[0] =Hz_Array_Stage_4[1];
            Hz_Array_Stage_4[1] =Hz_Array_Stage_4[2];
            Hz_Array_Stage_4[2] =Hz_Array_Stage_4[3];
            Hz_Array_Stage_4[3] =Hz_Array_Stage_4[4];
            Hz_Array_Stage_4[4] = Hz_stage_4;
             for(i=0;i<5;i++)
                 Hz_Dummy_Array_F[i] = Hz_Array_Stage_4[i];
             qsortf(Hz_Dummy_Array_F,0,4);

             HzFloat = (float)((Hz_Dummy_Array_F[1] + Hz_Dummy_Array_F[2] + Hz_Dummy_Array_F[3])/3.00);
             FourToTwenty2(HzFloat,500.00,DigitalMax);
         
         
         }
         
         
         
      

      return;
}
      









//////////////////////////////////////////////////////////////

int main(void)
{

    initHW();
    memset(Hz_array, 0, sizeof(Hz_array));
    memset(Hz_Array_Stage_1, 0, sizeof(Hz_array));
    memset(Hz_Array_Stage_2, 0, sizeof(Hz_array));
    memset(Hz_Array_Stage_3, 0, sizeof(Hz_array));
    memset(Hz_Array_Stage_4, 0, sizeof(Hz_array));
    
    memset(b_array, 0, sizeof(Hz_array));
    memset(b_stage_array, 0, sizeof(b_stage_array));
    memset(b_stage_array_2, 0, sizeof(b_stage_array_2));
    memset(b_stage_array_3, 0, sizeof(b_stage_array_3));
    memset(b_stage_array_4, 0, sizeof(b_stage_array_4));
    
       
    ///Add any further initializations or local variables....

    while(1)
    {
        ClrWdt();
        LoadCellAndTacho();
        //FourToTwenty1(10.00,10.00,DigitalMax);
        //FourToTwenty2(10.00,10.00,DigitalMax);
     }
   
 }










































