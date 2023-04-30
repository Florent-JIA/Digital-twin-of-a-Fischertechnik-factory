# PLC terminals description
This is part of the [PLC Allocation Plan](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/PLC%20Allocation%20Plan.md/).

![2.14](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.14image.png)<br>
In this representation, we'll note that the "end" pins are used for ground or "global" commands. We'll ignore those first two pins except for careful testing of the factory operability. I pins are situated from 5 to 16, there are a maximum of 12 of them on one adaptor. Q pins are situated from 17 to 32, there are a maximum of 16 of them.<br>
![2.15](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.15image.png)<br>
We can see on this table that all adaptor boards are connected to the PLC through a 34 pins PLC1, which explains observations reported [here](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/The%20cable%20connection.txt/).

Moreover, the R1->R8 pins correspond exactly to the PMW (pulse with modulation) terminals described [here](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/The%20cable%20connection.txt/).

On the other hand, the V1 -> V4 terminals correspond to valve commands.
