#include <SoftwareSerial.h>
SoftwareSerial s(6,5);
int data;
int led = 8;
void setup() {
s.begin(9600);
Serial.begin(9600);
pinMode(led,OUTPUT);
}
 
void loop() {
  s.write("o");
  if (s.available()>0)
  {
    data=s.read();
    Serial.println(data);
    if(data == 200){

      digitalWrite(led,HIGH);
    }else{
      digitalWrite(led,LOW);
    }
  }
 delay(100);
 
}
