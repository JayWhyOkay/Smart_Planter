#ifndef __SOIL_SENSOR
#define __SOIL_SENSOR

#include <Adafruit_seesaw.h>
// #include <SoftwareSerial.h>
// #include <HardwareSerial.h>

#define SOIL_I2C_ADDRESS 0x36
#define SOIL_READ_DELAY 100
#define MAX_ATTEMPTS 3

class Soil_Sensor {

    Adafruit_seesaw see_saw = Adafruit_seesaw();
    uint16_t __cap_touch_read  = 0; // capacitive touch read
    float __soil_temperature = 0; //in Celcius

    int state = 0; // 1 for functioning, 0 for not functioning

public:
    Soil_Sensor();

    void init();

    void read_sensor_values();

    char *get_char_array();

    String get_string();
};

#endif