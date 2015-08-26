#include "main.h"

#include "uart.h"

// ------ Private variable definitions --------------------

static bit busy = 0;

/*---------------------------------------------------------------*-
 * UART1_Init()
 * 
 * Initialization function for UART1 library
-*---------------------------------------------------------------*/
void UART1_Init()
{
	AUXR |= 0x04;	// Baudrate generator works in 1T mode
	SCON  = 0x50;	// 8-bit variable UART
	AUXR |= 0x01;	// Sets S1BRS bit
	BRT   = 0xFD;
					// Sets auto-reload value of baudrate generator
	PCON &= 0x7F;
	AUXR |= 0x10;	// Enable independent baudrate generator
}


/*---------------------------------------------------------------*-
 * UART2_Init()
 * 
 * Initialization function for UART2 library
-*---------------------------------------------------------------*/
void UART2_Init()
{
	S2CON = 0x50;	// 8-bit variable UART
	AUXR |= 0x04;	// Baudrate generator works in 1T mode
	BRT   = 0xFD;
					// Sets auto-reload value of baudrate generator
	AUXR |= 0x10;	// Enable independent baudrate generator
	IE2  |= 0x01;	// Enable UART2 interrupt
	EA    = 1;		// Open master interrupt switch
}


void UART2() interrupt 8 using 1
{
	if (S2CON & S2RI) {
		S2CON &= ~S2RI;
		// Something to do
	}
	if (S2CON & S2TI) {
		S2CON &= ~S2TI;
		busy = 0;
	}
}

void UART1_Send_Char(unsigned char CHAR)
{
	SBUF = CHAR;
	while (!TI)
		;
	TI = 0;
}

void UART2_Send_Char(unsigned char CHAR)
{
	while (busy)
		;

	busy = 1;
	S2BUF = CHAR;
}

void UART1_Send_String(unsigned char *STR)
{
	while (*STR != '\0') {
		UART1_Send_Char(*STR);
		STR++;
	}
}

void UART2_Send_String(unsigned char *STR)
{
	while (*STR != '\0') {
		UART2_Send_Char(*STR);
		STR++;
	}
}

