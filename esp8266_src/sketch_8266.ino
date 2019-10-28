/* Includes and libary supports */
#include <Wire.h>
#include <ESP8266WiFi.h>

#include "lib/display.h"
#include "lib/watchdog.h"
#include "lib/wifi_test.h"

/* Initialization of global variables */
Watchdog watchdog;              //! Debug Library Setup
C_Display display;              //! Display Library
WiFi_Test wifi_session;
const char* ssid      = SS_ID;  //! SS_ID 
const char* password  = SS_PW;  //! SS_PW 

/* ----------------------------
 * Initialization and setup
 * ---------------------------- */
void setup() {
    /* Initialize serial port */
    delay(1000);
    Serial.begin(115200);
    Serial.println(F("Initializing Serial"));
    Serial.println(F("**** SETUP IS INITIALIZING ****"));

    /* initialize digital OUT pins */
    pinMode(LED_BUILTIN, OUTPUT);
    pinMode(EXTERNAL_LED_PIN, OUTPUT);

    /* Initialize Wire for I2C Communication*/
    Wire.begin();

    /* Watchdog Initialization */
    watchdog.init();

  /* Initialize Display */
    wifi_session.init();

    /* FINISH SETUP */
    Serial.println(F("**** SETUP IS FINISHED ****"));
}

/* ----------------------------
 * Main Loop
 * ---------------------------- */
void loop() {
    wifi_session.ping_host(5);


}
