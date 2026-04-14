//
// Created by Cobin Grosjean on 4/14/26.
//

#include <Arduino.h>
#include <../lib/btMacropad/btMacropad.h>
#include <../lib/Macropad/src/Macropad.h>
#include <../lib/btMacropad/keyCodes.h>

btMacropad macropad;

Key key0(ROW0, COL0);
Key key1(ROW0, COL1);
Key key2(ROW0, COL2);
Key key3(ROW0, COL3);

Key key4(ROW1, COL0);
Key key5(ROW1, COL1);
Key key6(ROW1, COL2);
Key key7(ROW1, COL3);

Key key8(ROW2, COL0);
Key key9(ROW2, COL1);
Key key10(ROW2, COL2);
Key key11(ROW2, COL3);
Key key12(ROW2, COL4);

uint8_t noModifier[] = {0};
uint8_t shiftModifier[] = {LEFT_SHIFT};

void sendKey(uint8_t keycode, bool shifted = false) {
    uint8_t key[] = {keycode};
    if (shifted) {
        macropad.press(shiftModifier, 1, key, 1);
    } else {
        macropad.press(noModifier, 0, key, 1);
    }
    delay(50);
    macropad.releaseAll();
}

void setup() {
    Serial.begin(115200);
    delay(3000);
    macropad.begin();
    key0.begin();
    key1.begin();
    key2.begin();
    key3.begin();
    key4.begin();
    key5.begin();
    key6.begin();
    key7.begin();
    key8.begin();
    key9.begin();
    key10.begin();
    key11.begin();
    key12.begin();
    Serial.println("Ready - press any key to type its hex ID");
}

void loop() {
    if (key0.pressed())  { Serial.println("key0");  sendKey(NUMBER_0); }
    if (key1.pressed())  { Serial.println("key1");  sendKey(NUMBER_1); }
    if (key2.pressed())  { Serial.println("key2");  sendKey(NUMBER_2); }
    if (key3.pressed())  { Serial.println("key3");  sendKey(NUMBER_3); }
    if (key4.pressed())  { Serial.println("key4");  sendKey(NUMBER_4); }
    if (key5.pressed())  { Serial.println("key5");  sendKey(NUMBER_5); }
    if (key6.pressed())  { Serial.println("key6");  sendKey(NUMBER_6); }
    if (key7.pressed())  { Serial.println("key7");  sendKey(NUMBER_7); }
    if (key8.pressed())  { Serial.println("key8");  sendKey(NUMBER_8); }
    if (key9.pressed())  { Serial.println("key9");  sendKey(NUMBER_9); }
    if (key10.pressed()) { Serial.println("key10"); sendKey(A, true); }
    if (key11.pressed()) { Serial.println("key11"); sendKey(B, true); }
    if (key12.pressed()) { Serial.println("key12"); sendKey(C, true); }
}
