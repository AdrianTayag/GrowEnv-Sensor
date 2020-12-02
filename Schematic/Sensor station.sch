EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATtiny:ATtiny85-20PU U1
U 1 1 5FC370BB
P 4600 2750
F 0 "U1" H 4750 3350 50  0000 R CNN
F 1 "Digispark ATtiny85 Board" H 5600 3300 50  0000 R CNN
F 2 "Package_DIP:DIP-8_W7.62mm" H 4600 2750 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/atmel-2586-avr-8-bit-microcontroller-attiny25-attiny45-attiny85_datasheet.pdf" H 4600 2750 50  0001 C CNN
	1    4600 2750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x05 J3
U 1 1 5FC396B0
P 8300 3400
F 0 "J3" H 8380 3442 50  0000 L CNN
F 1 "BH1750 Light Sensor" H 8380 3351 50  0000 L CNN
F 2 "" H 8300 3400 50  0001 C CNN
F 3 "~" H 8300 3400 50  0001 C CNN
	1    8300 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J1
U 1 1 5FC3A403
P 8250 1850
F 0 "J1" H 8330 1892 50  0000 L CNN
F 1 "Soil Moisture Sensor V1.2" H 8330 1801 50  0000 L CNN
F 2 "" H 8250 1850 50  0001 C CNN
F 3 "~" H 8250 1850 50  0001 C CNN
	1    8250 1850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x07 J5
U 1 1 5FC3B782
P 8300 5050
F 0 "J5" H 8380 5092 50  0000 L CNN
F 1 "TCS34725 RGB Sensor" H 8380 5001 50  0000 L CNN
F 2 "" H 8300 5050 50  0001 C CNN
F 3 "~" H 8300 5050 50  0001 C CNN
	1    8300 5050
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x04 J6
U 1 1 5FC3C02C
P 8300 5750
F 0 "J6" H 8380 5742 50  0000 L CNN
F 1 "16x2 LCD Display" H 8380 5651 50  0000 L CNN
F 2 "" H 8300 5750 50  0001 C CNN
F 3 "~" H 8300 5750 50  0001 C CNN
	1    8300 5750
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J2
U 1 1 5FC3CAE1
P 8250 2500
F 0 "J2" H 8330 2542 50  0000 L CNN
F 1 "DHT11 Temp & Humidity Sensor" H 8330 2451 50  0000 L CNN
F 2 "" H 8250 2500 50  0001 C CNN
F 3 "~" H 8250 2500 50  0001 C CNN
	1    8250 2500
	1    0    0    -1  
$EndComp
Text Label 6900 1750 0    50   ~ 0
MoistureData
Text Label 6900 1850 0    50   ~ 0
Vcc
Text Label 6900 1950 0    50   ~ 0
GND
Text Label 6900 2500 0    50   ~ 0
TempHumData
Wire Wire Line
	8050 1950 7900 1950
Wire Wire Line
	7800 2400 7800 1850
Wire Wire Line
	8050 2600 7900 2600
Wire Wire Line
	7900 2600 7900 1950
Wire Wire Line
	7800 2400 8050 2400
Wire Wire Line
	8100 3200 7900 3200
Wire Wire Line
	7900 3200 7900 2600
Connection ~ 7900 2600
Wire Wire Line
	8100 3600 7800 3600
Wire Wire Line
	7800 3600 7800 2400
Connection ~ 7800 2400
Connection ~ 7900 3200
Connection ~ 7800 3600
Wire Wire Line
	7800 5350 8100 5350
Wire Wire Line
	8100 5250 7900 5250
Wire Wire Line
	7800 3600 7800 4300
$Comp
L Connector_Generic:Conn_01x07 J4
U 1 1 5FC3AC26
P 8300 4200
F 0 "J4" H 8380 4242 50  0000 L CNN
F 1 "TinyRTC Clock Module" H 8380 4151 50  0000 L CNN
F 2 "" H 8300 4200 50  0001 C CNN
F 3 "~" H 8300 4200 50  0001 C CNN
	1    8300 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 3200 7900 4400
Wire Wire Line
	8100 4300 7800 4300
Connection ~ 7800 4300
Wire Wire Line
	7800 4300 7800 5350
Wire Wire Line
	8100 4400 7900 4400
Connection ~ 7900 4400
Wire Wire Line
	7900 4400 7900 5250
Wire Wire Line
	8100 5650 7900 5650
Wire Wire Line
	7900 5650 7900 5250
Connection ~ 7900 5250
Wire Wire Line
	8100 5750 7800 5750
