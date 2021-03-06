/*
*    Example-Code that emulates a DS2433 4096 bits EEPROM
*
*   Tested with
*    - DS9490R-Master, atmega328@16MHz and teensy3.2@96MHz as Slave
*/

#include "OneWireHub.h"
#include "DS2433.h"

constexpr uint8_t pin_onewire   { 8 };

auto hub = OneWireHub(pin_onewire);
//reza
//23 5b ca c9 01 00 00 e0 ff
auto ds2433 = DS2433(DS2433::family_code, 0x5B, 0xCA, 0xC9, 0x01, 0x00, 0x00);

constexpr uint8_t memDUMP[] =
  {
    0xFF, 0x81, 0x8D, 0x00, 0x08, 0x02, 0x00, 0x48, 0xFF, 0xFF, 0x0E, 0xB3, 0x81, 0xE2, 0xFA, 0x2A, 0xC7, 0xC2, 0x1B,
    0x64, 0x69, 0xA8, 0xDE, 0xC0, 0xC1, 0xA4, 0x00, 0xE6, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x00, 0xF4, 0xB7,
    0x00, 0x3A, 0x3F, 0xFB, 0xCF, 0x66, 0xDE, 0xB8, 0xFA, 0x23, 0x8F, 0xD0, 0x3F, 0x63, 0xAC, 0x4B, 0xE1, 0xB9, 0x83,
    0x12, 0x50, 0x60, 0xF1, 0xB1, 0x13, 0x90, 0xFE, 0x7A, 0x10, 0x6B, 0xD9, 0xAE, 0x74, 0xDC, 0x77, 0xBE, 0xBE, 0x25,
    0xCC, 0xF1, 0xA3, 0xE1, 0x82, 0xE4, 0xC7, 0xD7, 0x4A, 0xD2, 0x47, 0x5D, 0x0D, 0xA9, 0xF6, 0xE1, 0x3D, 0x07, 0x68,
    0x55, 0xFE, 0xF2, 0x2F, 0x8D, 0x8B, 0x72, 0x93, 0x20, 0x35, 0x0C, 0x0D, 0xC8, 0xD7, 0x37, 0x26, 0x90, 0x4E, 0xFB,
    0x1A, 0x97, 0x1C, 0x8A, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55,
    0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x01, 0x55, 0x04, 0x55, 0x04, 0x55, 0x40, 0x55, 0x01,
    0x55, 0x00, 0x55, 0x10, 0x55, 0x04, 0x40, 0x00, 0x08, 0x3D, 0x60, 0x2F, 0x4C, 0x6E, 0xA1, 0x24, 0x8A, 0x5F, 0xC5,
    0x77, 0x95, 0x18, 0x40, 0x30, 0xEC, 0x50, 0x9C, 0xCC, 0x09, 0xEF, 0x27, 0x2E, 0x5E, 0x7B, 0xA3, 0x4F, 0xD4, 0x9D,
    0xD6, 0x73, 0x3B, 0x2C, 0x0E, 0xDD, 0xAC, 0x1F, 0xE5, 0x75, 0xCB, 0x86, 0x9D, 0xDA, 0x6C, 0x06, 0x6F, 0x89, 0xBC,
    0x72, 0xBF, 0x01, 0x9F, 0x74, 0xD9, 0xC3, 0x52, 0x70, 0x29, 0xE5, 0x41, 0x99, 0xA0, 0xD7, 0xFC, 0xAE, 0x09, 0x44,
    0x49, 0xC4, 0x8D, 0x78, 0x73, 0xB0, 0x0B, 0x49, 0x97, 0xD1, 0x40, 0x4E, 0xDD, 0xF3, 0xAA, 0x8E, 0xA9, 0xCD, 0xDF,
    0xD5, 0x5E, 0x1B, 0xF7, 0x99, 0xA5, 0x39, 0xFC, 0x96, 0xB0, 0x2E, 0xC7, 0x2E, 0x15, 0xF0, 0x28, 0x39, 0x28, 0xFA,
    0xD0, 0x7A, 0x60, 0x6F, 0xC1, 0x5B, 0x7D, 0x8D, 0x4C, 0x24, 0x04, 0xBF, 0xAA, 0xD6, 0x48, 0x78, 0xCD, 0x55, 0x82,
    0x8A, 0x29, 0xCB, 0x34, 0xBF, 0xF3, 0x87, 0x78, 0x76, 0xD6, 0x9B, 0xB5, 0x18, 0x63, 0xCB, 0x1F, 0x87, 0x11, 0xE7,
    0x31, 0x9A, 0x42, 0x8B, 0xD8, 0xDD, 0xD9, 0xE4, 0x8C, 0x03, 0xA1, 0x10, 0x17, 0x9D, 0x6F, 0xAF, 0x75, 0x4D, 0xCA,
    0x95, 0x33, 0x47, 0x66, 0xE1, 0x87, 0x2F, 0x58, 0x60, 0x5C, 0xC3, 0x4B, 0x0A, 0x54, 0x2E, 0x20, 0x26, 0x73, 0x6A,
    0x7C, 0x94, 0x05, 0x07, 0x96, 0xDA, 0xE1, 0xE8, 0x9C, 0x6C, 0x2F, 0x5B, 0x3E, 0x0C, 0xE9, 0x84, 0xB2, 0x73, 0x68,
    0xF7, 0x99, 0xDE, 0x55, 0xFD, 0x83, 0x35, 0xAB, 0x68, 0x5B, 0x3E, 0x27, 0x09, 0x51, 0x6D, 0x15, 0xDC, 0xAC, 0x1A,
    0xEE, 0x98, 0xBB, 0x06, 0x19, 0xE5, 0x37, 0x34, 0x47, 0x55, 0x67, 0x9D, 0xC9, 0x9F, 0x11, 0xE5, 0x55, 0x55
  };


void setup()
{
    Serial.begin(115200);
    Serial.println("OneWire-Hub DS2433");

    hub.attach(ds2433);

    ds2433.writeMemory(memDUMP, sizeof(memDUMP), 0);

    Serial.println("config done");
}

void loop()
{
    // following function must be called periodically
    hub.poll();
} 
