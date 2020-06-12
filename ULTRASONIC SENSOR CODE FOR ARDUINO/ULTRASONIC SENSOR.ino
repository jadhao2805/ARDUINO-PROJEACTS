#include <SoftwareSerial.h>
SoftwareSerial s(5,6);
const int pingPin = 9;
const int trigPin  = 8;
void setup() {
s.begin(9600);
  pinMode(pingPin, INPUT); //Set the connection pin output mode Echo pin
  pinMode(trigPin, OUTPUT);
Serial.begin(9600);
}
 
void loop() {

 int cm = ping(pingPin) ;
 Serial.println(cm);
if(s.available()>0)
{
 s.write(cm);
}
 delay(500);
}





long microsecondsToCentimeters(long microseconds) 
{ 

   return microseconds / 29 / 2; 
} 

int ping(int pingPin) 
{ 
  
   long duration, cm; 
  
   pinMode(trigPin, OUTPUT); 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); 
   digitalWrite(trigPin, HIGH); 
   delayMicroseconds(5); 
   digitalWrite(trigPin, LOW); 

   pinMode(pingPin, INPUT); 
   duration = pulseIn(pingPin, HIGH); 

   // convert the time into a distance 
   cm = microsecondsToCentimeters(duration); 
   return cm ; 
} 
