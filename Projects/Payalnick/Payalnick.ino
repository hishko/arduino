
#include <LiquidCrystal.h> //Подключаем библиотеку LCD дисплея
LiquidCrystal lcd(7, 6, 5, 4, 3, 2); // (RS, E, DB4, DB5, DB6, DB7)


byte shim = 9;              
byte potenc = 6;            //нп Ф6 снимаем данные потанциометра
byte potencDefault = 256;   
byte potencZnach;
byte soprZnach;
byte helloTime = 4000;    
  

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(shim, OUTPUT);
  lcd.begin(16, 2);   
  analogWrite(shim, potencDefault);  
  lcd.setCursor(5, 0);              
  lcd.print("Hello!"); 
  lcd.setCursor(6, 1);              
  lcd.print("100%");
  delay(helloTime); 
}                           

/*
Функция выводит данные на дисплей
*/
void loadLCD(byte str2) {      
  lcd.clear();
if (str2 < 1){
        lcd.setCursor(0, 0);
        lcd.print("                "); 
  }else if(str2 < 6) {
        lcd.setCursor(0, 0);
        lcd.print("*");      
  }else if(str2 < 12) {
        lcd.setCursor(0, 0);
        lcd.print("**");
  }else if(str2 < 18) {
        lcd.setCursor(0, 0);
        lcd.print("***");
  }else if(str2 < 24) {
        lcd.setCursor(0, 0);
        lcd.print("****");
  }else if(str2 < 30) {
        lcd.setCursor(0, 0);
        lcd.print("*****");
  }else if(str2 < 36) {
        lcd.setCursor(0, 0);
        lcd.print("******");
  }else if(str2 < 42) {
        lcd.setCursor(0, 0);
        lcd.print("*******");
  }else if(str2 < 48) {
        lcd.setCursor(0, 0);
        lcd.print("********");
  }else if(str2 < 54) {
        lcd.setCursor(0, 0);
        lcd.print("*********");
  }else if(str2 < 60) {
        lcd.setCursor(0, 0);
        lcd.print("**********");
  }else if(str2 < 66) {
        lcd.setCursor(0, 0);
        lcd.print("***********");
  }else if(str2 < 72) {
        lcd.setCursor(0, 0);
        lcd.print("************");
  }else if(str2 < 78) {
        lcd.setCursor(0, 0);
        lcd.print("*************");
  }else if(str2 < 84) {
        lcd.setCursor(0, 0);
        lcd.print("**************");
  }else if(str2 < 94) {
        lcd.setCursor(0, 0);
        lcd.print("***************");
  }else if(str2 <= 110) {
        lcd.setCursor(0, 0);
        lcd.print("****************");
  }else{
    
        lcd.setCursor(0, 0);
        lcd.print("                "); 
}  
  lcd.setCursor(0, 1); 
  lcd.print("Watt -");                  // Выводим текст
  lcd.setCursor(7,1);              // Устанавливаем курсор в начало 2 строки
  lcd.print(str2);                  // Выводим текст
  if(str2 == 100){              //ставим знак % послсле трехзначного числа
    lcd.setCursor(10,1);  
  }else{
    lcd.setCursor(9,1);
  }             
  lcd.print("%");  
  digitalWrite(LED_BUILTIN, 1); 
  delay(100); 
  digitalWrite(LED_BUILTIN, 0); 
}

/*
Функция переводит значение в процент
*/
byte procent(byte data){
  byte result =  data * 100 / 254; 
  return result;
}


void loop() {
  
  potencZnach = map(analogRead(potenc), 0, 1024, 0, 256); // получить значение
  analogWrite(shim, potencZnach);                         // подать на порт ШИМ сигнал, диапазон 0...255
  if(potencDefault == potencZnach || potencDefault+1 == potencZnach ){     
  }else{
    potencDefault = potencZnach;
    loadLCD(procent(potencZnach));
  }

}
