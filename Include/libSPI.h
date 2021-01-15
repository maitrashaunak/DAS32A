/*libSPI.h*/

#include<p32xxxx.h>

#define CSEE _RD12
#define TCSEE _TRISD12  //select line of serial eeprom
#define SPI_CONF 0x8120  //SPI on, 8 bit master,CKE=1, CKP = 0
//25LC256 serial eeprom commands
#define SEE_WRSR 1 	 // write ststus reg.
#define SEE_WRITE 2 	// write command
#define SEE_READ 3	// read command
#define SEE_WDI 4	// write disable
#define SEE_STAT 5	//read dtatus reg
#define SEE_WEN 6	//write enable
#define SPI_BAUD 15     // clock divider Fpb/(2*(15+1))
int writeSPI2(int i); 
void initSEE(void);
int readStatus(void);
int readSEE(int address);
void writeEnable(void);
void writeSEE(int address, int data);