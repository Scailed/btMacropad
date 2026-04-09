//
// Created by Cobin Grosjean on 4/8/26.
//

/*
This is the report map for the macropad, it tells
the HID Host (Laptop, Tablet, whatever's receiving
commands from the macropad) how the incoming data
from the macropad is formatted.
*/
static const uint8_t REPORT_MAP[] = {
    0x05, 0x01,  // USAGE_PAGE (Generic Desktop)
    0x09, 0x06,  // USAGE (Keyboard)
    0xA1, 0x01,  // COLLECTION (Application)

    // Modifier byte
    0x05, 0x07,  // USAGE_PAGE (Keyboard)
    0x19, 0xE0,  // USAGE_MINIMUM (Left Control)
    0x29, 0xE7,  // USAGE_MAXIMUM (Right GUI)
    0x15, 0x00,  // LOGICAL_MINIMUM (0)
    0x25, 0x01,  // LOGICAL_MAXIMUM (1)
    0x75, 0x01,  // REPORT_SIZE (1)
    0x95, 0x08,  // REPORT_COUNT (8)
    0x81, 0x02,  // INPUT (Data, Variable, Absolute)

    // Reserved byte
    0x75, 0x08,  // REPORT_SIZE (8)
    0x95, 0x01,  // REPORT_COUNT (1)
    0x81, 0x01,  // INPUT (Constant)

    // Keycode array
    0x19, 0x00,  // USAGE_MINIMUM (0)
    0x29, 0xFF,  // USAGE_MAXIMUM (255)
    0x15, 0x00,  // LOGICAL_MINIMUM (0)
    0x25, 0xFF,  // LOGICAL_MAXIMUM (255)
    0x75, 0x08,  // REPORT_SIZE (8)
    0x95, 0x06,  // REPORT_COUNT (6)
    0x81, 0x00,  // INPUT (Data, Array, Absolute)

    0xC0         // END_COLLECTION (Application)
};

static const uint16_t REPORT_MAP_LEN = sizeof(REPORT_MAP);