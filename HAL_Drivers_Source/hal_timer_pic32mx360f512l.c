
/* Timers HAL Driver Source File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 24/04/2019
 * 
 */

#include "hal_timer_pic32mx360f512l.h"

void hal_config_timer(Timer_TypeDef *Tx, timer_config_t *timer_config)
{
 if(timer_config->timer_type==M_T16)
 {
     Tx->TXCON = 0; //16 bit timer
     Tx->TMRX = 0;
 }
 if(timer_config->timer_type==M_T32) //32 bit timer
 {
     Tx->TXCON = 0;
     (Tx+512)->TXCON = 0; //T2 & T3 base addresses are 512 bytes appart same as T4 & T5
     Tx->TMRX = 0;
     (Tx+512) -> TMRX = 0;

 }
 hal_config_timer_T32(Tx, timer_config->timer_type);
 hal_config_timer_TCS(Tx, timer_config->timer_clock_source);
 hal_config_timer_pre_scalar(Tx, timer_config->timer_pre_scalar);
 hal_timer_write_PR(Tx,timer_config->timer_period);
 hal_timer_write_TMR(Tx, timer_config->timer_start_value);
 hal_timer_clear_it_flag(timer_config->timer_number);
 hal_config_timer_on_off(Tx, timer_config->timer_on_off);
 return;
}

void hal_config_timer_pre_scalar(Timer_TypeDef *Tx, uint8_t pre_scalar)
{

   
     (Tx->TXCON) |= (pre_scalar << 4);
   return;
}

void hal_config_timer_T32(Timer_TypeDef *Tx, mode_sel_t timer_type)
{
    if(timer_type == M_T32)
    {
        (Tx->TXCONSET) |= Timer_T32;
    }
    else if(timer_type == M_T16)
    {
        (Tx->TXCONCLR) |= Timer_T32;
    }
    return;
}

void hal_config_timer_TCS(Timer_TypeDef *Tx, mode_sel_t clock_source)
{
    if(clock_source == M_PBC)
    {
        (Tx->TXCONCLR) |= Timer_TCS; //internal clock
    }
    else if(clock_source == M_EXTC)
    {
        (Tx->TXCONSET) |= Timer_TCS; //external clock
    }
return;

}

void hal_timer_write_PR(Timer_TypeDef *Tx, uint32_t period)
{
    (Tx->PRX) = period;

return;
}

void hal_timer_write_TMR(Timer_TypeDef *Tx, uint32_t value)
{
    (Tx->TMRX) = value;
    return;
}

uint32_t hal_timer_read_TMR(Timer_TypeDef *Tx)
{
    uint32_t timer_value;
    timer_value = (Tx -> TMRX);
    return timer_value;

}
void hal_config_timer_on_off(Timer_TypeDef *Tx, mode_sel_t value)
{
    if(value == M_ON)
        (Tx->TXCONSET) |= Timer_ON_OFF;
    else if(value == M_OFF)
        (Tx -> TXCONCLR) |= Timer_ON_OFF;
    return;
}

