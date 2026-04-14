# Project Log

## Bug Tracker
These bugs should be checked off (not deleted) as they are solved
- [x] Platformio is having an issue with littleFs, it can't find it at the moment
  - **Fix:** `/opt/homebrew/Cellar/platformio/6.1.19_1/libexec/bin/python -m pip install littlefs-python`
- [x] Platformio is having an issue with fatFs, it can't find it at the moment
  - **Fix:** `/opt/homebrew/Cellar/platformio/6.1.19_1/libexec/bin/python -m pip install fatfs`
- [x] espressif32 platform version 6.13.0 drops Arduino framework support for seeed_xiao_esp32c6
  - **Fix:** Switch to the pioarduino fork (`platform = https://github.com/pioarduino/platform-espressif32.git#develop`) and add a custom `boards/seeed_xiao_esp32c6.json` with `"variant": "XIAO_ESP32C6"` in the `build` section.
- [x] No serial output from the device after switching to pioarduino/arduino-esp32 3.x
  - **Fix:** Add `-DARDUINO_USB_CDC_ON_BOOT=1` and `-DARDUINO_USB_MODE=1` to `build_flags` in `platformio.ini`
- [x] Apple devices don't respond at all to the macropad's reports
  - **Fix:** Add `READ_ENC` to the Report Map characteristic (`0x2A4B`) and the Report Reference descriptor (`0x2908`) in `btMacropad.cpp`

## Dated entries
**3/13/2026**
- First project log entry
- What works:
  - The macropad shows up as an HID keyboard
  - The macropad advertises itself
  - Key reports go through to android
- What doesn't work:
  - Keypress reports don't go through at all to mac
- Silicon labs says that I need the "Encrypted Read" permission on the report map characteristic and report reference designator to be compatible with iOS: https://docs.silabs.com/bluetooth/2.13/bluetooth-code-examples-applications/ble-hid-keyboard
