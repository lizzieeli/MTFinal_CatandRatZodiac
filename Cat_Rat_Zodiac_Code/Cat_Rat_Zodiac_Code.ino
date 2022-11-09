#include <Servo.h>

Servo arrow;

const int ledOnePin = 11;
const int ledTwoPin = 10;
const int ledThreePin = 9;

const int buttonOnePin = 2;
int buttonOneState = 0;
int lastButtonOneState = 0;

const int buttonTwoPin = 3;

bool stageTwo = false;
bool stageThree = false;

void setup() {
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

//interaction one
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
  {
    digitalWrite(ledOnePin, LOW);
    digitalWrite(ledTwoPin, HIGH);
  }
}

//interaction two

}
