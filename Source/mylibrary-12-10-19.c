// C program for implementation of various routines
#include<stdio.h>
#include<string.h>
#include<ctype.h>

/* // driver program to test ftoa() funtion
int main(void)
{
extern void ftoa(float n, char *res, int afterpoint);
char res[20];
    float n = -1234.0123;
    ftoa(n, res, 4);
    printf("\n\"%s\"\n", res);
    return 0;
}
*/
// reverses a string 'str' of length 'len'
void Reverse(char *str, int len)
{
    int i=0, j=len-1, temp;
    while (i<j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++; j--;
    }
}


void reverse(char *s)
{
int c,i,j;
for(i=0,j=strlen(s)-1; i<j; i++,j--)
{
c = s[i];
s[i] = s[j];
s[j] = c;
}
}

 // Converts a given integer x to string str[].  d is the number
 // of digits required in output. If d is more than the number
 // of digits in x, then 0s are added at the beginning.
int intToStr(int x, char str[], int d)
{
    int i,sign;
extern void Reverse(char *s, int n);
    if((sign = x) < 0) //record sign
	x = -x; //make x positive
	i = 0;
do  //generate s in reverse order
{
str[i++] = x % 10 + '0'; //get the next digit
}while((x /= 10) > 0);
    // If number of digits required is more, then
    // add 0s at the beginning
while (i < d)
        str[i++] = '0';

if(sign < 0)
str[i++] = '-';
str[i] = '\0';
    Reverse(str, i);
   // reverse(str);
    return i;
}

// ftoa() Converts a floating point number to string.


void ftoa(float n, char *res, int beforepoint, int afterpoint)
{
int i,sign;
extern int intToStr(int x, char *str, int d);
extern double power(double x, double y);

 if((sign = n) < 0) //record sign
	n = - n; //make n positive
    // Extract integer part
    int ipart = (int)n;
     // Extract floating part
    float fpart = n - (float)ipart;
	if(fpart < 0)
fpart = - fpart; //make f part positive in case of 0.xxx

    // convert integer part to  string with proper sign
if((sign < 0) && (ipart != 0)) //if ipart is 0 then sign has no meaning & '-' will be omitted

     i = intToStr(-ipart, res, beforepoint);
 else if(sign >= 0) //as the value may be 0.00
  i = intToStr(ipart, res, beforepoint);
else
{
i=0;
res[i++] = '-';
res[i++] = '0'; //to show as -0.xxx
}


    // check for display option after point
    if (afterpoint != 0)
    {
        res[i] = '.';  // add dot

        // Get the value of fraction part upto given no.
        // of points after dot. The third parameter is needed
        // to handle cases like 233.007

	fpart = fpart * power(10,afterpoint);

        intToStr((int)fpart, res + i + 1, afterpoint);
    }
}

double power(double x, double y)
{
double p;
for(p = 1; y  > 0 ; --y)
p = p * x;
return p;
}


/* Binary search program binsearch()
To find whether x belongs to the array v[n]
x => given number to search
*v or v[] = > pointer to the array of the numbers where v[0] <= v[1] <= v[2] ...<=v[n-1]
n => no of elements in v[]
/////////////////////////////////////////////
int binsearch(int x, int *v, int n) ////////////// using array indexing////////////////////
{
int low, high, mid;
low = 0;
high = n-1;
while(low <= high)
{
mid = (low + high)/2;
if(x<v[mid])
high = mid - 1;
else if(x>v[mid])
low = mid+1;
else ///////////////// found match //////////////////////////////
return mid;
}
return -1; /////////////////////////// no match ////////////////////
}

int binsearchP(int x, int *v, int n) //////////////// using pointer /
{
int low, high, mid;
low = 0;
high = n-1;
while(low <= high)
{
mid = (low + high)/2;
if(x < *(v+mid))
high = mid - 1;
else if(x > *(v+mid))
low = mid+1;
else //////// found match /
return mid;
}
return -1; //////////////////// no match
}


//// atoi() convert number string s to integer */

int atoi(char *s) /*array indexing version */
{

int i,n,sign;
for(i=0; isspace(s[i]); i++); /* skip any spaces */
sign = ( s[i] == '-') ? -1 : 1;
if(s[i] == '+' || s[i] == '-') /* skip sign */
i++;
for(n=0; isdigit(s[i]); i++)
n = n * 10 + (s[i] - '0');
return sign * n;
}

