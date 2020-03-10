#include <Arduino.h>

 /**
 *  code for arduino mega.
 *  
 *  proxy between Serial0 and Serial1
 *  
 *  send data to Serial0 to forward it to Serial1.
 *  when data is received from Serial1 it will be forwarded to Serial0.
 */

#define BUFFER_SIZE 20

char buffer[BUFFER_SIZE];


void setup() {
        // initialize both serial ports:
        Serial.begin(115200);
}

void loop() {
    char* testing = "alksjflksjadf";
    sprintf(buffer, "%s", testing);
    Serial.write(buffer, sizeof(buffer));
    delay(1000*3);
}