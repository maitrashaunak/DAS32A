/* I2C HAL Driver Header File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 11/04/2019
 * The master mode APIs are implemented
 * Interrupts not used
 * //////////////////////////////////////////////////////////////////////////
 * Important Note: The Base address of I2C1 & I2C2 are wrong in the header file \
 * p32mx360f512l.h in /opt/microchip/mplabc32/v2.01/pic32mx/include/proc
 * Change these two address as under:
 * #define _I2C1_BASE_ADDRESS                       0xBF805000
 * #define _I2C2_BASE_ADDRESS                       0xBF805200
 *  /////////////////////////////////////////////////////////////////////////////
 */

#include <p32xxxx.h>
#include <stdint.h>

#define __IO 	volatile
///Properly define the following FCY & PBCLK values/////////
#define FCY	72000000UL
#define PBCLK	36000000UL
/*
FSCK = Required Clock frequency (100KHz or 400 KHz etc).
I2CBRG = (PBCLK / (2 *FSCK)) - 2; //value to load into I2CBRG register
*/

typedef enum
{
	I2C_M_ON,
	I2C_M_OFF,
	I2C_M_ENABLE,
	I2C_M_DISABLE,
    	I2C_M_SET,
    	I2C_M_RESET,
	I2C_M_MASTER,
	I2C_M_SLAVE
}i2c_mode_sel_t;

typedef struct
{
  __IO uint32_t I2CCON;        			/*!< I2C control register 1                    Address offset: 0x00 */
  __IO uint32_t I2CCONCLR;    			 /*!< I2C control clear register,            Address offset: 0x04 */
  __IO uint32_t I2CCONSET;    			 /*!< I2C control set register,             Address offset: 0x08 */
  __IO uint32_t I2CCONINV;    			     /*!< I2C control invert,                   Address offset: 0x0C */
  __IO uint32_t I2CSTAT;     			 /*!< I2C Status register,  Address offset: 0x10 */
  __IO uint32_t I2CSTATCLR;     			/*!< I2C status clear,  Address offset: 0x14 */
  __IO uint32_t I2CSTATSET;     				/*!< I2C status set, Address offset: 0x18 */
  __IO uint32_t I2CSTATINV;    			/*!< I2C status invert,  Address offset: 0x1C */
  __IO uint32_t I2CADD;   				 /*!< I2C Slave Address, Address offset: 0x20 */
  __IO uint32_t I2ADDCLR;    /*!< I2C Slave Address clear  Address offset: 0x24 */
  __IO uint32_t I2CADDSET;    /*!< I2C Slave Address set, Address offset: 0x28 */
  __IO uint32_t I2CADDINV;    /*!< I2C SlaveAddress invert,Address offset: 0x2C */
  __IO uint32_t I2CMSK; 	   /*!< I2C Slave Addresss Mask,Address offset: 0x30 */
  __IO uint32_t I2CMSKCLR;   	 /*!< I2C Mask clear, Address offset: 0x34 */
  __IO uint32_t I2CMSKSET;    /*!< I2C Mask set,  Address offset: 0x38 */
  __IO uint32_t I2CMSKINV;    /*!< I2C Mask invert,  Address offset: 0x3C */
  __IO uint32_t I2CBRG;		 /*!< I2C Baud Rate Generator, Address offset: 0x40*/
  __IO uint32_t I2CBRGCLR;		 /*!< I2C Baud Rate Generator Clear, Address offset: 0x44*/	
  __IO uint32_t I2CBRGSET;		 /*!< I2C Baud Rate Generator set, Address offset: 0x48*/
  __IO uint32_t I2CBRGINV;		 /*!< I2C Baud Rate Generator invert,Address offset: 0x4c*/	
  __IO uint32_t I2CTRN;		 /*!< I2C Transmit register,Address offset: 0x50*/
  __IO uint32_t I2CTRNCLR;		 /*!< I2C Transmit Clear, Address offset: 0x54*/	
  __IO uint32_t I2CTRNSET;		 /*!< I2C Transmit set, Address offset: 0x58*/
  __IO uint32_t I2CTRNINV;		 /*!< I2C Transmit invert, Address offset: 0x5c*/
  __IO uint32_t I2CRCV;		 /*!< I2C Receive register, Address offset: 0x60*/	
}I2C_TypeDef;

