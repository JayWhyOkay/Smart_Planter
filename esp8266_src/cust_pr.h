#include <Arduino.h>
#include <SoftwareSerial.h>
#include "constants.h"

//#ifndef _USE_CUSTOM_PR

float get_PR_voltage()
{
    int sensorValue = analogRead(PhotoResistor);
    float voltage = sensorValue * (3.3 / 1023.0);
    Serial.print("voltage ");
    Serial.println(voltage);
    return voltage;
}