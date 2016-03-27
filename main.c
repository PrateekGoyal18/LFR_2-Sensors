/*
  In this project, we will design a Robotic Car which will follow a line (black or white) path. The path can be 
  of any pattern. We will use 2 IR sensor modules. Both the sensor modules we are connecting in PA0 & PA1.
  Note: The distance between the sensor modules should be slight more than the width of the line.
*/

#include<avr/io.h>

void forward()
{
  PORTC&=~(1<<0);
  PORTC|=(1<<1);
  PORTC&=~(1<<2);
  PORTC|=(1<<3);
}

void left()
{
  PORTC&=~(1<<1);
  PORTC|=(1<<0);
  PORTC&=~(1<<2);  
  PORTC|=(1<<3);
}

void right()
{
  PORTC&=~(1<<0);
  PORTC|=(1<<1);
  PORTC&=~(1<<3);
  PORTC|=(1<<2);
}

void motor_init()
{
  DDRC=0B00001111;
}

int main()
{
  motor_init();
  DDRA=0X00;
  PORTA=0XFF;
  while(1)
  {
    if((!(PINA&(3<<0)))==0X03)
    forward();
	
    else if
	((!(PINA&(3<<0)))==0X02)
    left();
	
    else if((!(PINA&(3<<0)))==0X01)
    right();
  }
}
