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
RB = 0x21
RG = 0x31
BG = 0x23
RGB = 0x33
OFF = 0

STEP = 1
TIME = 0
ANIM = 0

# Класс LED
class LED:

    def __init__(self, i2c_bus, index):
        self.is_on = False  # Изначально светодиод выключен
        
        self.client = i2c_bus

        self.index = index


    def turn_on(self, COLOR):
        self.is_on = True
        
        pak = [170, ON_LED_CLOCKWISE, COLOR, self.index, self.index, STEP, TIME, 0]
        self.client.write_i2c_block_data(ADDRESS_L, 0, pak)


    def turn_off(self, COLOR):
        self.is_on = False
        
        pak = [170, OFF_LED_CLOCKWISE, COLOR, self.index, self.index, STEP, TIME, 0]
        self.client.write_i2c_block_data(ADDRESS_L, 0, pak)

def clearRGB():
   pak = [170, CLR_SCR_COMMAND, 0, 1, 80, STEP, TIME, 0]#252
   i2c_bus.write_i2c_block_data(ADDRESS_L, 0, pak)

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
    #print(array)
    return array



def ledon(image_array):
  # Перебор транспонированных столбцов и массива изображения
  for leds, values in zip(transposed_columns, image_array):
      for led, value in zip(leds, values):
          if np.array_equal(value, [255, 0, 0]):
              COLOR = BLUE
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)
          if np.array_equal(value, [0, 255, 0]):
              COLOR = GREEN
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)
          if np.array_equal(value, [0, 0, 255]):
              COLOR = RED
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)
          if np.array_equal(value, [0, 255, 255]):
              COLOR = RG
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)
          if np.array_equal(value, [255, 0, 255]):
              COLOR = RB
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)
          if np.array_equal(value, [255, 255, 0]):
              COLOR = BG
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)
          if np.array_equal(value, [255, 255, 200]):
              COLOR = RGB
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)
          if np.array_equal(value, [0, 0, 0]):
              COLOR = OFF
              led.turn_on(COLOR)  # Включаем светодиод
              time.sleep(0.00002)

def anim2():
    for i in range(2):
        # Путь к изображению
        clearRGB()
        image_path = "eyeRF1.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF2.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF3.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF4.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF5.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF6.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF7.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF8.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF9.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF10.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF11.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF12.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF13.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

def anim1():
    for i in range(20):
        clearRGB()
        image_path = "eyeRF14.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF15.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF16.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF17.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF18.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF19.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

        clearRGB()
        image_path = "eyeRF20.png"
        image_array = image_to_array(image_path)
        ledon(image_array)
        time.sleep(delay)

def anim():
    for i in range(10):
      clearRGB()
      image_path = "eyeRF21.png"
      image_array = image_to_array(image_path)
      ledon(image_array)
      time.sleep(delay)

      clearRGB()
      image_path = "eyeRF22.png"
      image_array = image_to_array(image_path)
      ledon(image_array)
      time.sleep(delay)

delay = 0.05
anim1()


















