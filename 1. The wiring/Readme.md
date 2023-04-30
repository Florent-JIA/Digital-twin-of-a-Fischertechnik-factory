# Connecting the cables the right way
This part is dedicated to the description of our work and comprehension of the wiring of the SLD part. However, the process to wire other modules is similar and this file can thus be reuse in the future.
 
First of all, we had to understand the different documentations and the way the factory functioned. We used several resources to do so :
- [the allocation of the factory modules to the PLC]()
- [the requirements to activate the different parts of the PLC]()
 
Now, the most important part is to understand how the information will flow from a composant to the PLC. In the picture below we can see that the information from the compressor of the SLD module is first transmitted to the mother board of the SLD module. Then the information runs into the grey cable and ends in the factory mother board. This means that every information coming from the factory by cable will end up in the factory mother board. The wiring to the factory mother board is already done so you just need to understand it (not doing it).
![wiring to the mother board](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.1%20wiring%20to%20mother%20board.png)
Thus, we "only" need to wire from the factory mother board to the PLC. To do that, we are quite free on the choice of the place to wire on the PLC (we only need to select an empty working place). Thus, we are only constrained by the mother board which we need to know which place corresponds to what (and then test the wires we did). The two pictures below represents the same thing : the factory motherboard, one in picture the other on a schema.
![requirements of wiring](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.2%20requirement%20of%20wiring.png)
![the mother board](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.3%20the%20mother%20board.png)
This representation of the motherboard allows us to map the slots of the motherboard with their meaning in the factory. This mapping is made on [this document]() and allows us to know how to wire from the mother board to the PLC. The first page of this document (sheet "map", and the first picture below) shows us what each slot of the mother board corresponds to in terms of Module and pin. For example we can see that for the slot DO6 (second picture), 4 pins are used for the SSC module on slot a and 4 pins for the SSC module on slot b. We also have the information of the terminal used for those pins (here 19 to 26). Now, we can have a look at the sheet of the module we are interested in (here "SSC") to know what each terminal is related to (third picture). This is how we know which pin of the slot on the mother board is linked to which component in the factory.
![requirements of wiring](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.4%20Lien_carte_m%C3%A8re_modules.png)
![the mother board](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.5%20Lien_carte_m%C3%A8re_modules%201.png)
![requirements of wiring](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.6%20Lien_carte_m%C3%A8re_modules%202.png)
Once we understood what each cable represented, we started connecting the output wires of the factory to the PLC. We decided to connect all the cables to one PLC (which makes it easier for the code later since we do not need to link several PLCs' inputs / outputs). We identified the pins that were involved in the SLD with the mapping from the motherboard and then connected the wires in the places we needed.
 
We also created two mapping, one from the module part of the motherboard to the PLC and one from the PLC to the motherboard ; these two mapping are available on [this document (sheet "Mapping M-DUINO" and sheets of the modules)]() and are showing the same thing, we choose to maintain the two mapping since we want to avoid any issues and since one mapping can be easier to read given a specific situation.
 
As explained on the documentation, we connected the input on one side of the PLC (detectors and color sensor) whereas we connected the outputs on the other side (motor, compressor, ejectors) as shown on the next photos.
![wiring to PLC](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.7%20wiring%20to%20PLC.png)
![PLC output](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.8%20PLC_Output.png)
On the input side we didn't need to add any wire (the power supply of the PLC was already connected) since we used the pins of the PLC with a ground directly activated. However on the output side, we had to add a power and a ground wire so that the different outputs can activate.

Note : this part might seem obvious but it actually took us a while (about 3 weeks) to understand that we were lacking a ground with the different inputs and outputs. In order for next groups to gain time, we wrote the pins of the PLC that required ground or power in the [map of the PLC (sheet Mapping M-DUINO)]().

After correctly connecting the various wires, one can see lights at the top of the PLC. These lights correspond to the various inputs / outputs that are active. These lights are very useful since they allow you to test the different detectors and to test the outputs too.
![haut du PLC](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.9%20Haut_du_PLC.png)<br>
For example, the detector of the SLD part that stands right after the furnace is connected to I2.7 on the PLC, thus when we activate the power the light associated to this input turns on at the top, and when we put an element in front of it it turns off. Thus, we can almost know everything that's happening in the factory just by looking at the top of the PLC.<br>
![Haut_du_PLC_I2.7](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.10%20Haut_du_PLC_I2.7.png)<br>
Finally, there are two columns to connect wires on the PLC, the one with small holes is meant to be temporary (the wires can be disconnected by simply pulling them), this column is very useful when checking the connections. However when the wiring part is over and well done, we recommend that you switch the wires to the other column (with big holes and orange security) so that they are not disconnected too easily.
 
Note : of course the connection on the big holes is not irreversible, you just have to push the orange security with a screwdriver and to pull the wire.
 
Note : the connection we did for the SLD part can be changed, however you will need to change the [map of the PLC (sheet Mapping M-DUINO) and the map of the motherboard (sheet SLD for us)]() in consequence.<br>
![branchement](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/2.11%20Branchement.png)<br>
In order to give you a clear understanding of the wiring, a concrete example tracing the signal from the SLD module to the PLC [is available here]().

The process previously described can be applied to other modules. If you choose to do so, do not forget to update the [map of the PLC (sheet Mapping M-DUINO) and the map of the motherboard (sheet of your module)]() and to check every input and output (so that you don't have bad surprises in the code 😄  ).