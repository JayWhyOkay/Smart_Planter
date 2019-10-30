#ifndef __WIFI__
#define __WIFI__

#include <ESP8266WiFi.h>
#include "constants.h"

extern "C" {
    void esp_schedule();
    void esp_yield();
    #include <ping.h>
} 

#ifndef WIFI_CONF
    #define SS_ID       ""
    #define SS_PW       ""
    #define HOST_ID     "www.google.com"
    #define HOST_PORT   5000
#endif 

#ifdef _ENABLE_WIFI_DEBUG
    #define DEBUG_PING(...) Serial.printf(__VA_ARGS__)
#else
    #define DEBUG_PING(...)
#endif


class WiFi_Test{
    /*
     *  Debug class for indicating failures of the board. 
     */
    const char* ss_id   = SS_ID;
    const char* ss_pw   = SS_PW;

    const char* host_id = HOST_ID;
    uint8_t host_port   = HOST_PORT;
    
    WiFiClient client = WiFiClient();

protected:
    static byte _expected_count;
    static byte _errors;
    static byte _success;
    static int _avg_time;

    IPAddress _dest;
    ping_option _options;

    static void _ping_sent_cv(void *opt, void *pdata);
    static void _ping_recv_cb(void *opt, void *pdata);

public:
    /* Normal constructor */
    WiFi_Test();

    /* Constructor with different access point connection (probably unused) */
    WiFi_Test(const char* router_id, const char* router_pw);
    
    /* Initialization function [BLOCKING]
     * - Function that establishes connection to access point
     */
    void init();

    /* ** Function to connect to host website **
     * - Uses WiFiClient class to establish connection to a host 
     * 
     * Note: connection to an access point will be necessary first
     */
    void connect_to_host();

    bool ping_host(byte count);

    int average_time();

};

#endif
