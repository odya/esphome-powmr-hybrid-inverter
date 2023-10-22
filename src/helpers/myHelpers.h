#pragma once

#include <bitset>
#include "esphome.h"

uint16_t swapBytes(uint16_t value);

uint16_t swapBytes(std::string value);

void updateUnknownSelect(uint16_t sensorIndex, esphome::modbus_controller::ModbusSelect* selectComp);
