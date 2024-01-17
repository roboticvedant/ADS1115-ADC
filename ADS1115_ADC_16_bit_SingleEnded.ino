#include "Arduino.h"
#include "Wire.h"
#define I2Caddress 0x48 // 1001000-GND addr

// Running average
// unsigned int readings[20] = {0};
// unsigned char readCnt = 0;

void setup()
{
	Serial.begin(9600);
	Wire.begin();
	Serial.println("Setup completed.");
	Wire.beginTransmission(I2Caddress);
	Wire.write(0b00000001);
	Wire.write(0b00000010);
	Wire.write(0b11100010);
	Wire.endTransmission();
}
void loop()
{
	Wire.beginTransmission(I2Caddress);
	Wire.write(0b00000000);
	Wire.endTransmission();
	Wire.requestFrom(I2Caddress, 2);
	uint16_t convertedValue;
	convertedValue = (Wire.read() << 8 | Wire.read());
}