int atoiP(char *s) /* Pointer version */
{
int n,sign;
while(isspace(*s))
s++;
sign = (*s =='-') ? -1 : 1;
if(*s == '+' || *s == '-')
s++;
n=0;
while(isdigit(*s))
{
n = n * 10 + (*s - '0');
s++;
}
return sign * n;
}


/* itoa() convert n to characters in s */

void itoa(int n, char *s)
{
int i, sign;
if((sign = n) < 0) //record sign
n = -n; //make n positive
i=0;
do  //generate s in reverse order
{
s[i++] = n % 10 + '0'; //get the next digit
}while((n /= 10) > 0);
if(sign < 0)
s[i++] = '-';
s[i] = '\0';
reverse(s);
}


/* atof() convert string s to float */

float atof(char *s)
{

float val, power;
int i,sign;
for(i=0; isspace(s[i]); i++);
sign = (s[i] == '-') ? -1 : 1;
if(s[i] == '+' || s[i] == '-')
i++;
for(val = 0.0; isdigit(s[i]); i++)
val = 10.0 * val + (s[i] - '0');
if(s[i] == '.')
i++;
for(power = 1.0; isdigit(s[i]); i++)
{
val = 10.0 * val + (s[i] - '0');
power *= 10.0;
}
return sign * val / power;
}

