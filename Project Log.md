**3/13/2026**  
- First project log entry
- What works:
  - The macropad shows up as an HID keyboard
  - The macropad advertises itself
  - Key reports go through to android
- What doesn't work:
  - Keypress reports don't go through at all to mac
- Silicon labs says that I need the "Encrypted Read" permission on the report map characteristic and report reference designator to be compatible with iOS: https://docs.silabs.com/bluetooth/2.13/bluetooth-code-examples-applications/ble-hid-keyboard