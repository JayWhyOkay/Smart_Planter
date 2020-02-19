#include "uwu_soil.h"

Soil_Sensor::Soil_Sensor(){

}

void Soil_Sensor::init(){
    Serial.println("[SOIL] Initializing Soil Sensor");
    int attempt = 0;
    while(!see_saw.begin(SOIL_I2C_ADDRESS) && attempt < MAX_ATTEMPTS){
        Serial.print("[SOIL] Error! Seesaw not found. Trying again. Attempt #");
        Serial.print(attempt);
        Serial.print("\n");
        attempt++;
        delay(1000);
    }
    if (attempt >= MAX_ATTEMPTS) {
        Serial.println("[SOIL] Seesaw failed to initialize! Ignoring values");
        state = 0;
    }
    else {
        Serial.println("[SOIL] Seesaw found! Soil Sensor Initialized!");
        Serial.print("[SOIL] seesaw version: ");
        Serial.print(see_saw.getVersion(), HEX);
        Serial.print("\n");
        state = 1;
    }
}

void Soil_Sensor::read_sensor_values(){
    if (state) {
        __soil_temperature = see_saw.getTemp();
        __cap_touch_read = see_saw.touchRead(0);
    }
    else {
        __soil_temperature = -1.0;
        __cap_touch_read = -1;
    }
}

char *Soil_Sensor::get_char_array(){
    Serial.println("[SOIL] Calling get_string()");
    read_sensor_values();
    
    char *buffer = new char[200];
    sprintf(buffer, "soil_t=%f&soil=%d", __soil_temperature, __cap_touch_read);
    Serial.print("[SOIL] Soil Sensor String: ");
    Serial.print(buffer);
    Serial.print("\n");
    
    return buffer;
}

String Soil_Sensor::get_string(){
    Serial.println("[SOIL] Calling get_string()");
    read_sensor_values();

    String output = "soil_t=";
    output += String(__soil_temperature, 3);
    output += "&soil=";
    output += String(__cap_touch_read);
    // Serial.print("[SOIL] Soil Sensor String: ");
    // Serial.print(output);
    // Serial.print("\n");

    return output;
}