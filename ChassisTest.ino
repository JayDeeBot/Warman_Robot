
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
int enAWheel = 9;
int in1Wheel = 8;
int in2Wheel = 7; //Upper left motor
int enBWheel = 11;
int in3Wheel = 12;
int in4Wheel = 13; //Upper right motor
//Mechanum Wheels - Driver 2
int enA_driver2Wheel = 5;
int in1_driver2Wheel = 4;
int in2_driver2Wheel = 2; //Down left motor
int enB_driver2Wheel = 3;
int in3_driver2Wheel = 12;
// int in4_driver2Wheel = 13; //Down right motor

// scoop variables;
// int enAScoop = 13;
// int in1Scoop = 14;
// int in2Scoop = 15;
// int enBScoop = 16;
// int in3Scoop = A2;
// int in4Scoop = A3;

// int pickUpAngle = 135; // goal angle in deg for scoop when retrieving payload
// int scoopSpeedRPM = 7; // desired scoop speed in RPM - max 36 RPM at 12 V
// int scoopSpeedDigital = 255*scoopSpeedRPM/36; // map RPM to 8 bit binary value
// int scoopTime = pickUpAngle/(scoopSpeedRPM/6*1000); // time value for scoopForward function in ms


// release variables
// Servo servoMotor; // Create a Servo object
// int releaseAngle = 90; // goal angle for release gate open in degrees
// int closedAngle = 0; // goal angle for release gate closed in degrees

// lift variables;
// int enALift = 17;
// int in1Lift = 18;
// int in2Lift = 19;
// int enBLift = 20;
// int in3Lift = A4;
// int in4Lift = A5;

int zSilo1 = 350; // z-axis location of silo 1 in mm
int zSilo2 = 350; // z-axis location of silo 2 in mm
// int liftSpeed = 36; // lift speed in RPM
// int pulleyDia = 20; // Diameter of pulley in mm
// int liftTime1 = zSilo1/(liftSpeed*2*3.14/60*pulleyDia*1000); // lift time in ms
// int liftTime2 = zSilo2/(liftSpeed*2*3.14/60*pulleyDia*1000); // lift time in ms
bool warman = true;
const int buttonPin = 13;
int buttonState = 0;

void setup() {
  // run setup functions - sets entire system for main loop
  // pinMode(1, INPUT); /// Push Button pin set input
  pinMode(enAWheel, OUTPUT);
  pinMode(in1Wheel, OUTPUT);
  pinMode(in2Wheel, OUTPUT);
  // pinMode(enBWheel, OUTPUT);
  // pinMode(in3Wheel, OUTPUT);
  // pinMode(in4Wheel, OUTPUT);
 // Driver2
  pinMode(enA_driver2Wheel, OUTPUT);
  pinMode(in1_driver2Wheel, OUTPUT);
  pinMode(in2_driver2Wheel, OUTPUT);
  pinMode(enB_driver2Wheel, OUTPUT);
  pinMode(in3_driver2Wheel, OUTPUT);
  // pinMode(in4_driver2Wheel, OUTPUT); 
  // setupScoop();
  // setupLift();
  // setupRelease();
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // // put your main code here, to run repeatedly:
  // buttonState = digitalRead(1);
buttonState = digitalRead(buttonPin);
if (buttonState == HIGH) {
    // Payload 1 section - Squash Balls
  digitalWrite(in1_driver2Wheel, HIGH);
  digitalWrite(in2_driver2Wheel, LOW);
  analogWrite(enA_driver2Wheel, 170);
  digitalWrite(in2Wheel, HIGH);
  digitalWrite(in1Wheel, LOW);
  analogWrite(enAWheel, 30);
  delay(900);

  wheelsOff();
  delay(390);
  // digitalWrite(in1Wheel, LOW);
  // digitalWrite(in2Wheel, LOW);
  // analogWrite(enAWheel, 0);
  // delay(500);

  digitalWrite(in2Wheel, HIGH);
  digitalWrite(in1Wheel, LOW);
  analogWrite(enAWheel, 255);
  delay(800);
  
 // move to payload 1
  wheelsOff();
  delay(500);

    digitalWrite(in2_driver2Wheel, HIGH);
    digitalWrite(in1_driver2Wheel, LOW); 
    analogWrite(enA_driver2Wheel, 180);
    digitalWrite(in1Wheel, HIGH);
    digitalWrite(in2Wheel, LOW);
    analogWrite(enAWheel, 80);
    delay(500);

    // wheelsOff();
    // delay(3000);

    wheelsOff();
    
    delay(2000);

    

}
}



