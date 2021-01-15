/* TIMERS HAL Driver Header File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 24/04/2019
 * The Interrupts section are int the interrupt driver....
 * //////////////////////////////////////////////////////////////////////////
 * /////////////////////////////////////////////////////////////////////////////
 */

#include <p32xxxx.h>
#include <stdint.h>
#include "hal_it_pic32mx360f512l.h" //for enabling the interrupt

#define __IO 	volatile
///Properly define the following FCY & PBCLK values/////////
#define FCY	72000000UL
#define PBCLK	36000000UL
/*
 * Timer Pre-scalar values: for 16 bit timers
 * 11 = 1:256 prescale value
 * 10 = 1:64 prescale value
 * 01 = 1:8 prescale value
 * 00 = 1:1 prescale value
 * For 32 bit timers (T23 or T45)
 * 111 = 1:256 prescale value
 * 110 = 1:64 prescale value
 * 101 = 1:32 prescale value
 * 100 = 1:16 prescale value
 * 011 = 1:8 prescale value
 * 010 = 1:4 prescale value
 * 001 = 1:2 prescale value
 * 000 = 1:1 prescale value
 *
 *
*/

/* Interrupt sub priority
 * 11 = Interrupt subpriority is 3
 * 10 = Interrupt subpriority is 2
 * 01 = Interrupt subpriority is 1
 * 00 = Interrupt subpriority is 0
 * Interrupt Priority
 * 111 = Interrupt priority is 7
 * 110 = Interrupt priority is 6
 * 101 = Interrupt priority is 5
 * 100 = Interrupt priority is 4
 * 011 = Interrupt priority is 3
 * 010 = Interrupt priority is 2
 * 001 = Interrupt priority is 1
 * 000 = Interrupt is disabled
 * for 32bit timer....if use T23 then activate T3 Interrupt
 * & if use T45 then activate T5 interrupt
 * In general for Txy timer...the timer function will be activated by Tx
 * & the interrupt functions will be activated by Ty
 */
/* Syntax for ISR for c32 compiler....
 void __ISR(_Timer_1_Vector,ipl3)Timer1Handler(void)
 * in case of Subpriority = 1 Priority = 3
 */
typedef enum
{
	M_ON,
	M_OFF,
	M_ENABLE,
	M_DISABLE,
    	M_SET,
    	M_RESET,
        M_T16, //16 bit timer
        M_T32, //32 bit timer
        M_PBC, //peripheral bus clock
        M_EXTC //external clock

}mode_sel_t;

typedef enum{
            timer_T1,
            timer_T2,
            timer_T3,
            timer_T4,
            timer_T5,
            timer_T23,
            timer_T45

}timer_sel_t;

typedef struct
{
  __IO uint32_t TXCON;        			/*!< timer control register   Address offset: 0x00 */
  __IO uint32_t TXCONCLR;    			 /*!< timer control clear register,            Address offset: 0x04 */
  __IO uint32_t TXCONSET;    			 /*!< timer control set register,             Address offset: 0x08 */
  __IO uint32_t TXCONINV;    			     /*!< timer control invert,                   Address offset: 0x0C */
  __IO uint32_t TMRX;     			 /*!< timer register,  Address offset: 0x10 */
  __IO uint32_t TMRXCLR;                   /*!< timer register clear,  Address offset: 0x14 */
  __IO uint32_t TMRXSET;     /*!< timer register set, Address offset: 0x18 */
  __IO uint32_t TMRXINV;     /*!< timer register invert,  Address offset: 0x1C */
  __IO uint32_t PRX;   	   /*!< timer period Address offset: 0x20 */
  __IO uint32_t PRXCLR;    /*!< timer period clear  Address offset: 0x24 */
  __IO uint32_t PRXSET;    /*!<  timer period set, Address offset: 0x28 */
  __IO uint32_t PRXINV;    /*!< timer period invert,Address offset: 0x2C */
  
}Timer_TypeDef;

