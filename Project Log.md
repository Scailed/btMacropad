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

## To-Do List
- [ ] Consolidate the btMacropad and Macropad libraries
- [ ] Update the keymap header file to ensure that it doesn't overshadow any of arduino's macros
- [ ] With the consolidation of the btMacropad and Macropad libraries, update the hardware functions so I don't have 
  to declare 13 keys.

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

**3/14/2026**
Claude and I have gotten the macropad working with apple and android devices, now I need to do some work more along 
the lines of user experience. I need to figure out how I want the macropad's keymap to be laid out, and how I want 
to handle connecting to different devices.
- UX Brainstorming:
  - Keymap
    - I don't think I need any layers, 12-13 keys should be enough for anything that I want to specifically have at 
      the press of a button.
    - Each key should just do one thing. Keys on the macropad shouldn't be modifiers
  - Pairing and connecting and such
    - I'd like to have the XIAO show a light indicating that it's connected or in pairing mode.
    - I'd like to have a way to forcefully disconnect devices from the macropad so I don't have to dig up a device 
      from my backpack to disconnect from it.
- Library changes:
  - It would be nice to consolidate btMacropad and Macropad into one library
  - Having 13 "Key" objects is a bit cumbersome in the code, it would be nicer for me to just declare one macropad, 
    and have a configuration for it in a header file or something like that.
  - When a key is pressed, the function that it calls should have a way to wait until that key is released before it 
    sends a keyReleased report
    - This might have some issues with it. If I press a key to do something, and then quickly press another key to 
      do another thing, the first key might obscure the second key, since the microcontroller is still waiting for 
      the first key to be released.
    - There may be interrupts in my future.