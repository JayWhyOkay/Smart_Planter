#include "uwu_pr.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

PR_Sensor::PR_Sensor(){

}

void PR_Sensor::init(){
    //Serial.println("[PR] Initializing Photoresistor");

}

void PR_Sensor::read_sensor_values()
{
    //Serial.println("[PhotoResistor] Reading Sensor Values.");
    sensorValue = analogRead(PhotoResistor);
    voltage = sensorValue * (3.3/1023.0);

}

char *PR_Sensor::get_char_array(){
    //Serial.println("[PhotoResistor] Calling get_string()");
    read_sensor_values();

    char buffer[100];
    sprintf(buffer, "light_reading%f", voltage);

    return buffer;
}

String PR_Sensor::get_string(){
    //Serial.println("[PhotoResistor] Calling get_string");
    read_sensor_values();

    String output = "light_reading=";
    output += String(voltage, 3);

    return output;
}