/*
TODO
1. Insert LCD display code
2. Run system
3. cleanup code
*/
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
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

//Buttons
int button = 5;
int buttonstate = 0;
int mode = 0;

void setup() {
    Serial.begin(9600);
    lcd.begin();
    lcd.backlight();
    pinMode(button, INPUT);
    dht.begin();
    sensor_t sensor;
    if (tcs.begin()) {
        Serial.println("Found sensor");
    } 
    else {
        Serial.println("No TCS34725 found ... check your connections");
        while (1);
    }
    Serial.println("Clock");
    if (! rtc.begin()) {
        Serial.println("Couldn't find RTC");
        while (1);
    }
    if (! rtc.isrunning()) {
        Serial.println("RTC is NOT running, let's set the time!");
        rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
    }   
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
            Serial.print(now.year(), DEC);
            Serial.print('/');
            Serial.print(now.month(), DEC);
            Serial.print('/');
            Serial.print(now.day(), DEC);
            Serial.print(" (");
            Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
            Serial.print(") ");
            Serial.print(now.hour(), DEC);
            Serial.print(':');
            Serial.print(now.minute(), DEC);
            Serial.print(':');
            Serial.print(now.second(), DEC);
            Serial.println();   
            }
            break;    

        case 1: //DHT
            Serial.println("Temperature & Humidity");
            // Get temperature event and print its value.
            sensors_event_t event;
            dht.temperature().getEvent(&event);
            if (isnan(event.temperature)) {
                Serial.println(F("Error reading temperature!"));
            }
            else {
                Serial.print(F("Temperature: "));
                Serial.print(event.temperature);
                Serial.println(F("°C"));
            }
            // Get humidity event and print its value.
            dht.humidity().getEvent(&event);
            if (isnan(event.relative_humidity)) {
                Serial.println(F("Error reading humidity!"));
            }
            else {
                Serial.print(F("Humidity: "));
                Serial.print(event.relative_humidity);
                Serial.println(F("%"));
            }
            break;  

        case 2: //Soil Moisture
            Serial.println("Soil Moisture");
            soilMoistureValue = analogRead(A0);
            soilmoisturepercent = map(soilMoistureValue, AirValue, WaterValue, 0, 100);
            if(soilmoisturepercent >= 100) {
                Serial.println("100 %");
            }
            else if(soilmoisturepercent <=0) {
                Serial.println("0 %");
            }
            else if(soilmoisturepercent >0 && soilmoisturepercent < 100) {
                Serial.print(soilmoisturepercent);
                Serial.println("%");
            }
            break;
        
        case 3: //TCS
            Serial.println("Light Intensity and Color");
            uint16_t r, g, b, c, colorTemp, lux;
            tcs.getRawData(&r, &g, &b, &c);
            colorTemp = tcs.calculateColorTemperature_dn40(r, g, b, c);
            lux = tcs.calculateLux(r, g, b);

            Serial.print("Color Temp: "); Serial.print(colorTemp, DEC); Serial.print(" K - ");
            Serial.print("Lux: "); Serial.print(lux, DEC); Serial.print(" - ");
            Serial.print("R: "); Serial.print(r, DEC); Serial.print(" ");
            Serial.print("G: "); Serial.print(g, DEC); Serial.print(" ");
            Serial.print("B: "); Serial.print(b, DEC); Serial.print(" ");
            Serial.print("C: "); Serial.print(c, DEC); Serial.print(" ");
            Serial.println(" ");    
            break;         
    }
    delay(1000);
}
