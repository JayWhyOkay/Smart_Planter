/* Core Platform Includes / External libraries 
    - This will be in the form of libraries and
      core files downloaded from the PlatformIO
      extension
*/
#include <Arduino.h>
#include <Wire.h>
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

/* Internal libraries // See lib folder
    - Code that will be contained within
      the ./lib folder.
    - This code will often contain *.h and 
      *.cpp files to define certain methods 
      in this project.
*/
#include <uwu_dht.h>
#include <wifi_http.h>

/* Other includes and constants 
    - These files will often contain just 
      header files, which is useful to define
      constants for certain things.
*/
#include "__pinouts__.h"

#define BUFFER_SIZE 50

const char* ssid = "testing_head";
const char* password = "testing";

ESP8266WebServer server(80);

char buffer[BUFFER_SIZE][BUFFER_SIZE];

void handle_index();

void handle_data();

void setup_access_point();

void setup_server();

void setup_station_mode();

void handle_index(){
    Serial.println("[SERVER] Received Request @ \"/index\"");
    server.send(200, "text/plain", "Index client response");
}

void handle_data(){
    Serial.println("[SERVER] Received Request @ \"/data\"");    
    String ser_no = server.arg("num");
    String temp = server.arg("temp");
    String hum  = server.arg("hum");
    String soil = server.arg("soil");
    String bat  = server.arg("bat");

    String data_string = "num=";
    data_string += String(ser_no);
    data_string += "&temp=";
    data_string += String(temp);
    data_string += "&hum=";
    data_string += String(hum);
    data_string += "&soil=";
    data_string += String(soil);
    data_string += "&bat=";
    data_string += String(bat);
    data_string += "\r\n\r\n";

    Serial.print("[DATA] ");
    Serial.print(data_string);
    Serial.print("\n");
}

void setup_access_point(){
    Serial.println("[AP] Setting up access point");
    WiFi.disconnect();
    WiFi.softAP(ssid, password);
    IPAddress ip_address = WiFi.softAPIP();
    Serial.print("[AP] Access Point IP: "); Serial.print(ip_address);Serial.print("\n");
    setup_server();
}

void setup_server(){
    Serial.println("[SERVER] Setting up server");
    server.on("/", handle_index);
    server.on("/data", handle_data);
    server.begin();
    Serial.println("[SERVER] Server has begun! \n-------------------\n");
}

void setup_station_mode(String t, String v){

}

void setup(){
    Serial.begin(115200);
    WiFi.mode(WIFI_AP_STA);
    setup_access_point();
}

void loop(){
    server.handleClient();
}