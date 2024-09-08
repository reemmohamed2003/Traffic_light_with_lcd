/*
 * trafficlight.c
 *
 * Created: 8/26/2024 10:57:44 PM
 * Author : Reem Mohamed
 */ 
#include <avr/io.h>
#include "LCD.h"
#include "timer.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "LED.h"
#include <avr/interrupt.h>
volatile unsigned char counter1=0;
volatile unsigned char counter2=10; //LED RED
volatile unsigned char counter3=8;  // LED YELLOW
volatile unsigned char counter4=10;  // LED GREEN 
int main(void)
{
	LED_vInit('C',0);
	LED_vInit('C',1);
	LED_vInit('C',2);
	LCD_vInit();
	timer_CTC_init_interrupt();
	
	while(1)
	{
		counter2=10;
		counter3=8;
		counter4=10;
		LCD_clearscreen();
		LCD_vSend_string("count to 10 sec");
		LED_vTurnOn('C',0);
		while(counter2>0)
		{
			if(counter1>=50)
			{
				counter1=0;
				counter2--;
				LCD_movecursor(1,10);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter2 %10)+'0');
			}
		}
		_delay_ms(500);
		LED_vTurnOn('C',1);
		LED_vTurnOff('C',0);
		LCD_clearscreen();
		LCD_vSend_string("count to  8 sec");
		while(counter3>0)
		{
			if(counter1>=50)
			{
				counter1=0;
				counter3--;
				LCD_movecursor(1,10);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter3 %10)+'0');
			}
		}
		_delay_ms(500);
		LED_vTurnOn('C',2);
		LED_vTurnOff('C',1);
		LCD_clearscreen();
		LCD_vSend_string("count to 10 sec");
		while(counter4>0)
		{
			if(counter1>=50)
			{
				counter1=0;
				counter4--;
				LCD_movecursor(1,10);
				LCD_vSend_char(' ');
				LCD_vSend_char((counter4 %10)+'0');
			}
		}
		_delay_ms(500);
		LED_vTurnOff('C',2);
	}
	
}


ISR(TIMER0_COMP_vect)
{
	counter1++;
}
