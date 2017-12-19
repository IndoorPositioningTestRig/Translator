#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial RS485Serial(6, 5);

void setup()
{
    // Use serial to communicate with the main application
    Serial.begin(9600);

    // Use software serial to communicate with the RS485 bus
    RS485Serial.begin(9600);
}

void loop()
{
    // Communication: RS485 bus --> Main application
    if (RS485Serial.available())
    {
        while (RS485Serial.available())
        {
            Serial.write(RS485Serial.read());
        }        
    }
}

void serialEvent()
{
    // Communication: Main application --> RS485 bus
    if (Serial.available())
    {
        while (Serial.available())
        {
            RS485Serial.write(Serial.read());
        }
    }
}