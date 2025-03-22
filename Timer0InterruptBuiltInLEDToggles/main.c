/*
 * Timer0Interupt.c
 *
 * Created: 3/22/2025 8:33:10 AM
 * Author : Tegar Berbudi
 *
 * Eksperimen interupt Timer 0 ATmega328P, men-toggle built-in led pada Arduino Uno dengan periode tertentu.
 */

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <avr/interrupt.h>

// tipe data volatile untuk interupt routine
volatile uint8_t count = 0;


// increment setiap Timer 0 overflow / setiap (2^8)*T
ISR(TIMER0_OVF_vect)
{
	count++;
}

int main(void)
{
	// set built-in led sebagai output
	DDRB |= 0X20;
	
	// set Timer 0 dengan preskalar 1/1024 -> f = 15625 Hz atau T = 0.000064 s; normal mode; enable interupt pada overflow
	TCNT0 &= 0X00;
	TCCR0B |= (1 << CS02) | (1 << CS00);
	TIMSK0 |= (1 << TOIE0);
	
	// enable interupt
	sei();
	
	// variabel pembantu
	uint8_t aux = 0;
	
	// endless loop
    while (1)
	{
		// toggle built-in led setiap (2^8)*(2^8)*T karena count adalah 8 bit
		if (aux == 0 && count >= 128)
		{
			aux = 1;
			PORTB ^= 0X20;
		}
		else if (aux == 1 && count <= 127)
		{
			// juga bisa men-toggle di sini jika menginginkan periode toggle 2x lebih cepat
			aux = 0;
		}
	}
	return 0;
}
