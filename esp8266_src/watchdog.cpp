#include "watchdog.h"

Watchdog::Watchdog(){
    
}

void Watchdog::init(){
    Serial.println(F("[WATCHDOG] Watchdog module is initialized!"));
}

void Watchdog::blocking_loop_blink_LED(uint8_t pin){
    Serial.println(F("[WATCHDOG] Called from function: BLOCKING CODE PROGRESS\n"));
    for(;;){
        digitalWrite(pin, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);                       // wait for a second

        digitalWrite(pin, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);  
    };
}
