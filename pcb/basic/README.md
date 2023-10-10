# Basic PCB

OSHWLab page: https://oshwlab.com/ganzevich/PowMr-Hybrid-Inverter

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
| AC IN (L)              | Pin 2       |
| AC IN (N)              | Pin 1       |
| PZEM coil (black wire) | Pin 3       |
| PZEM coil (red wire)   | Pin 4       |  

<img src="photos/pzem_installation_example.jpeg" alt="PZEM module connection example" width="300" height="auto">

## Resources
- [BOM](BOM_PowMr%20Inverter.csv)
- [Schematics](Schematic_PowMr%20Inverter.pdf)
- [Gerber](Gerber_PCB_PowMr%20Inverter.zip)
- 
- [EasyEDA project backup](easyeda_project_backup.zip)
- PCB Top 
![PCB Top layer](pcb_top.png)
- PCB Bottom
![PCB Bottom layer](pcb_bottom.png)
