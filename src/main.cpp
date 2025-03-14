#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include "DHTesp.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_ADDR 0x3C
#define SDA_PIN 37  // GPIO8 для SDA
#define SCL_PIN 36  // GPIO9 для SCL
#define DHT_PIN 17   // Пин, к которому подключен DHT11
#define LED_PIN 48   // Пин, к которому подключен NeoPixel
#define NUMPIXELS 1  // Количество NeoPixel

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
DHTesp dht;
Adafruit_NeoPixel pixels(NUMPIXELS, LED_PIN, NEO_GRB + NEO_KHZ800);

// Прототип функции
void setPixelColor(float temp);

void setup() {
  Serial.begin(115200);
  
  // Инициализация OLED
  Wire.begin(SDA_PIN, SCL_PIN); // Указываем пины I2C
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  
  // Инициализация DHT11
  dht.setup(DHT_PIN, DHTesp::DHT11);
  
  // Инициализация NeoPixel
  pixels.begin();
  pixels.show(); // Выключаем светодиод в начале
}

void loop() {
  // Чтение данных с DHT11
  TempAndHumidity data = dht.getTempAndHumidity();
  if (dht.getStatus() != 0) {
    Serial.println("Ошибка чтения DHT11");
    return;
  }

  float temperature = data.temperature;
  float humidity = data.humidity;

  // Вывод данных в Serial Monitor
  Serial.print("Температура: ");
  Serial.print(temperature);
  Serial.print(" °C, Влажность: ");
  Serial.print(humidity);
  Serial.println(" %");

  // Управление светодиодом
  setPixelColor(temperature);
  pixels.show();

  // Вывод данных на OLED
  display.clearDisplay();
  display.setCursor(10, 10);
  display.print("Temp: ");
  display.print(temperature);
  display.print(" C");
  
  display.setCursor(10, 20);
  display.print("Humidity: ");
  display.print(humidity);
  display.print(" %");
  
  display.display();

  delay(2000); // Задержка между обновлениями данных
}

// Определение функции
void setPixelColor(float temp) {
  int minTemp = 26; // Нижняя граница (зелёный)
  int maxTemp = 31; // Верхняя граница (красный)

  if (temp < minTemp) temp = minTemp;
  if (temp > maxTemp) temp = maxTemp;

  float ratio = (temp - minTemp) / (maxTemp - minTemp);
  uint8_t red = map(ratio * 100, 0, 100, 0, 255);
  uint8_t green = map(ratio * 100, 0, 100, 255, 0);
  uint8_t blue = 0;

  pixels.setPixelColor(0, pixels.Color(red, green, blue));
}