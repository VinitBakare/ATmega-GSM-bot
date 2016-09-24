#include<avr/io.h>
#include<avr/delay.h>
#include<compat/deprecated.h>//header file for sbi & cbi function

//functions for writing command on lcd

void wrcommand(unsigned char command)
{
 cbi(PORTB,PB0);             //rs=0
 PORTD=command;              //data pin loaded with command
 sbi(PORTB,PB1);             //en=1
 _delay_ms(10);              //delay
 cbi(PORTB,PB1);             //en=0
}

void wrdata(unsigned char command)
{
 sbi(PORTB,PB0);             //rs=1 
 PORTD=command;              //data pin loaded with data
 sbi(PORTB,PB1);             //en=1
 _delay_ms(10);              //delay en width
 cbi(PORTB,PB1);             //en=0
}

void USART_initialization()
{
	UBRRL=51;
	UBRRH=0;
	UCSRB|=(1<<RXEN)|(1<<TXEN);
	UCSRC|=(1<<URSEL)|(3<<UCSZ0);
}

void USART_transmit(unsigned char data)
{
	while(!(UCSRA & (1<<UDRE)))
	
		UDR=data;
	
}
unsigned char USART_receive (void)
{
	while(!(UCSRA & (1<<RXC)))
	return(UDR);

}
void usart_string(unsigned char *string)
{
  while(*string)
  wrdata(*string++);
 }

 void lcd_initialisation()
{
 wrcommand(0x80);
 wrcommand(0x38);
 wrcommand(0x06);
 wrcommand(0x01);
 wrcommand(0x0c);
 }


void main()
{
 
 DDRB=0x00;
 DDRA=0xff;
 DDRC=0xFF;
 USART_initialization(); //9600 baud rate
 while(1)
 {
  //unsigned char data=USART_receive(); 
  USART_transmit(data);
  }

 }


