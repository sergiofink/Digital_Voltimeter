/* 
 * File:   newmain.c
 * Author: Satheesh *
 * Created on July 18, 2015, 10:42 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "Lib.h"
#include "Functions.h"
#include "LCD.h"

void main() 
{
    Init_ADC(); // Init ADC Channel for reading Voltage
    InitLCD(); // Init the 16*2 LCD 4 bit mode
   
    while(1)
    {
        unsigned int ADC_Value=Read_adc(AN0); // Read the ADC_Value        
        float Volt= ADC_Value*0.00494*(670/200); // Convert ADC value to input volt
        unsigned char string[25]; 
        sprintf(string,"%2.2fVolts",Volt); // formatting for output
        WriteLCDLine1(string); // Display the Voltage in  LCD
    }
}

