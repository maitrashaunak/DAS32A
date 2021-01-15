/* 10 Bit ADC HAL Driver Header File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 25/07/2019
 * No Interrupts are used.
 * //////////////////////////////////////////////////////////////////////////
 * /////////////////////////////////////////////////////////////////////////////
 */

#include <p32xxxx.h>
#include <stdint.h>

#define __IO 	volatile
///Properly define the following FCY & PBCLK values/////////
#define FCY	72000000UL
#define PBCLK	36000000UL
/*
FORM<2:0>: Data Output Format bits
011 = Signed Fractional 16-bit (DOUT = 0000 0000 0000 0000 sddd dddd dd00 0000)
010 = Fractional 16-bit (DOUT = 0000 0000 0000 0000 dddd dddd dd00 0000)
001 = Signed Integer 16-bit (DOUT = 0000 0000 0000 0000 ssss sssd dddd dddd)
000 = Integer 16-bit (DOUT = 0000 0000 0000 0000 0000 00dd dddd dddd) ///This one is only implemented here
111 = Signed Fractional 32-bit (DOUT = sddd dddd dd00 0000 0000 0000 0000)
110 = Fractional 32-bit (DOUT = dddd dddd dd00 0000 0000 0000 0000 0000)
101 = Signed Integer 32-bit (DOUT = ssss ssss ssss ssss ssss sssd dddd dddd)
100 = Integer 32-bit (DOUT = 0000 0000 0000 0000 0000 00dd dddd dddd)
*/

/*SSRC<2:0>: Conversion Trigger Source Select bits
111 = Internal counter ends sampling and starts conversion (auto convert) //This one is only inmplemented here
110 = Reserved
101 = Reserved
100 = Reserved
011 = Reserved
010 = Timer3 period match ends sampling and starts conversion
001 = Active transition on INT0 pin ends sampling and starts conversion
000 = Clearing SAMP bit ends sampling and starts conversion*/
/* AD1CON2 (ADC10XCON2) register is set to 0 directly by the configuration function
  * Presently we use MUX A, & use AVdd & AVss as Vref+/-
 * AD1CSSL also set to zero as we are not use  scaning mode in general...
 * we usually prefer AUTO CONVERSION &  start sampling when SMP is SET.*/

typedef enum
{

	ADC10_M_OFF,
	ADC10_M_ON,
	ADC10_M_ENABLE_IN_IDLE_STATE,
    ADC10_M_DISABLE_IN_IDLE_STATE,
    ADC10_M_START_CONV,
    ADC10_M_OP_FORMAT_INTEGER16,
    ADC10_M_AUTO_CONVERTION,
    ADC10_M_SAMPLING_AUTO,
    ADC10_M_SAMPLING_SAMP_BIT_SET,
    ADC10_M_RC_CLK,
    ADC10_M_PB_CLK,
    ADC10_M_AUTO_SAMP_TIME_31TAD

}adc10_mode_sel_e;

