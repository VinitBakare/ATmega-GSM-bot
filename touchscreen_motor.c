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

void lcd_initialisation()    //initialising ADSCR 
{
 wrcommand(0x80);             //1st row 1st column
 wrcommand(0x38);             //lcd 16x2 & 5x7
 wrcommand(0x06);             //data entry from left
 wrcommand(0x01);             //clearing
 wrcommand(0x0f);             //blinking cursor ON
 }

int x_axes()
{
   DDRA=0b00001010;           //pin 1 & 3 op
   PORTA=0b00001000;          //pin 3 vcc & 1 gnd
   ADMUX=0x62;                //second channel as op 
   _delay_ms(1);              // delay cause ADC takes more time for conversion
   return ADCH;               //digital value returned(in binary form)
}
int y_axes()
{
   DDRA=0b00000101;           //pin 0 & 2 as op
   PORTA=0b00000001;          //pin 0 vcc 2 gnd
   ADMUX=0X63;                //third channel as op
   _delay_ms(1);
   return ADCH;
}

 
 void main()
{   
    int x,y;
    ADCSRA=0b11100101;   //CONFIGURE ADC
    DDRD=255;
	DDRB=255;
	DDRC=255;

	lcd_initialisation();
  while(1)             // SO THAT THE DATA IN X IS READ AGAIN AND AGAIN THOUGH THE CONVERSION IS CONTINUOUS
  {
    
   ADMUX=0b01100000;   //SOC
   _delay_ms(1);
  
   x=x_axes();
   y=y_axes();         //storing adch value for digital converted anolog value of y coordinate

   wrcommand(0x80);
   wrdata(x/100+48);
   wrdata((x/10)%10+48);
   wrdata(x%10+48);
   wrdata('  ');
   wrdata(y/100+48);
   wrdata((y/10)%10+48);
   wrdata(y%10+48);
   
  if(y>135)
   {
      PORTC=0b00001001;              //forward
   }
   if(x==0 && y==0)
   {
     PORTC=0;                       //stop
	} 
	if(y<60 && x!=0 && y!=0)
	{
	  PORTC=0b00000110;              //backward
    }
	if(x>100 && y>60 && y<135)
	{
	  PORTC=0b00001010;              //right
    }
    if(x<100 && x!=0 && y>60 && y<135)
	{
	  PORTC=0b00000101;               //left
    }

  }
}

