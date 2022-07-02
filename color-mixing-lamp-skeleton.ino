// set up constants for the different colors of the RGB LED pins you're using
// when declaring constants, it is a common convention to use all uppercase letters
const int REDLEDPIN = 8;
[add code here] // set up green led pin
[add code here] // set up blue led pin

const int REDSENSORPIN = A0;
[add code here] // set up light sensor that corresponds to green
[add code here] // set up light sensor that corresponds to blue

// set up variables to store the sensor readings
int redSensorVal;
[add code here]
[add code here]

void setup() {
  // put your setup code here, to run once:
  // set up the LEDS as output and the sensors as input; remember to use your constants
  pinMode(REDLEDPIN, OUTPUT);
  [add code here] // set up LED as input
  [add code here] // set up LED as input

  [add code here] // set up sensor as output
  [add code here] // set up sensor as output
  [add code here] // set up sensor as output

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  // read the sensor values and store the value in the appropriate variable
  redSensorVal = analogRead(REDSENSORPIN);
  [add code here] // read value from the green sensor pin
  [add code here] // read value from the blue sensor pin

  // print red sensor value
  Serial.print("Red Sensor Value:");
  Serial.print(redSensorVal);
  Serial.print("\t"); // The "\t" is the equivalent of pressing the "tab" key on the keyboard

  // print green sensor value
  [add code here] // print text formatting
  [add code here] // print sensor value
  [add code here] // print tab

  // print blue sensor value
  [add code here] // print text formatting
  [add code here] // print sensor value
  [add code here] // print tab

  /*
     STOP HERE STOP HERE STOP HERE STOP HERE STOP HERE STOP HERE STOP HERE
     red covered: [add number here] (cover the red sensor and write in red sensor value)
     green covered: [add number here] (cover the red sensor and write in red sensor value)
     blue covered: [add number here] (cover the red sensor and write in red sensor value)
  */

  // if red sensor is covered, and green and blue sensors are not covered, turn on red LED
  if (redActive(redSensorVal) && !greenActive(greenSensorVal) && !blueActive(blueSensorVal)) { // red
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, LOW);
  }
  // if green sensor is covered, and red and blue sensors are not covered, turn on green LED
  else if ([add code here]) { // green
    [add code here]
    [add code here]
    [add code here]
  }
  // if blue sensor is covered, and red and green sensors are not covered, turn on blue LED
  else if ([add code here]) { // blue
    [add code here]
    [add code here]
    [add code here]
  }
  // if red and green sensors are covered, and the blue sensor is not covered, turn on red and green LEDs
  else if ([add code here]) { // yellow
    [add code here]
    [add code here]
    [add code here]
  }
  // if red and blue sensors are covered, and the green sensor is not covered, turn on red and blue LEDs
  else if ([add code here]) { // magenta
    [add code here]
    [add code here]
    [add code here]
  }
  // if green and blue sensors are covered, and the red sensor is not covered, turn on green and blue LEDs
  else if ([add code here]) { // cyan
    [add code here]
    [add code here]
    [add code here]
  }
  // if all three sensors are covered, turn on all three LEDs
  else if ([add code here]) { // white
    [add code here]
    [add code here]
    [add code here]
  }
  // is all three sensors are not covered, turn of all LEDs
  else {
    [add code here]
    [add code here]
    [add code here]
  }
}

// function that checks if the red sensor is being covered
bool redActive(int redVal) {
  int redThreshold = 100;
  if (redVal < redThreshold)
    return true;
  return false;
}

// function that checks if the green sensor is being covered
bool greenActive(int greenVal) {
  int greenThreshold = 750;
  if (greenVal < greenThreshold)
    return true;
  return false;
}

// function that checks if the blue sensor is being covered
bool blueActive(int blueVal) {
  int blueThreshold = 400;
  if (blueVal < blueThreshold)
    return true;
  return false;
}
