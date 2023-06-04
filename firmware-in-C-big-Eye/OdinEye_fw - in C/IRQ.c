#include <compat/twi.h>
uint8_t received_byte_array[6];
uint8_t is_all_received;

uint8_t get_is_data_received(){
	return is_all_received;
}
void clear_is_data_received(){
	is_all_received =0;
}
uint8_t get_i2c_byte(uint8_t i){
	return received_byte_array[i];
}
void clear_i2c_byte(){
	
	for (uint8_t i=0; i<6;i++){
		received_byte_array[i]=0;
	}
}



uint8_t received_byte_counter=0;

ISR(TWI_vect){
	uint8_t twi_status=TWSR & 0xF8; //mask prescaler bits
	// 	;TWSR = 0x60, Own SLA+W has been received; ACK has been returned
	// 	;TWSR = 0x68, Arbitration lost in SLA+R/W as Master; own SLA+W has been received; ACK has been returned
	// 	;TWSR = 0x70, General call address has been received; ACK has been returned
	// 	;TWSR = 0x78, Arbitration lost in SLA+R/W as Master; General call address has been received; ACK has beenreturned
	// 	;TWSR = 0x80, Previously addressed with own SLA+W; data has been received; ACK has been returned
	// 	;TWSR = 0x88, Previously addressed with own SLA+W; data has been received; NOT ACK has been returned
	// 	;TWSR = 0x90, Previously addressed with general call; data has been received; ACK has been returned
	// 	;TWSR = 0x98, Previously addressed with general call; data has been received; NOT ACK has been returned
	// 	;TWSR = 0xA0, A STOP condition or repeatedSTART condition has been received while still addressed as Slave
	switch (twi_status){
		case TW_SR_SLA_ACK :{// 0x60 receive start+correct address, ack returned
			//maybe do smth in future
			break;
		}
		case TW_SR_DATA_ACK :{// 0x80 data byte received, ack returned
			if ((TWDR == 0xAA)&&(received_byte_counter ==0))
			{	
				received_byte_counter=1;
				
			}
			else if (received_byte_counter){
				received_byte_array[received_byte_counter-1] = TWDR;
				received_byte_counter++;
			}
			if (received_byte_counter ==8)
			{	received_byte_counter=0;
				is_all_received=1;
			}
			
			break;
		}
		case TW_SR_STOP:
		case TW_ST_SLA_ACK:{	
			if (get_is_frame_ended())
			{
			TWDR = 0x00;
			}
			else{
			TWDR = 0xFF;
			}
			break;}
			 // 0xA8: SLA+R received, ACK returned
		case TW_ST_DATA_ACK:    // 0xB8: data transmitted, ACK received
		case TW_ST_DATA_NACK:   // 0xC0: data transmitted, NACK received
		case TW_ST_LAST_DATA:   // 0xC8: last data byte transmitted, ACK received
		case TW_BUS_ERROR:  // 0x00: illegal start or stop condition
		default:
		break;
	}
	
	
	TWCR |= (1<<TWINT); //clear TWI flag
}