/*///////////////////////////////////////////////////////////////////////////////////////
////////////////////Data Entry in State Machine Model Example////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////
int Edit_4_2(int value,char StartingAddress)
{
int digit1,digit2,digit3,digit4,digit5,digit6,rem,rem2;
int result = 0;
uint32_t exit_from_loop = 1;
typedef enum{ digit_1 = 0,digit_2,digit_3,digit_4,digit_5,digit_6,final_result}digit_state;
digit_state current_digit;
current_digit = digit_1;
digit1 = value/100000;
rem = value%100000;
digit2 = rem / 10000;
rem2 = rem % 10000;
digit3 = rem2 /1000;
rem = rem2 % 1000;
digit4 = rem / 100;
rem2 = rem % 100;
digit5 = rem2/10;
digit6 = rem2%10;

cmdLCD(0x0f);
do{
   ClrWdt();

switch(current_digit)
     {
         case digit_1:
              cmdLCD(StartingAddress); //first digit of TT
                 if((key=readK1(150))==key_Up)
                 {
                     digit1++;
                   if(digit1<=9)
                   {

            sprintf(digit1s,"%d",digit1);
            putsLCD4(digit1s);
            cmdLCD(StartingAddress);
                   }
                   else digit1=9;
                  }
                if(key==key_Down)
                {

             digit1--;
             if(digit1>=0)
             {

             sprintf(digit1s,"%d",digit1);
             putsLCD4(digit1s);
             cmdLCD(StartingAddress);
             }
             else digit1=0;
                }
                 if(key==key_Ok) current_digit = final_result;
                 if(key==key_Right) current_digit = digit_2;

              break;

     ////////////////////////////////////////////////////////

    case digit_2:
        cmdLCD(StartingAddress+1); //first digit of nomFlowRate
                 if((key=readK1(150))==key_Up)
                 {
                     digit2++;
                   if(digit2<=9)
                   {

            sprintf(digit2s,"%d",digit2);
            putsLCD4(digit2s);
            cmdLCD(StartingAddress+1);
                   }
                   else digit2=9;
                  }
                if(key==key_Down)
                {

             digit2--;
             if(digit2>=0)
             {

             sprintf(digit2s,"%d",digit2);
             putsLCD4(digit2s);
             cmdLCD(StartingAddress+1);
             }
             else digit2=0;
                }
         // if(key==key_BP) goto OperatorMenu;
          if(key==key_Left) current_digit = digit_1;
          if(key==key_Ok) current_digit = final_result;
          if(key==key_Right) current_digit = digit_3;

        break;
     /////////////////////////////////////////////////////////////////////
    case digit_3:
        cmdLCD(StartingAddress+2); //first digit of nomFlowRate
                 if((key=readK1(150))==key_Up)
                 {
                     digit3++;
                   if(digit3<=9)
                   {

            sprintf(digit3s,"%d",digit3);
            putsLCD4(digit3s);
            cmdLCD(StartingAddress+2);
                   }
                   else digit3=9;
                  }
                if(key==key_Down)
                {

             digit3--;
             if(digit3>=0)
             {

             sprintf(digit3s,"%d",digit3);
             putsLCD4(digit3s);
             cmdLCD(StartingAddress+2);
             }
             else digit3=0;
                }
         // if(key==key_BP) goto OperatorMenu;
                 if(key==key_Left) current_digit = digit_2;
                 if(key==key_Ok) current_digit = final_result;
                 if(key==key_Right) current_digit = digit_4;

        break;
///////////////////////////////////////////////////////////////////////////////////////
    case digit_4:
         cmdLCD(StartingAddress+3); //first digit of nomFlowRate
                 if((key=readK1(150))==key_Up)
                 {
                     digit4++;
                   if(digit4<=9)
                   {

            sprintf(digit4s,"%d",digit4);
            putsLCD4(digit4s);
            cmdLCD(StartingAddress+3);
                   }
                   else digit4=9;
                  }
                if(key==key_Down)
                {

             digit4--;
             if(digit4>=0)
             {

             sprintf(digit4s,"%d",digit4);
             putsLCD4(digit4s);
             cmdLCD(StartingAddress+3);
             }
             else digit4=0;
                }
        //  if(key==key_BP) goto OperatorMenu;
                 if(key==key_Left) current_digit = digit_3;
                 if(key==key_Ok) current_digit = final_result;
                 if(key==key_Right) current_digit = digit_5;

         break;

 ///////////////////////////////////////////////////////////////////////////

    case digit_5:
        cmdLCD(StartingAddress+5);
                 if((key=readK1(150))==key_Up)
                 {
                     digit5++;
                   if(digit5<=9)
                   {

            sprintf(digit5s,"%d",digit5);
            putsLCD4(digit5s);
            cmdLCD(StartingAddress+5);
                   }
                   else digit5=9;
                  }
                if(key==key_Down)
                {

             digit5--;
             if(digit5>=0)
             {

             sprintf(digit5s,"%d",digit5);
             putsLCD4(digit5s);
             cmdLCD(StartingAddress+5);
             }
             else digit5=0;
                }
                if(key==key_Left) current_digit = digit_4;
                 if(key==key_Ok) current_digit = final_result;
                 if(key==key_Right) current_digit = digit_6;
        break;
    /////////////////////////////////////////////////////////////////////
    case digit_6:
         cmdLCD(StartingAddress+6);
                 if((key=readK1(150))==key_Up)
                 {
                     digit6++;
                   if(digit6<=9)
                   {

            sprintf(digit6s,"%d",digit6);
            putsLCD4(digit6s);
            cmdLCD(StartingAddress+6);
                   }
                   else digit6=9;
                  }
                if(key==key_Down)
                {

             digit6--;
             if(digit6>=0)
             {

             sprintf(digit6s,"%d",digit6);
             putsLCD4(digit6s);
             cmdLCD(StartingAddress+6);
             }
             else digit6=0;
                }
                if(key==key_Left) current_digit = digit_5;
                 if(key==key_Ok) current_digit = final_result;

         break;
   ////////////////////////////////////////////////////////////////////////////

    case final_result:
 result = (digit1*100000)+(digit2*10000)+(digit3*1000)+ (digit4*100) + (digit5*10)+digit6;
 cmdLCD(0x0c);
 cmdLCD(StartingAddress);
 putsLCD4("-------");
 Delayms(1000);
 exit_from_loop = 0;
 break;
}
}while(exit_from_loop);

return(result);

}*/








