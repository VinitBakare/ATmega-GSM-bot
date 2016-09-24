#include <avr/io.h>
#define F_CPU 8000000
#include  "usart.h"
#include<avr/delay.h>

 
unsigned char p,keycode;

void main()
{
DDRA=0XF0;
USART_Init();
 
while(1)
{
for(p=0;p<4;p++)
{
PORTA=(0b11101111<<p) | 0x0f;
_delay_ms(50);
keycode=PINA;

switch(keycode)
{
//*
case(0b11100111):;
break;

//0
case(0b11010111): ;
break;

//#
case(0b10110111): ;
break;

//D
case(0b01110111): ;
break;

//7
case(0b11101011):;
break;

//8
case(0b11011011):;
break;

//9
case(0b10111011):;
break;

//C
case(0b01111011):;
break;

//4
case(0b11101101):;
break;

//5
case(0b11011101):;
break;

//6
case(0b10111101):;
break;

//B
case(0b01111101):;
break;

//1
case(0b11101110):;
break;

//2
case(0b11011110):;
break;

//3
case(0b10111110):;
break;

//A
case(0b01111110):{ 
                  usart_string("print stuff");
				  USART_Transmit(13); //SENDING ASCII VALUE OF enter
				 }
break;
}

if(p==4)
{
p=0;
}
}
}
}
