#include <avr/io.h>
#define F_CPU 8000000
#include "lcd.h"
#include "simcard.h"
#include<avr/delay.h>
#include  "usart.h"

void main()
{
USART_Init();

DDRA=0XF0;
DDRB=0XFF;
DDRC=0XFF;

LCD_init();
 
unsigned char p,keycode;
 
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
case(0b11101011):SMS_receive(7);
break;

//8
case(0b11011011):SMS_receive(8);
break;

//9
case(0b10111011):SMS_receive(9);
break;

//C
case(0b01111011):;
break;

//4
case(0b11101101):SMS_receive(4);
break;

//5
case(0b11011101):SMS_receive(5);
break;

//6
case(0b10111101):SMS_receive(6);
break;

//B
case(0b01111101):;
break;

//1
case(0b11101110):SMS_receive(1);
break;

//2
case(0b11011110):SMS_receive(2);
break;

//3
case(0b10111110):SMS_receive(3);
break;

//A
case(0b01111110): ;
break;
}

if(p==4)
{
p=0;
}
}
}
}





