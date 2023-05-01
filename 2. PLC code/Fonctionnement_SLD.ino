// List of output pins on the PLC
int output_motor = 41;
int output_compressor = 42;
int output_ejector_white = 43;
int output_ejector_red = 44;
int output_ejector_blue = 45;
int output_ejector;

// List of input pins on the PLC
int input_detector_blue = 69;
int input_detector_red = 68;
int input_detector_white = 67;
int input_detector;
int input_detector_after = 66;
int input_detector_before = 65;
int input_pulse = 64;
int input_detector_color = 60;

// Information about the spatial positions
int tour = 0;
int old_tour = digitalRead(input_pulse);
//int tour_color = 20;
//int tour_furnace = 5;
int distance_init = 5;
int distance = 1;
int distance_between_ejector = 10;

// Information about the state of the SLD module
int count = 0;
int toward_ejector = 0;
int toward_furnace = 0;

// Information about the color of the element
int min_color = analogRead(input_detector_color);
int blue_analog_value = 780;
int red_analog_value = 700;
int white_analog_value = 450;
int margin_color = 20;
int color = 2;


void setup() {
  // We initiate the connection with the PLC
  Serial.begin(9600UL);
}

void loop() {
  count ++;
  // We choose a 10ms delay so that we don't miss the pulse changes
  delay(10);

  sld();
  
}

void sld() {
  // We start when we have an element in the input of the PLC module
  if(!digitalRead(input_detector_before)) {
    input_element();
  }

  // We count the pulses so that we know where we are on the sorting line
  if(old_tour != digitalRead(input_pulse)) {
    increment_tour();
  }

  // We look at the color of the element
  if(min_color > analogRead(input_detector_color)
  && toward_furnace == 1) {
    changing_color();
  }

  // When we reach the detector after the furnace, we send a signal with the "reset" variable
  if(!digitalRead(input_detector_after)
  && toward_ejector == 0) {
    output_element();
  }

  if(toward_ejector == 1) {
    // We take action once the element is in front of its ejector
    check_position();
  }
}

void input_element() {
  Serial.println("Un jeton a ete detecte en entrée du SLD, le moteur se met en marche");
  delay(1000);
  // We start the motor
  digitalWrite(output_motor, HIGH);
  // We initiate the different values required for each cycle
  output_ejector = 45;
  input_detector = 69;
  tour = 0;
  distance_init = 5;
  color = 2;
  min_color = analogRead(input_detector_color);
  toward_furnace = 1;
  toward_ejector = 0;
}

void increment_tour() {
  tour ++;
  //Serial.print("Nombre de tours : ");
  //Serial.println(tour);
  old_tour = digitalRead(input_pulse);
}

void output_element() {
  Serial.println("Demarrage du compresseur.");
  // We start the compressor
  digitalWrite(output_compressor, HIGH);
  // We choose the right ejector and detector for the right color
  if(min_color < white_analog_value + margin_color) {
    output_ejector = output_ejector_white;
    input_detector = input_detector_white;
    color = 0;
    Serial.println("Couleur detectee : blanc.");
  }
  else if(min_color < red_analog_value + margin_color) {
    output_ejector = output_ejector_red;
    input_detector = input_detector_red;
    color = 1;
    Serial.println("Couleur detectee : rouge.");
  }
  else {
    Serial.println("Couleur détectee : bleu.");
    distance_init = distance_init+1;
  }
  // We calculate the distance to reach the ejector (from the detector after the furnace)
  distance = distance_init + color*distance_between_ejector;
  //Serial.print("Distance pour atteindre l'éjecteur associe : ");
  //Serial.println(distance);
  distance = distance + tour;
  toward_furnace = 0;
  toward_ejector = 1;
  Serial.println("Un jeton a ete detecte en sortie du four du SLD.");
}

void changing_color() {
  //Serial.print("Nouveau minimum de couleur : ");
  min_color = analogRead(input_detector_color);
  //Serial.println(min_color);
}

void check_position() {
  if(tour == distance) {
      digitalWrite(output_ejector, HIGH);
      delay(500);
      digitalWrite(output_ejector, LOW);
      delay(500);
      digitalWrite(output_compressor, LOW);
      delay(500);
      digitalWrite(output_motor, LOW);
      distance = 1;
      // We finally check if the element got in the right place
      if(digitalRead(input_detector)) {
        Serial.println("Le jeton n'a pas ete livre correctement.");
      }
      else {
        Serial.println("Le jeton a ete livre correctement.");
      }
    }
}