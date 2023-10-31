#include <LiquidCrystal.h>
#include "DHT.h"



#define pinLDR A0

#define pinLEDGreen 6
#define pinLEDYellow 5
#define pinLEDRed 4
#define pinBuzzer 3

#define minLight 50
#define maxLight 90

#define minTempe 10
#define maxTempe 15

#define minHumid 60
#define maxHumid 80



int timerArray1 = 0;
int timerArray2 = 0;
int qtdArrayLCD = 5;
float lightArray[] = {0,0,0,0,0};
float tempeArray[] = {0,0,0,0,0};
float humidArray[] = {0,0,0,0,0};

int timeBuzzer1 = 0;
int timeBuzzer2 = 0;
bool buzzerON = false;
 
LiquidCrystal LCD (12,11,10,9,8,7);
int timeLCD1 = 0;
int timeLCD2 = 0;
String LCDType = "AMBIENTE";

DHT dht(2, DHT22);

void setup() {
  pinMode(pinLDR, INPUT);
  pinMode(pinLEDGreen, OUTPUT);
  pinMode(pinLEDYellow, OUTPUT);
  pinMode(pinLEDRed, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);

  LCD.begin(16,2);

  dht.begin();
  
  Serial.begin(9600);
}

void loop() {
  int light = map(analogRead(pinLDR), 0, 1024, 0, 100);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  toggleLED(light);
  toneBuzzer(temperature, humidity);

  timerArray1 = millis()/1000;
  if (timerArray1 - timerArray2 >= 1) {
    timerArray2 = millis()/1000;
    for (int i = 0; i < qtdArrayLCD; i++) {
      if (i + 1 == qtdArrayLCD) {
        lightArray[i] = light;
        tempeArray[i] = temperature;
        humidArray[i] = humidity;
      }
      else {
        lightArray[i] = lightArray[i + 1];
        tempeArray[i] = tempeArray[i + 1];
        humidArray[i] = humidArray[i + 1];
      }
    }
  }

  float lightAVG = 0;
  float tempeAVG = 0;
  float humidAVG = 0;

  for (int i = 0; i < qtdArrayLCD; i++) {
    lightAVG += lightArray[i];
    tempeAVG += tempeArray[i];
    humidAVG += humidArray[i];
  }

  lightAVG = lightAVG / 5;
  tempeAVG = tempeAVG / 5;
  humidAVG = humidAVG / 5;

  writeLCD(lightAVG, tempeAVG, humidAVG);
}

void toggleLED(int light) {
  digitalWrite(pinLEDRed, LOW);
  digitalWrite(pinLEDYellow, LOW);
  digitalWrite(pinLEDGreen, LOW);
  
  if (light < minLight) {
    digitalWrite(pinLEDGreen, HIGH);
  }
  else if (light < maxLight) {
    digitalWrite(pinLEDYellow, HIGH);
  }
  else {
    digitalWrite(pinLEDRed, HIGH);
  }
}

void toneBuzzer(float temperature, float humidity) {
  if (temperature > maxTempe || humidity > maxHumid) {
    tone(pinBuzzer, 1500);
  }
  else if (temperature < minTempe || humidity < minHumid) {
    timeBuzzer1 = millis()/1000;
    if (timeBuzzer1 - timeBuzzer2 >= 3) {
      timeBuzzer2 = millis()/1000;

      if (buzzerON) {
        noTone(pinBuzzer);
      }
      else {
        tone(pinBuzzer, 1500);
      }

      buzzerON = !buzzerON;
    }
  }
  else {
    noTone(pinBuzzer);
  }
}

void writeLCD(int light, float temperature, float humidity) {
  timeLCD1 = millis()/1000;
  if (timeLCD1 - timeLCD2 >= 5) {
    timeLCD2 = millis()/1000;

    LCD.clear();
    LCD.setCursor(0,0);
    LCD.print(LCDType + " ");

    if (LCDType == "AMBIENTE") {
      LCD.setCursor(0,1);
      LCD.print(returnTextLight(light));

      LCDType = "TEMP.";
    }
    else if (LCDType == "TEMP.") {
      LCD.print(returnTextTemperature(temperature));
      LCD.setCursor(0,1);
      LCD.print(LCDType + " = " + temperature + "C");

      LCDType = "UMIDADE";
    }
    else {
      LCD.print(returnTextHumidity(humidity));
      LCD.setCursor(0,1);
      LCD.print(LCDType + " = " + humidity + "%");
      
      LCDType = "AMBIENTE";
    }
  }
}

String returnTextLight(int light) {
  if (light < minLight) {
    return "ESCURO";
  }
  else if (light < maxLight) {
    return "A MEIA LUZ";
  }
  else {
    return "MUITO CLARO";
  }
}

String returnTextTemperature(float temperature) {
  if (temperature < minTempe) {
    return "BAIXA";
  }
  else if (temperature < maxTempe) {
    return "OK";
  }
  else {
    return "ALTA";
  }
}

String returnTextHumidity(float humidity) {
  if (humidity < 60) {
    return "BAIXA";
  }
  else if (humidity < 80) {
    return "OK";
  }
  else {
    return "ALTA";
  }
}
