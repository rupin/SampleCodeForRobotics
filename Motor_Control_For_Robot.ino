#include <MotorDriver.h>

//Create an instance of the motor Driver library
MotorDriver m;

//Create Variables to hold state of the switches
int switch1State;
int switch2State;


void setup()
{
  //We use the servo connections ( top left corner on motor shield as our switch inputs)
  // The Servo1 S pin is pin 10
  //The Servo2 S pin is connected to Arduino Pin 10
  //Because the switch acts as an input device, we connect the center terminals of the DPDT switch to S pins on the servo connector.
  pinMode(9, INPUT);// Designate Pin number 9 as an input
  pinMode(10, INPUT);// Designate Pin number 10 as an input.
  Serial.begin(115200);// We can see the status of the pins using a Serial Connection
}


void loop()
{
  switch1State=digitalRead(9);
  switch2State=digitalRead(10);

  //Print the Status of the Switches on the Serial Terminal
  Serial.print("Switch 1 Reports");
  Serial.println(switch1State);

  Serial.print("Switch 2 Reports");
  Serial.println(switch2State);

  // Both Switch 1 *and* Switch 2 have been connected to 5V pin. 
  // Put the Motor in FWD direction
  if(switch1State && switch2State)
  {
     m.motor(1,FORWARD,255);
  }
  
  // Both Switch 1 *and* Switch 2 have been connected to GND pin. 
  //Notice the Exclamation marks which allow inversion of logic. 
  //Put the Motor in BACKWARD/Reverse direction
  if(!switch1State && !switch2State)
  {
     m.motor(1,BACKWARD,255);
  }
  
   

}
