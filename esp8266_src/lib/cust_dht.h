#include <Arduino.h>
#include <SoftwareSerial.h>
#include "constants.h"
#define DHT_TYPE 11

#ifndef _USE_CUSTOM_DHT
#include <DHT.h>

DHT dht(DHT_PIN, DHT_TYPE);

// private:
// float h;
// float t;
// //float c;
// float f;
// float hic;
// float hif;

// bool read_DHT_values()
// {
//     h = dht.readHumidity();
//     t = dht.readTemperature();
//     //c = (dht.readTemperature(true) - (float)32) * (float)(5 / 9);
//     f = dht.readTemperature(true);

//     if (isnan(h) || isnan(t) || isnan(f))
//     {
//         return false;
//     }
//     else
//     {
//         hic = dht.computeHeatIndex(t, h, false);
//         hif = dht.computeHeatIndex(f, h, true);

//         Serial.print("\nHumidity: ");
//         Serial.print(h);
//         Serial.print(" %\t Temperature: ");
//         Serial.print(t);
//         Serial.print(" *C ");
//         Serial.print(f);
//         Serial.print(" *F\t Heat index: ");
//         Serial.print(hic);
//         Serial.print(" *C ");
//         Serial.print(hif);
//         Serial.print(" *F\n");
//         return true;
//     }
// }

// public:
// int getHumidity()
// {
//     return this.h;
// }
// int getCelsius()
// {
//     return this.t;
// }
// int getFahrenheit()
// {
//     return this.f;
// }
// int getHIC()
// {
//     return this.hic;
// }
// int getHIF()
// {
//     return this.hif;
// }

#else
#define custom_dht 0 // ignore for now

#endif