//
// Created by Cobin Grosjean on 4/5/26.
//

#include "NimBLEDevice.h"

class btMacropad {
private:
    std::string _deviceName;
    NimBLEServer *_pServer;
    NimBLEService *_pHIDService;
    NimBLEService *_pBatteryService;
    NimBLEService *_pDeviceInformationService;
    NimBLECharacteristic *_pProtocolMode;
    NimBLECharacteristic *_pReportInputType;
    NimBLECharacteristic *_pReportMap;
    NimBLECharacteristic *_pHIDInformation;
    NimBLECharacteristic *_pHIDControlPoint;
    NimBLECharacteristic *_pBatteryLevel;
    NimBLECharacteristic *_pManufacturerNameString;
    NimBLEAdvertising *_pAdvertising;

public:
    btMacropad();
    void begin();
    void end();
    size_t press(int key);
    size_t release(int key);
    void setName(std::string deviceName);
};