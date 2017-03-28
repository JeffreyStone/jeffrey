#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // twelve servo objects can be created on most boards
int positions[] = {0,35,75,90,125};
const int buttonPin = 2; //the pin number of the pushbutton input pin
int buttonState = 0;
int buttonPressCount = 0;
int numberOfPositions = 5;


void setup() {
  // initialize the Servo pin as output:
  myservo.attach(9);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  
}
void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  Serial.print(buttonState);
  Serial.print(buttonPressCount);

  if (buttonState == 1 && buttonPressCount <= 4) {
    buttonPressCount++;
    myservo.write(positions [buttonPressCount]);
    delay(400);
  }
  else if (buttonState == 1 && buttonPressCount > 4) {
    buttonPressCount = 0;
    myservo.write(positions [buttonPressCount]);
    delay(400);
  }
  else if (buttonState == 0) {
    myservo.write(positions [buttonPressCount]);
  }

  
//  //check if button is pressed.
//  //it it is, the buttonState is HIGH): 
//    for (int i = 0; i<numberOfPositions; i++) {
//      if (buttonPressCount % numberOfPositions ==i) {
//        // change position/angel of servo:
//        myservo.write(positions [i]);
//    } else {
//    // don't move servo:
//   
//    }
//  }
// 
//  delay(400);
}
