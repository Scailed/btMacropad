//
// Created by Cobin Grosjean on 4/5/26.
//

#include "btMacropad.h"
#include "NimBLEDevice.h"
#include "reportMap.h"

btMacropad::btMacropad() {

}

/**
 * @brief
 * Initializes the NimBLEDevice, sets up the HID over GATT Profile,
 * and begins advertising the macropad
 *
 * @details
 * This function initializes the NimBLEDevice by calling NimBLE::init(),
 * creates a server with NimBLE::createServer(), creates three services with createService(): HID Service,
 * Battery Service, and Device Information Service, and adds characteristics to those services according to
 * their respective specifications. It then sets up the NimBLE server to be advertised and finally begins advertising.
 * The bluetooth specifications used to inform how this function was written are as follows:
 * - HID Over GATT Profile: https://www.bluetooth.com/specifications/specs/hid-over-gatt-profile/
 * - HID Device Service: https://www.bluetooth.com/specifications/specs/human-interface-device-service-1-0/
 * - Battery Service: https://www.bluetooth.com/specifications/specs/battery-service/
 * - Device Information Service: https://www.bluetooth.com/specifications/specs/device-information-service/
 * - Assigned Numbers: https://www.bluetooth.com/specifications/assigned-numbers/
 * - HID Device Class Definition: https://www.usb.org/document-library/device-class-definition-hid-111
 * - HID Usage Tables: https://www.usb.org/sites/default/files/hut1_6.pdf
 *
 * @usage
 * macropad.begin();
 */
void btMacropad::begin() {
    // Initialize the NimBLE Device and create the server
    NimBLEDevice::init("NimBLE");
    _pServer = NimBLEDevice::createServer();

    // Create the services specified in the HID over GATT Profile specification: https://www.bluetooth.com/specifications/specs/hid-over-gatt-profile/
    // Specifications for the HID Service from https://www.bluetooth.com/specifications/specs/human-interface-device-service-1-0/
    _pHIDService = _pServer->createService("1812");
    _pProtocolMode = _pHIDService->createCharacteristic("2A4E", NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::WRITE_NR);
    _pProtocolMode->setValue(01); // Set to Report Protocol Mode
    _pInputReport = _pHIDService->createCharacteristic("2A4D", NIMBLE_PROPERTY::READ | NIMBLE_PROPERTY::NOTIFY);
    _pReportMap = _pHIDService->createCharacteristic("2A4B", NIMBLE_PROPERTY::READ);
    _pReportMap->setValue(REPORT_MAP);
    _pHIDInformation = _pHIDService->createCharacteristic("2A4A", NIMBLE_PROPERTY::READ);
    _pHIDControlPoint = _pHIDService->createCharacteristic("2A4C", NIMBLE_PROPERTY::WRITE_NR);

    // Specifications for the Battery Service from https://www.bluetooth.com/specifications/specs/battery-service/
    _pBatteryService = _pServer->createService("180F");
    _pBatteryLevel = _pBatteryService->createCharacteristic("2A19", NIMBLE_PROPERTY::READ);

    // Specifications for the Device Information Service from https://www.bluetooth.com/specifications/specs/device-information-service/
    _pDeviceInformationService = _pServer->createService("180A");
    _pManufacturerNameString = _pDeviceInformationService->createCharacteristic("2A29", NIMBLE_PROPERTY::READ);

    _pAdvertising = NimBLEDevice::getAdvertising();
    _pAdvertising->addServiceUUID(_pHIDService->getUUID());
    _pAdvertising->addServiceUUID(_pBatteryService->getUUID());
    _pAdvertising->addServiceUUID(_pDeviceInformationService->getUUID());
    _pAdvertising->setName("NimBLE");
    _pAdvertising->start();
}

void btMacropad::end() {
}

// TODO: Test the functionality of this function
// TODO: Document this function
void btMacropad::press(uint8_t modifiers[], uint8_t numModifiers, uint8_t keys[], uint8_t numKeys) {
    uint8_t report[8] = {0};

    for (int i = 0; i < numModifiers; i++) {
        report[0] |= (1 << (modifiers[i] - 0xE0));
    }

    // Reserved Bit
    report[1] = 0x00;

    for (int i = 0; i < numKeys; i++) {
        report[i + 2] = keys[i];
    }

    sendKeyReport(report);
}

bool btMacropad::releaseAll() {
    uint8_t report[8] = {0};

    sendKeyReport(report);
    return 0;
}


void btMacropad::sendKeyReport(uint8_t keyReport[]) {
    _pInputReport->setValue(keyReport, 8);
    _pInputReport->notify();
}
