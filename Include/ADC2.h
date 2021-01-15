#define LCPower 5
#define LC1 4
#define LC2 2
#define LCGround 3
//#define AIN1 11
//#define AIN2 10
//#define AIN3 9
//#define AIN4 8
#define AINPUTS 0xffc3
void initADC (int amask);
int readADC(int ch);