Wire Wire Line
	7800 5750 7800 5350
Connection ~ 7800 5350
Connection ~ 7100 5050
Wire Wire Line
	7100 5950 7100 5050
Wire Wire Line
	7000 4950 7000 5850
Connection ~ 7000 4950
Wire Wire Line
	7000 4200 7000 4950
Connection ~ 7100 4100
Wire Wire Line
	7100 5050 7100 4100
Connection ~ 7000 4200
Connection ~ 7000 3400
Wire Wire Line
	7000 4200 7000 3400
Connection ~ 7100 3500
Wire Wire Line
	7100 4100 7100 3500
Text Label 6800 3500 0    50   ~ 0
SCL
Text Label 6800 3400 0    50   ~ 0
SDA
Wire Wire Line
	7000 3400 8100 3400
Wire Wire Line
	7100 3500 8100 3500
Wire Wire Line
	7100 4100 8100 4100
Wire Wire Line
	7000 4200 8100 4200
Wire Wire Line
	7000 4950 8100 4950
Wire Wire Line
	7100 5050 8100 5050
Wire Wire Line
	7000 5850 8100 5850
Wire Wire Line
	7100 5950 8100 5950
Connection ~ 7800 1850
Wire Wire Line
	7800 1850 8050 1850
Connection ~ 7900 1950
Wire Wire Line
	6900 2500 8050 2500
Wire Wire Line
	4600 1850 4600 2050
Wire Wire Line
	4600 1850 7800 1850
Wire Wire Line
	4000 3350 4000 1950
Wire Wire Line
	5200 2450 6300 2450
Wire Wire Line
	6300 2450 6300 3400
Wire Wire Line
	6300 3400 7000 3400
Wire Wire Line
	6200 2650 6200 3500
Wire Wire Line
	4000 3350 4600 3350
Wire Wire Line
	4000 1950 7900 1950
Wire Wire Line
	6800 1750 8050 1750
$Comp
L Switch:SW_MEC_5G SW1
U 1 1 5FC5E577
P 2850 2950
F 0 "SW1" H 2850 3235 50  0000 C CNN
F 1 "Toggle Switch" H 2850 3144 50  0000 C CNN
F 2 "" H 2850 3150 50  0001 C CNN
F 3 "http://www.apem.com/int/index.php?controller=attachment&id_attachment=488" H 2850 3150 50  0001 C CNN
	1    2850 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3500 7100 3500
Wire Wire Line
	5200 2650 6200 2650
Wire Wire Line
	5400 2550 5200 2550
Wire Wire Line
	2550 2050 4600 2050
Wire Wire Line
	2550 2950 2650 2950
Connection ~ 2650 2950
Wire Wire Line
	2650 2950 2750 2950
Connection ~ 4600 2050
Wire Wire Line
	4600 2050 4600 2150
Wire Wire Line
	3350 3250 3350 3350
Text Notes 7350 7500 0    50   ~ 0
General Wiring Diagram for GrowEnv-Sensor
Text Notes 8100 7650 0    50   ~ 0
Nov 29, 2020
Text Notes 10600 7650 0    50   ~ 0
1.0
Text Notes 7000 7100 0    50   ~ 0
Digispark ATtiny85 Development Board\nSoil Moisture Sensor V1.2\nDHT-11 Temp & Humidity Sensor\nBH1750 Light Intensity Sensor\nTinyRTC Clock Module\nTCS34725 RGB Sensor\n16x2 LCD Display Module
Connection ~ 4000 3350
Wire Wire Line
	5400 2550 5400 3600
Wire Wire Line
	2550 2050 2550 2950
Wire Wire Line
	4000 3350 3350 3350
Wire Wire Line
	3150 3600 3150 2950
Wire Wire Line
	3150 3600 5400 3600
Wire Wire Line
	3050 2950 3150 2950
Connection ~ 3150 2950
Wire Wire Line
	3150 2950 3350 2950
$Comp
L Device:R R1
U 1 1 5FC946E1
P 3350 3100
F 0 "R1" H 3420 3146 50  0000 L CNN
F 1 "Pulldown" H 3420 3055 50  0000 L CNN
F 2 "" V 3280 3100 50  0001 C CNN
F 3 "~" H 3350 3100 50  0001 C CNN
	1    3350 3100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 2850 5200 2850
Wire Wire Line
	6800 1750 6800 2850
Wire Wire Line
	5200 2750 6900 2750
Wire Wire Line
	6900 2750 6900 2500
$EndSCHEMATC
