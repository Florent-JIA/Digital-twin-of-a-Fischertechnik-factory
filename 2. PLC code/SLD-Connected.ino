// --------------------------------------------------------------------------------------------------------------------------

//         INITIALISATION OF VARIABLES

// --------------------------------------------------------------------------------------------------------------------------

// List of output pins on the PLC
int output_motor = 41;
int output_compressor = 42;
int output_ejector_white = 43;
int output_ejector_red = 44;
int output_ejector_blue = 45;
int output_ejector = 45;

// List of input pins on the PLC
int input_detector_blue = 69;
int input_detector_red = 68;
int input_detector_white = 67;
int input_detector = 69;
int input_detector_after = 66;
int input_detector_before = 65;
int input_pulse = 64;
int input_detector_color = 60;

// Information about the spatial positions
int tour = 0;
int tour_max = 50;
int old_tour = digitalRead(input_pulse);
int distance_first_piston = 5;
int distance = 1;
int distance_between_ejector = 10;

// Information about the state of the SLD module
int count = 0;
int old_count = 0;
int toward_ejector = 0;
int toward_furnace = 0;
int state = 0;
int delivered = 0;

// Information about the color of the element
int min_color = 780;
int red_analog_value = 700;
int white_analog_value = 470;
int margin_color = 30;
int color = 2;

// Constants
int delay_global = 10;
int delay_small = 1;
int activated = 1;
int desactivated = 0;
int color_white = 0;
int color_red = 1;
int color_blue = 2;
int state_init = 0;
int state_furnace = 1;
int state_piston = 2;
int state_delivered = 3;
int delivered_processing = 0;
int delivered_right = 1;
int delivered_wrong = 2;
int delivered_problem = 3;
int distance_init = 5;
int distance_ejector = 10;
int distance_compressor = 20;
int distance_motor = 30;
int distance_start_ejector = 4;
int init_min_color = 780;
int init_tour = 0;
int stop_SLD = 0;
int stop_SLD_init = 0;
int stop_SLD_required = 1;


// HTTP configuration (Ethernet, MAC, IP, port)
#include <SPI.h>
#include <Ethernet.h>
byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
IPAddress ip(10, 10, 10, 30);
EthernetServer server(80);


// --------------------------------------------------------------------------------------------------------------------------

//         INITIALISATION METHOD

// --------------------------------------------------------------------------------------------------------------------------

void setup() {
  // Initialisation of Ethernet connection
  Ethernet.init(10);
  // Open serial communications and wait for port to open:
  Serial.begin(9600UL);
  while (!Serial) {
    ; // Wait for serial port to connect. Needed for native USB port only
  }
  // Start the Ethernet connection and the server:
  Ethernet.begin(mac, ip);
  // Check for Ethernet hardware present
  if (Ethernet.hardwareStatus() == EthernetNoHardware) {
    while (true) {
      delay(delay_small); // do nothing, no point running without Ethernet hardware
    }
  }
  // Start the server
  server.begin();
}


// --------------------------------------------------------------------------------------------------------------------------

//         MAIN METHOD

// --------------------------------------------------------------------------------------------------------------------------

