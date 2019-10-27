#include "DHT.h"

#define DHTPIN 14    

#define DHTTYPE DHT11   

DHT dht(DHTPIN, DHT11);

void setup() {
  Serial.begin(9600);

  dht.begin();
}


void loop() {
  delay(2500);

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  float c = (dht.readTemperature(true) - (float)32 ) * (float)(5/9);
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

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
  Serial.print(" *F");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t Temperature: ");
  Serial.print(t);
  Serial.print(" *C ");
  Serial.print(f);
  Serial.print(" *F\t Heat index: ");
  Serial.print(hic);
  Serial.print(" *C ");
  Serial.print(hif);
  Serial.println(" *F");

}
