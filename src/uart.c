#include <avr/io.h>
#include "config.h"
#include "uart.h"

void UART_Init(void)
{
    UBRR0L = UART_UBRR;
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // 8N1
}

void UART_SendChar(char data)
{
    while (!(UCSR0A & (1 << UDRE0)))
        ;
    UDR0 = data;
}

void UART_SendString(char *s)
{
    while (*s)
        UART_SendChar(*s++);
}

int UART_Available(void)
{
    return (UCSR0A & (1 << RXC0));
}

char UART_Read(void)
{
    return UDR0;
}