#include <Arduino.h>

char m[50];

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.readBytes(m, 30);
    Serial.println(m);
    delay(1000);
}