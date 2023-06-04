import smbus
import time
b = smbus.SMBus(1)

#define CLR_SCR_COMMAND 0xFF          //очистить RGB матрицу
#define OFF_LED_CLOCKWISE 0xFE       //выключение светодиодов по часовой стрелке
#define OFF_LED_ANTICLOCKWISE 0xFD  //выключение светодиодов против часовой стрелке
#define ON_LED_CLOCKWISE 0xFC      //включение светодиодов по часовой стрелке
#define ON_LED_ANTICLOCKWISE 0xFB //включение светодиодов против часовой стрелке
#define PLAY_ANIMATION 0xFA      //проиграть анимацию зашитую в памяти контроллера RGB
#define SET_ADDRESS 0x0A        //установить адрес I2C
#define ON_LED_NOW 0xF9        //включить светодиод

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
#
#очистка RGB
pak = [170, 255, 0, 0, 0, 0, 0, 0]
b.write_i2c_block_data(0x5f, 0, pak)
time.sleep(0.005)
pak = [170, 255, 0, 0, 0, 0, 0, 0]
b.write_i2c_block_data(0x5E, 0, pak)
time.sleep(0.1)

for i in range(1,80):

	pak = [170, 0xFC, 2, i, i, 1, 0, 0]# зажечь один светодиод по часовой стрелке
	b.write_i2c_block_data(0x5F, 0, pak)
	time.sleep(0.005)
	pak = [170, 0xFC, 2, i, i, 1, 0, 0]#252
	b.write_i2c_block_data(0x5E, 0, pak)

	time.sleep(0.1)

	pak = [170, 0xFE, 2, i, i, 1, 0, 0]  # погасить один светодиод по часовой стрелке
	b.write_i2c_block_data(0x5F, 0, pak)
	time.sleep(0.005)
	pak = [170, 0xFE, 2, i, i, 1, 0, 0]  # 252
	b.write_i2c_block_data(0x5E, 0, pak)
	time.sleep(0.005)

#очистка RGB
pak=[170,255,0,0,0,0,0,0]
b.write_i2c_block_data(0x5f,0,pak)
time.sleep(0.005)
pak=[170,255,0,0,0,0,0,0]
b.write_i2c_block_data(0x5E,0,pak)
time.sleep(0.3)

for i in range(1,80):
	i=81-i
	pak = [170, 0xFB, 2, i, i, 1, 0, 0]# зажечь один светодиод против часовой стрелке
	b.write_i2c_block_data(0x5F, 0, pak)
	time.sleep(0.005)
	pak = [170, 0xFB, 2, i, i, 1, 0, 0]#252
	b.write_i2c_block_data(0x5E, 0, pak)

	time.sleep(0.1)

	pak = [170, 0xFD, 2, i, i, 1, 0, 0]  # погасить один светодиод против часовой стрелке
	b.write_i2c_block_data(0x5F, 0, pak)
	time.sleep(0.005)
	pak = [170, 0xFD, 2, i, i, 1, 0, 0]  # 252
	b.write_i2c_block_data(0x5E, 0, pak)
	time.sleep(0.005)

#очистка RGB
pak=[170,255,0,0,0,0,0,0]
b.write_i2c_block_data(0x5f,0,pak)
time.sleep(0.005)
pak=[170,255,0,0,0,0,0,0]
b.write_i2c_block_data(0x5E,0,pak)
time.sleep(0.005)
#
	#pak = [170, 0xFE, 2, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5F, 0, pak)
	#time.sleep(0.005)
	#pak = [170, 0xFE, 2, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5E, 0, pak)
	#time.sleep(0.400)
#
	#pak=[170,255,0,0,0,0,5,0]
	#b.write_i2c_block_data(0x5f,0,pak)
	#time.sleep(0.005)
	#pak=[170,255,0,0,0,0,5,0]
	#b.write_i2c_block_data(0x5E,0,pak)
	#time.sleep(0.005)
#
	#pak = [170, 0xFC, 4, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5F, 0, pak)
	#time.sleep(0.005)
	#pak = [170, 0xFB, 4, 80, 1, 1, 4,0]#252
	#b.write_i2c_block_data(0x5E, 0, pak)
	#time.sleep(0.400)
#
	#pak = [170, 0xFE, 4, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5F, 0, pak)
	#time.sleep(0.005)
	#pak = [170, 0xFE, 4, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5E, 0, pak)
	#time.sleep(0.400)
#
	#pak=[170,255,0,0,0,0,5,0]
	#b.write_i2c_block_data(0x5f,0,pak)
	#time.sleep(0.005)
	#pak=[170,255,0,0,0,0,5,0]
	#b.write_i2c_block_data(0x5E,0,pak)
	#time.sleep(0.005)
	#
	#pak = [170, 0xFC, 3, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5F, 0, pak)
	#time.sleep(0.005)
	#pak = [170, 0xFB, 3, 80, 1, 1, 4,0]#252
	#b.write_i2c_block_data(0x5E, 0, pak)
	#time.sleep(0.400)
#
	#pak = [170, 0xFE, 3, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5F, 0, pak)
	#time.sleep(0.005)
	#pak = [170, 0xFE, 3, 1, 80, 1, 4,0]#252
	#b.write_i2c_block_data(0x5E, 0, pak)
	#time.sleep(0.400)

# pak = [170, 0xFC, 3, 1, 80, 4, 30, 0]
# b.write_i2c_block_data(0x5f, 0, pak)


#time.sleep(5)
#pak = [170, 0xFF, 0, 0, 0, 0, 0, 0]
#b.write_i2c_block_data(0x5f, 0, pak)



# for i in range(1,80):
#     pak = [170, 252, 2, i, i, 1, 30, 0]
#     b.write_i2c_block_data(0x5f, 0, pak)
#     time.sleep(0.1)
#     pak = [170, 255, 0, 0, 0, 0, 0, 0]
#     b.write_i2c_block_data(0x5f, 0, pak)
#     time.sleep(0.1)
