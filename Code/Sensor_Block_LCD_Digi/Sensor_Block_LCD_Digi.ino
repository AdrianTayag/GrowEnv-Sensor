/*
 * Button at 5 
 * Soil at A2
 * DHT at 3
 *
 */
//Sensor block
//Coded for Digispark ATTiny85

//LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//DHT-11
#include "TinyDHT.h"
#define DHTPIN 3  // DHT connected to Arduino Uno Digital Pin 2
#define DHTTYPE DHT11   // DHT 11 
DHT dht(DHTPIN, DHTTYPE);

//Soil Moisture
const int AirValue = 460; //Manually determined
const int WaterValue = 450;
int soilMoistureValue = 0;
int soilmoisturepercent=0;

//TinyRTC
#include <TinyWireM.h>
#include <TinyRTClib.h>
RTC_DS1307 rtc;
//char daysOfTheWeek[7][12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

//GY-30
#include <BH1750.h>
BH1750 lightSensor = BH1750();

//Buttons
int button = 1;
int buttonstate = 0;
int mode = 0;

void setup() {
    TinyWireM.begin();
    lcd.begin();
    lcd.backlight();
    pinMode(button, INPUT);
    dht.begin();
    lightSensor.begin();
    rtc.begin();
    /*if (! dht.begin()) {
        lcd.print("No DHT-11 found.")
        while (1);
    }
    if (! myLux.begin()) {
        lcd.print("No GY-30 found.")
        while (1);
    }

    if (! rtc.begin()) {
        lcd.print("Couldn't find RTC");
        while (1);
    }*/
    if (! rtc.isrunning()) {
        rtc.adjust(DateTime(__DATE__, __TIME__));
    }
    lcd.clear();   
}

void loop() {
    buttonstate = digitalRead(button);
    if (buttonstate == HIGH) {
        mode = mode + 1;
        if (mode > 3) {
            mode = 0;
        }
    }

    switch(mode) {
        case 0: //RTC
            { //Curly brackets when declaring variables inside switch cases.
            DateTime now = rtc.now();
            lcd.setCursor(0,0);
            lcd.print(now.year(), DEC);
            lcd.print('/');
            lcd.print(now.month(), DEC);
            lcd.print('/');
            lcd.print(now.day(), DEC);
            lcd.print(" (");
            lcd.print(now.dayOfWeek());
            lcd.print(") ");

            lcd.setCursor(0,1);
            lcd.print(now.hour(), DEC);
            lcd.print(':');
            lcd.print(now.minute(), DEC);
            lcd.print(':');
            lcd.print(now.second(), DEC); 
            }
            break;    

        case 1: //DHT
            {
            // Get temperature event and print its value.
            int16_t temperature = dht.readTemperature(0); //0 for Celsius, 1 for Fahrenheit
            lcd.setCursor(0,0);
            if (temperature == BAD_TEMP) {
                break;
            }
            else {
                lcd.print(F("Temp: "));
                lcd.print(temperature);
                lcd.print(F("deg C"));
            }
            // Get humidity event and print its value.
            lcd.setCursor(0,1);
            int8_t humidity = dht.readHumidity();
            if (humidity == BAD_HUM) {
                lcd.print(F("Error reading humidity!"));
            }
            else {
                lcd.print(F("Humidity: "));
                lcd.print(humidity);
                lcd.print(F("%"));
            }
            }
            break;  

        case 2: //Soil Moisture
            {
            lcd.setCursor(0,0);
            lcd.print("Soil Moisture");
            soilMoistureValue = analogRead(A2); //refer to as 3, not A3
            soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
            lcd.setCursor(0,1);
            if(soilmoisturepercent >= 100) {
                lcd.print("100 %");
            }
            else if(soilmoisturepercent <=0) {
                lcd.print("0 %");
            }
            else if(soilmoisturepercent >0 && soilmoisturepercent < 100) {
                lcd.print(soilmoisturepercent);
                lcd.print("%");
            }
            }
            break;
  
        case 3: //GY-30
            {
            float light = lightSensor.getLightIntensity();
            lcd.setCursor(0,0);
            lcd.print("Light Intensity");
            lcd.setCursor(0,1);
            lcd.print(light, 1);
            lcd.print(" lux");
            }
            break;
    }
    delay(1000);
    lcd.clear();
}
