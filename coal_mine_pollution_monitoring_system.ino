#include <LiquidCrystal.h>
#include <DHT.h>

// Initialize sensors

//DHT11 init
#define DHTPIN 7
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

//LCD init
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);   

//Gas sensor init
int Gas1 = 9;
//int Gas2 = 8;

//Buzzer init
int Buzzer = 6;


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(Buzzer, OUTPUT);
  lcd.begin(16, 2);
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  //Humidity Monitor
  if (h>=85){
      lcd.setCursor(0,0);
      lcd.print("Humidity HIGH");
      lcd.setCursor(0,1);
      lcd.print(h);
      Serial.print("Humidity = ");
      Serial.println(h);
      tone(Buzzer,1000);
      delay(1000);
      noTone(Buzzer);     
    }
  else{
    lcd.setCursor(0,0);
    lcd.print("Humidity LOW");
    lcd.setCursor(0,1);
    lcd.print(h);
    Serial.print("Humidity = ");
    Serial.println(h);
    }
    delay(1000);
    lcd.clear();

  //Temperature Monitor
  if (t>=40){
    lcd.setCursor(0,0);
    lcd.print("Temperature HIGH");
    lcd.setCursor(0,1);
    lcd.print(t);
    Serial.print("Temperature = ");
    Serial.println(t);
    tone(Buzzer,1000);
    delay(1000);
    noTone(Buzzer);     
    }
  else{
    lcd.setCursor(0,0);
    lcd.print("Temperature LOW");
    lcd.setCursor(0,1);
    lcd.print(t);
    Serial.print("Temperature = ");
    Serial.println(t);
    }
  delay(1000);
  lcd.clear();
    
  //Gas Monitor
  if (digitalRead(Gas1) == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Smoke & Methane");
    lcd.setCursor(0,1);
    lcd.print("Detected! RUN!!!");
    Serial.print("Smoke and Methane Detected! RUN!!!");
    Serial.println(t);
    tone(Buzzer,1000);
    delay(1000);
    noTone(Buzzer);     
    }
  else{
    lcd.setCursor(0,0);
    lcd.print("Smoke under");
    lcd.setCursor(0,1);
    lcd.print("Control");
    Serial.print("Smoke under control");
    Serial.println(t);
    }
  delay(2000);
  lcd.clear();
}
