/* SPI HAL Driver Header File for pic32MX
 * Created by: Shaunak Maitra
 * Date: 25/03/2019
 */

#include <p32xxxx.h>
#include <stdint.h>

#define __IO 	volatile



typedef enum
{
	ON,
	OFF,
	ENABLE,
	DISABLE,
    	SET,
    	RESET,        
	MASTER,
	SLAVE,
	SDI_ENABLE,
	SDI_DISABLE,
	SDO_ENABLE,
	SDO_DISABLE
}mode_sel_t;




typedef struct
{
  __IO uint32_t SPICON;        /*!< SPI control register 1                    Address offset: 0x00 */
  __IO uint32_t SPICONCLR;        /*!< SPI control clear register,            Address offset: 0x04 */
  __IO uint32_t SPICONSET;         /*!< SPI control set register,             Address offset: 0x08 */
  __IO uint32_t SPICONINV;         /*!< SPI control invert,                   Address offset: 0x0C */
  __IO uint32_t SPISTAT;      /*!< SPI Status register						  Address offset: 0x10 */
  __IO uint32_t SPISTATCLR;     /*!< SPI status clear				         Address offset: 0x14 */
  __IO uint32_t SPISTATSET;     /*!< SPI status set					       Address offset: 0x18 */
  __IO uint32_t SPISTATINV;    /*!< SPI status invert,                     Address offset: 0x1C */
  __IO uint32_t SPIBUF;    /*!< SPI Buffer				,                     Address offset: 0x20 */
  __IO uint32_t Dummy_SPIBUFCLR;    /*!< SPI Buffer	clear,dummy reg,,not present  Address offset: 0x24 */
  __IO uint32_t Dummy_SPIBUFSET;    /*!< SPI Buffer	set, dummy               Address offset: 0x28 */
  __IO uint32_t Dummy_SPIBUFINV;    /*!< SPI Buffer invert, dummy            Address offset: 0x2C */
  __IO uint32_t SPIBRG;    /*!< SPI Baud Rate Generator,                     Address offset: 0x30 */
  __IO uint32_t SPIBRGCLR;    /*!< SPI Buffer				,                Address offset: 0x34 */
  __IO uint32_t SPIBRGSET;    /*!< SPI Buffer				,                Address offset: 0x38 */
  __IO uint32_t SPIBRGINV;    /*!< SPI Buffer				,                Address offset: 0x3C */
}SPI_TypeDef;

typedef struct
{
	mode_sel_t	spi_master_slave;
	uint32_t	spi_mode;
	uint32_t	spi_brg;
	mode_sel_t	spi_sdo_enable_disable;
	mode_sel_t	spi_sdi_enable_disable;
    mode_sel_t  spi_smp_set_reset;
	mode_sel_t	spi_on_off;
}spi_config_t;	
	

#define SPI1                ((SPI_TypeDef *) _SPI1_BASE_ADDRESS)
#define SPI2                ((SPI_TypeDef *) _SPI2_BASE_ADDRESS)
#define SPI_ON_OFF                      ((uint32_t) (1<<15))
#define SPI_ENABLE_DISABLE_SDO			((uint32_t) (1<<12))
#define SPI_SMP                         ((uint32_t) (1<<9))
#define SPI_CKE                         ((uint32_t) (1<<8))
#define SPI_CKP                         ((uint32_t)(1<<6))
#define SPI_MSTEN                       ((uint32_t) (1<<5))
#define SPI_ENABLE_DISABLE_SDI			((uint32_t) (1<<4))	
#define SPI_STATUS_RBF                  ((uint32_t) (1<<0))


/* Driver Exposed APIs*/

void _hal_config_spi(SPI_TypeDef *SPIx, spi_config_t *spi_config);
void hal_config_spi_master_slave(SPI_TypeDef *SPIx, mode_sel_t value);
void hal_config_spi_mode(SPI_TypeDef *SPIx, uint32_t mode);
void hal_config_spi_brg(SPI_TypeDef *SPIx, uint32_t value);
void hal_config_spi_sdo_enable_disable(SPI_TypeDef *SPIx, mode_sel_t value);
void hal_config_spi_sdi_enable_disable(SPI_TypeDef *SPIx, mode_sel_t value);
void hal_config_spi_smp_set_reset(SPI_TypeDef *SPIx, mode_sel_t value);
void hal_config_spi_on_off(SPI_TypeDef *SPIx, mode_sel_t value);
uint32_t hal_write_read_spi(SPI_TypeDef *SPIx, uint32_t value); 



  
