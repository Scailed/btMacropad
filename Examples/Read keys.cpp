//
// Created by Cobin Grosjean on 4/4/26.
//
#include <Arduino.h>
#include "../lib/Macropad/src/Macropad.h"

int row0 = D10;
int row1 = D9;
int row2 = D8;

int col0 = D0;
int col1 = D1;
int col2 = D2;
int col3 = D3;
int col4 = D4;


Key key1(row0, col0);
Key key2(row0, col1);
Key key3(row0, col2);
Key key4(row0, col3);
Key key5(row1, col0);
Key key6(row1, col1);
Key key7(row1, col2);
Key key8(row1, col3);
Key key9(row2, col0);
Key key10(row2, col1);
Key key11(row2, col2);
Key key12(row2, col3);
Key key13(row2, col4);

void setup() {
    Serial.begin(115200);
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
    key13.begin();
}

void loop() {

}