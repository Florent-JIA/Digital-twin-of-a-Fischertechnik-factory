# MQTT Failure
We first wanted to use MQTT as a communication tool. However, we failed to implement it and use it with our PLC and the associated parts of the factory (MQTT broker and raspberry pi). MQTT is a publish/subscribe system allowing us to send and receive information without refreshing a web page every 0.5 second.

You might use this technology in the future, if you do so you will need to change the Arduino code (but not that much since it follows a modular conception), the Unity scripts (again not much since it is just another module) and the Node-red code (again and again not much since there is a dedicated block replacing the HTTP one).

Moreover, we think that using MQTT will be easier for you if you come to use several PLCs.
