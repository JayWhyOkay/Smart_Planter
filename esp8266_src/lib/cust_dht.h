#include <Arduino.h>
#include <SoftwareSerial.h>
#include "constants.h"
#define DHT_TYPE 11

#ifndef _USE_CUSTOM_DHT
#include <DHT.h>

DHT dht(DHT_PIN, DHT_TYPE);


bool read_DHT_values(){
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float c = (dht.readTemperature(true) - (float)32 ) * (float)(5/9);
    float f = dht.readTemperature(true);

    if (isnan(h) || isnan(t) || isnan(f)){
        return false;
    }
    else {
        float hic = dht.computeHeatIndex(t, h, false);
        float hif = dht.computeHeatIndex(f, h, true);

        Serial.print("\nHumidity: ");
        Serial.print(h);
        Serial.print(" %\t Temperature: ");
        Serial.print(t);
        Serial.print(" *C ");
        Serial.print(f);
        Serial.print(" *F\t Heat index: ");
        Serial.print(hic);
        Serial.print(" *C ");
        Serial.print(hif);
        Serial.print(" *F\n");
        return true;
    }
}




#else
#define custom_dht 0 // ignore for now

#endif