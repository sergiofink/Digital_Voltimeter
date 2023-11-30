#include "Lib.h"

void lcdcmd(unsigned char value)
{
unsigned char cmd;
cmd = (value & 0xF0);  // Mask lower nibble data
Data =cmd;  // Send upper nibble data
RS=0; // command mode
RW=0; // write command
E=1;
__delay_ms(10);
E=0;

cmd= ((value<<4) & 0xF0);  // Mask upper nibble and save
Data =cmd;  // Send lower nibbble
RS=0; // Command mode
RW=0; // Wite mode
E=1;
__delay_ms(10);
E=0;
}



void lcddata(unsigned char value)
{
unsigned char dta;
dta = (value & 0xF0);
Data =dta;
RS=1;
RW=0;
E=1;
__delay_ms(1);
E=0;

dta= ((value<<4) & 0xF0);
Data =dta;
RS=1;
RW=0;
E=1;
__delay_ms(10);
E=0;
}

void InitLCD()
{
    TRISB=0x00;
    PORTB=0x00;
    __delay_ms(100);
E=0;
__delay_ms(250);
lcdcmd(0x2);
__delay_ms(250);
lcdcmd(0x28);
__delay_ms(15);
//lcdcmd(0x0F); // Display ON cursor blink
lcdcmd(0x0C);//Display ON cursor OFF
__delay_ms(15);
lcdcmd(0x06);
__delay_ms(15);
}

void WriteStringToLCD(const char *s)
{
   while(*s)
      lcddata(*s++);   // print first character on LCD
}

void LCD_Char_build(unsigned char location, unsigned char *ptr)
{
     unsigned char i;                          //For indexing

     if(location<8)                            //If valid address
    {
         lcdcmd(0x40+(location*8)); //Write to CGRAM
         for(i=0;i<8;i++)
            lcddata(ptr[i]);            //Write the character pattern to CGRAM
     }

    lcdcmd(0x80);                  //shift back to DDRAM location 0
}


void WriteLCDLine1(const char *s)    // length of s should be 16 for 16x2 LCD and 20 for 20x2 LCD
{
   lcdcmd(0x80);     // Goto 0,0 location
   WriteStringToLCD(s);
}


void WriteLCDLine2(const char *s)    // length of s should be 16 for 16x2 LCD and 20 for 20x2 LCD
{
   lcdcmd(0xc0);     // Goto 1,0 location
   WriteStringToLCD(s);
}

void ClearLCDScreen(void)       // Clear the Screen and return cursor to zero position
{
   lcdcmd(0x01);    // Clear the screen
   __delay_ms(2);              // Delay for cursor to return at zero position
}