/*

Rotations:
Rotate left 1 bit : c is unsigned char (8 bit)
c = (c<<1) | (c>>7);
Rotate left 2 bit : c is unsigned char (8 bit)
c = (c<<2) | (c>>6);
In case of set or reset a bit position:
Flag |= (1<<bit_position); //bit_position = 0,1,2,...n
so,
Flag |= 0x40;
Flag |= (1<<6);
Both are equivalent.
For clearing a bit position
Flag &= ~(1<<bit_position); //bit_position = 0,1,2,...n

Controller Port Access (Taking AVR uC as example):

We simply have to cast the address of DDRA (in I/O memory) to unsigned char pointer data type & then use '*' operator to assign a value to it.

*((volatile unsigned char *)0x3A) = 0xFF;

Better to use #define macros for simplification.

#define MYDDRA (*(volatile unsigned char *)(0x3A))
#define MYPORTA (*(volatile unsigned char *)(0x3B))

Now,
MYDDRA = 0xFF; // will do the same thing.

The keyword 'volatile' must be used to ensure that the load,use,store sequence is followed for every cycle which ensures the port memory location access instead of normal memory location.

Compiler specific extension of ANSI-C:Attribute based programming:

Eg1: Executing functions before main & after main


#include<stdio.h>
int i = 0;
void init()__attribute__((constructor)); //constructor arrtibute to execute 								//before main
void deinit()__attribute__(destructor)); //destructor arrtibute to execute
							//after main
void init()
{
i=10;
printf(“init : i=%d\n”, i);
}
void deinit()
{
i=0;
printf(“deinit : i=%d\n”,i);
}
int main()
{
i=i*2;
printf(“main : i=%d\n”,i);
return 0;
}



Output :
init : i = 10; //before main
main : i = 20; //in main
deinit : i = 0; //after main

#Eg2: Packing structures to save space in flash memory

Without attribute

#include<stdio.h>
int main()
{
struct data
{
int a;
char ch;
float s;
};
struct data e;
printf(“\n%u%u%u”,&e.a,&e.ch, &e.s);
printf(“\n%d”,sizeof(e));
return 0;
}

Output:
2280656 2280660 2280664
12

**** For 32 bit processor data stored in addresses at multiple of 4. This leads to wastage of memory space.

With attribute

#include<stdio.h>
int main()
{
struct data
{
int a;
char ch;
float s;
}__attribute__((packed)); //attribute packed specified that the fields should
				  //have the smallest possible allignment ie 1 byte.
struct data e;
printf(“\n%u%u%u”,&e.a,&e.ch, &e.s);
printf(“\n%d”,sizeof(e));
return 0;
}

Output:
2280656 2280660 2280661
9
*/

 void qsorti(int v[], int left, int right)
{
int i, last;
void swapi(int v[], int i, int j);
if (left >= right) // do nothing if array contains
return;
//// fewer than two elements
swapi(v, left, (left + right)/2); // move partition elem
last = left;
///// to v[0]
for (i = left + 1; i <= right; i++) ///* partition
if (v[i] < v[left])
swapi(v, ++last, i);
swapi(v, left, last);
// restore partition elem
qsorti(v, left, last-1);
qsorti(v, last+1, right);
}
/**We moved the swapping operation into a separate function swap because it occurs three times
in qsort .*/
/* swap: interchange v[i] and v[j] */
void swapi(int v[], int i, int j)
{
int temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}

void qsortf(float v[], int left, int right) //v[] data array..left is left index may be 0, and right is right index may be
{						// the max number of data minus 1.
int i, last;
void swapf(float v[], int i, int j);
if (left >= right) /* do nothing if array contains */
return;
/* fewer than two elements */
swapf(v, left, (left + right)/2); /* move partition elem */
last = left;
/* to v[0] */
for (i = left + 1; i <= right; i++) /* partition */
if (v[i] < v[left])
swapf(v, ++last, i);
swapf(v, left, last);
/* restore partition elem */
qsortf(v, left, last-1);
qsortf(v, last+1, right);
}
/**We moved the swapping operation into a separate function swap because it occurs three times
in qsort .*/
/* swap: interchange v[i] and v[j] */
void swapf(float v[], int i, int j)
{
float temp;
temp = v[i];
v[i] = v[j];
v[j] = temp;
}


/*float window_Filter(float v[], int no_of_data)
{
int i;
float sum,result;
sum = 0.00;
result = 0.00;
float dummy_array[no_of_data];
for(i=0;i<no_of_data;i++)
    dummy_array[i] = v[i];
    qsortf(dummy_array,0,(no_of_data-1));

    for(i=1;i<no_of_data-1;i++)
    sum = sum + dummy_array[i];
    result = sum / (no_of_data-2);
    return result;

}
*/