typedef struct
{
	uint32_t	timer_period;
        uint8_t        timer_pre_scalar;
        uint32_t        timer_start_value;
        mode_sel_t	timer_on_off;
        mode_sel_t      timer_type; //TypeA or TypeB ie M_16 or M_32
        mode_sel_t      timer_clock_source;
        timer_sel_t     timer_number;
 }timer_config_t;

typedef struct{

     mode_sel_t      intr_enable_disable;
     timer_sel_t     timer_no;
        uint8_t      intr_priority; //<2:0>
        uint8_t      intr_sub_priority; // <1:0>
}timer_config_it_t;

#define T1                		((Timer_TypeDef *) _TMR1_BASE_ADDRESS)
#define T2               		((Timer_TypeDef *) _TMR2_BASE_ADDRESS)
#define T3                		((Timer_TypeDef *) _TMR3_BASE_ADDRESS)
#define T23               		((Timer_TypeDef *) _TMR23_BASE_ADDRESS)
#define T4                		((Timer_TypeDef *) _TMR4_BASE_ADDRESS)
#define T5               		((Timer_TypeDef *) _TMR5_BASE_ADDRESS)
#define T45                		((Timer_TypeDef *) _TMR45_BASE_ADDRESS)


/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////CONFIGURATION//////////////////////////////////////
#define Timer_ON_OFF                     ((uint32_t) (1<<15)) //On off control of timer module
#define Timer_T32	                 ((uint32_t) (1<<3)) //1 = 32 bit, 0 = 16 bit
#define Timer_TCS	                 ((uint32_t) (1<<1)) //1= Ext Clock, 0 = Peripheral clock
////////////////////////////////////////STATUS///////////////////////////////////////////


////////////////////////////////////////////////APIs/////////////////////////////////////////////////////////////////////

void hal_config_timer(Timer_TypeDef *Tx, timer_config_t *timer_config);
void hal_config_timer_pre_scalar(Timer_TypeDef *Tx, uint8_t pre_scalar);
void hal_config_timer_T32(Timer_TypeDef *Tx, mode_sel_t timer_type);
void hal_config_timer_TCS(Timer_TypeDef *Tx, mode_sel_t clock_source);
void hal_config_timer_on_off(Timer_TypeDef *Tx, mode_sel_t value);
uint32_t hal_timer_read_TMR(Timer_TypeDef *Tx);
void hal_timer_write_TMR(Timer_TypeDef *Tx, uint32_t value);
void hal_timer_write_PR(Timer_TypeDef *Tx, uint32_t period);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Interrupt setup APIs //////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//////////////////////Interrupt Enable Bit in IEC0////////////////////////////////////////
#define T1_IE                    ((uint32_t) (1<<4)) //On off control of timer1 interrupt IEC0
#define T2_IE                    ((uint32_t) (1<<8)) //On off control of timer2 interrupt IEC0
#define T3_IE                    ((uint32_t) (1<<12)) //On off control of timer3 interrupt IEC0
#define T4_IE                    ((uint32_t) (1<<16)) //On off control of timer 4 interrupt IEC0
#define T5_IE                    ((uint32_t) (1<<20)) //On off control of timer5 interrupt IEC0


/////////////////Interrupt Flag Status Bit in IFS0/////////////////////////////////////////

#define T1_IF                    ((uint32_t) (1<<4)) //Flag Status of timer1 interrupt IFS0
#define T2_IF                    ((uint32_t) (1<<8)) //Flag Status of timer2 interrupt IFS0
#define T3_IF                    ((uint32_t) (1<<12)) //Flag Status of timer3 interrupt IFS0
#define T4_IF                    ((uint32_t) (1<<16)) //Flag Status of timer 4 interrupt IFS0
#define T5_IF                    ((uint32_t) (1<<20)) //Flag Status of timer5 interrupt IFS0

//////////////////////APIs//////////////////////////////////////////////////////////
void hal_config_timer_it( timer_config_it_t *timer_config_it);
void hal_config_timer_it_EI(timer_sel_t timer_no, mode_sel_t enable_disable);
void hal_timer_clear_it_flag(timer_sel_t timer_no);
////////////////////////////////////////////////////////////////////////////////////


