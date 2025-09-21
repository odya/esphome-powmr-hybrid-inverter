# PowMr Inverter registers map

### Read registers
- 4501 : Mode `measurement`
- 4502 : AC Voltage `measurement`
- 4503 : AC Frequency `measurement`
- 4504 : PV Voltage `measurement`
- 4505 : PV Power `measurement`
- 4506 : Battery Voltage `measurement`
- 4507 : Battery SoC `measurement`
- 4508 : Battery Charge Current `measurement`
- 4509 : Battery Discharge Current `measurement`
- 4510 : Load Voltage `measurement`
- 4511 : Load Frequency `measurement`
- 4512 : Load VA `measurement`
- 4513 : Load Power `measurement`
- 4514 : Load Percent `measurement`
- 4515 : Load Percent `measurement`
- 4516 : Binary flags `binary_flags`
    * `0x100` Something overload related (?)
- 4530 : Error Code
- 4535 : Settings binary flags `binary_flags`
    * `0x1` Record Fault Code `settings`
    * `0x2` Battery Equalization `settings`
    * `0x4` Equalization Activated Immediately `settings`
    * `0x100` Alarm `settings`
    * `0x400` Backlight `settings`
    * `0x800` Restart On Overload `settings`
    * `0x1000` Restart On Overheat `settings`
    * `0x2000` Beep On Primary Source Fail `settings`
    * `0x4000` Return To Default Screen `settings`
    * `0x8000` Overload Bypass `settings`
- 4536 : Charger Source Priority `settings`
- 4537 : Output Source Priority `settings`
- 4538 : AC Input Voltage Range `settings`
- 4540 : Target Output Frequency `settings`
- 4541 : Max Total Charging Current `settings`
- 4542 : Target Output Voltage `settings`
- 4543 : Max Utility Charging Current `settings`
- 4544 : Back To Utility Source Voltage `settings`
- 4545 : Back To Battery Source Voltage `settings`
- 4546 : Bulk Charging Voltage `settings`
- 4547 : Floating Charging Voltage `settings`
- 4548 : Low CutOff Voltage `settings`
- 4549 : Battery Equalization Voltage `settings`
- 4550 : Battery Equalized Time `settings`
- 4551 : Battery Equalized Timeout `settings`
- 4552 : Equalization Interval `settings`
- 4553 : Binary flags `binary_flags`
    * `0x100` On Battery
    * `0x200` AC Active
    * `0x1000` Load Off (Inverted "*Load Enabled*")
    * `0x2000` AC Active
    * `0x4000` Load Enabled
- 4554 : Binary flags `binary_flags`
    * `0x1` On Battery
    * `0x100` AC Active
    * `0x8000` AC Active
- 4555 : Charger Status *(0 - Off, 1 - Idle, 2 - Active)*
- 4557 : Temperature sensor (**HVM10.2M confirmed**, **HVM3.6M confirmed**, **HVM2.4H not confirmed**)
- 4563 : PV2 Voltage (*HVM10.2M only*) `measurement`
- 4564 : PV2 Power (*HVM10.2M only*) `measurement`

### Write registers
*( [+] means tested )*

| Register | Description                                                                         | HVM2.4H |
|----------|-------------------------------------------------------------------------------------|---------|
| 5002     | Buzzer Alarm (range 0-1, settings menu 18)                                          | +       |
| 5004     | Backlight control (range 0-1, settings menu 20)                                     |         |
| 5005     | Auto restart when overload occurs (range 0-1, settings menu 6)                      |         |
| 5006     | Auto restart when over temperature occurs (range 0-1, settings menu 7)              |         |
| 5007     | Beep On Primary Source Fail (range 0-1, settings menu 22)                           | +       |
| 5008     | Auto return to default display screen (range 0-1, settings menu 19)                 |         |
| 5009     | Overload Bypass (0-1, settings menu 23)                                             | +       |
| 5010     | Record fault code (range 0-1, settings menu 25)                                     |         |
| 5017     | Charger Source Priority (range 0-3, settings menu 16)                               | +       |
| 5018     | Output Source Priority (range 0-2, settings menu 1)                                 | +       |
| 5019     | AC input voltage range (range 0-1, settings menu 3) (0 - 90-280VAC, 1 - 170-280VAC) |         |
| 5020     | Battery type (range 0-2, settings menu 5)                                           |         |
| 5021     | Output frequency (range 0-1, settings menu 9) (0 - 50hz, 1 - 60hz)                  |         |
| 5022     | Max Total Charge Current (range 10-80, settings menu 2)                             | +       |
| 5023     | Output voltage (one of 220, 230, 240, settings menu 10)                             |         |
| 5024     | Utility Charge Current (one of 2, 10, 20, 30, 40, 50, 60, settings menu 11)         | +       |
| 5025     | Comeback Utility Mode Voltage (SBU) (0.5 volts step, settings menu 12)              |         |
| 5026     | Comeback Battery Mode Voltage (SBU) (0.5 volts step, settings menu 13)              |         |
| 5027     | Bulk charging voltage (settings menu 26)                                            |         |
| 5028     | Floating charging voltage (settings menu 27)                                        |         |
| 5029     | Low DC cut-off voltage (settings menu 29)                                           |         |
| 5030     | Battery equalization voltage (settings menu 31)                                     |         |
| 5031     | Battery equalized time (settings menu 33)                                           |         |
| 5032     | Battery equalized timeout (settings menu 34)                                        |         |
| 5033     | Equalization interval (settings menu 35)                                            |         |
