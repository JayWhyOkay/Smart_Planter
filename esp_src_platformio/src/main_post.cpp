/* Core Platform Includes / External libraries 
    - This will be in the form of libraries and
      core files downloaded from the PlatformIO
      extension
*/
#include <Arduino.h>
#include <Wire.h>
#include <painlessMesh.h>

/* Internal libraries // See lib folder
    - Code that will be contained within
      the ./lib folder.
    - This code will often contain *.h and 
      *.cpp files to define certain methods 
      in this project.
*/
#include <uwu_mesh.h>
#include <uwu_dht.h>
#include <wifi_http.h>

/*tesTING*/


/* Other includes and constants 
    - These files will often contain just 
      header files, which is useful to define
      constants for certain things.
*/
#include "pinouts.h"

/* ---- Main Code ---- */
WiFi_Test wifi_session;
custom_DHT dht;

void setup() {
    /* ----------------------------
     * Initialization and setup
     * ---------------------------- */
    /* Initialize serial port */
    delay(1000);
    Serial.begin(115200);
    Serial.println(F("Initializing Serial"));
    Serial.println(F("**** SETUP IS INITIALIZING ****"));

    Serial.println("[INIT] Initializing debug LED");
    pinMode(EXTERNAL_RGB_RED, OUTPUT);
    pinMode(EXTERNAL_RGB_GREEN, OUTPUT);
    pinMode(EXTERNAL_RGB_BLUE, OUTPUT);

    /* Initialize Wire for I2C Communication*/
    Wire.begin();
    
    /* Wifi Initialization */
    wifi_session.init();

    Serial.println(F("**** SETUP IS FINISHED ****"));
}

void loop() {
    wifi_session.do_post_request(dht.get_string());

    delay(4000);
}