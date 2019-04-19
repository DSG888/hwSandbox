#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

volatile uint32_t millis;

ISR(TIMER0_OVF_vect) {
	millis++;
}

int main(void) {
	DDRB |= (1<<PB5); //  pinMode(13,OUTPUT); в Wiring

	TIMSK =(1<<TOIE0);  // timer0 enable
	TCCR0 = (1<<CS01) | (1<<CS00); // prescaler 1/64

	volatile uint32_t curTime, lastTime, period;

	millis=0;
	lastTime=0;
	period=1000; // 1 sec

        sei();

        for (;;) {
		curTime=millis;
		if ((curTime -lastTime) > period) {
			PORTB ^= (1<<PB5);
			lastTime=curTime;
		}
	}
	return 0;
}
