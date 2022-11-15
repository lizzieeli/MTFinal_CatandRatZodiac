#include <Servo.h>

Servo arrow;
Servo bush;  
Servo push;
Servo wheel;

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
  arrow.attach(3);
  bush.attach(12);
  bush.write(180);
  push.attach(9);
  wheel.attach(11);
  wheel.write(0);

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
    //Serial.println("Race hasn't started");
    buttonOneState = digitalRead(buttonOnePin);

    if (buttonOneState != lastButtonOneState) {
      if (buttonOneState == HIGH) {
        stageTwo = true;
        Serial.println("Race started!");
      }
    }
  }

  if (stageTwo == true) {
    //button one activates led one to turn off
    //Serial.println("Race started!");
  }

  //interaction two - button two will trigger arrow
  if (digitalRead(buttonTwoPin) == HIGH) {
    arrow.write(140); //arrow falls down
    
  } else {
    arrow.write(0);
  }

  //interaction three - button three reveals rat's intents
  if (bushStay == false) {
    buttonThreeState = digitalRead(buttonThreePin);

    if (buttonThreeState != lastButtonThreeState) {
      if (buttonThreeState == HIGH) {
        bushStay = true;
      }
    }
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
        Serial.println("buttonfour is fine");
        stageThree = true;
      }
    }
  }
  if (stageThree == true) {
    push.write(180);
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
  }
  if (finale == true) {
    wheel.write(180);
    //Serial.println("Buttonisdown");
  } else {
    wheel.write(0);
    //Serial.println("buttonisup");
  }

}
