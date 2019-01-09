
#include <SPI.h> //SPI — библиотека, реализующая передачу данных через интерфейс SPI.

byte shim5 = 5; // Указываем номер порта с ШИМ
byte shim6 = 6; // Указываем номер порта с ШИМ


void setup() {
  Serial.begin(9600); //Скорость передачи порта связи с консолью ПК
  pinMode(shim5, OUTPUT); // настроить порт как выход
  pinMode(shim6, OUTPUT); // настроить порт как выход
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  for(int i = 100;i <= 250;i++){    
    delay(50);
    digitalWrite(LED_BUILTIN, 0);
    delay(50);
    digitalWrite(LED_BUILTIN, 1);
    analogWrite(shim5, i); // подать на порт ШИМ сигнал, диапазон 0...255
    analogWrite(shim6, i); // подать на порт ШИМ сигнал, диапазон 0...255   
    Serial.println(i);
  }

}
