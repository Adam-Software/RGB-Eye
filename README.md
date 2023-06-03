# RGB-Eye
This is example how to control Adam RGB Eye by i2c interface

#define CLR_SCR_COMMAND 0xFF //очистить RGB матрицу
#define OFF_LED_CLOCKWISE 0xFE //выключение светодиодов по часовой стрелке
#define OFF_LED_ANTICLOCKWISE 0xFD //выключение светодиодов против часовой стрелке
#define ON_LED_CLOCKWISE 0xFC //включение светодиодов по часовой стрелке
#define ON_LED_ANTICLOCKWISE 0xFB //включение светодиодов против часовой стрелке
#define PLAY_ANIMATION 0xFA //проиграть анимацию зашитую в памяти контроллера RGB
#define SET_ADDRESS 0x0A //установить адрес I2C
#define ON_LED_NOW 0xF9 //включить светодиод

#
#WRITE ADRESS
# pak = [0xAA, 0x0A, 0x5E, 0, 0, 0, 0,0]#252
# b.write_i2c_block_data(0x5f, 0, pak)
# time.sleep(2)

#pak=[170,252,2,1,80,3,30,0]

#write_i2c_block_data(int addr,char cmd,long vals[])
#time.sleep(1)
#pakkets addr,reg , color 2 red -3 green -4 blue ,start led ,stop led ,step,time,0,
#uint8_t color, uint8_t startLED, uint8_t finishLED, uint8_t stepLED, uint8_t delayLED, uint8_t delayFrame
