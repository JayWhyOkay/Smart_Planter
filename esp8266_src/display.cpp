#include "display.h"

C_Display::C_Display(){

}

/*  Initialization function 
 *    - Prints to Serial that C_Display module is initialized successfully.
 */
void C_Display::init(int voltage_setting, int i2c_address, uint8_t battery, uint8_t wifi){
    Serial.println(F("[Display] Display is initializing..."));

    if(!display.begin(voltage_setting, i2c_address)){
        Serial.println(F("[Display] ERROR in initialization of display!!!"));
        watchdog.blocking_loop_blink_LED(EXTERNAL_LED_PIN);
    }
    display.display();
    display.clearDisplay();
    delay(1000);

    battery_status = battery;
    wifi_status = wifi;
}

/*
 *
 */
void C_Display::initiate_status(){
    
}

/*
 *
 */
void C_Display::draw_battery_status(uint8_t status){
    display.clearDisplay();

    display.drawBitmap(0, 0, 
                        test, 16, 16, 1  );
    display.display();
    delay(1000);
}

/*
 * Function to test display output
 */
void C_Display::testdrawlines(){
    int16_t i;

    display.clearDisplay(); // Clear display buffer

    for(i=0; i<display.width(); i+=4) {
        display.drawLine(0, 0, i, display.height()-1, WHITE);
        display.display(); // Update screen with each newly-drawn line
        delay(1);
    }
    for(i=0; i<display.height(); i+=4) {
        display.drawLine(0, 0, display.width()-1, i, WHITE);
        display.display();
        delay(1);
    }
    delay(250);

    display.clearDisplay();

    for(i=0; i<display.width(); i+=4) {
        display.drawLine(0, display.height()-1, i, 0, WHITE);
        display.display();
        delay(1);
    }
    for(i=display.height()-1; i>=0; i-=4) {
        display.drawLine(0, display.height()-1, display.width()-1, i, WHITE);
        display.display();
        delay(1);
    }
    delay(250);

    display.clearDisplay();

    for(i=display.width()-1; i>=0; i-=4) {
        display.drawLine(display.width()-1, display.height()-1, i, 0, WHITE);
        display.display();
        delay(1);
    }
    for(i=display.height()-1; i>=0; i-=4) {
        display.drawLine(display.width()-1, display.height()-1, 0, i, WHITE);
        display.display();
        delay(1);
    }
    delay(250);

    display.clearDisplay();

    for(i=0; i<display.height(); i+=4) {
        display.drawLine(display.width()-1, 0, 0, i, WHITE);
        display.display();
        delay(1);
    }
    for(i=0; i<display.width(); i+=4) {
        display.drawLine(display.width()-1, 0, i, display.height()-1, WHITE);
        display.display();
        delay(1);
    }

    delay(2000); // Pause for 2 seconds
}