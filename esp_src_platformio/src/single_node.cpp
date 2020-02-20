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
#include <uwu_dht.h>
#include <uwu_soil.h>
#include <uwu_pr.h>
#include <wifi_http.h>

/* Other includes and constants 
    - These files will often contain just 
      header files, which is useful to define
      constants for certain things.
*/
#include "__pinouts__.h"

/* ---- Main Code ---- */
WiFi_Test wifi_session;
custom_DHT dht;
Soil_Sensor soil;

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
    
    /* Sensor Initialization*/
    dht.init();
    soil.init();

    /* Wifi Initialization */
    wifi_session.init();

    Serial.println(F("**** SETUP IS FINISHED ****"));
}

void loop() {
    // wifi_session.do_post_request(dht.get_string());
    Serial.println("[LOOP] CREATING DATA STRING");
    String serial_num = String(SERIAL_NUM);
    String dht_readings = dht.get_string();
    String soil_readings = soil.get_string();
    String data_string = String("mcu_no=" + serial_num 
                                + "&" + 
                                dht_readings 
                                + "&" + 
                                soil_readings);
    Serial.println(String("[LOOP] Data String: " + data_string));

    char body[200];
    data_string.toCharArray(body, 200);
    wifi_session.do_post_request(body);

    delay(4000);
}