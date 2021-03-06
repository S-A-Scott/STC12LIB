#ifndef _ADC_H
#define _ADC_H

// ------ Public constants --------------------------------

#define ADC_POWER		0x80	// ADC power control bit
#define ADC_FLAG		0x10	// ADC complete flag
#define ADC_START		0x08	// ADC start control bit
#define ADC_SPEED_540	0x00	// 540 clocks
#define ADC_SPEED_360 	0x20	// 360 clocks
#define ADC_SPEED_180 	0x40	// 180 clocks
#define ADC_SPEED_90	0x60	// 90 clocks

// ------ Public function prototypes ----------------------

void ADC_Init(unsigned char CHANNEL);
unsigned char ADC_Get_Result(unsigned char CHANNEL); 

#endif
