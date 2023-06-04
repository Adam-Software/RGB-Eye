#include "Odin_eye_header.h"
#include <avr/wdt.h>
#include <avr/eeprom.h>

void CLK_impulse(){//w5277c: задержка должна быть около 0.000002s
	_delay_us(0.02); //delay 40 ns for TLC
	PORTB |= (1<<SCLK_PIN);
	_delay_us(0.02);
	PORTB &=~ (1<<SCLK_PIN);
}

void lat_impulse(){//w5277c: задержка должна быть около 0.000002s
	PORTB |= (1<<LAT_PIN);
	_delay_us(0.02);
	PORTB &=~ (1<<LAT_PIN);
	_delay_us(0.02);
}

void send_register_data(uint8_t in_regs[6]){
	for(uint8_t i = 1; i<=6; ++i){
		uint8_t reg = in_regs[6-i];  //w5277: Биты вытаскиваем начиная со старшего байта и старшего бита
		for(uint8_t j = 1; j<=8; ++j){
			if ((reg)&(1<<(8-j))){
				PORTB |= (1<<SIN_PIN);
			}
			else{
				PORTB &=~ (1<<SIN_PIN);
			}
			CLK_impulse();
		}
	}
}

void send_command(uint8_t controller){
	PORTB |= (1<<SIN_PIN);
	CLK_impulse();
	switch (controller) {
		case U1_controller:{
			send_register_data(U1_registers);
		break;}
		case U2_controller:{
			send_register_data(U2_registers);
			break;
		}
	}
}

void send_data(uint8_t controller){
	PORTB &=~ (1<<SIN_PIN);
	CLK_impulse();
	switch (controller) {
		case U1_controller:{
			send_register_data(U1_registers);
		break;}
		case U2_controller:{
			send_register_data(U2_registers);
			break;
		}
	}
}


void clear_reg(){
	for (uint8_t i=0; i<=5; i++){
		U1_registers[i]=0;
	}
	for (uint8_t i=0; i<=5; i++){
		U2_registers[i]=0;
	}
}

void clear_reg_ff(){
	for (uint8_t i=0; i<=5; i++){
		U1_registers[i]=0xFF;
	}
	for (uint8_t i=0; i<=5; i++){
		U2_registers[i]=0xFF;
	}
}



void show(){
	send_data(U2_controller);
	send_data(U1_controller);
	lat_impulse();
}



void init(){
	cli();
	DDRB |= (1<<SIN_PIN) | (1<<LAT_PIN) | (1<<SCLK_PIN) | (1<<BLANK_PIN);
	//PORTB |= (1<<SIN_PIN) | (1<<LAT_PIN);
	PORTB &=~ (1<<SCLK_PIN) | (1<<BLANK_PIN) ;
	PORTB |= (1<<BLANK_PIN) | (1<<SIN_PIN) | (1<<LAT_PIN);
	//setup I2C
	//TWSR |= 0x00;
	//TWBR |= 0x48 //slave doesnt depend on bitrate
	uint8_t address = eeprom_read_byte((uint8_t*) 1);
	if (address==0xFF) //if nothing in EEPROM, will write default address
	{	
		eeprom_write_byte((uint8_t*) 1, 0xBD); // change address 0xB0/2 = 58
	}
	TWAR = eeprom_read_byte((uint8_t*) 1); //read address from eeprom
	// 	TWCR &=~ (1<<TWSTO); //disable stop condition
	// 	TWCR &=~ (1<<TWSTA); //disable
	TWCR |= (1<<TWINT);
	TWCR |= (1<<TWIE);// enable INT
	TWCR |= (1<<TWEA); //enable ack
	TWCR |= (1<<TWEN); //enable i2c/TWI
	TWBR = 0x02; //set 400khz
	TWSR &=~ (1<<TWPS0) | (1<<TWPS1); //set prescaler to 1
	TWDR = 0x00;
	wdt_enable(WDTO_2S); //enable watchdog to 2s
	sei();
	lat_impulse();

	U1_registers[0] = 0xFF;
	U1_registers[1] = 0xFF;
	U1_registers[2] = 0xFF;
	U1_registers[3] = 0x00;
	U1_registers[4] = 0x00;
	U1_registers[5] = 0b10010110; 
	
	U2_registers[0] = 0xFF;
	U2_registers[1] = 0xFF;
	U2_registers[2] = 0xFF;
	U2_registers[3] = 0x00;
	U2_registers[4] = 0x00;
	U2_registers[5] = 0b10010110;
	/*
	R1 |= (0b11111000 | 0b00000111) ; //; 0-2 MC, 3-7 part of BCR
	R2 |= (0b11111100 | 0b00000011); //8-9 part of BCR, 10-15 part of BCG
	R3 |= (0b11111110 | 0b00000001); //16 part of BCR, 17-23 BCB
	R4 |= (0b11111110 | 0b00000001); //24-25 SIDLD, 26-28 LODVLT, 29-30 LSDVLT, 31 part of PSMODE
	R5 |= (0b00000000 | 0b00000000); //32 part of PSMODE, 33-39 RSV
	R6 |= (0b10010110); // 40-47 CORRECT WRTCMD */
	send_command(U1_controller);
	send_command(U2_controller);
	lat_impulse();
	
	for (int i=1; i<=6; ++i){
		U1_registers[i]=0;
	}
	for (int i=1; i<=6; ++i){
		U2_registers[i]=0;
	}
	
	send_data(U1_controller);
	send_data(U2_controller);
	lat_impulse();
	PORTB &=~ (1<<BLANK_PIN);
}
