# Basic PCB

OSHWLab page: [https://oshwlab.com/ganzevich/PowMr-Hybrid-Inverter](https://oshwlab.com/ganzevich/PowMr-Hybrid-Inverter)

![Assembled in case bottom](assembled_case_b.png)

## PSU module connection
Using standard XL4005 module:

| Main board | XL4005 PSU        |
|------------|-------------------|
| GND pad    | PSU  ` - ` input  |
| 12V pad    | PSU `+` input     |
| 5V pad     | PSU  `+`  output  |

## PZEM module connection

| Inverter               | PZEM module |
|------------------------|-------------|
| AC IN (N)              | Pin 1       |
| AC IN (L)              | Pin 2       |
| PZEM coil (black wire) | Pin 3       |
| PZEM coil (red wire)   | Pin 4       |  

<img src="photos/pzem_ac_connection.jpeg" alt="PZEM AC connection diagram" width="600" height="auto">
<img src="photos/pzem_installation_example.jpeg" alt="PZEM module connection example" width="600" height="auto">

## Case
- [STL model](3DShell_1-PCB_PCB_PowMr_Inverter.zip)

## Resources
- [BOM](BOM_PowMr%20Hybrid%20Inverter_1-PCB_PCB_PowMr%20Inverter_2024-11-03.xlsx)
- [Schematics](SCH_PowMr%20Hybrid%20Inverter_2024-11-03.pdf)
- [Gerber](Gerber_1-PCB_PCB_PowMr_Inverter_2024-11-03.zip)
- [EasyEDA project backup](ProPrj_PowMr-Hybrid-Inverter_2024-11-03.epro)
- PCB Top 
![PCB Top layer](pcb_top.png)
- PCB Bottom
![PCB Bottom layer](pcb_bottom.png)