typedef struct
{
	uint32_t	i2c_brg;
	i2c_mode_sel_t	i2c_on_off;
}i2c_config_t;	



#define I2C1                		((I2C_TypeDef *) _I2C1_BASE_ADDRESS)
#define I2C2                		((I2C_TypeDef *) _I2C2_BASE_ADDRESS)
/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////CONFIGURATION//////////////////////////////////////
#define I2C_ON_OFF                       ((uint32_t) (1<<15)) //On off control of i2c module
#define I2C_A10M	                 ((uint32_t) (1<<10)) //10 bit slave address
#define I2C_ACK_DT	                 ((uint32_t) (1<<5)) //ACKDT, 0 for ACK, 1 for NACK
#define I2C_ACK_ENABLE	                 ((uint32_t) (1<<4)) //Start ACK sequence
#define I2C_RC_EN 	                 ((uint32_t) (1<<3)) //Start Receive sequence
#define I2C_P_EN	                 ((uint32_t) (1<<2)) //Start stop sequence
#define I2C_RS_EN	                 ((uint32_t) (1<<1)) //Start Restart sequence
#define I2C_S_EN	                 ((uint32_t) (1<<0)) //Start Start sequence

////////////////////////////////////////STATUS///////////////////////////////////////////
#define I2C_STAT_ACK                        	((uint32_t) (1<<15)) //ACK received status 0=received, 1= not received
#define I2C_STAT_MASTER_TRANSMIT               	((uint32_t) (1<<14)) //Master Transmit Status 1 = Transmit in progress, 0 = no transmit in progress
#define I2C_STAT_BUS_COLLISION                 	((uint32_t) (1<<10)) //Bus Clooision Status 1 = Collision Detected, 0 = no collision
#define I2C_STAT_A10M                       	((uint32_t) (1<<8)) //10 bit address match 1 = matched, 0 = not matched
#define I2C_STAT_WRITE_COLLISION               	((uint32_t) (1<<7)) //Write collision detect 1 = detected module busy,, 0 = no collision
#define I2C_STAT_P                         	((uint32_t) (1<<4)) //Stop bit detect 1 = detected ,, 0 = not detected
#define I2C_STAT_S                         	((uint32_t) (1<<3)) //Start bit detect 1 = detected ,, 0 = not detected
#define I2C_STAT_RBF                        	((uint32_t) (1<<1)) //Receive buffer Status 1 = buffeer full, 0 = empty
#define I2C_STAT_TBF			    	((uint32_t) (1<<0)) //Transmit buffer status 1= transmit in progress, 0 = transmit over 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////APIs/////////////////////////////////////////////////////////////////////

void hal_config_i2c(I2C_TypeDef *I2Cx, i2c_config_t *i2c_config);
void hal_config_i2c_brg(I2C_TypeDef *I2Cx, uint32_t value);
void hal_config_i2c_on_off(I2C_TypeDef *I2Cx,i2c_mode_sel_t value);
uint32_t hal_i2c_read(I2C_TypeDef *I2Cx, uint16_t slave_address_write,uint16_t slave_address_read,  uint16_t memory_address_read);
uint32_t hal_i2c_write(I2C_TypeDef *I2Cx, uint16_t slave_address_write, uint16_t memory_address_write, uint8_t data);
uint32_t hal_i2c_put_data(I2C_TypeDef *I2Cx, uint8_t data);
uint32_t hal_i2c_get_gata(I2C_TypeDef *I2Cx);
uint8_t hal_i2c_send_start(I2C_TypeDef *I2Cx);
uint8_t hal_i2c_send_stop(I2C_TypeDef *I2Cx);
uint8_t hal_i2c_send_restart(I2C_TypeDef *I2Cx);
uint8_t hal_i2c_send_ack(I2C_TypeDef *I2Cx);
uint8_t hal_i2c_send_nack(I2C_TypeDef *I2Cx);
uint8_t hal_i2c_enable_receive(I2C_TypeDef *I2Cx);
uint8_t hal_i2c_check_ack_status(I2C_TypeDef *I2Cx);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



