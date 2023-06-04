/*
* OdinEye_fw - in C.c
*
* Created: 09.08.2018 15:23:32
* Author : User3
*/
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdint.h>
#include <avr/interrupt.h>
#include <avr/wdt.h>

#include "hardware and init.c"
#include "Odin_eye_header.h"
#include "IRQ.c"
#include "set_led.c"
//#include "Set_led_small_pcb.c"
#include "animations.c"
#include <avr/eeprom.h>

uint8_t is_frame_ended=0;


uint8_t get_is_frame_ended(){
	return is_frame_ended;
}
void set_is_frame_ended(){
	is_frame_ended =1;
}
void clear_is_frame_ended(){
	is_frame_ended =0;
}



void i2c_delay(uint8_t byte_number){
	uint8_t delay = get_i2c_byte(byte_number);
	if (delay == 0){
		return;
	}
	if (byte_number==6){
		while (delay--){
			wdt_reset(); //try to not reset by delay
			_delay_ms(10); //between frames delay x10
		}
		return;
		}
	while (delay--){
		wdt_reset(); //try to not reset by delay
		_delay_ms(1);
	}
}


int main(void)
{
	init();
	clear_reg();
	show();
	while (1)
	{
		
		if (get_is_data_received())
	{	
		clear_is_data_received();
		clear_is_frame_ended();
		//get command
		switch (get_i2c_byte(COMMAND_BYTE)){
			case SET_ADDRESS:{
				cli();
				TWCR &=~ (1<<TWEN);
				TWAR = get_i2c_byte(COLOR_BYTE);
				TWCR |= (1<<TWEN);
				eeprom_write_byte((uint8_t*) 1, get_i2c_byte(COLOR_BYTE));
				sei();
				set_is_frame_ended();
				clear_i2c_byte();
				break;
			}
			case CLR_SCR_COMMAND:{
				clear_reg();
				show();
				set_is_frame_ended();
				clear_i2c_byte();
				break;
			}
			case ON_LED_CLOCKWISE:{
				set_color(get_i2c_byte(COLOR_BYTE), ON);
				for (uint8_t i=get_i2c_byte(START_LED_BYTE);i<=get_i2c_byte(FINISH_LED_BYTE);i=i+get_i2c_byte(STEP_LED_BYTE))
				{
					set_led(i,ON);
					show();
					i2c_delay(DELAY_LED_BYTE);
				}
				i2c_delay(DELAY_FRAME_BYTE);
				set_is_frame_ended();
				clear_i2c_byte();
				break;
			}
			case ON_LED_ANTICLOCKWISE:{
				set_color(get_i2c_byte(COLOR_BYTE), ON);
				for (uint8_t i=get_i2c_byte(START_LED_BYTE);i>=get_i2c_byte(FINISH_LED_BYTE);i=i-get_i2c_byte(STEP_LED_BYTE))
				{	
					if (i>81)
				{break;
				}
					set_led(i,ON);
					show();
					i2c_delay(DELAY_LED_BYTE);
				}
				i2c_delay(DELAY_FRAME_BYTE);
				set_is_frame_ended();
				clear_i2c_byte();
				break;
			}
			case OFF_LED_ANTICLOCKWISE:{
				//set_color(get_i2c_byte(COLOR_BYTE), ON);
				for (uint8_t i=get_i2c_byte(START_LED_BYTE);i>=get_i2c_byte(FINISH_LED_BYTE);i=i-get_i2c_byte(STEP_LED_BYTE))
				{	if (i>81)
					{break;
					}
					set_led(i,OFF);
					show();
					i2c_delay(DELAY_LED_BYTE);
				}
				i2c_delay(DELAY_FRAME_BYTE);
				set_is_frame_ended();
				clear_i2c_byte();
				break;
			}
			case OFF_LED_CLOCKWISE:{
				//set_color(get_i2c_byte(COLOR_BYTE), ON);
				for (uint8_t i=get_i2c_byte(START_LED_BYTE);i<=get_i2c_byte(FINISH_LED_BYTE);i=i+get_i2c_byte(STEP_LED_BYTE))
				{
					set_led(i,OFF);
					show();
					i2c_delay(DELAY_LED_BYTE);
				}
				i2c_delay(DELAY_FRAME_BYTE);
				set_is_frame_ended();
				clear_i2c_byte();
				break;
			}
			case PLAY_ANIMATION:{
				switch(get_i2c_byte(START_LED_BYTE)){
					case SPIRAL_ANIM:{
						spiral(get_i2c_byte(COLOR_BYTE));
						i2c_delay(DELAY_FRAME_BYTE);
						set_is_frame_ended();
						clear_i2c_byte();
						break;
					}
					case FAN_ANIM:{
						fan_animation(get_i2c_byte(COLOR_BYTE),get_i2c_byte(STEP_LED_BYTE));
						set_is_frame_ended();
						clear_i2c_byte();
						break;
					}
				}	
			}
			
			default:
			break;
		}
	}
		else{
			wdt_reset(); //try to not reboot while waiting
			set_is_frame_ended();
		}
	}
	}

