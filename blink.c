#include <avr/io.h>
#include <avr/interrupt.h>

ISR (TIMER1_COMPA_vect)
{
	// Toggles the leds at "PB5" and "PB4".
	PORTB ^= _BV(PORTB5) | _BV(PORTB4);

	// Resets the counter.
	TCNT1 = 0;
}

int main(void)
{
	// Sets "PB5" and "PB4" to an output.
	DDRB |= _BV(DDB5) | _BV(DDB4);
	PORTB |= _BV(PORTB5);

	// Sets the counter to zero.
	TCNT1 = 0;

	// Sets the max value to 15625.
	OCR1A = 15625;

	// Sets the prescaler to 1024.
	TCCR1B = (1 << CS10) | (1 << CS12);

	// Sets the mode to CTC.
	TCCR1A = (1 << WGM12);

	// Enables the "Output Compare A" interrupt.
	TIMSK1 = (1 << OCIE1A);

	// Enables the interrupt.
	sei();

	while (1)
	{
		;;
	}
}