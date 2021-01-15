#include <p32xxxx.h>
#include <serial.h>
#define U2CTS _RF12
#define U2RTS _RF13
#define U2TRTS TRISFbits.TRISF13
//#define TCTS TRISFbits.TRISF12
#define U2BRATE 15 //562.5K
#define U_ENABLE 0x8008
#define U_TX 0x1400
#define U1CTS _RD14
#define U1RTS _RD15
#define U1TRTS TRISDbits.TRISD15
#define TCTS TRISFbits.TRISF12
#define U1BRATE 17 //500K baud rate



void initU1(void)
{
U1BRG = U1BRATE;
U1MODE = U_ENABLE;
U1STA = U_TX;
U1TRTS = 0;
//TCTS = 1;
U1RTS = 0;
} // initU2

int putU1(int c)  //before comming here, check for CTS low
{
while(U1CTS);
while(U1STAbits.UTXBF);
U1TXREG = c;
return c;
} //putU2



char getU1(void)
{
 U1RTS = 0;
 while(!U1STAbits.URXDA);
   U1RTS=1;
return U1RXREG;
} //getU2

int U1puts(const char *s)
{
while(*s)
putU1(*s++);
putU1('\r');

}



char *getsnU1(char *s, int len)
{
char *p = s;
do
{
*s=getU1();
if(*s=='\r')
break;
s++;
len--;
}while(len>1);
*s='\0';
return p;
}



void initU2(void)
{
U2BRG = U2BRATE;
U2MODE = U_ENABLE;
U2STA = U_TX;
U2TRTS = 0;
//TCTS = 1;
U2RTS = 0;
} // initU2

int putU2(int c)  //before comming here, check for CTS low
{
while(U2CTS);
while(U2STAbits.UTXBF);
U2TXREG = c;
return c;
} //putU2

char getU2(void)
{
/*int count = 0;
RTS = 0;
do
{
Delayms(1);
count++;
if(count>10000) goto PT1;
} while(!U2STAbits.URXDA);
PT1:RTS=1;
return U2RXREG;*/
    U2RTS = 0;
   while(!U2STAbits.URXDA);
   U2RTS=1;
return U2RXREG;
} //getU2

int puts(const char *s)
{
while(*s)
putU2(*s++);
putU2('\r');

}

char *getsn(char *s, int len)
{
char *p = s;
do
{
*s=getU2();
if(*s=='\r')
break;
s++;
len--;
}while(len>1);
*s='\0';
return p;
}



