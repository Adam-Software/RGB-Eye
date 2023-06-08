import numpy as np
import cv2
import smbus
import time

i2c_bus = smbus.SMBus(1)

ADDRESS_R = 0x5E
ADDRESS_L = 0x5F

CONST = 170
CLR_SCR_COMMAND = 0xFF          #очистить RGB матрицу
OFF_LED_CLOCKWISE = 0xFE       #выключение светодиодов по часовой стрелке
OFF_LED_ANTICLOCKWISE = 0xFD  #выключение светодиодов против часовой стрелке
ON_LED_CLOCKWISE = 0xFC      #включение светодиодов по часовой стрелке
ON_LED_ANTICLOCKWISE = 0xFB #включение светодиодов против часовой стрелке
PLAY_ANIMATION = 0xFA      #проиграть анимацию зашитую в памяти контроллера RGB
SET_ADDRESS = 0x0A        #установить адрес I2C
ON_LED_NOW = 0xF9        #включить светодиод

#set color 0x00 - OFF, 2 -R, 4 - B, 3 - G, 0x21 -RB, 0x31 - RG, 0x23 - BG, 0x33 = RGB
RED = 2
GREEN = 3
BLUE = 4

STEP = 0
TIME = 0
ANIM = 0

# Класс LED
class LED:

    def __init__(self, i2c_bus, index):
        self.is_on = False  # Изначально светодиод выключен
        
        self.client = i2c_bus

        self.index = index


    def turn_on(self):
        self.is_on = True
        
        pak = [170, 0xFC, 0x31, self.index, self.index, 1, 0, 0]
        self.client.write_i2c_block_data(0x5E, 0, pak)


    def turn_off(self):
        self.is_on = False
        
        pak = [170, 0xFE, 0x31, self.index, self.index, 1, 0, 0]
        self.client.write_i2c_block_data(0x5E, 0, pak)

#очистка матрицы
pak = [170, 0xFF, 2, 1, 80, 1, 0, 0]#252
i2c_bus.write_i2c_block_data(0x5E, 0, pak)
#b.write_i2c_block_data(0x5F, 0, pak)
time.sleep(0.100)

# Создание списка объектов LED
led_list = [LED(i2c_bus, i + 1) for i in range(80)]

# Распределение LED по столбцам
columns = 20
column_size = 4
columns_list = [led_list[i:i+column_size] for i in range(0, len(led_list), column_size)]
transposed_columns = list(zip(*columns_list))

# Загрузка изображения и преобразование в массив NumPy
def image_to_array(image_path):
    image = cv2.imread(image_path)
    array = np.array(image)
    return array

# Путь к изображению
image_path = "eye2.png"
image_array = image_to_array(image_path)

# Перебор транспонированных столбцов и массива изображения
for leds, values in zip(transposed_columns, image_array):
    for led, value in zip(leds, values):
        if not np.array_equal(value, [255, 255, 255]):
            led.turn_on()  # Включаем светодиод
            time.sleep(0.0002)
        #else:
           # led.turn_off()  # Выключаем светодиод

# Проверка состояния светодиодов
for led in led_list:
    if led.is_on:
        print(f"LED {led.index} включен")
    else:
        print(f"LED {led.index} выключен")
