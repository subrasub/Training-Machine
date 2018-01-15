int motorPin = 3; // declares location of the first motor
int motorPin2 = 11; // declares location of the second motor

void setup() 
{ 
  pinMode(motorPin, OUTPUT); // sets mode of pin 3 to output
  pinMode(motorPin2, OUTPUT); // sets mode of pin 11 to output
  Serial.begin(9600); // opens serial port sets data rate to 9600 baud
  while (! Serial); // wait for serial port to connect
  Serial.println("Speed 40 to 150"); 
} 
 
 
void loop() 
{ 
  if (Serial.available())
  {
    int speed = Serial.parseInt(); // returns valid integer number
    print("1. Short Range \n");
    print("2. Medium Range \n");
    print("3. Long Range \n");
    print("4. Exit Program \n");

    
    switch(speed)
    {
      
      
      case 1:
      {
        Serial.print("Input speed [40-110] for short range: ");
        if (speed >= 40 && speed <= 110) // error checking, making sure the speed is within the lab bounds
        {
          analogWrite(motorPin, speed); //writes analog value to the pins
          analogWrite(motorPin2, speed);
        }
        else
          print("Speed inputted not within range! \n");
      }
      case 2:
      {
        Serial.print("Input speed [110-150] for medium range: "); //100-150
        if (speed > 110 && speed <= 150) // error checking, making sure the speed is within the lab bounds
        {
          analogWrite(motorPin, speed); //writes analog value to the pins
          analogWrite(motorPin2, speed);
        }
        else
          print("Speed inputted not within range! \n");
      }

      case 3:
      {
        Serial.print("Input speed [>150] for long range: ");
        if (speed >= 150) // error checking, making sure the speed is within the lab bounds
        {
          analogWrite(motorPin, speed); //writes analog value to the pins
          analogWrite(motorPin2, speed);
        }
        else
          print("Speed inputted not within range! \n");
      }

      case 4:
      {
        speed = 0;
        analogWrite(motorPin, speed); //writes analog value to the pins
        analogWrite(motorPin2, speed);
        
        Serial.print("Stopping the motors \n"};
      }
    }      
} 

