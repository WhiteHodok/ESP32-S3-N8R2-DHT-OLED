Извините за путаницу! Теперь я объединю всё в один блок кода, чтобы вы могли скопировать его за один клик без разрывов. Вот исправленный текст:

```markdown
# ESP32-S3 + OLED + DHT11 + NeoPixel

![Project Logo](https://via.placeholder.com/150) <!-- Замените ссылку на логотип вашего проекта, если есть -->

Этот проект демонстрирует использование ESP32-S3 для считывания данных с датчика DHT11 (температура и влажность), отображения их на OLED-дисплее и управления цветом светодиода NeoPixel в зависимости от температуры.

This project demonstrates the use of ESP32-S3 to read data from a DHT11 sensor (temperature and humidity), display it on an OLED screen, and control the color of a NeoPixel LED based on temperature.

---

## Оглавление
- [Описание проекта](#описание-проекта)
- [Требования](#требования)
- [Установка и настройка](#установка-и-настройка)
- [Используемые библиотеки](#используемые-библиотеки)
- [Схема подключения](#схема-подключения)

## Table of Contents
- [Project Description](#project-description)
- [Requirements](#requirements)
- [Installation and Setup](#installation-and-setup)
- [Libraries Used](#libraries-used)
- [Wiring Diagram](#wiring-diagram)

---

## Описание проекта

Этот проект предназначен для считывания данных с датчика DHT11 (температура и влажность) и отображения их на OLED-дисплее. Также проект включает управление светодиодом NeoPixel, который меняет цвет в зависимости от температуры:
- **Зеленый**: Температура ниже 26°C.
- **Красный**: Температура выше 31°C.
- **Градиент от зеленого к красному**: Температура в диапазоне 26°C–31°C.

Проект разработан для платы **ESP32-S3** и может быть развернут с использованием PlatformIO.

---

## Project Description

This project is designed to read data from a DHT11 sensor (temperature and humidity) and display it on an OLED screen. The project also includes control of a NeoPixel LED, which changes color depending on the temperature:
- **Green**: Temperature below 26°C.
- **Red**: Temperature above 31°C.
- **Gradient from green to red**: Temperature in the range of 26°C–31°C.

The project is developed for the **ESP32-S3** board and can be deployed using PlatformIO.

---

## Требования

- Плата **ESP32-S3**.
- Датчик **DHT11**.
- OLED-дисплей **SSD1306** (128x64).
- Светодиод **NeoPixel** (1 шт.).
- PlatformIO для сборки и загрузки прошивки.

---

## Requirements

- **ESP32-S3** board.
- **DHT11** sensor.
- **SSD1306** OLED display (128x64).
- **NeoPixel** LED (1 piece).
- PlatformIO for building and uploading the firmware.

---

## Установка и настройка

1. Установите [PlatformIO](https://platformio.org/).
2. Клонируйте репозиторий:
   ```bash
   git clone https://github.com/ваш-username/ваш-репозиторий.git
   ```
3. Перейдите в папку проекта:
   ```bash
   cd ваш-репозиторий
   ```
4. Установите необходимые библиотеки (см. раздел [Используемые библиотеки](#используемые-библиотеки)).
5. Подключите компоненты согласно [схеме подключения](#схема-подключения).
6. Соберите и загрузите проект на плату:
   ```bash
   pio run --target upload
   ```

---

## Installation and Setup

1. Install [PlatformIO](https://platformio.org/).
2. Clone the repository:
   ```bash
   git clone https://github.com/your-username/your-repository.git
   ```
3. Navigate to the project folder:
   ```bash
   cd your-repository
   ```
4. Install the required libraries (see [Libraries Used](#libraries-used)).
5. Connect the components according to the [wiring diagram](#wiring-diagram).
6. Build and upload the project to the board:
   ```bash
   pio run --target upload
   ```

---

## Используемые библиотеки

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) – для работы с графикой на OLED.
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) – драйвер для OLED-дисплея SSD1306.
- [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) – управление светодиодами NeoPixel.
- [DHTesp](https://github.com/beegee-tokyo/DHTesp) – библиотека для работы с датчиком DHT11.

Установите библиотеки через PlatformIO:
```bash
pio pkg install --library "adafruit/Adafruit GFX Library"
pio pkg install --library "adafruit/Adafruit SSD1306"
pio pkg install --library "adafruit/Adafruit NeoPixel"
pio pkg install --library "beegee-tokyo/DHTesp"
```

---

## Libraries Used

- [Adafruit GFX Library](https://github.com/adafruit/Adafruit-GFX-Library) – for graphics on OLED.
- [Adafruit SSD1306](https://github.com/adafruit/Adafruit_SSD1306) – driver for SSD1306 OLED display.
- [Adafruit NeoPixel](https://github.com/adafruit/Adafruit_NeoPixel) – control of NeoPixel LEDs.
- [DHTesp](https://github.com/beegee-tokyo/DHTesp) – library for working with the DHT11 sensor.

Install the libraries via PlatformIO:
```bash
pio pkg install --library "adafruit/Adafruit GFX Library"
pio pkg install --library "adafruit/Adafruit SSD1306"
pio pkg install --library "adafruit/Adafruit NeoPixel"
pio pkg install --library "beegee-tokyo/DHTesp"
```

---

## Схема подключения

```plaintext
ESP32-S3:
- SDA_PIN (GPIO37) -> SDA на OLED
- SCL_PIN (GPIO36) -> SCL на OLED
- DHT_PIN (GPIO17) -> DATA на DHT11
- LED_PIN (GPIO48) -> DIN на NeoPixel
```

---

## Wiring Diagram

```plaintext
ESP32-S3:
- SDA_PIN (GPIO37) -> SDA on OLED
- SCL_PIN (GPIO36) -> SCL on OLED
- DHT_PIN (GPIO17) -> DATA on DHT11
- LED_PIN (GPIO48) -> DIN on NeoPixel
```
