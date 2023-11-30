/* 
 * File:   Functions.h
 * Author: Satheesh
 *
 * Created on July 18, 2015, 10:46 PM
 */

#ifndef FUNCTIONS_H
#define	FUNCTIONS_H

#ifdef	__cplusplus
extern "C" {
#endif

#define AN0  0
#define AN1  1

void Init_ADC();
unsigned int GetADCValue(unsigned char Channel);
unsigned int Read_adc(unsigned char adc_parameter);


#ifdef	__cplusplus
}
#endif

#endif	/* FUNCTIONS_H */

