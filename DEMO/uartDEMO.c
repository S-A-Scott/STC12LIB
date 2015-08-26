#include "main.h"
#include "timeout.h"
#include "lcd12864.h"
#include "hc_sr04.h"
#include "pwm.h"
#include "uart.h"

void Delay1000ms()		//@11.0592MHz
{
	unsigned char i, j, k;

	i = 43;
	j = 6;
	k = 203;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
	UART1_Init();
	UART2_Init();
	while (1) {
		UART1_Send_String("hello world\n");
		UART2_Send_String("spencer scott\n");
		Delay1000ms();	
	}
}
