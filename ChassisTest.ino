
// function declarationsvoid setupWheels(); // declare function for mechanum wheels setup
void moveToPos(); // declare function to move wheels to a set pos in coordinate frame
void forward_drive(); // declare function for forward drive
void backward_drive(); // declare function for backward drive
void right_drive(); // declare function for right drive
void left_drive(); // declare function for left drive
// void setupScoop(); // declare function for scoop setup
// void scoopForward(); // declare function to scoop forwards
// void scoopBackward(); // declare function to scoop backwards
// void releaseSetup(); // declare function for payload release
// void releasePayload(); // declare function to release payloads
// void setupLift(); // declare function for lift setup
// void liftPayloads(); // declare function to lift payloads
void wheelsOff();
void scoop_drive(); // function for scoop 

// global variable declarations:

// declare variables for switch starting action


// payloads locations;
// payload 1
int deltaY;
int deltaT;
int xPayload1 = 0; // x-axis location of payload 1
int yPayload1 = 0; // y-axis location of payload 1
// payload 2
int xPayload2 = 0; // x-axis location of payload 2
int yPayload2 = 0; // y-axis location of payload 2

// silo locations;
// silo 1
int xSilo1 = 0; // x-axis location of silo 1
int ySilo1 = 0; // y-axis location of silo 1
//silo 2
int xSilo2 = 0; // x-axis location of silo 2
int ySilo2 = 0; // y-axis location of silo 2

// declare mechanum wheel variables
int wheelSpeedDigital = 255;

//Mechanum Wheels - Driver 1
int enAScoop = 9;
int in1Scoop = 8;
int in2Scoop = 7; // for the scoop 

int enBLift = 11;
int in3Lift = 12;
int in4Lift = 13; //Upper right motor
//Mechanum Wheels - Driver 2
int enA_driver2Wheel = 5;
int in1_driver2Wheel = 4;
int in2_driver2Wheel = 2; //Down left motor



void setup() {
  // run setup functions - sets entire system for main loop
  // pinMode(1, INPUT); /// Push Button pin set input
  pinMode(enAScoop, OUTPUT);
  pinMode(in1Scoop, OUTPUT);
  pinMode(in2Scoop, OUTPUT);

  pinMode(enBLift, OUTPUT);
  pinMode(in3Lift, OUTPUT);
  pinMode(in4Lift, OUTPUT);
 // Driver2
  pinMode(enA_driver2Wheel, OUTPUT);
  pinMode(in1_driver2Wheel, OUTPUT);
  pinMode(in2_driver2Wheel, OUTPUT);
  // pinMode(enB_driver2Wheel, OUTPUT);
  // pinMode(in3_driver2Wheel, OUTPUT);
  // pinMode(in4_driver2Wheel, OUTPUT); 
  // setupScoop();
  // setupLift();
  // setupRelease();
  // pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // // put your main code here, to run repeatedly:
  // buttonState = digitalRead(1);
// buttonState = digitalRead(buttonPin);

    // Payload 1 section - Squash Balls
  digitalWrite(in1_driver2Wheel, HIGH);
  digitalWrite(in2_driver2Wheel, LOW);
  analogWrite(enA_driver2Wheel, 170);
  digitalWrite(in2Scoop, HIGH);
  digitalWrite(in1Scoop, LOW);
  analogWrite(enAScoop, 0);
  delay(500);

  wheelsOff();
  delay(390);
  // digitalWrite(in1Wheel, LOW);
  // digitalWrite(in2Wheel, LOW);
  // analogWrite(enAWheel, 0);
  // delay(500);

  digitalWrite(in2Scoop, HIGH);
  digitalWrite(in1Scoop, LOW);
  analogWrite(enAScoop, 255);
  delay(1200);
  digitalWrite(in2Scoop, HIGH);
  digitalWrite(in1Scoop, LOW);
  analogWrite(enAScoop, 0);
  delay(500);
  digitalWrite(in1Scoop, HIGH);
  digitalWrite(in2Scoop, LOW);
  analogWrite(enAScoop, 60);
  delay(2900);
  digitalWrite(in2Scoop, HIGH);
  digitalWrite(in1Scoop, LOW);
  analogWrite(enAScoop, 0);
  delay(500);
 // move to payload 1
  wheelsOff();
  delay(1200);


  digitalWrite(in2_driver2Wheel, HIGH);
  digitalWrite(in1_driver2Wheel, LOW); 
  analogWrite(enA_driver2Wheel, 200);
  delay(200);

    // wheelsOff();
    // delay(3000);

  wheelsOff(); 
  delay(2000);

  digitalWrite(in3Lift, HIGH);
  digitalWrite(in4Lift, LOW);
  analogWrite(enBLift, 255);
  digitalWrite(in2Scoop, HIGH);
  digitalWrite(in1Scoop, LOW);
  analogWrite(enAScoop, 0);
  wheelsOff(); 
  delay(20000);

  digitalWrite(in3Lift, HIGH);
  digitalWrite(in4Lift, LOW);
  analogWrite(enBLift, 0);
  delay(2000);


  digitalWrite(in4Lift, HIGH);
  digitalWrite(in3Lift, LOW);
  analogWrite(enBLift, 255);
  digitalWrite(in2Scoop, HIGH);
  digitalWrite(in1Scoop, LOW);
  analogWrite(enAScoop, 0);
  wheelsOff(); 
  delay(12000);

  digitalWrite(in4Lift, HIGH);
  digitalWrite(in3Lift, LOW);
  analogWrite(enBLift, 0);
  digitalWrite(in2Scoop, HIGH);
  digitalWrite(in1Scoop, LOW);
  analogWrite(enAScoop, 0);
  wheelsOff(); 
  delay(4000);

}



