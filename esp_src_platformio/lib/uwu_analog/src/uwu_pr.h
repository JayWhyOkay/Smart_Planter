#ifndef __PR_SENSOR
#define __PR_SENSOR

#include <Arduino.h>
#define PhotoResistor 0 

class PR_Sensor
{
    int sensorValue = 0; 
    float voltage = 0;

    public: 
        PR_Sensor();
        
        void init();

        void read_sensor_values();

        char *get_char_array();

        String get_string();
};

#endif