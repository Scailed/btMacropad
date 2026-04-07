//
// Created by Cobin Grosjean on 4/5/26.
//
#include <Arduino.h>
#include "NimBLEDevice.h"

void setup() {
    NimBLEDevice::init("NimBLE");

    NimBLEServer *pServer = NimBLEDevice::createServer();
    NimBLEService *pService = pServer->createService("ABCD");
    NimBLECharacteristic *pCharacteristic = pService->createCharacteristic("1234");

    pService->start();
    pCharacteristic->setValue("Hello BLE");

    NimBLEAdvertising *pAdvertising = NimBLEDevice::getAdvertising();
    pAdvertising->addServiceUUID("ABCD"); // advertise the UUID of our service
    pAdvertising->setName("NimBLE"); // advertise the device name
    pAdvertising->start();
}