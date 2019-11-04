/* Includes and libary supports */
#include <Wire.h>
#include <ESP8266WiFi.h>

#include "constants.h"
#include "lib/display.h"
#include "lib/watchdog.h"
#include "lib/wifi_test.h"
#include "lib/cust_dht.h"

/* Initialization of global variables */
Watchdog watchdog;              //! Debug Library Setup
Display_Module display;              //! Display Library
WiFi_Test wifi_session;

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
    dht.begin();
    
    /* Initialize Display */
    wifi_session.init();

    /* FINISH SETUP */
    Serial.println(F("**** SETUP IS FINISHED ****"));
}


void loop() {
    /* ----------------------------
     * Main Loop
     * ---------------------------- */
    // Loop test ping to Google
    if (wifi_session.ping_host(1)){
        blink_RGB_LED(100, LOW, HIGH, LOW); // Blink Green if ping
    }
    else {
        blink_RGB_LED(100, HIGH, LOW, LOW); // Red if FAIL
    }
    delay(1000);

    bool dht_success = read_DHT_values();
    if(dht_success){
        blink_RGB_LED(100, LOW, LOW, HIGH);
    } 
    else {
        blink_RGB_LED(100, HIGH, LOW, HIGH);
    }
    delay(2000);
}
