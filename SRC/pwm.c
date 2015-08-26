#include "main.h"

#include "pwm.h"

/*---------------------------------------------------------------*-
 * PWM0_Init(void)
 * 
 * Initialization function for PWM library
-*---------------------------------------------------------------*/
void PWM0_Init(void)
{
	CCON = 0;		// Clears interrupt flag
	CMOD = 0x02;	// Sets PCA timer clock source as FOSC/2
	CL = 0;			// Resets PCA base timer
	CH = 0;

	CCAPM0 = 0x42;	// PCA moudle 0 works in 8-bit PWM mode
	CCAP0L = 0x00;
	CCAP0H = 0x00;

	CR = 1;			// Starts PCA
}


/*---------------------------------------------------------------*-
 * PWM0_set()
 * 
 * Set the duty cycle 
 * NOTE: duty cycle = *DUTY* / 255
-*---------------------------------------------------------------*/
void PWM0_Set(unsigned char DUTY)
{
	CCAP0L = 255 - DUTY;
	CCAP1H = 255 - DUTY;
}

/*---------------------------------------------------------------*-
 * PWM1_Init(void)
 * 
 * Initialization function for PWM library
-*---------------------------------------------------------------*/
void PWM1_Init(void)
{
	CCON = 0;		// Clears interrupt flag
	CMOD = 0x02;	// Sets PCA timer clock source as FOSC/2
	CL = 0;			// Resets PCA base timer
	CH = 0;

	CCAPM1 = 0x42;	// PCA moudle 0 works in 8-bit PWM mode
	CCAP1L = 0x00;
	CCAP1H = 0x00;

	CR = 1;			// Starts PCA
}


/*---------------------------------------------------------------*-
 * PWM1_set()
 * 
 * Set the duty cycle 
 * NOTE: duty cycle = *DUTY* / 255
-*---------------------------------------------------------------*/
void PWM1_Set(unsigned char DUTY)
{
	CCAP1L = 255 - DUTY;
	CCAP1H = 255 - DUTY;
}
