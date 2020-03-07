#include <painlessMesh.h>
#include <Arduino.h>
#include <Wire.h>
#include <uwu_dht.h>
#include <uwu_soil.h>
#include <uwu_pr.h>
#include <wifi_http.h>
#include "__pinouts__.h"
#include <SoftwareSerial.h>

SoftwareSerial mySerial (3,1,false,128);

custom_DHT dht;
Soil_Sensor soil;


void setup() {
  Serial.begin(115200);

  dht.init();
  soil.init();  

  mySerial.begin(115200);
  mySerial.println("connect");
}

void loop(){

    String dht_readings = dht.get_string();
    String soil_readings = soil.get_string();
    String data_string = String("dht=" + 
                                dht_readings 
                                + "& soil = " + 
                                soil_readings);
    Serial.printf("%s\n",data_string.c_str());
    // if(mySerial.available())
    //     Serial.write(data_string);
}