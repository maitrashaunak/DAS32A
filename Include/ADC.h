#include "hal_ADC_pic32mx360f512l.h"
#include <stdint.h>

#define LCPower 5
#define LCValue 4
#define LCGround 3
#define AIN1 11
#define AIN2 10
#define AIN3 9
#define AIN4 8
#define AINPUTS 0xf0c7
void initADC (int amask);
int readADC(int ch);

