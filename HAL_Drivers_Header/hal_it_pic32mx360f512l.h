/* INTERRUPTS HAL  Header File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 25/04/2019
 * The Interrupts section are to be used in the specific device driver....
 * //////////////////////////////////////////////////////////////////////////
 * /////////////////////////////////////////////////////////////////////////////
 * The function INTEnableSystemMultiVectoredInt() must be called before
 * configuring the interupt
 */

#include <p32xxxx.h>
#include <stdint.h>

#define __IO 	volatile
///Properly define the following FCY & PBCLK values/////////
//#define FCY	72000000UL
//#define PBCLK	36000000U
#define _INT_BASE_ADDRESS                        0xBF881000
#define _IFS_BASE_ADDRESS                        0xBF881030
#define _IEC_BASE_ADDRESS                        0xBF881060
#define _IPC_BASE_ADDRESS                        0xBF881090
#define BIT_MVEC                                 ((uint32_t) (1<<12)) //enable multivectored interrupt


typedef struct
{
  __IO uint32_t INTCONX;     /*!< Intrrupt control register   Address offset: 0x00 */
  __IO uint32_t INTCONCLR;   /*!<  control clear register,            Address offset: 0x04 */
  __IO uint32_t INTCONSET;   /*!<  control set register,             Address offset: 0x08 */
  __IO uint32_t INTCONINV;   /*!<  control invert,                   Address offset: 0x0C */
 //**********************************************************************************************
  __IO uint32_t INTSTATX;    /*!< Interrupt status register,  Address offset: 0x10 */
  __IO uint32_t dummy_INTSTATSET;
  __IO uint32_t dummy_INTSTATCLEAR;
  __IO uint32_t dummy_INTSTATINV;
  //*******************************************************************************************
  __IO uint32_t IPTMRX;
  __IO uint32_t IPTMRCLR;
  __IO uint32_t IPTMRSET;
  __IO uint32_t IPTMRINV;
//***************************************************************************************
 }ITCS_TypeDef;

typedef struct{
  __IO uint32_t IFS0X;
  __IO uint32_t IFS0CLR;
  __IO uint32_t IFS0SET;
  __IO uint32_t IFS0INV;

  __IO uint32_t IFS1X;
  __IO uint32_t IFS1CLR;
  __IO uint32_t IFS1SET;
  __IO uint32_t IFS1INV;
}IFS_TypeDef;

typedef struct{
  __IO uint32_t IEC0X;
  __IO uint32_t IEC0CLR;
  __IO uint32_t IEC0SET;
  __IO uint32_t IEC0INV;

   __IO uint32_t IEC1X;
  __IO uint32_t IEC1CLR;
  __IO uint32_t IEC1SET;
  __IO uint32_t IEC1INV;

}IEC_TypeDef;

typedef struct{
  __IO uint32_t IPC0X;
  __IO uint32_t IPC0CLR;
  __IO uint32_t IPC0SET;
  __IO uint32_t IPC0INV;

  __IO uint32_t IPC1X;
  __IO uint32_t IPC1CLR;
  __IO uint32_t IPC1SET;
  __IO uint32_t IPC1INV;

  __IO uint32_t IPC2X;
  __IO uint32_t IPC2CLR;
  __IO uint32_t IPC2SET;
  __IO uint32_t IPC2INV;
 __IO uint32_t IPC3X;
  __IO uint32_t IPC3CLR;
  __IO uint32_t IPC3SET;
  __IO uint32_t IPC3INV;

   __IO uint32_t IPC4X;
  __IO uint32_t IPC4CLR;
  __IO uint32_t IPC4SET;
  __IO uint32_t IPC4INV;

   __IO uint32_t IPC5X;
  __IO uint32_t IPC5CLR;
  __IO uint32_t IPC5SET;
  __IO uint32_t IPC5INV;

 __IO uint32_t IPC6X;
  __IO uint32_t IPC6CLR;
  __IO uint32_t IPC6SET;
  __IO uint32_t IPC6INV;
  __IO uint32_t IPC7X;
  __IO uint32_t IPC7CLR;
  __IO uint32_t IPC7SET;
  __IO uint32_t IPC7INV;
 __IO uint32_t IPC8X;
  __IO uint32_t IPC8CLR;
  __IO uint32_t IPC8SET;
  __IO uint32_t IPC8INV;
 __IO uint32_t IPC9X;
  __IO uint32_t IPC9CLR;
  __IO uint32_t IPC9SET;
  __IO uint32_t IPC9INV;
 __IO uint32_t dummy_IPC10X;
  __IO uint32_t dummy_IPC10CLR;
  __IO uint32_t dummy_IPC10SET;
  __IO uint32_t dummy_IPC10INV;

 __IO uint32_t IPC11X;
  __IO uint32_t IPC11CLR;
  __IO uint32_t IPC11SET;
  __IO uint32_t IPC11INV;

}IPC_TypeDef;


#define ITCS              ((ITCS_TypeDef *) _INT_BASE_ADDRESS)
#define ITFS           	  ((IFS_TypeDef *) _IFS_BASE_ADDRESS)
#define ITIEC             ((IEC_TypeDef *) _IEC_BASE_ADDRESS)
#define ITIPC             ((IPC_TypeDef *) _IPC_BASE_ADDRESS)

//Enable multi vectored interrupt macro///////////////////////


