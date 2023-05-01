# Digital twin of a Fishertechnik factory
![whole+SLD+DigitalTwin](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fishertechnik-factory/blob/main/imgs/1.%20whole%20factory%2BSLD%2Bdigital%20twin.png)
This is a complex project organized by my school. My teammates and I built a digital twin for our Fischertechnik factory model over 6 months. In order to realize it, we have accomplished the wiring of the factory model, wrote the control program to make the factory run, built a dashboard to display the working status of each module of the factory, established a real-time 3D representation of the factory and wrote script codes to automate the program execution.
## Introduction
Dgital twin technology is an important part of Industry 4.0. This technology aims to rebuild a vitrual model in the virtual space that can reflect the working status of the factory in real time, so that the factory can be remotely monitored, controlled and diagnosed. Our work mainly contains 4 parts: 1) **the wiring**, 2) **PLC code**, 3) **dashboard** and 4) **3D representation**.
## The wiring
In this project we used a [Fischtechnik](https://www.fischertechnik.de/en/products/industry-and-universities/) factory model. The components of this factory model were not 100% connected before the project started. The different modules have already been conencted to the factory mother board. So, we needed to wire from the factory mother board to the PLC.
![wiring](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.%20wiring%20to%20the%20mother%20board%20and%20to%20the%20PLC.png)
For more information, please consult [The wiring](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/tree/main/1.%20The%20wiring/) folder.
## PLC code
Due to time constraints, we mainly work on the SLD (Sorting Line based on color Detection) module. We wrote an Arduino program to activate the operation of this modulem and tansmit the working status changes detected by sensors to the server in real time.

For more informaiton, please consult [PLC code](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/tree/main/2.%20PLC%20code/) floder.
![SLD plan](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.1%20plan%20of%20SLD.png)
**(f) the plan of the SLD module**

![work flow of SLD code](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.2%20State_diaram_ProCom__1_.png)
<br>**work flow of PLC code**
## Dashboard
## 3D representation
