#include <avr/io.h>
#define F_CPU 8000000
#include  "usart.h"
#include<avr/delay.h>
#include "simcard.h"
#define RS PB0
#define EN PB2
#define dataport PORTD
#include <compat/deprecated.h>

void LCD_init(void)
{
wrcomm(0x38); //initialize LCD 2 lines, 5x7 matrix  00111000
wrcomm(0x06);//entry mode
wrcomm(0x01);//Clear LCD
wrcomm(0x80); //fist line first column
wrcomm(0x0C); //Display on, Cursor Blinking
//wrcomm(0x08);

}

void wrcomm(unsigned char Command)

{
cbi(PORTB,RS);//
PORTC = Command;
 sbi(PORTB,EN);
_delay_ms(20); 
cbi(PORTB,EN);
_delay_ms(20);
}
void wrdata(unsigned char Data)


{
sbi(PORTB,RS); 

PORTC = Data;
sbi(PORTB,EN);
_delay_ms(20);
cbi(PORTB,EN); 
_delay_ms(20);
 }


void LCD_String ( unsigned char *string)
{
while (*string)
wrdata(*string++);
}





void main()
{
USART_Init();

DDRA=0X0f;
DDRB=0XFF;
DDRC=0XFF;

LCD_init();
LCD_String ( "Hello");
_delay_ms(1000);
wrcomm(0x01);
_delay_ms(1000);_delay_ms(1000);_delay_ms(1000);
LCD_String ( "My Mobile ");
_delay_ms(1000);_delay_ms(1000);_delay_ms(1000);



while(1)
       {
	 
       GSM_STANDBY();
       }
}
