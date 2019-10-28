#include "wifi_test.h"

WiFi_Test::WiFi_Test(){
    WiFi.mode(WIFI_STA);
    WiFi.begin(ss_id, ss_pw);
}

WiFi_Test::WiFi_Test(const char* router_id, const char* router_pw) : ss_id(router_id), ss_pw(router_pw) {
    WiFi.mode(WIFI_STA);
    WiFi.begin(ss_id, ss_pw);
}

void WiFi_Test::init(){
    while (WiFi.status() != WL_CONNECTED) {
        delay(250);
        Serial.print(".");
    }
    Serial.println("");
    Serial.print("WiFi connected! ");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void WiFi_Test::connect_to_host(){
    
}

bool WiFi_Test::ping_host(byte count){
    IPAddress _remote_address;
    if (WiFi.hostByName(host_id, _remote_address)){
        _expected_count = count;
        _errors = 0;
        _success = 0;
        _avg_time = 0;

        memset(&_options, 0, sizeof(struct ping_option));

        _options.count = count;
        _options.coarse_time = 1;
        _options.ip = _remote_address;

        /* Callbacks */
        _options.recv_function = reinterpret_cast<ping_recv_function>(&WiFi_Test::_ping_recv_cb);
        _options.sent_function = NULL;

        if (ping_start(&_options)){
            esp_yield();
        }

        return (_success > 0);
    }

    return false;
}

void WiFi_Test::_ping_recv_cb(void *opt, void *resp){
    // Cast the parameters to get some usable info
    ping_resp*   ping_resp = reinterpret_cast<struct ping_resp*>(resp);

    // Determine Error or Success
    if (ping_resp->ping_err == -1)
        _errors++;
    else {
        _success++;
        _avg_time += ping_resp->resp_time;
    }

    // Set and print debug info
    DEBUG_PING(
            "DEBUG: ping reply\n"
            "\ttotal_count = %d \n"
            "\tresp_time = %d \n"
            "\tseqno = %d \n"
            "\ttimeout_count = %d \n"
            "\tbytes = %d \n"
            "\ttotal_bytes = %d \n"
            "\ttotal_time = %d \n"
            "\tping_err = %d \n",
            ping_resp->total_count, ping_resp->resp_time, ping_resp->seqno,
            ping_resp->timeout_count, ping_resp->bytes, ping_resp->total_bytes,
            ping_resp->total_time, ping_resp->ping_err
    );

    // Check if time to end
    if (_success + _errors == _expected_count) {
        _avg_time = _success > 0 ? _avg_time / _success : 0;

        // Print debug statement if declared 
        DEBUG_PING("Avg resp time %d ms\n", _avg_time);

        // Done, return to main functiom
        esp_schedule();
    }
}

int WiFi_Test::average_time(){
    return _avg_time;
}

byte WiFi_Test::_expected_count = 0;
byte WiFi_Test::_errors     = 0;
byte WiFi_Test::_success    = 0;
int WiFi_Test::_avg_time    = 0;