void loop() {

  // *****************************
  // Dealing with parameters
  // *****************************
  
  // Incrementation of count
  count ++;
  // We choose a 10ms delay so that we don't miss the pulse changes
  delay(delay_global);

  // *****************************
  // Methods to run the factory
  // *****************************
  
  SLD();

  // *****************************
  // HTTP communication part
  // *****************************
  
  // Creation of client
  EthernetClient client = server.available();
  // HTTP communication with computer (end of ethernet wire)
  if (client) {
    // An HTTP request ends with a blank line
    boolean currentLineIsBlank = true;

    // This part is for the action from the computer on the real factory
    String requestType = client.readStringUntil(' ');
    String requestUrl = client.readStringUntil(' ');
    // We check the request url and apply the changes required on the factory
    if (requestUrl == "/stop/"){
      // If the stop button is pressed we call the stop method
      SLD_voluntary_stop();
    }
    else if (requestUrl == "/working/") {
      // If the button is not pressed we apply the working method
      SLD_voluntary_working();
    }

    // This part is for transmitting information from the real factory to the computer
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        // If you've gotten to the end of the line (received a newline character) and the line is blank, the HTTP request has ended, so you can send a reply
        if (c == '\n' && currentLineIsBlank) {
          // Send a standard HTTP response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          // The connection will be closed after completion of the response
          client.println("Connection: close");  
          // Refresh the page automatically every second
          client.println("Refresh: 1");  
          client.println();
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");

          // *****************************
          // Data sent through HTTP
          // *****************************

          // Output_motor
          client.print(digitalRead(output_motor));
          client.println("<br />");
          // Output_compressor
          client.print(digitalRead(output_compressor));
          client.println("<br />");
          // Output_ejector_blue
          client.print(digitalRead(output_ejector_blue));
          client.println("<br />");
          // Output_ejector_red
          client.print(digitalRead(output_ejector_red));
          client.println("<br />");
          // Output_ejector_white
          client.print(digitalRead(output_ejector_white));
          client.println("<br />");
          // Captor before furnace
          client.print(1-digitalRead(input_detector_before));
          client.println("<br />");
          // Captor after furnace
          client.print(1-digitalRead(input_detector_after));
          client.println("<br />");
          // Captor white
          client.print(1-digitalRead(input_detector_white));
          client.println("<br />");
          // Captor red
          client.print(1-digitalRead(input_detector_red));
          client.println("<br />");
          // Captor blue
          client.print(1-digitalRead(input_detector_blue));
          client.println("<br />");
          // Captor color
          client.print(min_color);
          client.println("<br />");
          // State furnace
          client.print(toward_furnace);
          client.println("<br />");
          // State ejector
          client.print(toward_ejector);
          client.println("<br />");
          // State of the element
          client.print(state);
          client.println("<br />");
          // Tours of the pulse
          client.print(tour);
          client.println("<br />");
          // If element was delivered (including alerts)
          client.print(delivered);
          client.println("<br />");
          // Color of the element
          client.print(color);
          client.println("<br />");
          // If the button to stop the factory is pressed or not
          client.print(stop_SLD);
          client.println("<br />");
          
          client.println("</html>");
          break;
        }
        if (c == '\n') {
          // You're starting a new line
          currentLineIsBlank = true;
        } else if (c != '\r') {
          // You've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // Give the web browser time to receive the data
    delay(delay_small);
    // Close the connection
    client.stop();
  }
}


// --------------------------------------------------------------------------------------------------------------------------

//         GENERAL METHODS

// --------------------------------------------------------------------------------------------------------------------------

// *****************************
// Method to run the SLD module
// *****************************

void SLD(){
  // We start when we have an element in the input of the SLD module
  if(!digitalRead(input_detector_before)
  && stop_SLD != stop_SLD_required) {
    SLD_input_element();
  }
  
  // We count the pulses so that we know where we are on the sorting line (spatial landmark)
  if(old_tour != digitalRead(input_pulse)) {
    SLD_increment_tour();
  }

  // We check if the element gets out of the furnace, else we shut down the SLD module
  if(toward_furnace == activated
  && tour > tour_max) {
    SLD_urgent_stop();
  }
  
  // We look at the color of the element
  if(min_color > analogRead(input_detector_color)
  && toward_furnace == activated) {
    SLD_changing_color();
  }

  // When we reach the detector after the furnace, we change our objective from detecting color to pushing the element at the right place
  if(!digitalRead(input_detector_after)
  && toward_ejector == desactivated 
  && toward_furnace == activated
  && stop_SLD != stop_SLD_required) {
    SLD_output_element();
  }

  // We deal with the final delivery of the element
  if((toward_ejector == activated 
  || state == state_delivered)
  && stop_SLD != stop_SLD_required) {
    // We take action once the element is in front of its ejector
    SLD_check_position();
  }
}

// *****************************
// Method for the incoming elements
// *****************************

void SLD_input_element() {
  // We start the motor
  digitalWrite(output_motor, HIGH);
  // We initiate the different values required for each cycle  
  SLD_initialize();
}

void SLD_initialize() {
  tour = init_tour;
  distance_first_piston = distance_init;
  min_color = init_min_color;
  toward_furnace = activated;
  toward_ejector = desactivated;
  state = state_furnace;
  delivered = delivered_processing;
}


// *****************************
// Method to increment the pulse
// *****************************

void SLD_increment_tour() {
  tour ++;
  // We update the state of the pulse
  old_tour = digitalRead(input_pulse);
}

// *****************************
// Method to stop the SLD module when a problem is detected
// *****************************

void SLD_urgent_stop() {
  // We turn the motor off to avoid any more problem
  digitalWrite(output_motor, LOW);
  delivered = delivered_problem;
  old_count = count;
}

// *****************************
// Method to stop the SLD module when required on the dashboard
// *****************************

void SLD_voluntary_stop() {
  // We turn the outputs off
  stop_SLD = stop_SLD_required;
  digitalWrite(output_motor, LOW);
  digitalWrite(output_ejector, LOW);
  delay(5);
  digitalWrite(output_compressor, LOW);
}

// *****************************
// Method to launch the SLD module when required on the dashboard
// *****************************

void SLD_voluntary_working() {
  SLD_initialize();
  stop_SLD = stop_SLD_init;
}

// *****************************
// Method to update the color minimum
// *****************************

void SLD_changing_color() {
  // We update the minimum of the analog signal we got for our element (to detect the right color)
  min_color = analogRead(input_detector_color);
}

// *****************************
// Method for the elements coming out of the furnace
// *****************************

void SLD_output_element() {
  // We choose the right ejector and detector for the right color
  if(min_color < white_analog_value + margin_color) {
    output_ejector = output_ejector_white;
    input_detector = input_detector_white;
    color = color_white;
  }
  else if(min_color < red_analog_value + margin_color) {
    output_ejector = output_ejector_red;
    input_detector = input_detector_red;
    color = color_red;
  }
  else {
    distance_first_piston ++;
    output_ejector = output_ejector_blue;
    input_detector = input_detector_blue;
    color = color_blue;
  }
  // We calculate the distance to reach the ejector (from the detector after the furnace)
  distance = distance_first_piston + color*distance_between_ejector + tour;
  toward_furnace = desactivated;
  toward_ejector = activated;
  state = state_piston;
}

// *****************************
// Method to deal with the delivery of the element
// *****************************

void SLD_check_position() {
  if(color == color_white
  && state == state_piston) {
      // We start the compressor
      digitalWrite(output_compressor, HIGH);
  }
  else if(tour == distance - distance_start_ejector
  && state == state_piston) {
      // We start the compressor
      digitalWrite(output_compressor, HIGH);
  }
  
  // When in front of the ejector we push the element
  if(tour == distance) {
      state = state_delivered;
      digitalWrite(output_ejector, HIGH);
      toward_ejector = desactivated;
  }
  // After some time (expressed in distance here) we pull back the ejector
  else if(tour == distance + distance_ejector) {
      digitalWrite(output_ejector, LOW);
  }
  // After some more time we turn the compressor off
  else if(tour == distance + distance_compressor) {
      digitalWrite(output_compressor, LOW);
  }
  // After even more time we turn the motor off
  else if(tour == distance + distance_motor) {
      digitalWrite(output_motor, LOW);
      state = state_init;

      // We finally check if the element got in the right place
      if(digitalRead(input_detector)) {
        // Wrong place
        delivered = delivered_wrong;
        old_count = count;
      }
      else {
        // Right place
        delivered = delivered_right;
      }
   }
}
