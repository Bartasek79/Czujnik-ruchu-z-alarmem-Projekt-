#include <avr/io.h>
#include <avr/interrupt.h>
#include "timer.h"

static volatile uint32_t timer_ms = 0;

void Timer0_Init(void)
{
    TCCR0A |= (1 << WGM01);              // Tryb CTC
    TCCR0B |= (1 << CS01) | (1 << CS00); // Preskaler 64
    OCR0A = 249;                         // 1ms przy 16MHz
    TIMSK0 |= (1 << OCIE0A);             // Przerwanie Compare Match
}

uint32_t millis(void)
{
    uint32_t ms;
    cli(); // Wyłącz przerwania na chwilę, by bezpiecznie odczytać 32-bitową zmienną
    ms = timer_ms;
    sei(); // Włącz przerwania z powrotem
    return ms;
}

ISR(TIMER0_COMPA_vect)
{
    timer_ms++;
}