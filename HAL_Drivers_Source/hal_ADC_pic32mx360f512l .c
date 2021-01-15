
/* ADC HAL Driver Source File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 26/07/2019
 * 
 */

#include "hal_ADC_pic32mx360f512l.h"

void hal_config_adc10(ADC10_TypeDef *ADCx, adc10_config_t *adc10_config)
{
 (ADCx->ADC10XCON2) = 0;
 (ADCx->ADC10XCSSL) = 0;
 hal_config_adc10_port_config(ADCx, adc10_config->port_config); //1 for digital, 0 for analog
 hal_config_adc10_idle_state(ADCx, adc10_config->adc10_idle_state_on_off);
 hal_config_adc10_opformat(ADCx, adc10_config->adc10_data_op_format);
 hal_config_adc10_conversion(ADCx, adc10_config->adc10_conversion_auto_or_timer_or_int);
 hal_config_adc10_clk(ADCx, adc10_config->adc10_clock_source_rcc_or_pbc);
 hal_config_adc10_auto_samp(ADCx, adc10_config->adc10_sampling_auto_or_smp_bit);
 hal_config_adc10_samp_time(ADCx, adc10_config->adc10_auto_sample_time);
 hal_config_adc10_on_off(ADCx, adc10_config->adc10_on_off);
 return;

}

void hal_config_adc10_idle_state(ADC10_TypeDef *ADCx, adc10_mode_sel_e idle_state)
{
    if(idle_state == ADC10_M_ENABLE_IN_IDLE_STATE)
        (ADCx->ADC10XCON1CLR) |= ADC10_STOP_IN_IDLE_BIT;
    else
        (ADCx->ADC10XCON1SET) |= ADC10_STOP_IN_IDLE_BIT;
    return;

 }
void hal_config_adc10_opformat(ADC10_TypeDef *ADCx, adc10_mode_sel_e opformat)
{
    if(opformat==ADC10_M_OP_FORMAT_INTEGER16)

     (ADCx->ADC10XCON1CLR) |= ((uint32_t)(0b111<<8));  //000 in ADC1CON1 <10:8>
    return;
}

void hal_config_adc10_conversion(ADC10_TypeDef *ADCx, adc10_mode_sel_e conv)
{
    if(conv == ADC10_M_AUTO_CONVERTION)
        (ADCx->ADC10XCON1SET) |= ((uint32_t)(0b111<<5)); // 111 in ADC1CON1 <7:5>
    return;
}

void hal_config_adc10_clk(ADC10_TypeDef *ADCx, adc10_mode_sel_e clk_source)
{
    if(clk_source ==   ADC10_M_PB_CLK)
        (ADCx->ADC10XCON3CLR) |= ((uint32_t) (1<<15));
    else
        (ADCx->ADC10XCON3SET) |= ((uint32_t) (1<<15));

    return;
}

void hal_config_adc10_auto_samp(ADC10_TypeDef *ADCx, adc10_mode_sel_e samp)
{
    if(samp == ADC10_M_SAMPLING_SAMP_BIT_SET)
      (ADCx->ADC10XCON1CLR) |=  ADC10_SAMP_AUTO_START_BIT;
    else
        (ADCx->ADC10XCON1SET) |= ADC10_SAMP_AUTO_START_BIT;
    return;
}

void hal_config_adc10_samp_time(ADC10_TypeDef *ADCx, adc10_mode_sel_e samp_time)
{
    if(samp_time ==  ADC10_M_AUTO_SAMP_TIME_31TAD)
        (ADCx->ADC10XCON3) |= 0x1F3F;
    return;


}

void hal_config_adc10_port_config(ADC10_TypeDef *ADCx, int value) //1 for digital, 0 for analog
{
    (ADCx->ADC10XPCFG) = value;
    return;
}

void hal_config_adc10_on_off(ADC10_TypeDef *ADCx, adc10_mode_sel_e on_off)
{
    if(on_off==ADC10_M_ON)
        (ADCx->ADC10XCON1SET) |= ADC10_ON_OFF_BIT;
    else if(on_off==ADC10_M_OFF)
        (ADCx->ADC10XCON1CLR) |= ADC10_ON_OFF_BIT;
    return;
}

int hal_adc10_read_AD(ADC10_TypeDef *ADCx, int channel_no) //we use MUX A always
{
    (ADCx->ADC10XCHS) = ((uint32_t)(channel_no << 16)); // CH0SA <19:16>
    //AD1CHSbits.CH0SA = channel_no;
    (ADCx->ADC10XCON1SET) |= ADC10_SAMP_BIT; //set SAMP bit
   // AD1CON1bits.SAMP = 1;
    while(!((ADCx->ADC10XCON1) & ADC10_CONV_DONE_BIT)); //wait untill goes high
    // while(!AD1CON1bits.DONE);
    return (ADCx->ADC10XBUF0);
  //return ADC1BUF0;
}
