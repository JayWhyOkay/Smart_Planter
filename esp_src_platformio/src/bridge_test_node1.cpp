#include <Arduino.h>

char m[30] = "stanMX";

void setup()
{
    Serial.begin(115200);
}

void loop()
{
    Serial.write(m, 30);
    delay(1000);
}