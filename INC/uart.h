#ifndef _UART_H
#define _UART_H

// ------ Public constants --------------------------------

#define S2RI  0x01			// S2CON.0
#define S2TI  0x02			// S2CON.1

#define BAUD_RATE	115200	

// ------ Public function prototypes ----------------------

void UART1_Init(void);
void UART2_Init(void);
void UART1_Send_Char(unsigned char CHAR);
void UART2_Send_Char(unsigned char CHAR);
void UART1_Send_String(unsigned char *STR);
void UART2_Send_String(unsigned char *STR);

#endif
