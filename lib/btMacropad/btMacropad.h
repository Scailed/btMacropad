//
// Created by Cobin Grosjean on 4/5/26.
//

#include "NimBLEDevice.h"

class MacropadServerCallbacks;

class btMacropad {
    friend class MacropadServerCallbacks;

private:
    std::string _deviceName;
    bool _connected = false;
    NimBLEServer *_pServer;
    NimBLEService *_pHIDService;
    NimBLEService *_pBatteryService;
    NimBLEService *_pDeviceInformationService;
    NimBLECharacteristic *_pProtocolMode;
    NimBLECharacteristic *_pInputReport;
    NimBLECharacteristic *_pReportMap;
    NimBLECharacteristic *_pHIDInformation;
    NimBLECharacteristic *_pHIDControlPoint;
    NimBLECharacteristic *_pBatteryLevel;
    NimBLECharacteristic *_pManufacturerNameString;
    NimBLECharacteristic *_pModelNumberString;
    NimBLECharacteristic *_pFirmwareRevisionString;
    NimBLECharacteristic *_pSoftwareRevisionString;
    NimBLEAdvertising *_pAdvertising;
    MacropadServerCallbacks *_pServerCallbacks;

public:
    btMacropad();
    void begin();
    void end();
    bool isConnected() const { return _connected; }
    void press(uint8_t modifiers[], uint8_t numModifiers, uint8_t keys[], uint8_t numKeys);
    bool releaseAll();
    void sendKeyReport(uint8_t keyReport[]);
};