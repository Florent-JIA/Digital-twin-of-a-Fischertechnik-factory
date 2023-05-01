# Node Red Installation
The installation of applications on the computer of our office is confidential. So, we invited a teacher who has confidential ID to give us the access to install NodeRed on the computer.

NodeRed is used to create the dashboard of our factory. To install it, type the following command in a terminal:

bash <(curl -sL https://raw.githubusercontent.com/node-red/linux-installers/master/deb/update-nodejs-and-nodered)

(website industrialshields [here](https://www.industrialshields.com/blog/arduino-industrial-1/post/arduino-tutorial-node-red-dashboard-and-arduino-web-server-440#:~:text=Node%2DRED%20is%20a%20programming,runtime%20in%20a%20single%20click/))

During installation, you must have the administrator role. To do this, you need to run the following commands

1. start a session with the user
2. open a terminal, and change to superuser with su (someone who knows the root password of the machine must be present)
3. apt update; apt install sudo
4. adduser user sudo
5. restart the sudo user's session.

Run the following command if you want Node-RED to run when the open source PLC is turned on, or re-booted.

sudo systemctl enable nodered.service

sudo systemctl start nodered.service

Once NodeRed is installed and running you can go to the http://localhost:1880/ and import the json file to retrieve the dashboard.

# Creation of Dashboard
To create the dashboard, we used the industrialShield tutorial. You can find this tutorial by following this link

In the section "Node-RED Dashboard Nodes", you can find out how to install the package needed to build the dashboard. In the following section, you will find instructions on how to Get input data from the server.

For the Dashboard of the SLD part. we obtain the following result:
![Work flow of the dashboard](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.7%20FlowAll.png)
This flow is composed of different parts.

Retrieving and displaying data :
![Retrieving and displaying data](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.8%20Motor.png)

<br>Putting on coloured gauges :
<br>![Putting on coloured gauges](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.9%20Colors.png)

<br>Show notifications :
<br>![Show notifications](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.10%20Notif.png)

<br>Interacting with the factory :
<br>![Interacting with the factory](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.11%20Interaction.png)

<br>Final Result:
<br>![Final Result](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.6%20Dashboard.png)

# Interaction with the factory
We explained earlier how to transmit information from the factory to the computer (and we can imagine a server in the future), however it is also very important to understand how to send information from the computer to the factory, in order to make digital actions reality.

In our module, we use this mechanism (action on the factory from the computer) in order to stop the production line with a stop button on the dashboard.
![stop button](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.12%20Button_Stop.png)

To do so, we use a little trick about URLs. Indeed, our main URL for the HTTP Web Server is "10.10.10.30/" (which you can change in the Arduino code and in the other codes if you want), however we can also snd information to "10.10.10.30/stop/" and "10.10.10.30/working/" which will be our  URLs for the purpose of our stop button. Now, when our button is "on" then it sends a request to "10.10.10.30/stop/" which is received in the Arduino code and then take action on the factory (stopping the motor, the compressor, etc...). On the other hand, when the button is "off" then we send a request to "10.10.10.30/working/" and the different variables are adapted for a "normal" functionning.
![stop work flow](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.11%20Interaction.png)
![code of stop](https://github.com/Weizhe-JIA/2.Digital-twin-of-a-Fischertechnik-factory/blob/main/imgs/3.13%20PROCOM_PHOTO_4.png)
Note : you might have understood that using MQTT would have been much easier here, we would just need to publish the information of the button on a certain topic instead of reaching new URLs.
