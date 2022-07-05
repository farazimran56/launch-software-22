// constants
const int REDLEDPIN = 8;
const int GREENLEDPIN = 9;
const int BLUELEDPIN = 10;

const int REDSENSORPIN = A0;
const int GREENSENSORPIN = A1;
const int BLUESENSORPIN = A2;

// non-constant variables
int redSensorVal;
int greenSensorVal;
int blueSensorVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(REDLEDPIN, OUTPUT);
  pinMode(GREENLEDPIN, OUTPUT);
  pinMode(BLUELEDPIN, OUTPUT);

  pinMode(REDSENSORPIN, INPUT);
  pinMode(GREENSENSORPIN, INPUT);
  pinMode(BLUESENSORPIN, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  redSensorVal = analogRead(REDSENSORPIN);
  greenSensorVal = analogRead(GREENSENSORPIN);
  blueSensorVal = analogRead(BLUESENSORPIN);

  Serial.print(redSensorVal);
  Serial.print("\t");
  Serial.print(greenSensorVal);
  Serial.print("\t");
  Serial.println(blueSensorVal);

  if (redActive(redSensorVal) && !greenActive(greenSensorVal) && !blueActive(blueSensorVal)) { // red
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, LOW);
  }
  else if (!redActive(redSensorVal) && greenActive(greenSensorVal) && !blueActive(blueSensorVal)) { // green
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, LOW);
  }
  else if (!redActive(redSensorVal) && !greenActive(greenSensorVal) && blueActive(blueSensorVal)) { // blue
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, HIGH);
  }
  else if (redActive(redSensorVal) && greenActive(greenSensorVal) && !blueActive(blueSensorVal)) { // yellow
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, LOW);
  }
  else if (redActive(redSensorVal) && !greenActive(greenSensorVal) && blueActive(blueSensorVal)) { // magenta
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, HIGH);
  }
  else if (!redActive(redSensorVal) && greenActive(greenSensorVal) && blueActive(blueSensorVal)) { // cyan
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, HIGH);
  }
  else if (redActive(redSensorVal) && greenActive(greenSensorVal) && blueActive(blueSensorVal)) { // white
    digitalWrite(REDLEDPIN, HIGH);
    digitalWrite(GREENLEDPIN, HIGH);
    digitalWrite(BLUELEDPIN, HIGH);
  }
  else {
    digitalWrite(REDLEDPIN, LOW);
    digitalWrite(GREENLEDPIN, LOW);
    digitalWrite(BLUELEDPIN, LOW);
  }
}

bool redActive(int redVal) {
  int redThreshold = 100;
  if (redVal < redThreshold)
    return true;
  return false;
}

bool greenActive(int greenVal) {
  int greenThreshold = 750;
  if (greenVal < greenThreshold)
    return true;
  return false;
}

bool blueActive(int blueVal) {
  int blueThreshold = 400;
  if (blueVal < blueThreshold)
    return true;
  return false;
}
