/*
 * Timer1Interrupt.c
 *
 * Created: 3/23/2025 1:24:23 PM
 * Author : Tegar Berbudi
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif
#include <avr/io.h>
#include <avr/interrupt.h>

// toggle led setiap Timer 1 overflow yaitu setiap (2^16)*T = 4.194304 s -- karena TCNT Timer 1 adalah 2 bytes (16 bits)
ISR(TIMER1_OVF_vect)
{
	PORTB ^= 0X20;
}

int main(void)
{
	// set built-in led sebagai output
	DDRB |= 0X20;
	
	// set Timer 1 dengan preskalar 1/1024 -> f = 15625 Hz atau T = 0.000064 s; normal mode; enable interupt pada overflow
	TCNT1 &= 0X0000;
	TCCR1B |= (1 << CS12) | (1 << CS10);
	TIMSK1 |= (1 << TOIE1);
	
	// enable interupt
	sei();
	
	// endless loop
	while (1);
	return 0;
}
