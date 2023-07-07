# ESPHome PowMr Hybrid Inverter
ESPHome config for various PowMr Hybrid Inverter models.

## Compatibility
All models that are supported by the [**WIFI-VM**](https://powmr.com/products/powmr-wifi-module-with-rs232-remote-monitoring-solution-wifi-vm) device should work:

- [**POW-HVM1.5H-12V**](https://powmr.com/products/all-in-one-inverter-charger-1500watt-220vac-12vdc)
- **POW-HVM2.0H-12V**
- [**POW-HVM2.4H-24V**](https://web.archive.org/web/20230329235125/https://powmr.com/inverters/all-in-one-inverter-chargers/powmr-2400watt-dc-24v-ac-220v-solar-inverter-charger)
- [**POW-HVM3.2H-24V**](https://powmr.com/products/all-in-one-inverter-charger-3000w-220vac-24vdc)
- [**POW-HVM3.6M-24V**](https://powmr.com/products/hybrid-inverter-charger-3600w-220vac-24vdc)
- [**POW-HVM4.2M-24V**](https://powmr.com/products/hybrid-inverter-charger-4200w-220vac-24vdc)
- [**POW-HVM5.5K-48V**](https://powmr.com/products/all-in-one-inverter-charger-5500w-220vac-48vdc)
- [**POW-HVM6.2M-48V**](https://powmr.com/products/hybrid-inverter-charger-6200w-220vac-48vdc)
- [**POW-HVM8.2M**](https://powmr.com/products/hybrid-inverter-charger-8000w-220vac-48vdc)
- [**POW-HVM10.2M**](https://powmr.com/products/hybrid-inverter-charger-10200w-200vac-48vdc)

### Tested models

- **POW-HVM2.4H-24V**
- **POW-HVM10.2M**

## Requirements
- One half of an ethernet cable with RJ45 connector
- RS232-to-TTL module (MAX3232CSE f.e.)
- Generic ESP32 (recommended) or ESP8266 board

## Connection
![PowMr ESP32 connection diagram](images/powmr_esp32_connection.png "PowMr ESP32 connection diagram")

## ESP8266
This configuration can be used on the ESP8266, but you won't be able to use all the sensors due to the memory limitations of the ESP8266. 
You can use minimal set of sensors/selects, leaving only the ones you need. You can use "Heap size" sensor of Debug component to determine how much free memory left. 
Looks like minimum heap size, that ensures stability, is near 6Kb.

## Usage
- Copy `config` & `powmr-inverter` from src directory
- Customize config details (secrets, device name, etc.)

## Debugging
- Uncomment debug section to enable the debug output of the UART component 
  ```
  uart:
    id: uart_0
    baud_rate: 2400
    tx_pin: ${tx_pin}
    rx_pin: ${rx_pin}
    # debug:
    #   direction: BOTH
    #   dummy_receiver: false
  ```
- Increase the log level to `DEBUG` or `VERBOSE`
  ```
  logger:
    level: WARN
  ```

## Notes
- Registers map: [registers-map.md](docs/registers-map.md)
- Read registers are using little-endian format that doesn't have a native support in ESPHome, so we need a custom function to swap bytes.
- Manuals:
  - [POW-HVM1.5H-12V](docs/POW-HVM2.4H-24V.pdf)
  - [POW-HVM2.4H-24V](docs/POW-HVM2.4H-24V.pdf)
  - [POW-HVM2.0H-12V](docs/POW-HVM3.2H-24V.pdf)
  - [POW-HVM3.2H-24V](docs/POW-HVM3.2H-24V.pdf)
  - [POW-HVM10.2M](docs/POW-HVM10.2M.pdf)

## References & thanks
- https://github.com/leodesigner/powmr_comm 
  Great research on PowMr registers and C++ firmware code with MQTT. Thanks to author, it helps me a lot.
- https://github.com/syssi/esphome-smg-ii
  ESPHome project to monitor and control a ISolar/EASUN SMG II inverter via RS232
