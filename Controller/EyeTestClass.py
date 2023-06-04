import numpy as np
import cv2

# Класс LED
class LED:
    def __init__(self, index):
        self.index = index
        self.is_on = False  # Изначально светодиод выключен

    def turn_on(self):
        self.is_on = True

    def turn_off(self):
        self.is_on = False

# Создание списка объектов LED
led_list = [LED(i + 1) for i in range(80)]

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
image_path = "eye.png"
image_array = image_to_array(image_path)

# Перебор транспонированных столбцов и массива изображения
for leds, values in zip(transposed_columns, image_array):
    for led, value in zip(leds, values):
        if not np.array_equal(value, [0, 0, 0]):
            led.turn_on()  # Включаем светодиод
        else:
            led.turn_off()  # Выключаем светодиод

# Проверка состояния светодиодов
for led in led_list:
    if led.is_on:
        print(f"LED {led.index} включен")
    else:
        print(f"LED {led.index} выключен")