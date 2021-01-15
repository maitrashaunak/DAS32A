#include "libSPI.h"
#include "hal_spi_pic32mx360f512l.h"
// send one byte of data & receive one back at the same time

/*int writeSPI2(int i)
{
SPI2BUF = i;
while( !SPI2STATbits.SPIRBF);
return SPI2BUF;
}*/

/*void initSEE(void)
{
CSEE = 1; // deselect the serial eeprom
TCSEE = 0; // make CSEE pin output
SPI2CON = SPI_CONF;	//enable the peripheral
SPI2BRG = SPI_BAUD;     //select clock speed
}*/
void initSEE(void)
{
CSEE = 1; // deselect the serial eeprom
TCSEE = 0; // make CSEE pin output
spi_config_t spi_config;
spi_config.spi_brg = 15;
spi_config.spi_master_slave = MASTER;
spi_config.spi_mode = 0;
spi_config.spi_sdi_enable_disable = SDI_ENABLE;
spi_config.spi_sdo_enable_disable = SDO_ENABLE;
spi_config.spi_smp_set_reset = SET;
spi_config.spi_on_off = ON;
_hal_config_spi(SPI2, &spi_config);
}

int writeSPI2(int i)
{
    uint32_t value_ret;
    value_ret = hal_write_read_spi(SPI2,i);
    return value_ret;
}

int readStatus(void)
{
int i;
CSEE = 0; //select the serial eeprom
writeSPI2(SEE_STAT); // send a read status command
i = writeSPI2(0);	//send/receive
CSEE = 1;	//deselect terminate command
return i;
}

int readSEE(int address) //32 bit value must start from even address as per memory data sheet
{
int i;
while(readStatus() & 0x01);
CSEE = 0;
writeSPI2(SEE_READ);
writeSPI2(address>>8);	//MSB of address
writeSPI2(address & 0xfc);
i = writeSPI2(0); //send dummy, read msb
i = (i<<8) + writeSPI2(0);
i = (i<<8) + writeSPI2(0);
i = (i<<8) + writeSPI2(0); // read 32 bit value
CSEE = 1;
return (i);
}

void writeEnable(void)
{
CSEE = 0;
writeSPI2(SEE_WEN);
CSEE = 1;
}
void writeSEE(int address, int data) //starting from an even address
{
while(readStatus() & 0x01);
writeEnable();
CSEE = 0;
writeSPI2(SEE_WRITE);
writeSPI2(address>>8);
writeSPI2(address & 0xfc);
writeSPI2(data>>24); //msb
writeSPI2(data>>16);
writeSPI2(data>>8);
writeSPI2(data);
CSEE = 1;
}



		

