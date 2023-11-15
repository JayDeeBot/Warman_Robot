

void wheelsOff();


int wheelSpeedDigital = 255;
//DRIVER 1 - ENA CONTROL THE SCOOP
int enAWheel = 9;
int in1Wheel = 8;
int in2Wheel = 7; 

int enBWheel = 11;
int in3Wheel = 12;
int in4Wheel = 13; 
//DRIVER 2 -  ENA CONTROL 4 WHEELS
int enA_driver2Wheel = 5;
int in1_driver2Wheel = 4;
int in2_driver2Wheel = 2; 

int enB_driver2Wheel = 3;
int in3_driver2Wheel = 12;
// int in4_driver2Wheel = 13; 


void setup() {

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

}

void loop() {


    // Payload 1 section - Squash Balls
  digitalWrite(in1_driver2Wheel, HIGH);
  digitalWrite(in2_driver2Wheel, LOW);
  analogWrite(enA_driver2Wheel, 170);
  digitalWrite(in2Wheel, HIGH); //This is for the scoop, turn off while the chassis is moving
  digitalWrite(in1Wheel, LOW);
  analogWrite(enAWheel, 30); 
  delay(900);    //Driving time 

  wheelsOff();  //Stop the chassis 
  delay(390);


  digitalWrite(in2Wheel, HIGH); //Turn the scoop 
  digitalWrite(in1Wheel, LOW);
  analogWrite(enAWheel, 255);
  delay(800);
  
 
  wheelsOff();                //Stop the chassis a lil bit
  delay(500);

    digitalWrite(in2_driver2Wheel, HIGH); //Move back a bit and turn the scoop down
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

