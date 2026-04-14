//
// Created by Cobin Grosjean on 4/6/26.
//

// Keycodes retrieved from section 10 of https://www.usb.org/document-library/hid-usage-tables-17
// Keycode names roughly follow ZMK's list of keycodes: https://zmk.dev/docs/keymaps/list-of-keycodes

// Alphabet
#define A 0x04
#define B 0x05
#define C 0x06
#define D 0x07
#define E 0x08
// TODO: #define F conflicts with Arduino's F() string macro — consider renaming
#define F 0x09
#define G 0x0A
#define H 0x0B
#define I 0x0C
#define J 0x0D
#define K 0x0E
#define L 0x0F
#define M 0x10
#define N 0x11
#define O 0x12
#define P 0x13
#define Q 0x14
#define R 0x15
#define S 0x16
#define T 0x17
#define U 0x18
#define V 0x19
#define W 0x1A
#define X 0x1B
#define Y 0x1C
#define Z 0x1D

// Numbers
#define NUMBER_1 0x1E
#define NUMBER_2 0x1F
#define NUMBER_3 0x20
#define NUMBER_4 0x21
#define NUMBER_5 0x22
#define NUMBER_6 0x23
#define NUMBER_7 0x24
#define NUMBER_8 0x25
#define NUMBER_9 0x26
#define NUMBER_0 0x27

// Control and whitespace
#define ESCAPE 0x29
#define ENTER 0x28
#define SPACE 0x2C
#define TAB 0x2B
#define DELETE 0x2A
#define INSERT 0x49

// Navigation
#define HOME 0x4A
#define END 0x4D
#define PAGE_UP 0x4B
#define PAGE_DOWN 0x4E
#define UP_ARROW 0x52
#define DOWN_ARROW 0x51
#define LEFT_ARROW 0x50
#define RIGHT_ARROW 0x4F

// Function keys
#define F1 0x3A
#define F2 0x3B
#define F3 0x3C
#define F4 0x3D
#define F5 0x3E
#define F6 0x3F
#define F7 0x40
#define F8 0x41
#define F9 0x42
#define F10 0x43
#define F11 0x44
#define F12 0x45
#define F13 0x68
#define F14 0x69
#define F15 0x6A
#define F16 0x6B
#define F17 0x6C
#define F18 0x6D
#define F19 0x6E
#define F20 0x6F
#define F21 0x70
#define F22 0x71
#define F23 0x72
#define F24 0x73

// Modifiers
#define LEFT_SHIFT 0xE1
#define LEFT_CONTROL 0xE0
#define LEFT_ALT 0xE2
#define LEFT_GUI 0xE3
#define RIGHT_CONTROL 0xE4
#define RIGHT_SHIFT 0xE5
#define RIGHT_ALT 0xE6
#define RIGHT_GUI 0xE7

// Lock keys
#define CAPS_LOCK 0x39
#define NUM_LOCK 0x53
#define SCROLL_LOCK 0x47
#define PRINT_SCREEN 0x46
#define PAUSE 0x48

// Symbols and punctuation
#define MINUS 0x2D
#define EQUAL 0x2E
#define LEFT_BRACKET 0x2F
#define RIGHT_BRACKET 0x30
#define BACKSLASH 0x31
#define SEMICOLON 0x33
#define SINGLE_QUOTE 0x34
#define GRAVE 0x35
#define COMMA 0x36
#define PERIOD 0x37
#define SLASH 0x38

// Numpad
#define KP_SLASH 0x54
#define KP_ASTERISK 0x55
#define KP_MINUS 0x56
#define KP_PLUS 0x57
#define KP_ENTER 0x58
#define KP_1 0x59
#define KP_2 0x5A
#define KP_3 0x5B
#define KP_4 0x5C
#define KP_5 0x5D
#define KP_6 0x5E
#define KP_7 0x5F
#define KP_8 0x60
#define KP_9 0x61
#define KP_0 0x62
#define KP_DOT 0x63