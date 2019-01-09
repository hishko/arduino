
byte shim5 = 5; // Указываем номер порта с ШИМ
byte potenc = 0; // потенциометр на 0 аналоговом
byte potencZnach = 130; //значение потенциометра по умолчанию

void setup() {
  Serial.begin(9600); //Скорость передачи порта связи с консолью ПК
  pinMode(shim5, OUTPUT); // настроить порт как выход
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(100);
  digitalWrite(LED_BUILTIN, 0);

  potencZnach = map(analogRead(potenc), 0, 1023, 0, 255); // получить значение
  Serial.println(potencZnach); 
  analogWrite(shim5, potencZnach); // подать на порт ШИМ сигнал, диапазон 0...255
  
   
  
  delay(100);
  digitalWrite(LED_BUILTIN, 1);
    
}