void forward_drive(int time_driving, int speed_driving){
  // //for driver 1
  // digitalWrite(in1Wheel, HIGH);
  // digitalWrite(in2Wheel, LOW);
  // analogWrite(enAWheel, speed_driving);
  // delay(time_driving);
  // digitalWrite(in3Wheel, HIGH);
  // digitalWrite(in4Wheel, LOW);
  // analogWrite(enBWheel, speed_driving);
  // delay(time_driving);
  //for driver 2
  digitalWrite(in1_driver2Wheel, HIGH);
  digitalWrite(in2_driver2Wheel, LOW);
  analogWrite(enA_driver2Wheel, speed_driving);
  delay(time_driving);
  // digitalWrite(in3_driver2Wheel, HIGH);
  // digitalWrite(in4_driver2Wheel, LOW);
  // analogWrite(enB_driver2Wheel, speed_driving);
  //delay a little bit
  delay(time_driving);
}
void scoop_drive(int time_driving, int speed_driving){
  // //for driver 1
  digitalWrite(in1Scoop, HIGH);
  digitalWrite(in2Scoop, LOW);
  analogWrite(enAScoop, speed_driving);
  delay(time_driving);
  // digitalWrite(in3Wheel, HIGH);
  // digitalWrite(in4Wheel, LOW);
  // analogWrite(enBWheel, speed_driving);
  // delay(time_driving);
  //for driver 2
  // digitalWrite(in1_driver2Wheel, HIGH);
  // digitalWrite(in2_driver2Wheel, LOW);
  // analogWrite(enA_driver2Wheel, speed_driving);
  // delay(time_driving);
  // digitalWrite(in3_driver2Wheel, HIGH);
  // digitalWrite(in4_driver2Wheel, LOW);
  // analogWrite(enB_driver2Wheel, speed_driving);
  // //delay a little bit
  // delay(time_driving);
}
void backward_drive(int time_driving, int speed_driving)
{
  // digitalWrite(in2Wheel, HIGH);
  // digitalWrite(in1Wheel, LOW);
  // analogWrite(enAWheel, speed_driving);
  // delay(time_driving);
  // digitalWrite(in4Wheel, HIGH);
  // digitalWrite(in3Wheel, LOW);
  // analogWrite(enBWheel, speed_driving);
  // delay(time_driving);
//for driver 2
  digitalWrite(in2_driver2Wheel, HIGH);
  digitalWrite(in1_driver2Wheel, LOW); 
  // analogWrite(enA_driver2Wheel, speed_driving);

  // digitalWrite(in4_driver2Wheel, HIGH);
  // digitalWrite(in3_driver2Wheel, LOW);
  // // analogWrite(enB_driver2Wheel, speed_driving);
  // delay(time_driving);
}


void wheelsOff() // turn wheels off after driving
{


   //For driver 2
  digitalWrite(in1_driver2Wheel, HIGH);
  digitalWrite(in2_driver2Wheel, LOW);
  analogWrite(enA_driver2Wheel, 0);
  // delay(stopT);
  // digitalWrite(in3_driver2Wheel, LOW);
  // digitalWrite(in4_driver2Wheel, LOW);
  // analogWrite(enB_driver2Wheel, 0);


}

