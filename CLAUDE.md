# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Build & Flash Commands

This project uses [PlatformIO](https://platformio.org/) targeting the **Seeed XIAO ESP32-C6**.

```bash
# Build
pio run

# Flash to device
pio run --target upload

# Open serial monitor (115200 baud)
pio device monitor

# Build + flash + monitor
pio run --target upload && pio device monitor
```

There are no automated tests — functionality is verified on hardware by Grosjean.

## Architecture

The project implements a **Bluetooth LE macropad** (HID keyboard over BLE GATT) on the Seeed XIAO ESP32-C6.

### Libraries

**`lib/btMacropad/`** — BLE HID layer
- `btMacropad.cpp/.h` — The main BLE device. `begin()` initializes NimBLE, creates the GATT server with three services (HID `0x1812`, Battery `0x180F`, Device Information `0x180A`), and starts advertising. `press()` builds an 8-byte HID keyboard report and sends it via `sendKeyReport()`. `releaseAll()` sends a zeroed report.
- `reportMap.h` — The HID report descriptor. Defines an 8-byte report: 1 byte modifiers, 1 byte reserved, 6 bytes keycodes.
- `keyCodes.h` — USB HID keycodes as `#define` constants, named following ZMK conventions. Modifier keys (`LEFT_SHIFT`, etc.) range `0xE0–0xE7` and are passed in the `modifiers[]` array. All other keys go in the `keys[]` array.

**`lib/Macropad/src/`** — Hardware abstraction for the physical keys of the macropad.
- `Macropad.cpp/.h` — `Key` class for a single key in a row/column matrix. `begin()` sets pin modes (`INPUT_PULLDOWN` for row, `OUTPUT` for col). `read()` drives the column HIGH, samples the row, applies debounce, and drives column LOW. `pressed()`, `released()`, and `held()` are convenience wrappers.

**`src/main.cpp`** — Entry point. Instantiates `Key` and `btMacropad`, calls `begin()` on both in `setup()`, then polls `key0.pressed()` in `loop()`.

### Key BLE Details

- Security: bonding-only (`BLE_SM_PAIR_AUTHREQ_BOND`), no I/O capability — the host decides pairing automatically.
- The Input Report characteristic (`0x2A4D`) uses `READ | NOTIFY | READ_ENC`. iOS requires `READ_ENC` to recognize HID characteristics.
- Services start automatically when created via `createService()` — **never call `->start()` on a service**.
- On disconnect, advertising restarts automatically via `MacropadServerCallbacks::onDisconnect`.

### HID Report Format

`press(modifiers[], numModifiers, keys[], numKeys)` builds an 8-byte report:
- Byte 0: modifier bitmask (bit `n` = modifier key `0xE0 + n`)
- Byte 1: reserved (always `0x00`)
- Bytes 2–7: up to 6 keycodes

Pass modifier keycodes (`LEFT_SHIFT`, `LEFT_CONTROL`, etc.) in `modifiers[]` and regular keycodes in `keys[]`.

### Bug tracker
These bugs should be checked off (not deleted) as they are solved
- [ ] Platformio is having an issue with littleFs, it can't find it at the moment
- [ ] Apple devices don't respond at all to the macropad's reports
