#include <painlessMesh.h>
#include <Arduino.h>
#include <Wire.h>
#include <uwu_dht.h>
#include <uwu_soil.h>
#include <uwu_pr.h>
#include <wifi_http.h>
#include <string>
#include "__pinouts__.h"

#define   MESH_SSID       "whateverYouLike"
#define   MESH_PASSWORD   "somethingSneaky"
#define   MESH_PORT       5555

// Prototypes
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
String serial_num;
String rcved;

void sendMessage() ; // Prototype
Task taskSendMessage( TASK_SECOND * 1, TASK_FOREVER, &sendMessage ); // start with a one second interval
//Task

void setup() {
    Serial.begin(115200);

    dht.init();
    soil.init();  
    pr.init();
    randomSeed(analogRead(A0));

    mesh.setDebugMsgTypes(ERROR | DEBUG);  
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
    String data_string = "stan monsta x please\n";
    String dht_readings = dht.get_string();
    String soil_readings = soil.get_string();
    String pr_readings = pr.get_string();
    int mx = atoi(serial_num.c_str());
    if (mx > 0)
    {
        serial_num = String("serial num = " + serial_num + "\n" + "dht = " + dht_readings + "\n& soil = " + 
                                soil_readings + "\n&pr = " + pr_readings + "\n\n"+ "rcved from = " + rcved + "\n\n\n");
        int n = serial_num.length();
        char c[n+1];
        strcpy(c,serial_num.c_str());
        Serial.write(c, n);
        delay(1000);  
    }
}


/* 
**** Mesh Functions **** 
 */
void sendMessage() {
//   String msg = "Hello from node ";
//   msg += mesh.getNodeId();
//   msg += " myFreeMemory: " + String(ESP.getFreeHeap());
    String msg;
  
    serial_num = String(SERIAL_NUM);
    // String dht_readings = dht.get_string();
    // String soil_readings = soil.get_string();
    // String pr_readings = pr.get_string();
    // String data_string = String("dht=" + 
    //                             dht_readings 
    //                             + "\n& soil = " + 
    //                             soil_readings + "\n&pr = " + pr_readings + "\n");
   
    //Serial.println(String("[LOOP] Data String: " + data_string));
    String data_string = String("num=" + serial_num);

    msg += "\n" + String(data_string);
  
    mesh.sendBroadcast(msg);

    if (calc_delay) {
        SimpleList<uint32_t>::iterator node = nodes.begin();
        while (node != nodes.end()) {
            mesh.startDelayMeas(*node);
            node++;
        }
        calc_delay = false;
    }
    // Serial.printf("Sending message: %s\n", msg.c_str());
    taskSendMessage.setInterval( random(TASK_SECOND * 1, TASK_SECOND * 5));  // between 1 and 5 seconds
}

void receivedCallback(uint32_t from, String & msg) {
    rcved = msg;
    Serial.printf("startHere: Received from %u msg=%s\n", from, msg.c_str());
}

void newConnectionCallback(uint32_t nodeId) {
    //Serial.printf("--> startHere: New Connection, nodeId = %u\n", nodeId);
    //Serial.printf("--> startHere: New Connection, %s\n", mesh.subConnectionJson(true).c_str());
}

void changedConnectionCallback() {
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