# Script and steps to run the digital twin from scratch
## Steps to deploy the digital twin from scratch
### Install all tools
**Git**
In order to recover all the elements of the project, you must start by cloning the project
git clone git@gitlab.imt-atlantique.fr:idf/dtfischertechnik.git with a ssh
or
git clone https://gitlab.imt-atlantique.fr/idf/dtfischertechnik.git with https
then retrieve the different parts of the project with the command
git pull

**Arduino IDE**
1. Install Arduino IDE 1.8.0 or later on your machine (download [here](https://www.arduino.cc/en/software/))
2. Open Arduino IDE
3. Go to File > Preferences
4. Put this URL as a new Additional Board Manager:
https://apps.industrialshields.com/main/arduino/boards/package_industrialshields_index.json
5. Confirm this modification and exit Preferences with Okay (bottom right)
6. Go to Tools > Board  > Boards Manager
7. Search for the keyword “industrialshields”
8. Install the latest version of the industrialshield Board Manager
From this point onwards, the steps are specific to the PLC model described above.
9.Go to Tools > Board > inustrialshields and select the M-Duino family entry
10. Go to Tools > Model and select the M-Duino 58+

**Connecting a PC to the PLC**
1. Use an USB interface on both machines.
2. Open Arduino IDE
3. (Make sure the Arduino IDE is correctly set up)
4. In Tools > Port select the appropriate port

**Unity (for develop)**
If you want to modify the 3D model, you have to install Unity (dowload [here](https://unity.com/fr/download/))

**NodeRed**
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

**Launching the digital twin**
for that you have to follow the instructions:

In order to launch all the components (Dashboard, 3D model) we have made a bash script that allows to run the Unity executable in order to launch our 3D factory and to open a web page on the dashboard.

In order to execute the script, the following command must be entered in a terminal:

./Execution_Jumeau_Numérque.sh

Before execution, it must be taken into account that the path to access the Unity executable is correct. If this is not the case, it will be necessary to modify the script in order to set the correct path.

Structure of the script :

#!/bin/bash
cd ~/Script_directory
./Name_of_executable_unity &
Open a web page in parallel
firefox "link_nodered"

## Script to launch Unity and the dashboard
In order to launch all the components (Dashboard, 3D model) we have made a bash script that allows to run the Unity executable in order to launch our 3D factory and to open a web page on the dashboard.

In order to execute the script, the following command must be entered in a terminal:

./Execution_Jumeau_Numérque.sh

Before execution, it must be taken into account that the path to access the Unity executable is correct. If this is not the case, it will be necessary to modify the script in order to set the correct path.

Structure of the script :

#!/bin/bash
cd ~/Script_directory
./Name_of_executable_unity &

Open a web page in parallel

firefox "link_nodered"
