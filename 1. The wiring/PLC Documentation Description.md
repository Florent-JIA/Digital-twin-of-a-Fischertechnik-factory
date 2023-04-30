# PLC Documentation Description
[MDuino58+_User_Guide](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/MDuino58%2B_User_Guide.pdf/)

30/08/2019 -- Revision 0

This page describes the documentation found for the Arduino PLC pair available in order to control the factory.

More information on those can be found on the Industrial Shield shop [webpage](https://www.industrialshields.com/shop/product/is-mduino-58-m-duino-plc-arduino-ethernet-58-i-o-s-analog-digital-plus-176/):

Model: M-DUINO PLC Arduino Ethernet 58 I/O's Analog/Digital PLUS

## Introduction
![2.21](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.21%20image.png)
The model has its interfaces separated in between 4 zones. Zone A holds a specific role as it contains all the network interfaces. It does not contain any digital or analogic port, so we can forget it when connecting the factory to the PLCs. The port names are built using three information:
- Nature: Input -> I; Digital output -> Q; Analog output -> A;
- Zone: B -> 0; C -> 1; D -> 2;
- Position: from 1 to 13 for inputs and from 1 to 8 for outputs

E.g. The second input pin of the zone C has the name I1.2 .

Every port on the three zones can act as a digital port.

B and C zones are perfectly similar. They totalize 13 inputs and 8 outputs each. D zone is slightly smaller with only 11 inputs and 6 outputs.

One side of the PLC is dedicated to inputs, while the other is dedicated to outputs.

## Symbology
On the sides of the PLC are multiple symbols to help understand the meaning of the different interfaces. This table from the document explains how to read them.
![2.22](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.22%20image.png)
<br>We'll particularly notice the first three lines of this table.

Industrial Shields PLC are programmed using Arduino IDE, which is a software based on the C language. They can also be programmed using directly C but it is much easier working with Arduino IDE as it provides lots of libraries that helps in the programming. Industrial Shields provides boards for programming the PLCs much easier. Basically it is no needed to define the pins and if that pins are inputs or outputs. Everything is set up automatically if using the boards.

## Setting up the software interface
1. Install Arduino IDE 1.8.0 or later on your machine (download [here](https://www.arduino.cc/en/software/))
2. Open Arduino IDE
3. Go to **File** > **Preferences**
4. Put this [URL](https://apps.industrialshields.com/main/arduino/boards/package_industrialshields_index.json/) as a new **Additional Board Manager**:
5. Confirm this modification and exit Preferences with **Okay** (bottom right)
6. Go to **Tools** > **Board**  > **Boards Manager**
7. Search for the keyword “**industrialshields**”
8. Install the latest version of the industrialshield Board Manager
From this point onwards, the steps are specific to the PLC model described above.
9. Go to **Tools** > **Board** > **inustrialshields** and select the **M-Duino family** entry
10. Go to **Tools** > **Model** and select the **M-Duino 58+**

## Connecting a PC to the PLC
1. Use an **USB interface** on both machines.
2. Open Arduino IDE
3. (Make sure the Arduino IDE is correctly set up)
4. In **Tools** > **Port** select the appropriate port

## Analog/Digital ports config
For outputs, the nature must be specified manually for the three (only two in zone D) upper ports. An analog port in the table below is noted as A, while digital ports are noted as Q. If the respective switch at the top of each output zone is **ON**, the port is **DIGITAL**.
![2.22.1](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.22.1image.png)

## PLC Pinnouts
All the information can be found in the document, and most of it can be understood by looking at the PLCs. We'll take the example of zone B here. Zones C and D are organized in the same fashion.
![2.23](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.23%20image.png)
We can see that on the first face of the PLC, the zone only holds inputs (color coded with a pale green background in the document). From the bottom of the PLC, we can first find the 5 digital only inputs (I0.0 -> I0.4). Above it is a couple of interrupt inputs (I0.5 - I0.6). They can serve specific functions for the PLC (see [here](/) for an explanation) . Above it are 6 inputs that can serve for both analog and digital signals (I0.7 -> I0.12).

On the table to the left, we can notice the Arduino Pins column, which gives us the ID of the pins to indicate on the Arduino IDE software.
![2.24](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.24%20image.png)
This part is the second side face of the PLC, for zone B. We can see that this face is "shorter" than the other one. On the bottom are the 8 digital outputs (Q0.0 -> Q0.7). Above it are the three analog outputs (A0.5 -> A0.7). At the top we see the switches for configuration again. Only one of each of the three pairs with identifier 0.5 -> 0.7 is active at a moment, based on their respective switch state.

/!\ The switch states on the A zone can deactivate some ports on zones B, C and D.
