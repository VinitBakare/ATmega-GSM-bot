#include <avr/io.h>
#define F_CPU 8000000
#include  "usart.h"
#include<avr/delay.h>

void main()
{
DDRA=255;
USART_Init();

usart_string("AT+CMGF=1");

 
USART_Transmit(13); //SENDING ASCII VALUE OF enter
PORTA=1;
_delay_ms(1000);_delay_ms(1000);
usart_string("AT+CMGS=");
USART_Transmit('"');
usart_string("Print number");
USART_Transmit('"');
USART_Transmit(13); //SENDING ASCII VALUE OF enter
PORTA=2;
_delay_ms(1000);_delay_ms(1000);
usart_string("Bot Start ");
PORTA=4;
_delay_ms(1000);_delay_ms(1000);

USART_Transmit(0X1A); //SENDING ASCII VALUE OF ctrl+Z
PORTA=8;

}
