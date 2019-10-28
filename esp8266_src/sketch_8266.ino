/* Includes and libary supports */
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <DHT.h>

#include "constants.h"
#include "lib/display.h"
#include "lib/watchdog.h"
#include "lib/wifi_test.h"

/* Initialization of global variables */
Watchdog watchdog;              //! Debug Library Setup
Display_Module display;              //! Display Library
WiFi_Test wifi_session;
DHT dht(DHT_PIN, 11);

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

    // Read DHT Sensor
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float c = (dht.readTemperature(true) - (float)32 ) * (float)(5/9);
    float f = dht.readTemperature(true);

    if (isnan(h) || isnan(t) || isnan(f)) {
        Serial.println("Failed to read from DHT sensor");
        blink_RGB_LED(100, HIGH, LOW, HIGH); // YELLOW if FAIL
    }
    else{
        float hic = dht.computeHeatIndex(t, h, false);
        float hif = dht.computeHeatIndex(f, h, true);
        Serial.print("\nHumidity: ");
        Serial.print(h);
        Serial.print(" %\t Temperature: ");
        Serial.print(t);
        Serial.print(" *C ");
        Serial.print(f);
        Serial.print(" *F\t Heat index: ");
        Serial.print(hic);
        Serial.print(" *C ");
        Serial.print(hif);
        Serial.print(" *F");
        Serial.print("Humidity: ");
        Serial.print(h);
        Serial.print(" %\t Temperature: ");
        Serial.print(t);
        Serial.print(" *C ");
        Serial.print(f);
        Serial.print(" *F\t Heat index: ");
        Serial.print(hic);
        Serial.print(" *C ");
        Serial.print(hif);
        Serial.println(" *F");
        blink_RGB_LED(100, LOW, LOW, HIGH); // Blue if success
    }
    delay(1000);
}
