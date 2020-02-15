/*
Author: Justin Kim

This library is a wrapper to enable the soil sensor on the board. The soil sensor is 
enabled on I2C address 0x36 on the SDA and SCL pins of the NodeMCU ESP12-E. 
*/

#ifndef __SOIL_SENSOR
#define __SOIL_SENSOR

#include <Adafruit_seesaw.h>
// #include <SoftwareSerial.h>
// #include <HardwareSerial.h>

#define SOIL_I2C_ADDRESS 0x36
#define SOIL_READ_DELAY 100
#define MAX_ATTEMPTS 5

class Soil_Sensor {

    Adafruit_seesaw see_saw = Adafruit_seesaw();
    uint16_t __cap_touch_read  = 0; // capacitive touch read
    float __soil_temperature = 0; //in Celcius

    int state = 0; // 1 for functioning, 0 for not functioning

public:
    /* void */
    Soil_Sensor();

    /*
        This function begins the initialization process and is meant
        to be called in void setup(). 

        It will attempt to initialize the sensor by finding the I2C. 
        If the sensor is not detected, the sensor will be in a down state,
        and will try to recover on the next bootup. 
    */
    void init();

    /*
        This function is to call the functions that read the sensor values from 
        the adafruit seesaw library. The function will write the corresponding
        values to the private variables of the object.  
    */
    void read_sensor_values();

    /*
        This function returns the values of the private variables in char* form. 
        It will return in the format:
            soil_t=%f&soil=%d
        where soil_t is soil temperature (float) and soil is soil moisture (int) 
    */
    char *get_char_array();

    /*
        This function returns the values similar to char *get_char_array().
        The main difference is that this returns in String format.  
    */
    String get_string();
};

#endif