# ESP32-S3 + OLED + DHT11 + NeoPixel

![Project Logo](https://via.placeholder.com/150)

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
