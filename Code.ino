int relay = 4 ;// define relay pin
int flamedigital = 9; // define the flame sensor digital pin
int flameanalog = A3; // define the flame sensor analog pin
int buzzer = 5; //define buzzer pin
int val ; // define numeric variable val
float sensor; //define floating variable sensor
int pirPin = A0;                            //MOTION SENSOR INPUT PIN.
int sensorValue = LOW;
int ledPin = 13;            
void setup ()
{
  pinMode (flamedigital, INPUT) ;// input interface defines the flame sensor
  pinMode (flameanalog, INPUT) ;// input interface defines the flame sensor
  pinMode (relay, OUTPUT); //output interface defines the relay
  pinMode (buzzer, OUTPUT); //output interface defines the buzzer
  pinMode(buzzer, OUTPUT);               //SET BUZZER AS OUTPUT.
  pinMode(ledPin, OUTPUT);                  //SET LED AS OUTPUT.
  pinMode(pirPin, INPUT);    
  Serial.begin(9600);
  pinMode(buzzer,OUTPUT);

}

void loop ()
{
  int sensorReading= analogRead(A5); //reads the sensor value

Serial.println (sensorReading); //prints out the sensor reading

if (sensorReading < 1000){//if reading is above 800, LED blinks on and off
tone (buzzer,1200); //turns the LED on
delay(1000); //waits for a second
}
else {
noTone (buzzer); //turns the LED off
delay(1000); //waits for a second
}
  Serial.begin(9600);
pinMode(buzzer,OUTPUT);

  sensorValue = digitalRead(pirPin);        //READ PIR INPUT PIN.
  if ( sensorValue == HIGH) {               //IF MOTION IS DETECTED.
    tone(buzzer, 1200);                  //BUZZ THE BUZZER. 
    digitalWrite(ledPin, HIGH);             //ON LED.
    delay(100);                             //TIME DIFFERENCE BETWEEN HIGH(ON)& LOW(OFF).
    noTone(buzzer);                      //SILENT BUZZER.
    digitalWrite(ledPin, LOW);              //OFF LED.
    delay(100);                             //TIME DIFFERENCE BETWEEN HIGH(ON)& LOW(OFF).
  }
  else {                                    //IF NO MOTION IS DETECTED.
    noTone(buzzer);                      //SILENT THE BUZZER.
    digitalWrite(ledPin, LOW);              //OFF LED.
  }

  
  sensor = analogRead(flameanalog); //read flameanalog value and assigne it to sensor variable


  val = digitalRead (flamedigital) ;// read flamedigital value and assigne it to val variable
  if (val == HIGH) // When the flame sensor detects a signal relay is on and buzzer sound (void alarm)
  {
    alarm();
    digitalWrite (relay, HIGH); //close the relay circuit

  }
  else
  {
    digitalWrite (relay, LOW); //open the relay circuit
  }
  delay(1000);
  
}

 

void alarm()  {
  tone(buzzer, 400, 500); //the buzzer emit sound at 400 MHz for 500 millis
  delay(500); //wait 500 millis
  tone(buzzer, 650, 500); //the buzzer emit sound at 650 MHz for 500 millis
  delay(500); //wait 500 millis
   sensorValue = digitalRead(pirPin);        //READ PIR INPUT PIN.
  if ( sensorValue == HIGH) {               //IF MOTION IS DETECTED.
    tone(buzzer, 1200);                  //BUZZ THE BUZZER. 
    digitalWrite(ledPin, HIGH);             //ON LED.
    delay(100);                             //TIME DIFFERENCE BETWEEN HIGH(ON)& LOW(OFF).
    noTone(buzzer);                      //SILENT BUZZER.
    digitalWrite(ledPin, LOW);              //OFF LED.
    delay(100);                             //TIME DIFFERENCE BETWEEN HIGH(ON)& LOW(OFF).
  }
  
  else {                                    //IF NO MOTION IS DETECTED.
    noTone(buzzer);                      //SILENT THE BUZZER.
    digitalWrite(ledPin, LOW);              //OFF LED.
  }
  
}
