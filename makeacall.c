#include <avr/io.h>
#define F_CPU 8000000

#include<avr/delay.h>

#include  "usart.h"
 

void main()
{
USART_Init();

usart_string("ATD+xxxxxxxxxx;"); //replace xxxxxx with the mobile number
 
USART_Transmit(13); //SENDING ASCII VALUE OF enter

}