void hal_config_timer_it(timer_config_it_t *timer_config_it)
{
    if((timer_config_it->timer_no) == timer_T1)
    {
        (ITFS->IFS0CLR) |= T1_IF;
        (ITIPC -> IPC1X) |= (timer_config_it->intr_sub_priority);
        (ITIPC -> IPC1X) |= ((timer_config_it->intr_priority) << 2);
        if((timer_config_it->intr_enable_disable)== M_ENABLE)
            (ITIEC->IEC0SET) |= T1_IE;
        else
            (ITIEC->IEC0CLR) |= T1_IE;

   }

    else if((timer_config_it->timer_no) == timer_T2)
    {
        (ITFS->IFS0CLR) |= T2_IF;
        (ITIPC -> IPC2X) |= (timer_config_it->intr_sub_priority);
        (ITIPC -> IPC2X) |= ((timer_config_it->intr_priority) << 2);
        if((timer_config_it->intr_enable_disable)== M_ENABLE)
            (ITIEC->IEC0SET) |= T2_IE;
        else
            (ITIEC->IEC0CLR) |= T2_IE;

    }

    else if((timer_config_it->timer_no) == timer_T3)
    {
        (ITFS->IFS0CLR) |= T3_IF;
        (ITIPC -> IPC3X) |= (timer_config_it->intr_sub_priority);
        (ITIPC -> IPC3X) |= ((timer_config_it->intr_priority) << 2);
        if((timer_config_it->intr_enable_disable)== M_ENABLE)
            (ITIEC->IEC0SET) |= T3_IE;
        else
            (ITIEC->IEC0CLR) |= T3_IE;

 }

    else if((timer_config_it->timer_no) == timer_T4)
    {
        (ITFS->IFS0CLR) |= T4_IF;
        (ITIPC -> IPC4X) |= (timer_config_it->intr_sub_priority);
        (ITIPC -> IPC4X) |= ((timer_config_it->intr_priority) << 2);
        if((timer_config_it->intr_enable_disable)== M_ENABLE)
            (ITIEC->IEC0SET) |= T4_IE;
        else
            (ITIEC->IEC0CLR) |= T4_IE;

 }
    else if((timer_config_it->timer_no) == timer_T5)
    {
        (ITFS->IFS0CLR) |= T4_IF;
        (ITIPC -> IPC5X) |= (timer_config_it->intr_sub_priority);
        (ITIPC -> IPC5X) |= ((timer_config_it->intr_priority) << 2);
        if((timer_config_it->intr_enable_disable)== M_ENABLE)
            (ITIEC->IEC0SET) |= T5_IE;
        else
            (ITIEC->IEC0CLR) |= T5_IE;

 }
return;
}

void hal_config_timer_it_EI(timer_sel_t timer_no, mode_sel_t enable_disable)
{
 if(timer_no == timer_T1)
    {
        (ITFS->IFS0CLR) |= T1_IF;
        if(enable_disable == M_ENABLE)
            (ITIEC->IEC0SET) |= T1_IE;
        else
            (ITIEC->IEC0CLR) |= T1_IE;

   }

 else if(timer_no == timer_T2)
    {
        (ITFS->IFS0CLR) |= T2_IF;
        if(enable_disable == M_ENABLE)
            (ITIEC->IEC0SET) |= T2_IE;
        else
            (ITIEC->IEC0CLR) |= T2_IE;

   }

 else if(timer_no == timer_T3)
    {
        (ITFS->IFS0CLR) |= T3_IF;
        if(enable_disable == M_ENABLE)
            (ITIEC->IEC0SET) |= T3_IE;
        else
            (ITIEC->IEC0CLR) |= T3_IE;

   }

 else if(timer_no == timer_T4)
    {
        (ITFS->IFS0CLR) |= T4_IF;
        if(enable_disable == M_ENABLE)
            (ITIEC->IEC0SET) |= T4_IE;
        else
            (ITIEC->IEC0CLR) |= T4_IE;

   }
 else if(timer_no == timer_T5)
    {
        (ITFS->IFS0CLR) |= T5_IF;
        if(enable_disable == M_ENABLE)
            (ITIEC->IEC0SET) |= T5_IE;
        else
            (ITIEC->IEC0CLR) |= T5_IE;

   }

return;
}

void hal_timer_clear_it_flag(timer_sel_t timer_no)
{
   if(timer_no == timer_T1)

        (ITFS->IFS0CLR) |= T1_IF;
    if(timer_no == timer_T2)

        (ITFS->IFS0CLR) |= T2_IF;

    if(timer_no == timer_T3)

        (ITFS->IFS0CLR) |= T3_IF;

 if(timer_no == timer_T4)

        (ITFS->IFS0CLR) |= T4_IF;

    if(timer_no == timer_T5)

        (ITFS->IFS0CLR) |= T5_IF;
if(timer_no == timer_T23)

        (ITFS->IFS0CLR) |= T3_IF;
   if(timer_no == timer_T45)

        (ITFS->IFS0CLR) |= T5_IF;
return;
}