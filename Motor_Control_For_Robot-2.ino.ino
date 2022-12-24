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
  pinMode(9, INPUT_PULLUP);// Designate Pin number 9 as an input.The arduino provides the resistor between 5v and the pin internally
  pinMode(10, INPUT_PULLUP);// Designate Pin number 10 as an input. The arduino provides the resistor between 5v and the pin internally
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
  // Put the Motor in FWD direction if switch 1 is pressed
  if(switch1State)
  {
     m.motor(1,FORWARD,255);
  }
  
  
  //Put the Motor in BACKWARD/Reverse direction if switch 2 is pressed
  else if(switch2State)
  {
     m.motor(1,BACKWARD,255);
  }
  else
  {
    //By default, just turn off the motor. 
    m.motor(1,FORWARD,0);
  }
  
   

}
