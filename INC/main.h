/*---------------------------------------------------------------*-
 * WILL NEED TO EDIT THIS SECTION FOR EVERY PROJECT
-*---------------------------------------------------------------*/

#ifndef _MAIN_H
#define _MAIN_H

/*---------------------------------------------------------------*-
 * Must include the appropriate microcontroller header file here 
-*---------------------------------------------------------------*/
#include <STC12C5A60S2.H>
#include <stdio.h>
#include <intrins.h>		// declare _nop_()


/*---------------------------------------------------------------*-
 * Oscillator frequency (in Hz) e.g 11059200UL
-*---------------------------------------------------------------*/
//#define OSC_FREQ	12000000UL
//#define _USE_12M
#define OSC_FREQ	11059200UL

/*---------------------------------------------------------------*-
 * Number of oscillations per instruction (12, etc) 
 * 12 - original 8051 / 8052
 * 6  - Various Infineon and Philips devices, etc
 * 4  - Dallas 320, 520 etc
 * 1  - Dallas 420, etc	
-*---------------------------------------------------------------*/
#define OSC_PER_INST	1


/*---------------------------------------------------------------*-
 * 							Typedefs 
-*---------------------------------------------------------------*/
typedef unsigned char uchar;
typedef unsigned int  uint;
typedef unsigned long ulong;


/*---------------------------------------------------------------*-
 * 							Interrupts
-*---------------------------------------------------------------*/
#define INTERRUPT_Timer_0_Overflow 1
#define INTERRUPT_Timer_1_Overflow 3
#define INTERRUPT_Timer_2_Overflow 5

#endif
