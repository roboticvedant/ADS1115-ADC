#include "Arduino.h"
#include "Wire.h"
#define I2Caddress 0x48 // 1001000-GND addr
#define clockFrequency 400000 //fast clock i2c
#include <TimerOne.h>
void setup()
{
	Serial.begin(9600);
	Wire.begin();
	Wire.setClock(clockFrequency);
	Serial.println("Setup completed.");
	Wire.beginTransmission(I2Caddress);
	Wire.write(0b00000001);
	Wire.write(0b00000010);
	Wire.write(0b11100010);
	Wire.endTransmission();
	Timer1.initialize(16667); // 60Hz sampling
	Timer1.attachInterrupt(sendDatatoSerial); // attach the callback function   
}
void loop()
{	
}
void sendDatatoSerial () {
	Wire.beginTransmission(I2Caddress);
	Wire.write(0b00000000);
	Wire.endTransmission();
	Wire.requestFrom(I2Caddress, 2);
	uint16_t convertedValue;
	convertedValue = (Wire.read() << 8 | Wire.read());
	Serial.println(convertedValue);
}
