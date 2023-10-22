#include <bitset>
#include <string>
#include <iostream>
#include "esphome.h"
#include "esphome/core/log.h"
#include "myHelpers.h"

uint16_t swapBytes(uint16_t value)
{
  return (value << 8) | (value >> 8);
}

uint16_t swapBytes(std::string value)
{
  uint16_t intValue = std::stoi(value);
  return (intValue << 8) | (intValue >> 8);
}

void updateUnknownSelect(uint16_t sensorIndex, esphome::modbus_controller::ModbusSelect* selectComp)
{
  const char* logTag = "myHelpers";
  if (!selectComp->active_index().has_value() || sensorIndex != selectComp->active_index().value()) {
    //esphome::ESP_LOGW(logTag, "Update select to index %d", sensorIndex);
    auto call = selectComp->make_call();
    call.set_index(sensorIndex);
    call.perform();
  }
}



