#include "Macropad.h"
#include <Arduino.h>

Key::Key(int rowPin, int colPin, int debounceMs, int buttonHeldMs) {
    _rowPin = rowPin;
    _colPin = colPin;
    _state = 0;
    _debounceMs = debounceMs;
    _ignoreNewInputMs = 0;
    _buttonHeldMs = buttonHeldMs;
    _buttonHeldWaitForMs = 0;
}

void Key::begin(){
    // Sets the pin modes for the row pin and column pin of this key
    pinMode(_rowPin, INPUT_PULLDOWN);
    pinMode(_colPin, OUTPUT);
}

bool Key::read() {
    // Turn on the column pin
    digitalWrite(_colPin, HIGH);

    // Check if the debounce time has passed
    if (_ignoreNewInputMs > millis()) {
        // Don't do anything, since the debounce period hasn't passed
    }

    else if (digitalRead(_rowPin) != _state) {
        // Set new time to wait for debounce
        _ignoreNewInputMs = millis() + _debounceMs;
        // Set new time to wait for button held state
        _buttonHeldWaitForMs = millis() + _buttonHeldMs;
        // Change the button state
        _state = !_state;
    }

    // Turn off the column pin
    digitalWrite(_colPin, LOW);
    return _state;
}

bool Key::pressed() {
    // Is the button currently being pressed?
    return (read() == 1);
}

bool Key::released() {
    return(read() == 0);
}

bool Key::held() {
    // Check if the button is pressed and that the time for the button to be "held" has elapsed
    return (read() & (_buttonHeldWaitForMs < millis()));
}
