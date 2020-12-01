# GrowEnv-Sensor
### An Arduino based Growing Environment Sensor Module  
#### Blogpost for more detailed discussion/thoughts

Initially, an Arduino Micro clone was used for quickly verifying if the whole stack of modules work. To save cost, the code was then modified to run with a Digispark ATtiny85 (Soil Moisture and RGB Sensor is not yet working).  

The respective sketches for the Arduino Micro and ATtiny are included in this repository. The wiring schematics and pictures of the project can also be viewed.

![Block Picture](https://user-images.githubusercontent.com/31812460/100542437-c3624000-3284-11eb-847c-dc49c9e598a6.jpg)

Sensors Used:  
BH1750 - Light Intensity Sensor  
DHT11 - Temperature and Humidity Sensor  
TCS34725 - RGB Sensor  
Soil Moisture Sensor v1.2  
  
Libraries used are gathered from several open source repositories.