typedef struct
{
  __IO uint32_t ADC10XCON1;        			/*!< ADC control register1   Address offset: 0x00 */
  __IO uint32_t ADC10XCON1CLR;    			 /*!< ADC control clear register,            Address offset: 0x04 */
  __IO uint32_t ADC10XCON1SET;    			 /*!< ADC  control set register,             Address offset: 0x08 */
  __IO uint32_t ADC10XCON1INV;    			     /*!< ADC control invert,                   Address offset: 0x0C */
  
  __IO uint32_t ADC10XCON2;        			/*!< ADC control register2 base address 0xXXXXXX10   Address offset: 0x00 */
  __IO uint32_t ADC10XCON2CLR;    			 /*!< ADC control clear register2,            Address offset: 0x04 */
  __IO uint32_t ADC10XCON2SET;    			 /*!< ADC  control set register2,             Address offset: 0x08 */
  __IO uint32_t ADC10XCON2INV;    			     /*!< ADC control invert2,                   Address offset: 0x0C */
  
  __IO uint32_t ADC10XCON3;        			/*!< ADC control register3  base address 0xXXXXXX20 Address offset: 0x00 */
  __IO uint32_t ADC10XCON3CLR;    			 /*!< ADC control clear register3,            Address offset: 0x04 */
  __IO uint32_t ADC10XCON3SET;    			 /*!< ADC  control set register3,             Address offset: 0x08 */
  __IO uint32_t ADC10XCON3INV;    			     /*!< ADC control invert3,                   Address offset: 0x0C */

   __IO uint32_t dummy_ADC10XCON4;        			/*!< ADC control register3  base address 0xXXXXXX30 Address offset: 0x00 */
  __IO uint32_t dummy_ADC10XCON4CLR;    			 /*!< ADC control clear register3,            Address offset: 0x04 */
  __IO uint32_t dummy_ADC10XCON4SET;    			 /*!< ADC  control set register3,             Address offset: 0x08 */
  __IO uint32_t dummy_ADC10XCON4INV;    			     /*!< ADC control invert3,                   Address offset: 0x0C */


  __IO uint32_t ADC10XCHS;            /*!< ADC register,  BaseAddress 0xXXXXXX40 : Address offset: 0x00 */
  __IO uint32_t ADC10XCHSCLR;          /*!< ADC register clear,  Address offset: 0x04 */
  __IO uint32_t ADC10XCHSSET;     /*!< ADC register set, Address offset: 0x08 */
  __IO uint32_t ADC10XCHSINV;     /*!< ADC register invert,  Address offset: 0x0C */

   __IO uint32_t ADC10XCSSL;   	   /*!< ADC register base address : 0xXXXXXX50 Address offset: 0x00 */
  __IO uint32_t ADC10XCSSLCLR;    /*!< ADC period clear  Address offset: 0x04 */
  __IO uint32_t ADC10XCSSLSET;    /*!<  ADC period set, Address offset: 0x08 */
  __IO uint32_t ADC10XCSSLINV;    /*!< ADC period invert,Address offset: 0x0C */

  
  
  
  __IO uint32_t ADC10XPCFG;   	   /*!< ADC register base address : 0xXXXXXX60 Address offset: 0x00 */
  __IO uint32_t ADC10XPCFGCLR;    /*!< ADC period clear  Address offset: 0x04 */
  __IO uint32_t ADC10XPCFGSET;    /*!<  ADC period set, Address offset: 0x08 */
  __IO uint32_t ADC10XPCFGINV;    /*!< ADC period invert,Address offset: 0x0C */

  __IO uint32_t ADC10XBUF0;    /*!< ADC buffer register ,BAse address 0xXXXXXX70 Address offset: 0x00 */
  
}ADC10_TypeDef;






typedef struct
{
        adc10_mode_sel_e         adc10_on_off;
        adc10_mode_sel_e        adc10_idle_state_on_off;
        adc10_mode_sel_e        adc10_data_op_format;
        adc10_mode_sel_e        adc10_conversion_auto_or_timer_or_int;
        adc10_mode_sel_e        adc10_sampling_auto_or_smp_bit;
        adc10_mode_sel_e        adc10_clock_source_rcc_or_pbc;
        adc10_mode_sel_e        adc10_auto_sample_time;
        int                     port_config;
      

}adc10_config_t;




#define ADC10                		((ADC10_TypeDef *) _ADC10_BASE_ADDRESS)


/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////CONFIGURATION//////////////////////////////////////
#define ADC10_ON_OFF_BIT                     ((uint32_t) (1<<15)) //On off control of ADC module 1=ON
#define ADC10_STOP_IN_IDLE_BIT               ((uint32_t) (1<<13)) //1 = stop in idle mode
#define ADC10_SAMP_AUTO_START_BIT            ((uint32_t) (1<<2)) //1 = AUTO SAMPLING, 0 = SAMPLE START WHEN SAMP IS SET
#define ADC10_SAMP_BIT	                     ((uint32_t) (1<<1)) //1 = SAMPLING, 0 = HOLDING

////////////////////////////////////////STATUS///////////////////////////////////////////
#define ADC10_CONV_DONE_BIT	             ((uint32_t) (1<<0)) //1= Conv. done, 0 = Conv. in progress

////////////////////////////////////////////////APIs/////////////////////////////////////////////////////////////////////

void hal_config_adc10(ADC10_TypeDef *ADCx, adc10_config_t *adc10_config);
void hal_config_adc10_idle_state(ADC10_TypeDef *ADCx, adc10_mode_sel_e idle_state);
void hal_config_adc10_opformat(ADC10_TypeDef *ADCx, adc10_mode_sel_e opformat);
void hal_config_adc10_conversion(ADC10_TypeDef *ADCx, adc10_mode_sel_e conv);
void hal_config_adc10_clk(ADC10_TypeDef *ADCx, adc10_mode_sel_e clk_source);
void hal_config_adc10_auto_samp(ADC10_TypeDef *ADCx, adc10_mode_sel_e samp);
void hal_config_adc10_samp_time(ADC10_TypeDef *ADCx, adc10_mode_sel_e samp_time);
void hal_config_adc10_port_config(ADC10_TypeDef *ADCx, int value); //1 for digital, 0 for analog
void hal_config_adc10_on_off(ADC10_TypeDef *ADCx, adc10_mode_sel_e on_off);
int hal_adc10_read_AD(ADC10_TypeDef *ADCx, int channel_no); //we use MUX A always



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

