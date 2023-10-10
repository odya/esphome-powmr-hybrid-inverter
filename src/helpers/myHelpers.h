#pragma once

#include "Arduino.h"
#include <bitset>
#include "esphome.h"

uint16_t swapBytes(uint16_t value);

uint16_t swapBytes(std::string value);

std::string intToBinStr(uint16_t x);

void updateUnknownSelect(uint16_t sensorIndex, esphome::modbus_controller::ModbusSelect* selectComp);
