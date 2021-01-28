/*
 * File:   DAClib.c
 * Author: shaunak
 *
 * Created on December 19, 2011, 12:37 PM
 */


#include <plib.h>
#include <p32xxxx.h>
#define LDAC1 _RD11 // pin 71
#define SDIN1 _RD0 //pin 72
#define SCLK1 _RD9 //pin 69
#define SYNC1 _RA15 //pin 67
#define LDAC2 _RD8 //pin 68
#define SDIN2 _RA14 //pin 66
#define SCLK2 _RD10 //pin 70
#define SYNC2 _RD2 //pin 77
#define LDAC3 _RC4
#define SDIN3 _RC3
#define SCLK3 _RC1
#define SYNC3 _RC2
void FourToTwenty1(float FlowRate, float nomFlowRate, int DigitalMax);
void FourToTwentyDrive1(int value);
void FourToTwenty2(float FlowRate, float nomFlowRate, int DigitalMax);
void FourToTwentyDrive2(int value);
void FourToTwenty3(float FlowRate, float nomFlowRate, int DigitalMax);
void FourToTwentyDrive3(int value);
void writeDAC1(int t);
void writeDAC2(int t);
void writeDAC3(int t);

void  FourToTwenty1 (float FlowRate, float nomFlowRate, int DigitalMax)
{
int DigitalOut;
DigitalOut = (FlowRate*DigitalMax) / nomFlowRate;
if(DigitalOut > 65535)
    DigitalOut = 65535;
writeDAC1(DigitalOut);
Delayus(2);
return;
}
void  FourToTwenty2 (float FlowRate, float nomFlowRate, int DigitalMax)
{
int DigitalOut;
DigitalOut = (FlowRate*DigitalMax)/ nomFlowRate;
if(DigitalOut > 65535)
    DigitalOut = 65535;
writeDAC2(DigitalOut);
Delayus(2);
return;
}
void  FourToTwenty3 (float FlowRate, float nomFlowRate, int DigitalMax)
{
int DigitalOut;
DigitalOut = (FlowRate*DigitalMax)/ nomFlowRate;
if(DigitalOut > 65535)
    DigitalOut = 65535;
writeDAC3(DigitalOut);
Delayus(2);
return;
}
void FourToTwentyDrive1(int value)
{
     int DigitalOut;
    DigitalOut = value;
    if(DigitalOut> 65535)
        DigitalOut = 65535;
    writeDAC1(DigitalOut);
    return;

}
void FourToTwentyDrive2(int value)
{
    int DigitalOut;
    DigitalOut = value;
    if(DigitalOut> 65535)
        DigitalOut = 65535;
    writeDAC2(DigitalOut);
    Delayus(2);
    return;

}
void FourToTwentyDrive3(int value)
{
    int DigitalOut;
    DigitalOut = value;
    if(DigitalOut> 65535)
        DigitalOut = 65535;
    writeDAC3(DigitalOut);
    Delayus(2);
    return;

}


void writeDAC1(int t)
{
    int value = t;
    int count;
    SCLK1 = 1;
    SYNC1 = 1;
    LDAC1 = 1;
    Delayus(10);
    for(count = 0; count < 16; count++)
    {
        SDIN1 = (value>>15) & 0x01; //MSB first
        Delayus(10);
        value = value<<1;
        SYNC1 = 0;
        Delayus(10);
        SCLK1 = 0;
        Delayus(20);
        SCLK1 = 1;
        Delayus(10);
    }
    SYNC1 = 1;
    Delayus(20);
    LDAC1 = 0;
    Delayus(20);
    LDAC1 = 1;
}
void writeDAC2(int t)
{
    int value = t;
    int count;
    SCLK2 = 1;
    SYNC2 = 1;
    LDAC2 = 1;
    Delayus(10);
    for(count = 0; count < 16; count++)
    {
        SDIN2 = (value>>15) & 0x01; //MSB first
        Delayus(10);
        value = value<<1;
        SYNC2 = 0;
        Delayus(10);
        SCLK2 = 0;
        Delayus(20);
        SCLK2 = 1;
        Delayus(10);
    }
    SYNC2 = 1;
    Delayus(20);
    LDAC2 = 0;
    Delayus(20);
    LDAC2 = 1;
}


void writeDAC3(int t)
{
    int value = t;
    int count;
    SCLK3 = 1;
    SYNC3 = 1;
    LDAC3 = 1;
    Delayus(10);
    for(count = 0; count < 16; count++)
    {
        SDIN3 = (value>>15) & 0x01; //MSB first
        Delayus(10);
        value = value<<1;
        SYNC3 = 0;
        Delayus(10);
        SCLK3 = 0;
        Delayus(20);
        SCLK3 = 1;
        Delayus(10);
    }
    SYNC3 = 1;
    Delayus(20);
    LDAC3 = 0;
    Delayus(20);
    LDAC3 = 1;
}

