# UwUPlants

The goal of this project is to upload temperature data to a local server and store the data on said server. The server may be held on a Raspberry Pi (which should also act as the access point for the board). The board should be able to automatically water the plants and display any diagnostics on its mini screen. 

The current steps in this projects are the following:
- [x] Design the board (completed)
- [x] Establish the build-environment
- [x] Code the DHT Sensor
- [x] Code the soil moisture 
- [x] Code the Wifi Module to send data
- [x] Code the server to accept and ack the data
- [ ] Others
- [x] Configure server 


## Firmware/Hardware Details
To see the details of the hardware/firmware, navigate to the esp_src directory. A readme will be there containing the details of the hardware/firmware.

## Webserver
To see the details of the website, navigate to the Django directory.