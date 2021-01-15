#define U2CTS _RF12
#define U2RTS _RF13
#define U1CTS _RD14
#define U1RTS _RD15
void initU2(void);
void initU1(void);
int putU2(int c);
int putU1(int c);
char getU2(void);
char getU1(void);
int puts(const char *s);
int U1puts(const char *s);
char *getsn( char *s, int n);
char *getsnU1(char *s, int n);
