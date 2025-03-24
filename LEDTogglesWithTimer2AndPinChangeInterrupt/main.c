/*
 * Timer2AndPinChangeInterrupt.c
 *
 * Created: 3/24/2025 1:49:38 PM
 * Author : Tegar Berbudi
 */ 

#ifndef F_CPU
#define F_CPU 16000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>

// untuk menghitung jumlah overflow interrupt Timer 2
volatile uint8_t count;

// timer 2 overflow interrupt akan dihitung
ISR(TIMER2_OVF_vect)
{
	count++;
}

// pin change interrupt port B akan men-toggle PB5/pin-digital-13/LED-built-in
ISR(PCINT0_vect)
{
	PORTB ^= 0X20;
}

int main(void)
{
	// pin digital 13/PB5/LED-built-in DAN pin digital 12/PB4; di-set sebagai output
	DDRB |= (1 << DDB5) | (1 << DDB4);
	
	// Timer 2 di-set dengan preskalar 1/1024 --> 15625 Hz; mode normal
	TCCR2B |= (1 << CS22) | (1 << CS21) | (1 << CS20);
	
	// mengaktifkan Timer 2 overflow interrupt
	TIMSK2 |= (1 << TOIE2);
	
	// mengaktifkan mask pada PCINT4/PB4/pin digital 12 untuk pin change interrupt
	PCMSK0 |= (1 << PCINT4);
	
	// mengaktifkan pin change interrupt pada port B
	PCICR |= (1 << PCIE0);
	
	// mengaktifkan interrupt global
	sei();
	
	// endless loop
    while (1)
    {
		// jika count bernilai 0 atau kurang dari 128 --> PCINT4/PB4/pin digital 12 di-set ke LOW
		// jika count berada di tengah (anggap 128 berada di tengah 0 - 255) --> PCINT4/PB4/pin digital 12 di-set ke HIGH
		(count >= 128) ? (PORTB |= (1 << PORTB4)) : (PORTB &= ~(1 << PORTB4));
    }
}