// put function definitions here:


void moveToPos(int xInit, int yInit, int xGoal, int yGoal, int speed) // define wheel movement
{
  // move wheels to set location inside the track
  // if (xInit > xGoal) {
  //   deltaX = xInit - xGoal;
  //   deltaT = (deltaX*1000*255)/(speed*36*2*3.14);
  //   left_drive(deltaT,speed);
  // }
  // else {
  //   deltax = xGoal - xInit;
  //   deltaT = (deltaX*1000*255)/(speed*36*2*3.14);
  //   right_drive(deltaT,speed);
  // }
  // if (yInit > yGoal){
  //   deltaY = yInit - yGoal;
  //   deltaT = (deltaY*1000*255)/(speed*36*2*3.14);
  //   backward_drive(deltaT,speed);
  // }
  // else {
    deltaY = yGoal - yInit;
    deltaT = (deltaY*1000*255)/(speed*36*2*3.14);
    forward_drive(deltaT,speed);
  // }
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
  digitalWrite(in1Wheel, HIGH);
  digitalWrite(in2Wheel, LOW);
  analogWrite(enAWheel, speed_driving);
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
// void right_drive(int time_driving, int speed_driving){
//   //For driver 1 - Back wheels (Look from the back)
//   digitalWrite(in1Wheel, HIGH);
//   digitalWrite(in2Wheel, LOW);
//   analogWrite(enAWheel, speed_driving); //Right Back wheel 
//   // delay(time_driving);
//   digitalWrite(in3Wheel, LOW);
//   digitalWrite(in4Wheel, HIGH);
//   analogWrite(enBWheel, speed_driving-3); //Left Back wheel
//   // delay(time_driving);
//   //  //For driver 2 - Front wheels 
//   digitalWrite(in1_driver2Wheel, LOW);
//   digitalWrite(in2_driver2Wheel, HIGH);
//   analogWrite(enA_driver2Wheel, speed_driving); //Right Front wheel
//   // delay(time_driving);
//   digitalWrite(in3_driver2Wheel, HIGH);
//   digitalWrite(in4_driver2Wheel, LOW);
//   analogWrite(enB_driver2Wheel, speed_driving-3); //Left Front wheel
//   delay(time_driving);
// }

// void left_drive(int time_driving, int speed_driving){

//    //For driver 1
//   digitalWrite(in1Wheel, HIGH);
//   digitalWrite(in2Wheel, LOW);
//   analogWrite(enAWheel, speed_driving);
//   digitalWrite(in3Wheel, LOW);
//   digitalWrite(in4Wheel, HIGH);
//   analogWrite(enBWheel, speed_driving);

//    //For driver 2
//   digitalWrite(in1_driver2Wheel, LOW);
//   digitalWrite(in2_driver2Wheel, HIGH);
//   analogWrite(enA_driver2Wheel, speed_driving);
//   digitalWrite(in3_driver2Wheel, HIGH);
//   digitalWrite(in4_driver2Wheel, LOW);
//   analogWrite(enB_driver2Wheel, speed_driving);
//   delay(time_driving);

// }

// void setupScoop() // define scoop setup
// { 
//   // setup scoop
//   // Driver1
//   pinMode(enAScoop, OUTPUT);
//   pinMode(in1Scoop, OUTPUT);
//   pinMode(in2Scoop, OUTPUT);
//   pinMode(enBScoop  ,OUTPUT);
//   pinMode(in3Scoop, OUTPUT);
//   pinMode(in4Scoop, OUTPUT);
// }

// void scoopForward(int time_driving, int speed_driving) // define payload scooping function
// {
//   // scoop payloads
//   digitalWrite(in1Scoop, LOW);
//   digitalWrite(in2Scoop, HIGH);
//   analogWrite(enAScoop, speed_driving);
//   digitalWrite(in3Scoop, LOW);
//   digitalWrite(in4Scoop, HIGH);
//   analogWrite(enBScoop, speed_driving);
//   delay(time_driving);
// }

// void scoopBackward(int time_driving, int speed_driving){
//   digitalWrite(in1Scoop, LOW);
//   digitalWrite(in2Scoop, HIGH);
//   analogWrite(enAScoop, speed_driving);
//   digitalWrite(in3Scoop, LOW);
//   digitalWrite(in4Scoop, HIGH);
//   analogWrite(enBScoop, speed_driving);
//   delay(time_driving);
// }

// void releaseSetup()   // define payload release setup
// {
//   // setup release
//   servoMotor.attach(9); // Attach the servo to pin 9
// }

// void releasePayload(int angle, int stepDelay) // define release payloads function
// {
//   // release payloads
//   int currentAngle = servoMotor.read(); // Read the current servo angle

//   // Gradually move to the desired angle
//   while (currentAngle != angle) 
//   {
//     if (currentAngle < angle) {
//       currentAngle++;
//     } else {
//       currentAngle--;
//     }
//     servoMotor.write(currentAngle);
//     delay(stepDelay);
//   }
// }
// }

// void setupLift() // define lift setup
// {
//   // setup lift
//   pinMode(enALift, OUTPUT);
//   pinMode(in1Lift, OUTPUT);
//   pinMode(in2Lift, OUTPUT);
//   pinMode(enBLift, OUTPUT);
//   pinMode(in3Lift, OUTPUT);
//   pinMode(in4Lift, OUTPUT);
// }

// void moveLift(int direction, int time, int speed) // define payload lifting function
// {
//   // lift payloads
//   if (direction) { // move upward
//   digitalWrite(in1Lift, HIGH);
//   digitalWrite(in2Lift, LOW);
//   analogWrite(enALift, speed);
//   digitalWrite(in3Lift, HIGH);
//   digitalWrite(in4Lift, LOW);
//   analogWrite(enBLift, speed);
//   delay(time);
//   }
//   else if (!direction) { // move downward
//   digitalWrite(in1Lift, LOW);
//   digitalWrite(in2Lift, HIGH);
//   analogWrite(enALift, speed);
//   digitalWrite(in3Lift, LOW);
//   digitalWrite(in4Lift, HIGH);
//   analogWrite(enBLift, speed);
//   delay(time);
//   }
// }

void wheelsOff() // turn wheels off after driving
{
     //For driver 1 
  // digitalWrite(in1Wheel, LOW);
  // digitalWrite(in2Wheel, LOW);
  // analogWrite(enAWheel, 0);
  // delay(stopT);
  // digitalWrite(in3Wheel, LOW);
  // digitalWrite(in4Wheel, LOW);
  // analogWrite(enBWheel, 0);
  // delay(stopT);

   //For driver 2
  digitalWrite(in1_driver2Wheel, HIGH);
  digitalWrite(in2_driver2Wheel, LOW);
  analogWrite(enA_driver2Wheel, 0);
  // delay(stopT);
  // digitalWrite(in3_driver2Wheel, LOW);
  // digitalWrite(in4_driver2Wheel, LOW);
  // analogWrite(enB_driver2Wheel, 0);


}

// void scoopOff() //turn scoop off
// {
//     // scoop payloads
//   digitalWrite(in1Scoop, LOW);
//   digitalWrite(in2Scoop, LOW);
//   analogWrite(enAScoop, 0);
//   digitalWrite(in3Scoop, LOW);
//   digitalWrite(in4Scoop, LOW);
//   analogWrite(enBScoop, 0);
//     //for driver 2
//   digitalWrite(in2_driver2Scoop, LOW);
//   digitalWrite(in1_driver2Scoop, LOW);
//   analogWrite(enA_driver2Scoop, 0);
//   digitalWrite(in4_driver2Scoop, LOW);
//   digitalWrite(in3_driver2Scoop, LOW);
//   analogWrite(enB_driver2Scoop, 0);
// }

// void liftOff() // turn lift off
// {
//     digitalWrite(in1Lift, LOW);
//   digitalWrite(in2Lift, LOW);
//   analogWrite(enALift, 0);
//   digitalWrite(in3Lift, LOW);
//   digitalWrite(in4Lift, LOW);
//   analogWrite(enBLift, 0);
// }
