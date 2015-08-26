#include <stdio.h>
#include <intrins.h>
#include "main.h"
#include "timeout.h"

#include "adc.h"

void ADC_Init(unsigned char CHANNEL)
{
	P1ASF = CHANNEL;
	ADC_RES = 0;
	ADC_CONTR = ADC_POWER | ADC_SPEED_540;
	Delay_10us();		// ADC power on and delay
}

unsigned char ADC_Get_Result(unsigned char CHANNEL)
{
	ADC_CONTR = ADC_POWER | ADC_SPEED_540 | ADC_START | CHANNEL;
	_nop_();	// Must wait before inquiry
	_nop_();
	_nop_();
	_nop_();
	while (!(ADC_CONTR & ADC_FLAG))
		;			// Wait complete bit
	ADC_CONTR &= ~ADC_FLAG;

	return ADC_RES;
}
