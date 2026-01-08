#include <avr/io.h>
#include <avr/interrupt.h>
#include "config.h"
#include "timer.h"
#include "uart.h"
#include "alarm.h"

int main(void)
{
    // GPIO
    LED_DDR |= (1 << LED_PIN);
    BUZZ_DDR |= (1 << BUZZ_PIN);
    PIR_DDR &= ~(1 << PIR_PIN);

    Timer0_Init();
    UART_Init();
    sei(); // Globalne włączenie przerwń

    state_t current_state = STATE_IDLE;
    uint32_t state_start_time = 0;

    UART_SendString("\r\n--- SYSTEM ALARMOWY GOTOWY ---\r\n");
    UART_SendString("Instrukcja: 'a' - uzbroj, 'd' - rozbroj\r\n");

    while (1)
    {
        // Obsługa UART
        if (UART_Available())
        {
            char cmd = UART_Read();
            if (cmd == 'a')
            {
                current_state = STATE_ARMED;
                UART_SendString("[STATUS] System Uzbrojony.\r\n");
            }
            else if (cmd == 'd')
            {
                current_state = STATE_IDLE;
                LED_PORT &= ~(1 << LED_PIN);
                BUZZ_PORT &= ~(1 << BUZZ_PIN);
                UART_SendString("[STATUS] System Rozbrojony.\r\n");
            }
        }

        // Maszyna Stanów
        switch (current_state)
        {
        case STATE_IDLE:
            // Czuwanie
            break;

        case STATE_ARMED:
            // Sprawdzanie czujnika PIR
            if (PIR_PORT_IN & (1 << PIR_PIN))
            {
                current_state = STATE_ALARM;
                state_start_time = millis();
                UART_SendString("!!! ALARM: WYKRYTO RUCH !!!\r\n");
            }
            break;

        case STATE_ALARM:
            // Efekty alarmowe (mruganie co 250ms)
            if ((millis() / 250) % 2)
            {
                LED_PORT |= (1 << LED_PIN);
                BUZZ_PORT |= (1 << BUZZ_PIN);
            }
            else
            {
                LED_PORT &= ~(1 << LED_PIN);
                BUZZ_PORT &= ~(1 << BUZZ_PIN);
            }

            // Automatyczne wyciszenie po 10 sekundach
            if (millis() - state_start_time >= 10000)
            {
                current_state = STATE_ARMED;
                LED_PORT &= ~(1 << LED_PIN);
                BUZZ_PORT &= ~(1 << BUZZ_PIN);
                UART_SendString("[INFO] Alarm wyciszony automatycznie.\r\n");
            }
            break;
        }
    }
}