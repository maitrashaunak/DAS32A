
/* EXTRENAL INTERUPT HAL Driver Source File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 04/07/2019
 * 
 */

#include "hal_INT_pic32mx360f512l.h"

void hal_clear_ext_int_flag(ext_int_mode_sel_e ext_int_number)
{
    if(ext_int_number == EXT_INT_0)
        (ITFS->IFS0CLR) |= EXT_INT_0_FLAG;
    if(ext_int_number == EXT_INT_1)
        (ITFS->IFS0CLR) |= EXT_INT_1_FLAG;
     if(ext_int_number == EXT_INT_2)
        (ITFS->IFS0CLR) |= EXT_INT_2_FLAG;
    if(ext_int_number == EXT_INT_3)
        (ITFS->IFS0CLR) |= EXT_INT_3_FLAG;
     if(ext_int_number == EXT_INT_4)
        (ITFS->IFS0CLR) |= EXT_INT_4_FLAG;
   return;
}

void hal_config_ext_int_edge_select(ext_int_mode_sel_e ext_int_number,ext_int_mode_sel_e edge_select)
{
    if(ext_int_number == EXT_INT_0)
    {
        if(edge_select == EXT_INT_FALLING_EDGE)
        (ITCS->INTCONCLR) |=  ((uint32_t) (1<<0));
        else if(edge_select == EXT_INT_RISING_EDGE)
            (ITCS->INTCONSET) |= ((uint32_t)(1<<0));
    }
    
    else if(ext_int_number == EXT_INT_1)
    {
        if(edge_select == EXT_INT_FALLING_EDGE)
        (ITCS->INTCONCLR) |=  ((uint32_t) (1<<1));
        else if(edge_select == EXT_INT_RISING_EDGE)
            (ITCS->INTCONSET) |= ((uint32_t)(1<<1));
    }

    if(ext_int_number == EXT_INT_2)
    {
        if(edge_select == EXT_INT_FALLING_EDGE)
        (ITCS->INTCONCLR) |=  ((uint32_t) (1<<2));
        else if(edge_select == EXT_INT_RISING_EDGE)
            (ITCS->INTCONSET) |= ((uint32_t)(1<<2));
    }

    if(ext_int_number == EXT_INT_3)
    {
        if(edge_select == EXT_INT_FALLING_EDGE)
        (ITCS->INTCONCLR) |=  ((uint32_t) (1<<3));
        else if(edge_select == EXT_INT_RISING_EDGE)
            (ITCS->INTCONSET) |= ((uint32_t)(1<<3));
    }
   if(ext_int_number == EXT_INT_4)
    {
        if(edge_select == EXT_INT_FALLING_EDGE)
        (ITCS->INTCONCLR) |=  ((uint32_t) (1<<4));
        else if(edge_select == EXT_INT_RISING_EDGE)
            (ITCS->INTCONSET) |= ((uint32_t)(1<<4));
    }

}

void hal_config_ext_int_prority(ext_int_mode_sel_e ext_int_number,uint8_t priority_value)
{
  if(ext_int_number == EXT_INT_0)
      (ITIPC->IPC0X) |= (priority_value << 26);
  else if(ext_int_number == EXT_INT_1)
      (ITIPC->IPC1X) |= (priority_value << 26);
  else if(ext_int_number == EXT_INT_2)
      (ITIPC->IPC2X) |= (priority_value << 26);
  else if(ext_int_number == EXT_INT_3)
      (ITIPC->IPC3X) |= (priority_value << 26);
   else if(ext_int_number == EXT_INT_4)
      (ITIPC->IPC4X) |= (priority_value << 26);
  return;
}
void hal_config_ext_int_sub_prority(ext_int_mode_sel_e ext_int_number,uint8_t sub_priority_value)
{
  if(ext_int_number == EXT_INT_0)
      (ITIPC->IPC0X) |= (sub_priority_value << 24);
  else if(ext_int_number == EXT_INT_1)
      (ITIPC->IPC1X) |= (sub_priority_value << 24);
  else if(ext_int_number == EXT_INT_2)
      (ITIPC->IPC2X) |= (sub_priority_value << 24);
  else if(ext_int_number == EXT_INT_3)
      (ITIPC->IPC3X) |= (sub_priority_value << 24);
   else if(ext_int_number == EXT_INT_4)
      (ITIPC->IPC4X) |= (sub_priority_value << 24);
  return;
}
void hal_config_ext_int_enable_disable(ext_int_mode_sel_e ext_int_number,ext_int_mode_sel_e enable_disable)
{
    if(ext_int_number == EXT_INT_0)
    {
        if(enable_disable == EXT_INT_M_ENABLE)
            (ITIEC ->IEC0SET) |= EXT_INT_0_ENABLE;
        else if(enable_disable == EXT_INT_M_DISABLE)
            (ITIEC ->IEC0CLR) |= EXT_INT_0_ENABLE;
    }

if(ext_int_number == EXT_INT_1)
    {
        if(enable_disable == EXT_INT_M_ENABLE)
            (ITIEC ->IEC0SET) |= EXT_INT_1_ENABLE;
        else if(enable_disable == EXT_INT_M_DISABLE)
            (ITIEC ->IEC0CLR) |= EXT_INT_1_ENABLE;
    }

if(ext_int_number == EXT_INT_2)
    {
        if(enable_disable == EXT_INT_M_ENABLE)
            (ITIEC ->IEC0SET) |= EXT_INT_2_ENABLE;
        else if(enable_disable == EXT_INT_M_DISABLE)
            (ITIEC ->IEC0CLR) |= EXT_INT_2_ENABLE;
    }
if(ext_int_number == EXT_INT_3)
    {
        if(enable_disable == EXT_INT_M_ENABLE)
            (ITIEC ->IEC0SET) |= EXT_INT_3_ENABLE;
        else if(enable_disable == EXT_INT_M_DISABLE)
            (ITIEC ->IEC0CLR) |= EXT_INT_3_ENABLE;
    }
  if(ext_int_number == EXT_INT_4)
    {
        if(enable_disable == EXT_INT_M_ENABLE)
            (ITIEC ->IEC0SET) |= EXT_INT_4_ENABLE;
        else if(enable_disable == EXT_INT_M_DISABLE)
            (ITIEC ->IEC0CLR) |= EXT_INT_4_ENABLE;
    }  
    
    return;
    
}

void hal_config_ext_int(ext_int_config_t *ext_int_config)
{
  hal_clear_ext_int_flag(ext_int_config->ext_int_no);
  hal_config_ext_int_edge_select(ext_int_config->ext_int_no,ext_int_config->edge_selection);
  hal_config_ext_int_prority(ext_int_config->ext_int_no, ext_int_config->ext_int_priority);
  hal_config_ext_int_prority(ext_int_config->ext_int_no, ext_int_config->ext_int_sub_priority);
  hal_config_ext_int_enable_disable(ext_int_config->ext_int_no, ext_int_config->ext_intr_enable_disable);

}

// A sample call is as under///////

