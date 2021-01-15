
/* I2C HAL Driver Source File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 11/04/2019
 * The master mode APIs are implemented
 * Interrupts not used
 * Delayus(100) is called from LCDlib.c for delay requirement.
 */

#include "hal_i2c_pic32mx360f512l.h"
#include "LCD.h" //for 100ms delay only--> Delayus(100) is used here.

void hal_config_i2c(I2C_TypeDef *I2Cx, i2c_config_t *i2c_config)
{
 hal_config_i2c_brg(I2Cx, i2c_config->i2c_brg);
 hal_config_i2c_on_off(I2Cx, i2c_config->i2c_on_off);
}

void hal_config_i2c_brg(I2C_TypeDef *I2Cx, uint32_t value)
{
    (I2Cx -> I2CBRG) = value;
}
void hal_config_i2c_on_off(I2C_TypeDef *I2Cx, i2c_mode_sel_t value)
{
    if(value== I2C_M_ON)
        (I2Cx -> I2CCONSET) |= I2C_ON_OFF;
    else if(value== I2C_M_OFF)
        (I2Cx -> I2CCONCLR) |= I2C_ON_OFF;
}

uint8_t hal_i2c_send_start(I2C_TypeDef *I2Cx)
{
    //check the P bit to ensure bus idle
    while((I2Cx->I2CSTAT) & I2C_STAT_MASTER_TRANSMIT); //wait for bus idle
    (I2Cx->I2CCONSET) |= I2C_S_EN; //set the bit high
    while((I2Cx->I2CCON) & I2C_S_EN); //wait untill goes low
    return 0;
}


uint8_t hal_i2c_send_stop(I2C_TypeDef *I2Cx)
{
    while((I2Cx->I2CSTAT) & I2C_STAT_MASTER_TRANSMIT); //wait for bus idle
    (I2Cx->I2CCONSET) |= I2C_P_EN;
    while((I2Cx->I2CCON) & I2C_P_EN);
    return 0;
}


uint8_t hal_i2c_send_restart(I2C_TypeDef *I2Cx)
{
    while((I2Cx->I2CSTAT) & I2C_STAT_MASTER_TRANSMIT); //wait for bus idle
    (I2Cx->I2CCONSET) |= I2C_RS_EN;
    while((I2Cx->I2CCON) & I2C_RS_EN);
    return 0;
}


uint8_t hal_i2c_send_ack(I2C_TypeDef *I2Cx)
{
while((I2Cx->I2CSTAT) & I2C_STAT_MASTER_TRANSMIT); //wait for bus idle
(I2Cx->I2CCONCLR) |= I2C_ACK_DT;
(I2Cx->I2CCONSET) |= I2C_ACK_ENABLE;
while((I2Cx->I2CCON) & I2C_ACK_ENABLE);
return 0;

}

uint8_t hal_i2c_send_nack(I2C_TypeDef *I2Cx)
{
while((I2Cx->I2CSTAT) & I2C_STAT_MASTER_TRANSMIT); //wait for bus idle
(I2Cx->I2CCONSET) |= I2C_ACK_DT;
Nop();
Nop();
(I2Cx->I2CCONSET) |= I2C_ACK_ENABLE;
Nop();
Nop();
while((I2Cx->I2CCON) & I2C_ACK_ENABLE);
return 0;
}

uint8_t hal_i2c_enable_receive(I2C_TypeDef *I2Cx)
{
    while((I2Cx->I2CCON) & 0x0000001f);
    (I2Cx->I2CCONSET) |= I2C_RC_EN;
 
    return 0;
}

uint8_t hal_i2c_check_ack_status(I2C_TypeDef *I2Cx)
{
     return ((I2Cx->I2CSTAT) & I2C_STAT_ACK); //0 for ack & 1 for no ack
        
}

uint32_t hal_i2c_put_data(I2C_TypeDef *I2Cx,uint8_t data)
{
 while((I2Cx->I2CSTAT) & I2C_STAT_MASTER_TRANSMIT); //wait for bus idle
 (I2Cx->I2CTRN) = data;
 while((I2Cx->I2CSTAT) & I2C_STAT_TBF);
 return 0;
 }

uint32_t hal_i2c_get_gata(I2C_TypeDef *I2Cx)
{
    hal_i2c_enable_receive(I2Cx);
    while(!((I2Cx->I2CSTAT)& I2C_STAT_RBF));
    Delayus(100);
    return(I2Cx->I2CRCV);
}


uint32_t hal_i2c_write(I2C_TypeDef *I2Cx, uint16_t slave_address_write, uint16_t memory_address_write,uint8_t data)
{
    hal_i2c_send_start(I2Cx);
    //hal_i2c_put_data(I2Cx,(slave_address_write>>8)); //in case of 10 bit slave address
    // Delayus(100);
   // while(hal_i2c_check_ack_status(I2Cx));
    hal_i2c_put_data(I2Cx,(slave_address_write & 0x00ff));
    Delayus(100);
    while(hal_i2c_check_ack_status(I2Cx));
    
     //hal_i2c_put_data(I2Cx,(memory_address_write>>8)); //in case of 16 bit memory address
     //Delayus(100);
    //while(hal_i2c_check_ack_status(I2Cx));
    hal_i2c_put_data(I2Cx,(memory_address_write & 0x00ff));
      Delayus(100);
    while(hal_i2c_check_ack_status(I2Cx));
   
    hal_i2c_put_data(I2Cx,data);
      Delayus(100);
    while(hal_i2c_check_ack_status(I2Cx));
    
    hal_i2c_send_stop(I2Cx);
    
    return 0;
}

uint32_t hal_i2c_read(I2C_TypeDef *I2Cx, uint16_t slave_address_write, uint16_t slave_address_read, uint16_t memory_address_read)
{
    uint8_t received_data;
   hal_i2c_send_start(I2Cx);
    //hal_i2c_put_data(I2Cx,(slave_address_write>>8)); //in case of 10 bit slave address
    //Delayus(100);
   // while(hal_i2c_check_ack_status(I2Cx));
    hal_i2c_put_data(I2Cx,(slave_address_write & 0x00ff));
      Delayus(100);
    while(hal_i2c_check_ack_status(I2Cx));
     //hal_i2c_put_data(I2Cx,(memory_address_read>>8)); //in case of 16 bit memory address
     //Delayus(100);
    //while(hal_i2c_check_ack_status(I2Cx));
    hal_i2c_put_data(I2Cx,(memory_address_read & 0x00ff));
      Delayus(100);
    while(hal_i2c_check_ack_status(I2Cx));
      hal_i2c_send_restart(I2Cx);
     //hal_i2c_put_data(I2Cx,(slave_address_read>>8)); //in case of 10 bit slave address
    //Delayus(100);
      // while(hal_i2c_check_ack_status(I2Cx));
    hal_i2c_put_data(I2Cx,(slave_address_read & 0x00ff));
      Delayus(100);
    while(hal_i2c_check_ack_status(I2Cx));
   received_data = hal_i2c_get_gata(I2Cx);
     Delayus(100);
    hal_i2c_send_nack(I2Cx);
    hal_i2c_send_stop(I2Cx);
    return received_data;
}