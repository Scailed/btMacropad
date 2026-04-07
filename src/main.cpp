/**
* This example turns the ESP32 into a Bluetooth LE keyboard that writes the words, presses Enter, presses a media key and then Ctrl+Alt+Delete
 */
#include <Arduino.h>
//#include <../lib/NimBLE-Arduino/NimBLEDevice.h>
#include <../lib/btMacropad/btMacropad.h>
btMacropad macropad;


void setup() {
    delay(1000);
    macropad.begin();
}


void loop() {
}