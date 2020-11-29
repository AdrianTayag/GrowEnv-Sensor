//Sensor block
//Coded for Arduino Micro 32u4

//LCD
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//DHT-11
#include <DHT.h>
#include <DHT_U.h>
#include <Adafruit_Sensor.h>
#define DHTPIN 6
#define DHTTYPE DHT11 
DHT_Unified dht(DHTPIN, DHTTYPE);

//Soil Moisture
const int AirValue = 585; 
const int WaterValue = 274;
int soilMoistureValue = 0;
int soilmoisturepercent=0;

//TCS34725
#include <Wire.h>
#include <Adafruit_TCS34725.h>
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

//RTC
#include <RTClib.h>
RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

//GY-30
#include "BH1750FVI.h"
BH1750FVI myLux(0x23);

//Buttons
int button = 5;
int buttonstate = 0;
int mode = 0;

void setup() {
    lcd.begin();
    lcd.backlight();
    pinMode(button, INPUT);
    dht.begin();
    myLux.powerOn();
    myLux.setContHighRes();
    tcs.begin();
    if (! rtc.begin()) {
        lcd.print("Couldn't find RTC");
        while (1);
    }
    if (! rtc.isrunning()) {
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }
    lcd.clear();   
}

void loop() {
    buttonstate = digitalRead(button);
    if (buttonstate == HIGH) {
        mode = mode + 1;
        if (mode > 4) {
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
            lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
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
            // Get temperature event and print its value.
            sensors_event_t event;
            dht.temperature().getEvent(&event);
            lcd.setCursor(0,0);
            if (isnan(event.temperature)) {
                lcd.print(F("Error reading temperature!"));
            }
            else {
                lcd.print(F("Temp: "));
                lcd.print(event.temperature);
                lcd.print(F("deg C"));
            }
            // Get humidity event and print its value.
            lcd.setCursor(0,1);
            dht.humidity().getEvent(&event);
            if (isnan(event.relative_humidity)) {
                lcd.print(F("Error reading humidity!"));
            }
            else {
                lcd.print(F("Humidity: "));
                lcd.print(event.relative_humidity);
                lcd.print(F("%"));
            }
            break;  

        case 2: //Soil Moisture
            lcd.setCursor(0,0);
            lcd.print("Soil Moisture");
            soilMoistureValue = analogRead(A0);
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
            break;
        
        case 3: //TCS
            uint16_t r, g, b, c, colorTemp, lux;
            tcs.getRawData(&r, &g, &b, &c);
            colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
            lux = tcs.calculateLux(r, g, b);
            
            lcd.setCursor(0,0); 
            lcd.print("Temp: "); lcd.print(colorTemp, DEC); lcd.print("K");
            lcd.setCursor(0,1);
            lcd.print("Lux: "); lcd.print(lux, DEC); lcd.print(" ");
            delay(3000);
            lcd.clear();
            lcd.setCursor(0,0);
            lcd.print("R: "); lcd.print(r, DEC); lcd.print(" ");
            lcd.setCursor(0,1);
            lcd.print("G: "); lcd.print(g, DEC); lcd.print(" ");
            lcd.setCursor(8,1);
            lcd.print("B: "); lcd.print(b, DEC); lcd.print(" "); 
            delay(3000);
            break;       

        case 4: //GY-30
            float light = myLux.getLux();
            lcd.setCursor(0,0);
            lcd.print("Light Intensity");
            lcd.setCursor(0,1);
            lcd.print(light, 1);
            lcd.print(" lux");
    }
    delay(1000);
    lcd.clear();
}
