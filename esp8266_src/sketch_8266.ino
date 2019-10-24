/* Includes and libary supports */
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "watchdog.h"
#include "constants.h"
#include "display.h"

/* Initialization of global variables */
// Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Watchdog watchdog;
C_Display display;

void testdrawline();

/* ----------------------------
 * Initialization and setup
 * ---------------------------- */
void setup() {
  /* Initialize serial port */
  delay(1000);
  Serial.begin(115200);
  Serial.println(F("Initializing Serial"));
  Serial.println(F("**** SETUP IS INITIALIZING ****"));

  /* initialize digital OUT pins */
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(EXTERNAL_LED_PIN, OUTPUT);

  /* Initialize Wire for I2C Communication*/
  Wire.begin();

  /* Watchdog Initialization */
  watchdog.init();

  /* Initialize Display */
  display.init(SSD1306_SWITCHCAPVCC, I2C_ADDRESS, BATTERY_HIGH, SIGNAL_HIGH);
  display.draw_battery_status(BATTERY_HIGH);

  Serial.println(F("**** SETUP IS FINISHED ****"));
}

/* ----------------------------
 * Main Loop
 * ---------------------------- */
void loop() {
  // display.testdrawlines();

}
