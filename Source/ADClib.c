/*
 * File:   ADClib.c
 * Author: shaunak
 *
 * Created on August 29, 2011, 2:21 PM
 */

#include <p32xxxx.h>
#include "ADC.h"


void initADC(int amask)
{
   /* AD1PCFG = amask;
    AD1CON1 = 0x00E0;
    AD1CSSL = 0;
    AD1CON2 = 0;
    AD1CON3 = 0x1F3F;
    AD1CON1SET = 0x8000;
*/
    
    adc10_config_t adc10_conf;
    adc10_conf.adc10_auto_sample_time = ADC10_M_AUTO_SAMP_TIME_31TAD;
    adc10_conf.adc10_clock_source_rcc_or_pbc = ADC10_M_PB_CLK;
    adc10_conf.adc10_conversion_auto_or_timer_or_int = ADC10_M_AUTO_CONVERTION;
    adc10_conf.adc10_data_op_format = ADC10_M_OP_FORMAT_INTEGER16;
    adc10_conf.adc10_idle_state_on_off = ADC10_M_ENABLE_IN_IDLE_STATE;
    adc10_conf.adc10_on_off = ADC10_M_ON;
    adc10_conf.adc10_sampling_auto_or_smp_bit = ADC10_M_SAMPLING_SAMP_BIT_SET;
    adc10_conf.port_config = amask;
    hal_config_adc10(ADC10,&adc10_conf);
    
    return;




}

int readADC(int ch)
{
  /*  AD1CHSbits.CH0SA = ch;
    AD1CON1bits.SAMP = 1;
    while(!AD1CON1bits.DONE);
    return ADC1BUF0;
*/
int conv_data;
 conv_data = hal_adc10_read_AD(ADC10,ch);   
 return(conv_data);

}
