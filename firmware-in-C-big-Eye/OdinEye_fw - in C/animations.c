#include "Odin_eye_header.h"

void spiral(uint8_t color){
		set_color(color, ON);
		for (uint8_t i=1; i<=80;i=i+4)
		{
			set_led(i, ON);
			show();
			i2c_delay(DELAY_LED_BYTE);
		}
		for (uint8_t i = 2; i<=80; i=i+4)
		{
			set_led(i, ON);
			show();
			i2c_delay(DELAY_LED_BYTE);
		}
		for (uint8_t i = 3; i<=80; i=i+4)
		{
			set_led(i, ON);
			show();
			i2c_delay(DELAY_LED_BYTE);
		}
		for (uint8_t i = 4; i<=80; i=i+4)
		{
			set_led(i, ON);
			show();
			i2c_delay(DELAY_LED_BYTE);
		}
}


void fan_animation(uint8_t color, uint8_t repeat){
	
	for (uint8_t j=0; j<=repeat; j++)
	{
		set_color(color, ON);
		for (uint8_t i=1; i<=80;i=i+5)
		{
			set_led(i, ON);
		}
		show();
		_delay_ms(50);
		wdt_reset();		
		clear_reg();
		set_color(color, ON);		
		for (uint8_t i=5; i<=80;i=i+5)
		{
			set_led(i, ON);
		}
		show();
		_delay_ms(50);
		wdt_reset();
		clear_reg();
		set_color(color, ON);
		for (uint8_t i=9; i<=120;i=i+5)
		{
			set_led(i, ON);
		}
		show();
		_delay_ms(50);
		wdt_reset();
		clear_reg();
		set_color(color, ON);	
		for (uint8_t i=13; i<=120;i=i+5)
		{
			set_led(i, ON);
		}
		show();
		_delay_ms(50);
		wdt_reset();
		clear_reg();
		set_color(color, ON);
		for (uint8_t i=17; i<=120;i=i+5)
		{
			set_led(i, ON);
		}
		_delay_ms(50);
		wdt_reset();
		show();
		clear_reg();
		set_color(color, ON);
		for (uint8_t i=21; i<=120;i=i+5)
		{
			set_led(i, ON);
		}
		show();
		_delay_ms(50);
		wdt_reset();
		clear_reg();
	}
	

}
void focus_main(uint8_t color,uint8_t repeat){
		for (uint8_t i = 1; i<=80; i=i+4)
		{
			set_color(RED, ON);
			set_led(i, ON);
			show();
			_delay_ms(70);
		}
		
		
		for (uint8_t i = 2; i<=80; i=i+4)
		{
			set_color(RED, ON);
			set_led(i, ON);

		}
		show();
		_delay_ms(100);
		
		for (uint8_t i = 3; i<=80; i=i+4)
		{
			set_color(RED, ON);
			set_led(i, ON);

		}
		show();
		_delay_ms(100);
		for (uint8_t i = 4; i<=80; i=i+4)
		{
			set_color(RED, ON);
			set_led(i, ON);

		}
		show();
		_delay_ms(2000);
		
		
		
		
		
		for (uint8_t i = 4; i<=80; i=i+4)
		{
			set_color(RED, ON);
			set_led(i, OFF);

		}
		show();
		_delay_ms(100);

		
		
		
		
		for (uint8_t i = 3; i<=80; i=i+4)
		{
			set_color(RED, ON);
			set_led(i, OFF);

		}
		show();
		_delay_ms(1000);	
}



