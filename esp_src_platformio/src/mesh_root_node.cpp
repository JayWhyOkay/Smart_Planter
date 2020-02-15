/* Core Platform Includes / External libraries 
    - This will be in the form of libraries and
      core files downloaded from the PlatformIO
      extension
*/
#include <Arduino.h>
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

/* Other includes and constants 
    - These files will often contain just 
      header files, which is useful to define
      constants for certain things.
*/
#include "__pinouts__.h"


/* ---- Mesh Functions ---- */
#define MESH_SSID       "tinyMesh"
#define MESH_PASSWORD   "d92b82mdfdh3e"
#define MESH_PORT       5555

#define BLINK_PERIOD    3000
#define BLINK_DURATION  100

void sendMessage();

void receivedCallback(uint32_t from, String & msg);

void newConnectionCallback(uint32_t nodeId);

void changedConnectionCallback(); 

void nodeTimeAdjustedCallback(int32_t offset); 

void delayReceivedCallback(uint32_t from, int32_t delay);

/* Instances */
Scheduler userScheduler; // task controller 
painlessMesh mesh;

/* Tasks */
Task taskSendMessage( TASK_SECOND * 1, TASK_FOREVER, &sendMessage ); // start with a one second interval
Task blinkNoNodes;
Task receiveData;

bool onFlag = false;


void sendMessage() {
    String msg = "[MESH](SendMessage) Hello from node: ";
    msg += mesh.getNodeId();
    mesh.sendBroadcast(msg);


}

void receivedCallback(uint32_t from, String & msg) {
    /*
        Receive handler? 
    */
    Serial.printf("[MESH](recvCallBack) Received from %u msg=%s\n", from, msg.c_str());
}

void newConnectionCallback(uint32_t nodeId) {

}

void changedConnectionCallback() {

}

void nodeTimeAdjustedCallback(int32_t offset) {

}

void delayReceivedCallback(uint32_t from, int32_t delay) {

}

/* ---- Arduino Main ---- */
void setup() {
    Serial.begin(115200);

    Serial.print("[MESH] mesh debug msg types: ");
    mesh.setDebugMsgTypes( ERROR | STARTUP | MESH_STATUS |
                           CONNECTION | DEBUG );
    mesh.onReceive( &receivedCallback);
    mesh.onNewConnection(&newConnectionCallback);
    mesh.onChangedConnections(&changedConnectionCallback);
    mesh.onNodeTimeAdjusted(&nodeTimeAdjustedCallback);
    mesh.onNodeDelayReceived(&delayReceivedCallback);
}

void loop() {

}