#include <painlessMesh.h>
#include <Arduino.h>
#include <Wire.h>
#include <uwu_dht.h>
#include <uwu_soil.h>
#include <uwu_pr.h>
#include <wifi_http.h>
#include "__pinouts__.h"

#define   MESH_SSID       "whateverYouLike"
#define   MESH_PASSWORD   "somethingSneaky"
#define   MESH_PORT       5555

/* Globals */
void sendMessage(); 
void receivedCallback(uint32_t from, String & msg);
void newConnectionCallback(uint32_t nodeId);
void changedConnectionCallback(); 
void nodeTimeAdjustedCallback(int32_t offset); 
void delayReceivedCallback(uint32_t from, int32_t delay);

Scheduler     userScheduler; // to control your personal task
painlessMesh  mesh;
custom_DHT dht;
Soil_Sensor soil;
PR_Sensor pr;

bool calc_delay = false;
SimpleList<uint32_t> nodes;

void sendMessage() ; // Prototype
Task taskSendMessage( TASK_SECOND * 1, TASK_FOREVER, &sendMessage ); // start with a one second interval

/*
    Main Functions 
 */
void setup() {
    Serial.begin(115200);

    dht.init();
    soil.init();  
    pr.init();
    randomSeed(analogRead(A0));
    
    mesh.setDebugMsgTypes(ERROR | DEBUG);  // set before init() so that you can see error messages
    mesh.init(MESH_SSID, MESH_PASSWORD, &userScheduler, MESH_PORT);
    mesh.onReceive(&receivedCallback);
    mesh.onNewConnection(&newConnectionCallback);
    mesh.onChangedConnections(&changedConnectionCallback);
    mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);
    mesh.onNodeDelayReceived(&delayReceivedCallback);

    userScheduler.addTask( taskSendMessage );
    taskSendMessage.enable();

}

void loop() {
  mesh.update();
}


/*
 **** Mesh Functions ****
 */
void sendMessage() {
    Serial.println("[SendMessage] CREATING DATA STRING");
    String serial_num = String(SERIAL_NUM);
    String dht_readings = dht.get_string();
    String soil_readings = soil.get_string();
    String pr_readings = pr.get_string();
    String data_string = String("mcu_no=" + serial_num 
                                + "&" + 
                                dht_readings 
                                + "&" + 
                                soil_readings
                                + "&" +
                                pr_readings);

    mesh.sendBroadcast(data_string);

    if (calc_delay) {
        SimpleList<uint32_t>::iterator node = nodes.begin();
        while (node != nodes.end()) {
            mesh.startDelayMeas(*node);
            node++;
        }
        calc_delay = false;
    }

    Serial.printf("[SendMessage] Sending message: %s\n", data_string.c_str());
    taskSendMessage.setInterval( random(TASK_SECOND * 1, TASK_SECOND * 5));  // between 1 and 5 seconds
}

void receivedCallback(uint32_t from, String & msg) {
    //Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
}

void newConnectionCallback(uint32_t nodeId) {
    //Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
    //Serial.printf("--> startHere: New Connection, %s\n", mesh.subConnectionJson(true).c_str());
}

void changedConnectionCallback() {
    //Serial.printf("Changed connections\n");
    nodes = mesh.getNodeList();
    Serial.printf("Num nodes: %d\n", nodes.size());
    Serial.printf("Connection list:");
    SimpleList<uint32_t>::iterator node = nodes.begin();
    while (node != nodes.end()) {
        Serial.printf(" %u", *node);
        node++;
    }
    Serial.println();
    calc_delay = true;
}

void nodeTimeAdjustedCallback(int32_t offset) {
    //Serial.printf("Adjusted time %u. Offset = %d\n", mesh.getNodeTime(), offset);
}

void delayReceivedCallback(uint32_t from, int32_t delay) {
    //Serial.printf("Delay to node %u is %d us\n", from, delay);
}