#ifndef UART_H
#define UART_H

void UART_Init(void);
void UART_SendChar(char data);
void UART_SendString(char *s);
int UART_Available(void);
char UART_Read(void);

#endif