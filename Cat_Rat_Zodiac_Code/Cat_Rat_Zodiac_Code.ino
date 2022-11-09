#include <Servo.h>

Servo arrow;
Servo bush;
Servo push;
Servo wheel;

const int ledOnePin = 11;
const int ledTwoPin = 10;
const int ledThreePin = 9;

const int buttonOnePin = 2;
int buttonOneState = 0;
int lastButtonOneState = 0;

const int buttonTwoPin = 3;

const int buttonThreePin = 1;

const int buttonFourPin = 8;
int buttonFourState = 0;
int lastButtonFourState = 0;

const int buttonFivePin = 12;

bool stageTwo = false;
bool stageThree = false;

void setup() {
arrow.attach(4);
bush.attach(5);
push.attach(6);
wheel.attach(7);

pinMode(ledOnePin, OUTPUT);
pinMode(ledTwoPin, OUTPUT);
pinMode(ledThreePin, OUTPUT);

pinMode(buttonOnePin, INPUT);
pinMode(buttonTwoPin, INPUT);
pinMode(buttonThreePin, INPUT);
pinMode(buttonFourPin, INPUT);
pinMode(buttonFivePin, INPUT);

Serial.begin(9600);
}

void loop() {

//interaction one - button one starts to phase two
if (!stageTwo) {
  //led one is on by default
  digitalWrite(ledOnePin, HIGH);
  buttonOneState = digitalRead(buttonOnePin);

  if(buttonOneState != lastButtonOneState) {
    if (buttonOneState == HIGH) {
      stageTwo = true;
    }
  }
} if (stageTwo == true) {
  //button one activates led one to turn off
    digitalWrite(ledOnePin, LOW);
    digitalWrite(ledTwoPin, HIGH);
}

//interaction two - button two will trigger arrow
if (digitalRead(buttonTwoPin) == HIGH) {
  arrow.write(90); //arrow falls down
  } else {
  arrow.write(0);
  }

//interaction three - button three reveals rat's intents
if (digitalRead(buttonThreePin) == HIGH) {
  bush.write(180); //bush opens up
  } else {
  bush.write(0);
  }

//interaction four - button activates cat to be pushed
if (!stageThree) {
  buttonFourState = digitalRead(buttonFourPin);

  if(buttonFourState != lastButtonFourState) {
    if (buttonFourState == HIGH) {
      stageThree = true;
    }
  }
}
if (stageThree == true) {
  digitalWrite(ledTwoPin, LOW);
  digitalWrite(ledThreePin, HIGH);
  push.write(180);
}

//interaction five - rat finishing triggers wheel to be complete
if (digitalRead(buttonFivePin) == HIGH) {
  wheel.write(180);
} else {
  wheel.write(0);
}
}
