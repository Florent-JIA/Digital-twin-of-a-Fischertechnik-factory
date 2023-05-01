# Digital twin of a Fishertechnik factory
![whole+SLD+DigitalTwin](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fishertechnik-factory/blob/main/imgs/1.%20whole%20factory%2BSLD%2Bdigital%20twin.png)
This is a complex project organized by my school. My teammates and I built a digital twin for our Fischertechnik factory model over 6 months. In order to realize it, we have accomplished the wiring of the factory model, wrote the control program to make the factory run, built a dashboard to display the working status of each module of the factory, established a real-time 3D representation of the factory and wrote script codes to automate the program execution.
## Introduction
Dgital twin technology is an important part of Industry 4.0. This technology aims to rebuild a vitrual model in the virtual space that can reflect the working status of the factory in real time, so that the factory can be remotely monitored, controlled and diagnosed. Our work mainly contains 4 parts: 1) **the wiring**, 2) **PLC code**, 3) **dashboard**, 4) **3D representation** and 5) **scripts**.
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
<br>**(g) work flow of PLC code**
## Dashboard
We used a software called **Node Red** to buil a dashboard to display the working status of each component of the SLD module.

For more informaiton, please consult [Dashboard](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/tree/main/3.%20Dashboard/) floder.
![Dashboard](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.6%20Dashboard.png)
<br>**(h) Dashboard**
## 3D representation
The core of the digital twin is to create a virtual model of the factory in the virtual space. The oparation of this virtual model is consistent with the real factory and can provide more information as required. We used **Unity** to create a digital twin for our factroy model.

For more informaiton, please consult [3D representation](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/tree/main/4.%203D%20representation/) floder.

<br>![digital twin of SLD](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.digital%20twin%20of%20SLD.png)
<br>**(i) digital twin of the SLD module**
## Script and Steps
Our work is done on different platforms. Entering these platforms to view the results separately will cause difficulties for users. So, we have written some scipts to allow these cross-platform work to run automatically, which makes it easy to use.

For more informaiton, please consult [Scripts](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/tree/main/5.%20Scripts/) floder.
