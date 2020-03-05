#include <Arduino.h>
#include <Wire.h>

#include <uwu_dht.h>
#include <uwu_soil.h>
#include <uwu_pr.h>

custom_DHT dht;
Soil_Sensor soil;
PR_Sensor pr;

void setup()
{
    Serial.begin(115200);

    dht.init();
    soil.init();  
    pr.init();
}

void loop()
{

    String dht_readings = dht.get_string();
    String soil_readings = soil.get_string();
    String pr_readings = pr.get_string();
    String data_string = String("dht=" + 
                                dht_readings 
                                + "& soil = " + 
                                soil_readings);
    // int n = data_string.length();
    // char c[n+1];
    // strcpy(c,data_string.c_str());
    int n = data_string.length();
    char c[n+1];
    strcpy(c,data_string.c_str());
    Serial.write(c, n);
    delay(1000);
}