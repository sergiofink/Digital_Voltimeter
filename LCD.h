/* 
 * File:   LCD.h
 * Author: Satheesh
 *
 * Created on July 18, 2015, 10:50 PM
 */

#ifndef LCD_H
#define	LCD_H

#ifdef	__cplusplus
extern "C" {
#endif

#define E PORTBbits.RB0
#define RS PORTBbits.RB1
#define RW PORTBbits.RB2
#define Busy PORTBbits.RB7
#define LCD_port_dir TRISB
#define Data PORTB




// Function Declarations
void lcdcmd(unsigned char value);
void lcddata(unsigned char value);
void InitLCD();
void ClearLCDScreen(void);
void WriteStringToLCD(const char *s);
void LCD_Char_build(unsigned char location, unsigned char *ptr);

void WriteLCDLine1(const char *s);
void WriteLCDLine2(const char *s);
void ClearLCDScreen(void);


#ifdef	__cplusplus
}
#endif

#endif	/* LCD_H */

