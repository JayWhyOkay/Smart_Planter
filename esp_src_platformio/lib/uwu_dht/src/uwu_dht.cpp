#include "uwu_dht.h"

/* Constructor */
custom_DHT::custom_DHT() {

}

void custom_DHT::init() {
    //Serial.println("[DHT] Initializing DHT Sensor");
    dht.begin();
}

/* Protected */
void custom_DHT::read_sensor_values() {
    //Serial.println("[DHT] Reading Sensor Values.");
    __humidity = dht.readHumidity();
    __temperature = dht.readTemperature();

    int read_attempts = 0;    
    while ( (isnan(__humidity) || isnan(__temperature)) && read_attempts < MAX_ATTEMPT){
        __humidity = dht.readHumidity();
        __temperature = dht.readTemperature();
    }
}

/* Public */
char *custom_DHT::get_char_array() {
    //Serial.println("[DHT] Calling get_string()");
    read_sensor_values();
    
    char buffer[200];
    sprintf(buffer, "temp=%f&humidity=%f", __temperature, __humidity);

    // Serial.print("[DHT] DHT String: ");
    // Serial.print(buffer);
    // Serial.print("\n");

    return buffer;
}

String custom_DHT::get_string() {
    //Serial.println("[DHT] Calling get_string()");
    read_sensor_values();

    String output = "temp=";
    output += String(__temperature, 3);
    output += "&humidity=";
    output += String(__humidity, 3);

    // Serial.print("[DHT] DHT String: ");
    // Serial.print(output);
    // Serial.print("\n");

    return output;
}