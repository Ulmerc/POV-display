EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
EELAYER 25 0
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
L Jack-DC J?
U 1 1 5A852F1A
P 2250 3850
F 0 "J?" H 2250 4060 50  0001 C CNN
F 1 "Jack-DC" H 2250 3675 50  0000 C CNN
F 2 "" H 2300 3810 50  0001 C CNN
F 3 "" H 2300 3810 50  0001 C CNN
	1    2250 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A852FEA
P 2650 4000
F 0 "#PWR?" H 2650 3750 50  0001 C CNN
F 1 "GND" H 2650 3850 50  0000 C CNN
F 2 "" H 2650 4000 50  0001 C CNN
F 3 "" H 2650 4000 50  0001 C CNN
	1    2650 4000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A853002
P 3700 4150
F 0 "#PWR?" H 3700 3900 50  0001 C CNN
F 1 "GND" H 3700 4000 50  0000 C CNN
F 2 "" H 3700 4150 50  0001 C CNN
F 3 "" H 3700 4150 50  0001 C CNN
	1    3700 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A85301A
P 2950 4050
F 0 "#PWR?" H 2950 3800 50  0001 C CNN
F 1 "GND" H 2950 3900 50  0000 C CNN
F 2 "" H 2950 4050 50  0001 C CNN
F 3 "" H 2950 4050 50  0001 C CNN
	1    2950 4050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A853031
P 3650 3350
F 0 "#PWR?" H 3650 3100 50  0001 C CNN
F 1 "GND" H 3650 3200 50  0000 C CNN
F 2 "" H 3650 3350 50  0001 C CNN
F 3 "" H 3650 3350 50  0001 C CNN
	1    3650 3350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A853048
P 5550 3900
F 0 "#PWR?" H 5550 3650 50  0001 C CNN
F 1 "GND" H 5550 3750 50  0000 C CNN
F 2 "" H 5550 3900 50  0001 C CNN
F 3 "" H 5550 3900 50  0001 C CNN
	1    5550 3900
	1    0    0    -1  
$EndComp
$Comp
L MC78L05_TO92 U?
U 1 1 5A8530E6
P 3700 3750
F 0 "U?" H 3550 3875 50  0001 C CNN
F 1 "5V_Regulator" H 3700 3875 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Narrow_Oval" H 3700 3975 50  0001 C CIN
F 3 "" H 3700 3700 50  0001 C CNN
	1    3700 3750
	1    0    0    -1  
$EndComp
$Comp
L C_Small C?
U 1 1 5A85316B
P 2950 3850
F 0 "C?" H 2960 3920 50  0001 L CNN
F 1 "1 uF" H 2960 3770 50  0000 L CNN
F 2 "" H 2950 3850 50  0001 C CNN
F 3 "" H 2950 3850 50  0001 C CNN
	1    2950 3850
	1    0    0    -1  
$EndComp
$Comp
L LD274 D?
U 1 1 5A85326D
P 4850 3250
F 0 "D?" H 4870 3320 50  0000 L CNN
F 1 "LD274" H 4810 3140 50  0000 C CNN
F 2 "LEDs:LED_D5.0mm" H 4850 3425 50  0001 C CNN
F 3 "" H 4800 3250 50  0001 C CNN
	1    4850 3250
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x02_Male J?
U 1 1 5A85332C
P 3300 3150
F 0 "J?" H 3300 3250 50  0001 C CNN
F 1 "Fan_headers" H 3300 2950 50  0000 C CNN
F 2 "" H 3300 3150 50  0001 C CNN
F 3 "" H 3300 3150 50  0001 C CNN
	1    3300 3150
	0    1    1    0   
$EndComp
$Comp
L Conn_01x02_Female IR_LED_headers
U 1 1 5A853377
P 4600 3550
F 0 "IR_LED_headers" H 4600 3650 50  0000 C CNN
F 1 "Conn_01x02_Female" H 4600 3350 50  0001 C CNN
F 2 "" H 4600 3550 50  0001 C CNN
F 3 "" H 4600 3550 50  0001 C CNN
	1    4600 3550
	0    -1   -1   0   
$EndComp
$Comp
L Fan M?
U 1 1 5A8533EE
P 3300 2700
F 0 "M?" H 3400 2900 50  0001 L CNN
F 1 "Fan" V 3400 2600 50  0000 L TNN
F 2 "" H 3300 2710 50  0001 C CNN
F 3 "" H 3300 2710 50  0001 C CNN
	1    3300 2700
	0    -1   -1   0   
$EndComp
$Comp
L R_Small R?
U 1 1 5A853939
P 5350 3750
F 0 "R?" H 5380 3770 50  0001 L CNN
F 1 "76.8 Ohms" V 5380 3710 50  0000 L CNN
F 2 "" H 5350 3750 50  0001 C CNN
F 3 "" H 5350 3750 50  0001 C CNN
	1    5350 3750
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2550 3950 2650 3950
Wire Wire Line
	2650 3950 2650 4000
Wire Wire Line
	2550 3750 3400 3750
Wire Wire Line
	2950 3950 2950 4050
Connection ~ 2950 3750
Wire Wire Line
	3700 4050 3700 4150
Wire Wire Line
	3200 3350 3200 3750
Connection ~ 3200 3750
Wire Wire Line
	3300 3350 3650 3350
Wire Wire Line
	4000 3750 4600 3750
Wire Wire Line
	5550 3750 5550 3900
Wire Wire Line
	5450 3750 5550 3750
Wire Wire Line
	4600 3550 4600 3250
Wire Wire Line
	4600 3250 4650 3250
Wire Wire Line
	4950 3250 4950 3500
Wire Wire Line
	4950 3500 4700 3500
Wire Wire Line
	4700 3500 4700 3550
Wire Wire Line
	4700 3750 5250 3750
Wire Wire Line
	3200 3150 3200 2850
Wire Wire Line
	3200 2850 3000 2850
Wire Wire Line
	3000 2850 3000 2700
Wire Wire Line
	3500 2700 3500 2850
Wire Wire Line
	3500 2850 3300 2850
Wire Wire Line
	3300 2850 3300 3150
$EndSCHEMATC
