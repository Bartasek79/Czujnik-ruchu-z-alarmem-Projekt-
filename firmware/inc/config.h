#ifndef CONFIG_H
#define CONFIG_H

#include <avr/io.h>

#define F_CPU 16000000UL

// Definicje pinów - LED i Buzzer
#define LED_DDR DDRB
#define LED_PORT PORTB
#define LED_PIN PB0

#define BUZZ_DDR DDRB
#define BUZZ_PORT PORTB
#define BUZZ_PIN PB1

// Definicje pinów - PIR
#define PIR_DDR DDRD
#define PIR_PORT_IN PIND
#define PIR_PIN PD2

// Konfiguracja UART
#define UART_BAUD 9600
#define UART_UBRR 103 // Zmienione z MYUBRR na UART_UBRR

#endif