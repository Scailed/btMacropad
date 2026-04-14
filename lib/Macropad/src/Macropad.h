#include <Arduino.h>

// Pin definitions for my particular macropad
const int ROW0 = D10;
const int ROW1 = D9;
const int ROW2 = D8;

const int COL0 = D0;
const int COL1 = D1;
const int COL2 = D2;
const int COL3 = D3;
const int COL4 = D4;


/*
This is the keymap for my particular macropad:
       +------+------+-------+-------+-------+
       | COL0 | COL1 | COL2  | COL3  | COL4  |
+------+------+------+-------+-------+-------+
| ROW0 | key0 | key1 | key2  | key3  |
+------+------+------+-------+-------+
| ROW1 | key4 | key5 | key6  | key7  |
+------+------+------+-------+-------+-------+
| ROW2 | key8 | key9 | key10 | key11 | key12 |
+------+------+------+-------+-------+-------+
 */

class Key {

    public:
        Key(int rowPin, int colPin, int debounceMs = 100, int buttonHeldMs = 500);
        void begin();
        bool read();
        bool pressed();
        bool released();
        bool held();

    private:
        int _rowPin;
        int _colPin;
        bool _state;
        int _debounceMs;
        int _ignoreNewInputMs;
        int _buttonHeldMs;
        int _buttonHeldWaitForMs;
};