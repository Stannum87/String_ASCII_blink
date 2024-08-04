#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    DDRB = 0xff;
    
    char array[12] = "Hello world";  // you can also use  char *message = "Hello world";
    int n = 0;
	int b = 0;
    char words = *(array+n);
	
    while (1) 
    {
		if (words & 0x01) // can be used in other way using bool 
		{
			PORTB = 0x00;
			PORTB |= 1<<PINB1;
			PORTB |= 1<<PINB0;
			
			_delay_ms(500);
		}
		else
		{
			PORTB = 0x00;
			PORTB |= 1<<PINB1;
			PORTB &= ~(1<<PINB0);
			_delay_ms(500);
		}
		words = words>>1;
		b++;
		if (b>=8)
		{
			PORTB |= 1<<PINB2;
			b=0;
			n++;
			words = *(array+n);
			_delay_ms(1000);
			if (n>=12)
			{
				n=0;
			}
		}
		PORTB=0x00;
		_delay_ms(500);
    }
}