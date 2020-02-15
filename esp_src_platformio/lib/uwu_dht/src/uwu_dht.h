#ifndef USE_CUSTOM_DHT
#define USE_CUSTOM_DHT

#include <DHT.h>
// #include <SoftwareSerial.h>
// #include <HardwareSerial.h>

#define DHT_TYPE 11
#define DHT_PIN 14
#define MAX_ATTEMPT 5

class custom_DHT{
private:
    DHT dht = DHT(DHT_PIN, DHT_TYPE);

    float __humidity;
    float __temperature;
    float __heat_index;

protected:
    /*
        This function is to call the functions that read the sensor values from 
        the DHT library. The function will write the corresponding
        values to the private variables of the object.  
    */
    void read_sensor_values();

public:

    custom_DHT();

    /*
        This function begins the initialization process and is meant
        to be called in void setup(). 

        It will attempt to iinitialize the DHT sensor in bootup. The 
        purpose of initialization being in a separate function is to 
        maintain uniformity of the sensors
    */
    void init();

    /*
        This function returns the values of the private variables in char* form. 
        It will return in the format:
            temp=%f&hum=%f
        where temp is the temperature in Celc (float) and hum is humidity (float)
    */
    char *get_char_array();

    /*
        This function returns the values similar to char *get_char_array().
        The main difference is that this returns in String format.  
    */
    String get_string();
};

#endif