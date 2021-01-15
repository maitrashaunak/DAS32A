/* LCD Library LCDlib.c */
#include<p32xxxx.h>
#include<plib.h>
//#include<explorer.h>
#include "LCD.h"
#define PMDATA PMDIN

void Delayms(unsigned t);
void Delayus(unsigned b);
void initLCD(void)
{
mPMPOpen(PMP_ON|PMP_READ_WRITE_EN|3,
			PMP_DATA_BUS_8|PMP_MODE_MASTER1|PMP_WAIT_BEG_4|PMP_WAIT_MID_15|
			PMP_WAIT_END_4,
			0x0001,
			PMP_INT_OFF);
Delayms(30);
//Initiate the HD44780 display 8-bit init sequence
PMPSetAddress(LCDCMD); // select command register

PMPMasterWrite(0x38);  //8-bit int 2 lines, 5X7
Delayms(1);				// >48 us

PMPMasterWrite(0x0f);	// On No cursor  blink
Delayms(1);				// >48 us

PMPMasterWrite(0x01);	// clear display
Delayms(2);				// >1.6 ms

PMPMasterWrite(0x06);	// increment cursor no shift
Delayms(2);				// >1.6 ms
PMPMasterWrite(0x80);	// increment cursor no shift
Delayms(2);
}		// initLCD
void initLCDNoBlink(void)  // init lcd with out blinking cursor
{
mPMPOpen(PMP_ON|PMP_READ_WRITE_EN|3,
			PMP_DATA_BUS_8|PMP_MODE_MASTER1|PMP_WAIT_BEG_4|PMP_WAIT_MID_15|
			PMP_WAIT_END_4,
			0x0001,
			PMP_INT_OFF);
Delayms(30);
//Initiate the HD44780 display 8-bit init sequence
PMPSetAddress(LCDCMD); // select command register

PMPMasterWrite(0x38);  //8-bit int 2 lines, 5X7
Delayms(1);				// >48 us

PMPMasterWrite(0x0c);	// On No cursor no blink
Delayms(1);				// >48 us

PMPMasterWrite(0x01);	// clear display
Delayms(2);				// >1.6 ms

PMPMasterWrite(0x06);	// increment cursor no shift
Delayms(2);				// >1.6 ms
PMPMasterWrite(0x80);	// increment cursor no shift
Delayms(2);
}		// initLCDNoBlink

char readLCD(int addr)
{
	PMPSetAddress(addr);		//select register
	mPMPMasterReadByte();		// initiate read sequence
	return mPMPMasterReadByte();	//read actual data
}		//readLCD

void writeLCD(int addr, char c)
{
	while(busyLCD());
	PMPSetAddress(addr);
	PMPMasterWrite(c);
}	// writeLCD

void putsLCD(char *s)
{
	char c;
	while(*s)
	{
		switch(*s)
		{
			case '\n':
			setLCDC(0x40);	//point to second line
			break;
			case '\r':
			setLCDC(0);		// home point to first line
			case '\t':
			c=addrLCD();	//advance next tab (8) positions
			while(c & 7)
			{
				putLCD(' ');
				c++;
			}
			if(c>20)
			setLCDC(0x40);	//if necessary move to second line
			break;
			default:
			putLCD(*s);		// print character
			break;
		}//switch
		s++;
	}//while	
}//putsLCD
void putsLCD4(char *s)
{
    while(*s)
        putLCD(*s++);
}


	
void Delayms(unsigned t)
{
	T1CON=0x8000;
	while(t--)
	{
		TMR1=0;
		while(TMR1<36000000L/1000);
	}// timer

}// Delayms
	
	
  
  void Delayus(unsigned t)
 {
   T1CON = 0x8030;
    while(t--)

    {
       TMR1=0;
     while(TMR1<1);

    }
 }
