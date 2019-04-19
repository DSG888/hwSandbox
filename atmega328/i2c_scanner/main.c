// i2c scanner
#define F_CPU 16000000UL
#define SCL_CLOCK 100000UL  // I2C bus clocked at 100kHz
#define UART_BAUD_RATE 9600

#include <avr/io.h>
#include <stdlib.h>			//itoa
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "i2c.h"
#include "uart.h"

int main(){
	char buf[10];
	// Configure All Pins as Inputs
	DDRB = 0x00;  //0 == Input; 1 = Output
	DDRC = 0x00;
	DDRD = 0x00;
	// Enable All Pull-Ups
	PORTB = 0xFF;  //0 = Tri-State; 1 = Pull-Up
	PORTC = 0xFF;
	PORTD = 0xFF;

	// SPI Конфигурация
	SPCR |= (1<<SPE) | (1<<MSTR);  // SPI enabled as master, Mode0 at 4 MHz
	SPSR |= (1<<SPI2X);  // double the SPI rate: 4-->8 MHz

	
	// Initialize I2C Bus
	TWSR &= ~(1<<TWPS1) & ~(1<<TWPS0);  // set TWI bit rate prescaler value to 1-one
	TWBR = ((F_CPU/SCL_CLOCK)-16)/2;    // SCL frequency = CPU Clock Frequency / (16+(2*TWBR*Prescaler))

	//char i;

	//init uart
	uart_init( UART_BAUD_SELECT(UART_BAUD_RATE,F_CPU) );
	sei();

	while(1) {
		for (uint8_t i = 1; i < 127; i++) {	// перебираем допустимый 7-битный диапазон адресов
			if( (i2cStart((i << 1) | 0)) == 0 ) {  // Если i2cStart() вернула 0, нет ответа
				itoa(i, buf, 10);	// число в char
				uart_puts(buf);
				uart_puts("dec ACK=0 no response");
				uart_puts("\r\n");
				 _delay_ms(500);
			}
			else {						// если i2cStart() вернула 1, slave ACK получен
				itoa(i, buf, 10);
				uart_puts(buf);
				uart_puts("dec - found I2C addr, ACK=1");
				uart_puts("\r\n");
				}
		}
		i2cStop();
		_delay_ms(5000);
	}
}
