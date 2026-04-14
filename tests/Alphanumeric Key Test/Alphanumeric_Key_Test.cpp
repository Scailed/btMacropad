//
// Created by Cobin Grosjean on 4/14/26.
//

#include <Arduino.h>
#include <../lib/btMacropad/btMacropad.h>
#include <../lib/Macropad/src/Macropad.h>
#include <../lib/btMacropad/keyCodes.h>

int row0 = D10;
int col0 = D0;

Key key0(row0, col0);
btMacropad macropad;

uint8_t noModifier[] = {0};

uint8_t alphanumericKeys[] = {
    A, B, C, D, E, F, G, H, I, J, K, L, M,
    N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
    NUMBER_1, NUMBER_2, NUMBER_3, NUMBER_4, NUMBER_5,
    NUMBER_6, NUMBER_7, NUMBER_8, NUMBER_9, NUMBER_0
};

void sendAlphanumericSequence() {
    for (int i = 0; i < 36; i++) {
        uint8_t key[] = {alphanumericKeys[i]};
        macropad.press(noModifier, 0, key, 1);
        delay(50);
        macropad.releaseAll();
        delay(50);
    }
}

void setup() {
    Serial.begin(115200);
    delay(3000);
    macropad.begin();
    key0.begin();
    Serial.println("Ready - press key 0 to send alphanumeric sequence");
}

void loop() {
    if (key0.pressed()) {
        Serial.println("Sending alphanumeric sequence...");
        sendAlphanumericSequence();
        Serial.println("Done - expected output: ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890");
    }
}
