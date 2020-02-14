/* Core Platform Includes / External libraries 
    - This will be in the form of libraries and
      core files downloaded from the PlatformIO
      extension
*/
#include <Arduino.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

/* Internal libraries // See lib folder
    - Code that will be contained within
      the ./lib folder.
    - This code will often contain *.h and 
      *.cpp files to define certain methods 
      in this project.
*/
#include <uwu_dht.h>
#include <wifi_http.h>
#include <uwu_pr.h>
#include <uwu_soil.h>

/* Other includes and constants 
    - These files will often contain just 
      header files, which is useful to define
      constants for certain things.
*/
#include "__pinouts__.h"

/* ---- Main Code ---- */
// #define LEAF_NODE

/* Wifi configurations */
// WiFi_Test wifi_session;
IPAddress ip(192, 168, 4, 4);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
const char* ssid = "testing_head";
const char* password = "testing";
String serverHost = "http://192.168.4.1/data";
String data;

/* Sleep configurations */

/* Class initializations */ 
custom_DHT dht;
Soil_Sensor soil;
WiFiClient client;

void setup() {
    /* ----------------------------
     * Initialization and setup
     * ---------------------------- */
    /* Initialize serial port */
    // delay(1000);
    Serial.begin(115200);
    Serial.println(F("Initializing Serial"));
    Serial.println(F("**** SETUP IS INITIALIZING ****"));

    Serial.println("[INIT] Initializing debug LED");
    pinMode(EXTERNAL_RGB_RED, OUTPUT);
    pinMode(EXTERNAL_RGB_GREEN, OUTPUT);
    pinMode(EXTERNAL_RGB_BLUE, OUTPUT);
    /* Initialize Wire for I2C Communication*/
    // Wire.begin();
    
    /* Wifi Initialization */
    // wifi_session.init();
    Serial.println("[WIFI] Initializing WiFi client");
    WiFi.mode(WIFI_STA);
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, password);

    Serial.println("[WIFI} attempting to connect to root.");
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }
    Serial.println("\n[WIFI] CONNECTED TO AP");




    Serial.println(F("**** SETUP IS FINISHED ****"));
}

void loop() {

    // Serial.println("[LOOP] CREATING DATA STRING");
    // String serial_num = String(SERIAL_NUM);
    // String dht_readings = dht.get_string();
    // String soil_readings = soil.get_string();
    // String data_string = String("num=" + serial_num 
    //                             + "&" + 
    //                             dht_readings 
    //                             + "&" + 
    //                             soil_readings);
    // Serial.println(String("[LOOP] Data String: " + data_string));

    // char body[200];
    // data_string.toCharArray(body, 200);
    // // wifi_session.do_post_request(body);

    // delay(4000);
}