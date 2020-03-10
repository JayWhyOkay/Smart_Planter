#include <Arduino.h>
#include <SoftwareSerial.h>

#define BUFFER_SIZE 20

char buffer[BUFFER_SIZE];
SoftwareSerial portOne(13,15);


void setup() {
    Serial.begin(115200);
    portOne.begin(9600);
}

void loop(){

    portOne.listen();
    Serial.println("Data from port one: ");

    while(portOne.available() > 0){
        char inByte = portOne.read();
        Serial.write(inByte);
    }
    Serial.println();



}