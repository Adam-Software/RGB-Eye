import numpy as np
import cv2
import smbus
import time

i2c_bus = smbus.SMBus(1)

ADDRESS_L = 0x5F
ADDRESS_R = 0x5E

COLORS = {
    "OFF": 0,
    "RED": 2,
    "GREEN": 3,
    "BLUE": 4,
    "RB": 0x21,
    "RG": 0x31,
    "BG": 0x23,
    "RGB": 0x33
}

STEP = 1
TIME = 0
ANIM = 0

class LED:
    def __init__(self, i2c_bus, address, index):
        self.is_on = False
        self.client = i2c_bus
        self.address = address
        self.index = index
        self.color = COLORS["OFF"]

    def turn_on(self, color):
        # Включение светодиода определенного цвета
        self.is_on = True
        self.color = color
        pak = [170, 0xFC, self.color, self.index, self.index, STEP, TIME, ANIM]
        self.client.write_i2c_block_data(self.address, 0, pak)

    def turn_off(self):
        # Выключение светодиода
        self.is_on = False
        self.color = COLORS["OFF"]
        pak = [170, 0xFE, self.color, self.index, self.index, STEP, TIME, ANIM]
        self.client.write_i2c_block_data(self.address, 0, pak)

class EyeController:
    def __init__(self, i2c_bus, address):
        self.client = i2c_bus
        self.address = address
        #self.led_list = zip(*[iter([LED(i2c_bus, address, i + 1) for i in range(80)])] * 4)
        leds = [LED(i2c_bus, address, i + 1) for i in range(80)]
        columns_list = [leds[i:i+4] for i in range(0, len(leds), 4)]
        self.led_list = list(zip(*columns_list))
         
    def set_led_color(self, index, color):
        # Установка цвета светодиода по указанному индексу
        led = self.led_list[index - 1]
        led.turn_on(color)

    def clear_leds(self):
        # Выключение всех светодиодов
        for leds in self.led_list:
            for led in leds:
                led.turn_off()
                time.sleep(0.0002)

    def clear_rgb(self):
        # Очистка RGB-матрицы
        pak = [170, 0xFF, 0, 1, 80, STEP, TIME, 0]
        self.client.write_i2c_block_data(self.address, 0, pak)

    def process_image(self, image_path):
        # Обработка изображения и управление светодиодами
        image = cv2.imread(image_path)
        image_array = np.array(image)

        for leds, values in zip(self.led_list, image_array):
            for led, value in zip(leds, values):
                if np.array_equal(value, [255, 0, 0]):
                    led.turn_on(COLORS["BLUE"])
                elif np.array_equal(value, [0, 255, 0]):
                    led.turn_on(COLORS["GREEN"])
                elif np.array_equal(value, [0, 0, 255]):
                    led.turn_on(COLORS["RED"])
                elif np.array_equal(value, [0, 255, 255]):
                    led.turn_on(COLORS["RG"])
                elif np.array_equal(value, [255, 0, 255]):
                    led.turn_on(COLORS["RB"])
                elif np.array_equal(value, [255, 255, 0]):
                    led.turn_on(COLORS["BG"])
                elif np.array_equal(value, [255, 255, 200]):
                    led.turn_on(COLORS["RGB"])
                else:
                    led.turn_off()

                time.sleep(0.0002)

    def display_image(self, image_path):
        # Отображение изображения на светодиодах
        #self.clear_rgb()
        self.process_image(image_path)


# Пример использования

i2c_bus = smbus.SMBus(1)

# Создание объектов EyeController для левого и правого глаза
eye_controller_l = EyeController(i2c_bus, ADDRESS_L)
#eye_controller_r = EyeController(i2c_bus, ADDRESS_R)

# Отображение изображения на светодиодах левого глаза
#image_path_l = "ExampleImage/eyeR.png"
#eye_controller_l.display_image(image_path_l)
#eye_controller_l.clear_leds()
#time.sleep(1)

eye_controller_l.clear_rgb()
for j in range(20):
  for i in range(7):
      i =i+10
      image_path_l = "ExampleImage/"+str(i)+".png"
      eye_controller_l.display_image(image_path_l)
      time.sleep(0.05)

time.sleep(5)
# Отображение изображения на светодиодах правого глаза
#image_path_r = "eye_right.png"
#eye_controller_r.display_image(image_path_r)

# Установка цвета для определенных светодиодов левого глаза
#eye_controller_l.set_led_color(1, COLORS["BLUE"])
#eye_controller_l.set_led_color(2, COLORS["RED"])
#eye_controller_l.set_led_color(3, COLORS["GREEN"])
#eye_controller_l.set_led_color(4, COLORS["OFF"])

# Установка цвета для определенных светодиодов правого глаза
#eye_controller_r.set_led_color(1, COLORS["BLUE"])
#eye_controller_r.set_led_color(2, COLORS["RED"])
#eye_controller_r.set_led_color(3, COLORS["GREEN"])
#eye_controller_r.set_led_color(4, COLORS["OFF"])

# Выключение всех светодиодов левого и правого глаза
#eye_controller_l.clear_leds()
eye_controller_l.clear_rgb()
#eye_controller_r.clear_leds()
