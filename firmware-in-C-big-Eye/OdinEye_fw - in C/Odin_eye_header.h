#define U1_controller 1
#define U2_controller 2
#define ON 1
#define OFF 0
#define LAT_PIN  PB1 //data latch
#define BLANK_PIN  PB2 //blank
#define SIN_PIN  PB3 //input serial data
#define SCLK_PIN  PB5 // shift clock pin
#define SLAVE_ADDRESS 0xBD //real address will be 5F
#define RED 2
#define BLUE 4
#define GREEN 3
#define RB_COLOR 0x21
#define BG_COLOR 0x23
#define RG_COLOR 0x31
#define RGB_COLOR 0x33


//set color 0x00 - OFF, 0x01 -R, 0x02 - B, 0x03 - G, 0x21 -RB, 0x31 - RG, 0x23 - BG, 0x33 = RGB

#define CLR_SCR_COMMAND 0xFF
#define OFF_LED_CLOCKWISE 0xFE
#define OFF_LED_ANTICLOCKWISE 0xFD
#define ON_LED_CLOCKWISE 0xFC
#define ON_LED_ANTICLOCKWISE 0xFB
#define PLAY_ANIMATION 0xFA
#define SET_ADDRESS 0x0A

#define COMMAND_BYTE 0
#define COLOR_BYTE 1
#define START_LED_BYTE 2
#define FINISH_LED_BYTE 3
#define STEP_LED_BYTE 4
#define DELAY_LED_BYTE 5
#define DELAY_FRAME_BYTE 6

#define SPIRAL_ANIM 0x01
#define FAN_ANIM 0x02
#define FOCUS_MAIN 0x03


uint8_t U1_registers [6];
uint8_t U2_registers [6];  //w5277c: 6 items array

void init();
void lat_impulse();
void CLK_impulse();
void send_register_data(uint8_t in_regs[6]);
void send_command(uint8_t controller);
void send_data(uint8_t controller);
void set_led(uint8_t led, uint8_t state);
void set_color(uint8_t color, uint8_t state);
void clear_reg();
void show();

uint8_t is_all_received;
uint8_t received_byte;
uint8_t is_frame_ended;
uint8_t received_byte_array[6];
uint8_t get_is_data_received();
uint8_t get_i2c_byte(uint8_t byte_number);
uint8_t get_is_frame_ended();

void clear_i2c_byte();
void set_is_frame_ended();
void clear_is_frame_ended();
void clear_is_data_received();
void i2c_delay(uint8_t byte_number);


void spiral(uint8_t color);
void fan_animation(uint8_t color,uint8_t repeat);
void focus_main(uint8_t color,uint8_t repeat);