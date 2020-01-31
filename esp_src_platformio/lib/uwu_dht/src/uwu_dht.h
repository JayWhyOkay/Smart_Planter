#ifndef USE_CUSTOM_DHT
#define USE_CUSTOM_DHT

#include <DHT.h>
#include <SoftwareSerial.h>

#define DHT_TYPE 11
#define DHT_PIN 14

class custom_DHT{
private:
    DHT dht = DHT(DHT_PIN, DHT_TYPE);

    float __humidity;
    float __temperature;
    float __heat_index;

protected:

    void read_sensor_values();

public:

    custom_DHT();

    char *get_string();
};

#endif