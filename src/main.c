/*
 * ATmega32 LED blink example (avr-gcc / avr-libc).
 *
 * Wiring: PB0 -> 330 ohm resistor -> LED anode; LED cathode -> GND.
 * Assumes an active-high LED and a 1 MHz CPU clock. Set F_CPU to the
 * actual clock selected by your oscillator and fuse settings.
 * Defining F_CPU does not configure the hardware clock or fuses.
 *
 * Build from the repository root:
 *   avr-gcc -mmcu=atmega32 -DF_CPU=1000000UL -Os -Wall -Wextra -std=c99 -o blink.elf src/main.c
 *   avr-objcopy -O ihex -R .eeprom blink.elf blink.hex
 *
 * Flash blink.hex using your AVR programmer.
 */

#ifndef F_CPU
#define F_CPU 1000000UL
#endif

#include <avr/io.h>
#include <util/delay.h>

#define LED_PIN PB0

int main(void)
{
    /* Set the output latch low before enabling PB0 as an output. */
    PORTB &= (unsigned char)~_BV(LED_PIN);
    DDRB |= _BV(LED_PIN);

    for (;;) {
        PORTB |= _BV(LED_PIN);
        _delay_ms(500);

        PORTB &= (unsigned char)~_BV(LED_PIN);
        _delay_ms(500);
    }
}
