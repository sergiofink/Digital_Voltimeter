/* 
 * File:   Lib.h
 * Author: Satheesh
 *
 * Created on July 18, 2015, 10:51 PM
 */

#ifndef LIB_H
#define	LIB_H

#ifdef	__cplusplus
extern "C" {
#endif
    /*Crystal frequency */
#define _XTAL_FREQ   20000000
   
    

// PIC16F877A Configuration Bit Settings

// 'C' source line config statements

#include <xc.h>

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = OFF      // Brown-out Reset Enable bit (BOR disabled)
#pragma config LVP = OFF        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)



    
#include "LCD.h"
#include "Functions.h"
#include <xc.h>
    
/*Global Variables*/
unsigned int AVG_NUM=10;


#ifdef	__cplusplus
}
#endif

#endif	/* LIB_H */

