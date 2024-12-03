#include "main.h"


int main(void)
{
	DDRB |= (1 << PB5);
	while (true)
	{
		PORTB &= ~(1 << PB5);
		for (int i = 0; i < 1000; i++)
		{
			PORTB |= (1 << PB5);
		}
	}
}