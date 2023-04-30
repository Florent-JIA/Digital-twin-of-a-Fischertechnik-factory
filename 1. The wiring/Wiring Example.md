## Wiring Example
In order to give you a clear understanding of the wiring, we will develop here a concrete example, tracing the signal from the SLD module to our PLC.

Let's take the case of the Motor Conveyer Belt, it stands right on the left of the conveyer belt and is one of the main part of the SLD module. As we can see in the picture below, the motor (in black) is linked to its electronic card with two wires. Then the electronic card is linked itself to the motherboard with the grey wire carpet.
![2.25](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.25%20Motor_view.png)
We are now at the motherboard with all its pins and we need to know which one is linked to the motor. To do that, we take a look into the [map of the motherboard (sheet map, or SLD for us)](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/2022-10-18a_Belegungsplan_V2_EN-withITEM.xlsx/), and we see the following :
![2.26](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.26%20Motor_infos.png)
We can read that the pin of the motor conveyer belt is the number "1" of the slot "D05.a". When you first connect your wires the columns "I/O M-DUINO 58+" and "Pin in PLC" will both be empty since you won't have chosen were to connect it on the PLC yet.

Given the names of the pin on the motherboard with [this document](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.2%20requirement%20of%20wiring.png/) we are now able to know which pin we are interested in :
![2.27](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.27%20Motor_pin.png)
Now that we have the motherboard side of the wire, we need to know where to connect it on the PLC. The motor is an output element which means it has to be on the output side of the PLC, it is the one with the letter "Q". There are several compartment to connect wires on the output side of the PLC, but whatever you choose you will need power supply and ground to activate your motor. We recommend that you connect your wire in a section that already has power.

When this is done, you will need to update the [map of the PLC (sheet Mapping M-DUINO) and the information on the module (sheet SLD for us)](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/2022-10-18a_Belegungsplan_V2_EN-withITEM.xlsx/) with the new pins associated.

Once you have updated the documentation you will have to test your new connection. Since the motor is an output you cannot just put your finger in front of a captor and look at the light on the PLC, you will have to write some Arduino code to make it run and then make it stop. For our motor, the code could look like this :
![2.28](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.28%20Motor_tets.png)
This example was meant to describe the process of wiring with a little more details, the principle stays the same with an input, but the checking gets easier.
