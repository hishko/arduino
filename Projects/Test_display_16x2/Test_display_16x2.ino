#include <LiquidCrystal.h> //Подключаем библиотеку LCD дисплея
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)


void setup() {
  Serial.begin(9600); //Скорость передачи порта связи с консолью ПК
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("Привет Мир!");

  
  lcd.begin(16, 2);                 // Задаем размерность экрана
  lcd.setCursor(0, 0);              // Устанавливаем курсор в начало 1 строки
  lcd.print("Hello, world!");       // Выводим текст
  lcd.setCursor(0, 1);              // Устанавливаем курсор в начало 2 строки
  lcd.print("Test 2");                // Выводим текст
}

void loop() {
  delay(100);
  digitalWrite(LED_BUILTIN, 0);  
  delay(100);
  digitalWrite(LED_BUILTIN, 1); 
}
