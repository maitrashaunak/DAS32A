/* LCD.h*/
#define HLCD 16 // width 16 char
#define VLCD 2	// height 2
#define LCDDATA 1	// address of data reg
#define LCDCMD 0	// addrfess of command reg
void initLCD(void);
void writeLCD(int addr, char c);
char readLCD(int addr);

#define putLCD(d) writeLCD(LCDDATA, (d))
#define cmdLCD(c) writeLCD(LCDCMD,(c))

#define clrLCD() writeLCD(LCDCMD,1)
#define homeLCD() writeLCd(LCDCMD,2)

#define setLCDG(a) writeLCD(LCDCMD,(a & 0x3f)|0x40)
#define setLCDC(a) writeLCD(LCDCMD,(a & 0x7f)|0x80)

#define busyLCD() (readLCD(LCDCMD)& 0x80)
#define addrLCD() (readLCD(LCDCMD) & 0x7f)
#define getLCD() readLCD(LCDDATA)

void putsLCD(char *s);
void putsLCD4(char *s);
void Delayms(unsigned t);
void Delayus(unsigned t);

