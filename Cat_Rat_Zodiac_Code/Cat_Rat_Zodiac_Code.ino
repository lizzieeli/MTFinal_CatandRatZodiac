#include <Servo.h>

Servo sign;
Servo bush;  
Servo push;
Servo wheel;

const int ledOne = 1;
const int ledTwo = 4;
const int ledThree = 8;

const int buttonOnePin = 13;
int buttonOneState = 0;
int lastButtonOneState = 0;

const int buttonTwoPin = 10;

const int buttonThreePin = 7;
int buttonThreeState = 0;
int lastButtonThreeState = 0;

const int buttonFourPin = 2;
int buttonFourState = 0;
int lastButtonFourState = 0;

const int buttonFivePin = 5;
int buttonFiveState = 0;
int lastButtonFiveState = 0;

bool bushStay = false;
bool stageTwo = false;
bool stageThree = false;
bool finale = false;

void setup() {
  sign.attach(3);
  sign.write(40);
  bush.attach(12);
  bush.write(180);
  push.attach(9);
  wheel.attach(11);
  wheel.write(0);

  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  pinMode(ledThree, OUTPUT);
  pinMode(buttonOnePin, INPUT);
  pinMode(buttonTwoPin, INPUT);
  pinMode(buttonThreePin, INPUT);
  pinMode(buttonFourPin, INPUT);
  pinMode(buttonFivePin, INPUT);

  Serial.begin(9600);
}

void loop() {

  //interaction one - button one starts to phase two
  if (stageTwo == false) {
    buttonOneState = digitalRead(buttonOnePin);
    digitalWrite(ledOne, HIGH);

    if (buttonOneState != lastButtonOneState) {
      if (buttonOneState == HIGH) {
        stageTwo = true;
        Serial.println("Race started!");
      }
    }
    lastButtonOneState = buttonOneState;
  }

  if (stageTwo == true) {
    //button one activates led one to turn off
    digitalWrite(ledTwo, HIGH);
  }

  //interaction two - button two will trigger caution sign
  if (digitalRead(buttonTwoPin) == HIGH) {
    sign.write(120); //sign points up
    
  } else {
    sign.write(40);
  }

  //interaction three - button three reveals rat's intents
  if (bushStay == false) {
    buttonThreeState = digitalRead(buttonThreePin);

    if (buttonThreeState != lastButtonThreeState) {
      if (buttonThreeState == HIGH) {
        bushStay = true;
      }
    }
   lastButtonThreeState = buttonThreeState;
  }
  if (bushStay == true) {
    bush.write(0); //bush opens up
  } else {
    bush.write(180);
  }

  //interaction four - button activates cat to be pushed
  if (stageThree == false) {
    buttonFourState = digitalRead(buttonFourPin);

    if (buttonFourState != lastButtonFourState) {
      if (buttonFourState == HIGH) {
        //Serial.println("buttonfour is fine");
        stageThree = true;
      }
    }
   lastButtonFourState = buttonFourState;
  }
  if (stageThree == true) {
    push.write(180);
    digitalWrite(ledThree, HIGH);
  }
  else {
    push.write(0);
  }

 
  //interaction five - rat finishing triggers wheel to be complete
  if (finale == false) {
    buttonFiveState = digitalRead(buttonFivePin);
    Serial.println(buttonFiveState);

    if (buttonFiveState != lastButtonFiveState) {
      if (buttonFiveState == HIGH) {
        finale = true;
        Serial.write("finale button pressed");
      }
    }
   lastButtonFiveState = buttonFiveState;
  }
  if (finale == true) {
    wheel.write(155);
  } else {
    wheel.write(0);
  }

}
