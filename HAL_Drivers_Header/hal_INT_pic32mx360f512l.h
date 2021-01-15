
///////////////////////////////////////////////////////////////////////////
/* I2C EXTERNAL INTERRUPT (INT) Driver Header File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 03/07/2019
 * 
 * //////////////////////////////////////////////////////////////////////////
 *
 */


#include <stdint.h>
#include "hal_it_pic32mx360f512l.h"

#define __IO 	volatile
///Properly define the following FCY & PBCLK values/////////
#define FCY	72000000UL
#define PBCLK	36000000UL


typedef enum
{
        EXT_INT_0,
        EXT_INT_1,
        EXT_INT_2,
        EXT_INT_3,
        EXT_INT_4,
        EXT_INT_RISING_EDGE,
        EXT_INT_FALLING_EDGE,
        EXT_INT_M_ENABLE,
	EXT_INT_M_DISABLE,
    	
}ext_int_mode_sel_e;


typedef struct
{
    ext_int_mode_sel_e     ext_int_no; //interrupt number
    ext_int_mode_sel_e     edge_selection; //rising or falling edge
    ext_int_mode_sel_e      ext_intr_enable_disable; //enable/disable interrupt
    uint8_t      ext_int_priority; //<28:26> of IPCx //prority range 0 to 7
    uint8_t      ext_int_sub_priority; // <25:24> of IPCx //sub priority range 0 to 3
}ext_int_config_t;




/////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////CONFIGURATION//////////////////////////////////////
#define EXT_INT_0_ENABLE                 ((uint32_t) (1<<3)) //On off control of inturrpt0 module reg->IEC0
#define EXT_INT_1_ENABLE                 ((uint32_t) (1<<7)) //On off control of inturrpt1 module reg->IEC0
#define EXT_INT_2_ENABLE                 ((uint32_t) (1<<11)) //On off control of inturrpt2 module reg->IEC0
#define EXT_INT_3_ENABLE                 ((uint32_t) (1<<15)) //On off control of inturrpt3 module reg->IEC0
#define EXT_INT_4_ENABLE                 ((uint32_t) (1<<19)) //On off control of inturrpt4 module reg->IEC0

#define EXT_INT_0_FLAG                 ((uint32_t) (1<<3)) //On off control of inturrpt0 module reg->IFS0
#define EXT_INT_1_FLAG                 ((uint32_t) (1<<7)) //On off control of inturrpt1 module reg->IFS0
#define EXT_INT_2_FLAG                 ((uint32_t) (1<<11)) //On off control of inturrpt2 module reg->IFS0
#define EXT_INT_3_FLAG                 ((uint32_t) (1<<15)) //On off control of inturrpt3 module reg->IFS0
#define EXT_INT_4_FLAG                 ((uint32_t) (1<<19)) //On off control of inturrpt4 module reg->IFS0





////////////////////////////////////////////////APIs/////////////////////////////////////////////////////////////////////

void hal_config_ext_int(ext_int_config_t *ext_int_config);
void hal_clear_ext_int_flag(ext_int_mode_sel_e ext_int_number);
void hal_config_ext_int_edge_select(ext_int_mode_sel_e ext_int_number,ext_int_mode_sel_e edge_select);
void hal_config_ext_int_enable_disable(ext_int_mode_sel_e ext_int_number,ext_int_mode_sel_e enable_disable);
void hal_config_ext_int_prority(ext_int_mode_sel_e ext_int_number,uint8_t priority_value);
void hal_config_ext_int_sub_prority(ext_int_mode_sel_e ext_int_number,uint8_t sub_priority_value);


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//ISR CALL....
//void __ISR(_EXTERNAL_0_VECTOR ,ipl1) INT0InterruptHandeler(void)
//ALL THE VECTOR NUMBERS/DEFINITIONS ARE AVAILABLE IN DEVICE SPECIFIC HEADER FILE


