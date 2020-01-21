/* Includes and libary supports */
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <painlessMesh.h>

#include "constants.h"
#include "lib/watchdog.h"
#include "lib/wifi/wifi_test.h"
#include "lib/cust_dht.h"
#include "lib/cust_pr.h"

/* Initialization of global variables */
Watchdog watchdog;              //! Debug Library Setup
WiFi_Test wifi_session;
custom_DHT dht;
painlessMesh mesh;

const char* ssid      = SS_ID;  //! SS_ID 
const char* password  = SS_PW;  //! SS_PW 

void setup() {
    /* ----------------------------
     * Initialization and setup
     * ---------------------------- */
    /* Initialize serial port */
    delay(1000);
    Serial.begin(115200);
    Serial.println(F("Initializing Serial"));
    Serial.println(F("**** SETUP IS INITIALIZING ****"));

    /* initialize digital OUT pins */
    pinMode(LED_BUILTIN, OUTPUT); digitalWrite(LED_BUILTIN, LOW);
    initialize_RGB_LED();

    /* Initialize Wire for I2C Communication*/
    Wire.begin();

    /* Watchdog Initialization */
    watchdog.init();

    /* DHT Initialization */
    
    /* Wifi Initialization */
    wifi_session.init();

    Serial.println(F("**** SETUP IS FINISHED ****"));
}


void loop() {
    wifi_session.do_post_request(dht.get_string());

    delay(4000);

}

