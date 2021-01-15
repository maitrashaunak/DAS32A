/* SPI HAL Driver Source File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 25/03/2019
 */

#include "hal_spi_pic32mx360f512l.h"

void hal_config_spi_master_slave(SPI_TypeDef *SPIx, mode_sel_t value)
{
    if(value==MASTER)
        (SPIx->SPICONSET) |= SPI_MSTEN;
    else if(value==SLAVE)
        (SPIx->SPICONCLR) |= SPI_MSTEN;
}

void hal_config_spi_mode(SPI_TypeDef *SPIx, uint32_t mode)
{
    switch(mode){
        case 0: 
            (SPIx->SPICONCLR) |= SPI_CKP;
            (SPIx->SPICONSET) |= SPI_CKE; //CKE is  invert of Clock Phase
            break;
        case 1:
            (SPIx->SPICONCLR) |= SPI_CKP;
            (SPIx->SPICONCLR) |= SPI_CKE;
            break;
        case 2:
            (SPIx->SPICONSET) |= SPI_CKP;
            (SPIx->SPICONSET) |= SPI_CKE;
            break;
       
        case 3:   
            (SPIx->SPICONSET) |= SPI_CKP;
            (SPIx->SPICONCLR) |= SPI_CKE;
            break;
        default:
            (SPIx->SPICONCLR) |= SPI_CKP; //mode 0 is default
            (SPIx->SPICONSET) |= SPI_CKE; //CKE is  invert of Clock Phase
}
}

void hal_config_spi_brg(SPI_TypeDef *SPIx, uint32_t value)
{
    (SPIx->SPIBRG) = value;
}

void hal_config_spi_sdo_enable_disable(SPI_TypeDef *SPIx, mode_sel_t value)
{
    if(value==SDO_ENABLE)
        (SPIx->SPICONCLR)  |= SPI_ENABLE_DISABLE_SDO;
    else if(value==SDO_DISABLE)
        (SPIx->SPICONSET) |= SPI_ENABLE_DISABLE_SDO;
    
}
void hal_config_spi_sdi_enable_disable(SPI_TypeDef *SPIx, mode_sel_t value)
{
    if(value==SDI_ENABLE)
        (SPIx->SPICONCLR)  |= SPI_ENABLE_DISABLE_SDI;
    else if(value==SDI_DISABLE)
        (SPIx->SPICONSET) |= SPI_ENABLE_DISABLE_SDI;
}
void hal_config_spi_smp_set_reset(SPI_TypeDef *SPIx, mode_sel_t value)
{
    if(value==SET)
        (SPIx->SPICONSET) |= SPI_SMP;
    else if(value==RESET)
        (SPIx->SPICONCLR) |= SPI_SMP;
}

void hal_config_spi_on_off(SPI_TypeDef *SPIx, mode_sel_t value)
{
    if(value==ON)
        (SPIx->SPICONSET) |= SPI_ON_OFF;
    else if(value==OFF)
        (SPIx->SPICONCLR) |= SPI_ON_OFF;
}  
uint32_t hal_write_read_spi(SPI_TypeDef *SPIx, uint32_t value)
{
 (SPIx->SPIBUF) = value;
 while(!((SPIx->SPISTAT) & SPI_STATUS_RBF)); //wait till bit_0 is set
 return (SPIx->SPIBUF);
}

void _hal_config_spi(SPI_TypeDef *SPIx, spi_config_t *spi_config)
{
  hal_config_spi_master_slave(SPIx, spi_config->spi_master_slave);  
  hal_config_spi_mode(SPIx, spi_config->spi_mode);  
  hal_config_spi_brg(SPIx, spi_config->spi_brg);
  hal_config_spi_sdo_enable_disable(SPIx, spi_config->spi_sdo_enable_disable);
  hal_config_spi_sdi_enable_disable(SPIx, spi_config->spi_sdi_enable_disable);
  hal_config_spi_smp_set_reset(SPIx, spi_config->spi_smp_set_reset);  
  hal_config_spi_on_off(SPIx, spi_config->spi_on_off);
}
