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
- [**POW-HVM6.2M-48V**](https://powmr.com/products/hybrid-inverter-charger-6200w-220vac-48vdc)
- [**POW-HVM8.2M**](https://powmr.com/products/hybrid-inverter-charger-8000w-220vac-48vdc)
- [**POW-HVM10.2M**](https://powmr.com/products/hybrid-inverter-charger-10200w-200vac-48vdc)

### Tested models

- **POW-HVM2.4H-24V**
- **POW-HVM10.2M**

## Connection
![PowMr ESP32 connection diagram](images/powmr_esp32_connection.png "PowMr ESP32 connection diagram")

## ESP8266
This configuration can be used on the ESP8266, but you won't be able to use all the sensors due to the memory limitations of the ESP8266. 
You can use minimal set of sensors/selects, leaving only the ones you need. You can use "Heap size" sensor of Debug module to determine how much free memory left. 
Looks like minimum heap size, that ensures stability, is near 6Kb. Although I still strongly recommend using ESP32.

## Usage
1) Create new project subdirectory within your ESPHome configuration directory (let it be `powmr-inverter`, for example) 
2) Copy the contents of the `src` repo folder to a newly created project directory.
3) Now, the `main.yaml` file must be located under `<esphome_config>/powmr-inverter`
4) Create file `powmr-inverter.yaml` in the esphome config directory root and copy contents of [example config](/examples/powmr-inverter.yaml)
5) Edit substitutions & customize `powmr-inverter.yaml`. You can add contents of [common_system](/examples/common_system.yaml) & [common_sensors](/examples/common_sensors.yaml) to this file or include them separately following the example.
6) Flash firmware to your ESP32

## PCB`s
There are 2 versions of PCB design available. Advanced version is more compact but needs SMD soldering skills, basic version uses 2.54 parts & modular approach. 
- Docs for [Basic PCB](pcb/basic/README.md)
- Docs for [Advanced PCB](pcb/advanced/README.md) by [@davidebeatrici](https://github.com/davidebeatrici)

## PZEM module
In version 1.2, a [PZEM](https://esphome.io/components/sensor/pzem004t) module was added for measuring parameters of the input AC grid. If you do not wish to use it, comment out the include of the corresponding module in the [main.yaml](/src/main.yaml) file.

## UART debugging
- Uncomment debug section in [modules/inverter.yaml](/src/modules/inverter.yaml) or [modules/pzem.yaml](/src/modules/pzem.yaml) to enable the debug output of the UART component 
  ```
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
