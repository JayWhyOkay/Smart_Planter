#ifndef __PROJ_CONST__
#define __PROJ_CONST__

/* Serial Pins 
    Note: Serial2 might be required 
*/
#define SERIAL_PIN_RX   13  // D7 -- RXD2
#define SERIAL_PIN_TX   15  // D8 -- TXD2
#define SERIAL_PIN_TX_RO 2  // D4 -- TXD1, Readonly


/* Other Pins (Declared Elsewhere) */
#define DHT_PIN 14          // D5

#define PhotoResistor 10    // SD3  PhotoResistor pin

#define ADC_PIN A0          // A0   ADC

#define SCL_PIN 5           // D1   SCL Pin on ESP8266
#define SDA_PIN 4           // D2   SDA Pin on ESP8266

#ifdef LEAF_NODE
    #define EXTERNAL_RGB_RED    12
    #define EXTERNAL_RGB_GREEN  13
    #define EXTERNAL_RGB_BLUE   15
#else
    #define DEBUG_LED   9 // SDD2 
#endif

#endif
