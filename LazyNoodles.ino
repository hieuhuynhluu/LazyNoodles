


#include <Servo.h>

Servo myshoulder;
Servo myelbow;
Servo mywrist;
Servo mychopsticks;
int pos;
int shoulderGetPos, elbowGetPos, wristGetPos, chopsticksGetPos; // positions when getting the noodles
int shoulderFeedPos, elbowFeedPos, wristFeedPos, chopsticksFeedPos; // positions when feeding user
int feedingDelay; // amount of time holding up the noodles before going back down
int buttonPin = 2;
int buttonState = 0;
int buttonPressed = 0;


void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT);
  
  shoulderGetPos = 150;
  elbowGetPos = 50;
  wristGetPos = 20;
  chopsticksGetPos = 60;

  shoulderFeedPos = 120;
  elbowFeedPos = 30;
  wristFeedPos = 70;
  chopsticksFeedPos = 20;
  
  myshoulder.attach(3);
  myelbow.attach(5);
  mywrist.attach(6);
  mychopsticks.attach(9);
  
  // Robot initial position
  
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);
  if (buttonPressed == 0){
    Serial.println("button off");
    myshoulder.write(120);             
    myelbow.write(30);               
    mywrist.write(70);
    mychopsticks.write(chopsticksGetPos); 
  } else if (buttonPressed == 1) {
    Serial.println("button on");   
    mywrist.write(wristGetPos);
    delay(1000);
    mychopsticks.write(chopsticksGetPos);
    delay(1000);          
    myelbow.write(elbowGetPos); 
    delay(1000);             
    myshoulder.write(shoulderGetPos);
    delay(1000);
    mychopsticks.write(chopsticksFeedPos);
    delay(1000);

    
    myshoulder.write(shoulderFeedPos);   
    delay(1000);          
    myelbow.write(elbowFeedPos);  
    delay(1000);             
    mywrist.write(wristFeedPos);
    delay(1000); 
  }
  
  if (buttonState == HIGH && buttonPressed == 0) {
    buttonPressed = 1;
    delay(500);
  } else if (buttonState == HIGH && buttonPressed == 1) {
    buttonPressed = 0;
    delay(500);
  }
}
