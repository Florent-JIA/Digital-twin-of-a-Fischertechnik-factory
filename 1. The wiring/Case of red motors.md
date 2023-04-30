During our project we dealt with black motors which are very simple to control (HIGH and LOW states) but there is another type of motors that you should be careful with. The red motors are part of several modules (HBW, VGR) and need to be correctly wired. Those motors need to be wired using interruption outputs (PWM in the documentation) in order to know their state and position correctly (the time step we're using in an Arduino code is too big). To do that you will need to use some callback methods.

You will realize that some other elements require interruption outputs (even some black motors), then you should wire them only in the right place.

In order for you not to do any mistake, always follow [this document of the mapping of the factory](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/2022-10-18a_Belegungsplan_V2_EN-withITEM.xlsx/).
