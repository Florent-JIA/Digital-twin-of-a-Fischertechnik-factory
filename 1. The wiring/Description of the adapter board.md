# Adapter board description
This is part of the [PLC Allocation Plan](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/1.%20The%20wiring/PLC%20Allocation%20Plan.md/).

Each module on the factory is connected to the PLC via an adapter board. On our model, the adaptor boards are already cabled. The grey ribbon cable is connected to the PLC connection board. On the other hand, the rainbow ribbon cables are connected to all the sensors and actuators of the model.
![2.12](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.12%20AdapterBoard.png)
On this first representation, we can witness the amount of available regular terminals which is 32. This (with the four PWM terminals) will be the maximum amount of pins we can connect to this module.

The system also has a number of bidirectional motors, which need more support than regular actuators. Bidirectional are controlled through either the actuator +24V pin (number 1 on the ST1 header for PLC connection) or the appropriate PWM port. In order to "choose" which source we're using, there are 4 jumpers on each of the adapter boards. By default they define the PWM ports as sources.
![2.13](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.13%20image.png)
PWM (Pulse Width Modulation) ports are relayed to bi-directional motors on the adapter board. They are limited to four per adapter board, and as seen above, are not always used.
