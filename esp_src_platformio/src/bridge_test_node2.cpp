#include <Arduino.h>

char m[100];

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.readBytes(m, 100);
    Serial.println(m);
    delay(1000);
}