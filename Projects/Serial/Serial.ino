
 int cicle = 2;
 int led = 0;
 int t = 0;

void setup() {
  Serial.begin(9600); //указываем скорость от ардуинки
  Serial.println("Hello"); //ардуинка посылает на порт
    
  pinMode(LED_BUILTIN, OUTPUT);
  cicle = cicle * 2;
 
}

void loop() {
  for(int i = 0; i != cicle;i++){
    if (led == 0){      
      digitalWrite(LED_BUILTIN, 0);
      led = 1;
      delay(100);
    }else{
      digitalWrite(LED_BUILTIN, 1);
      led = 0;
      delay(100);
    }      
  }
  led = 0;
  digitalWrite(LED_BUILTIN, 0);
  delay(1000); 
  Serial.println(t); 
  t++; 
}
