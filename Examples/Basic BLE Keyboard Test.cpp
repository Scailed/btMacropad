// This example sends the keycode for "z" when key0 is pressed

#include <Arduino.h>
#include <../lib/btMacropad/btMacropad.h>
#include <../lib/Macropad/src/Macropad.h>
#include <../lib/btMacropad/keyCodes.h>

int row0 = D10;
int col0 = D0;

uint8_t modifiers[] = {0};
uint8_t key[] = {Z};

Key key0(row0, col0);
btMacropad macropad;


void setup() {
    Serial.begin(115200);
    delay(3000);
    macropad.begin();
    key0.begin();
    Serial.println("Ready");
}


void loop() {
    if (key0.pressed()) {
        Serial.println("Pressing z!");
        macropad.press(modifiers, 1, key, 1);
        delay(100);
        Serial.println("Releasing z!");
        macropad.releaseAll();
    }
}