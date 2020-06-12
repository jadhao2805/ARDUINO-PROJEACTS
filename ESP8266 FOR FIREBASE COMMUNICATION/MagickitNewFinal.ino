#include <ArduinoJson.h>
 
 
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
 
// Set these to run example.
#define FIREBASE_HOST "https://magickit-7cc8c.firebaseio.com/"
#define FIREBASE_AUTH "226g8PxxsCIzUqgqRkFLKOi4eAwT8GdRtGZfh8mr"
#define WIFI_SSID "iPhone"
#define WIFI_PASSWORD "7264952105"
FirebaseData firebaseData;
int flag;
void streamCallback(StreamData data)
{
 
Serial.println(data.stringData());
String dataString = data.stringData();

//Firebase.getJSON(firebaseData,"/lab1");
//DynamicJsonBuffer jsonBuffer;
//JsonObject& root=jsonBuffer.parseObject(firebaseData.jsonString());
if( dataString.substring(0) == "1"){
  Serial.println("HIGH");
  flag = 1;
  digitalWrite(LED_BUILTIN,HIGH);
}else if(dataString.substring(0) == "0"){
  Serial.println("LOW");
  flag = 0;
  digitalWrite(LED_BUILTIN,LOW);
}
 
 
}
 
//Global function that notifies when stream connection lost
//The library will resume the stream connection automatically
void streamTimeoutCallback(bool timeout)
{
  if(timeout){
    //Stream timeout occurred
    Serial.println("Stream timeout, resume streaming...");
  }  
}
 
 
 
 
 
 
void setup() {
  Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);     // Initialize the LED_BUILTIN pin as an output

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
 
  Firebase.setStreamCallback(firebaseData, streamCallback, streamTimeoutCallback);
 

 
 if (!Firebase.beginStream(firebaseData, "lab1"))
 {
  //Could not begin stream connection, then print out the error detail
  Serial.println(firebaseData.errorReason());
  
 }
 
 
 
 
 // Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}
 
int n = 0;
 
void loop() {

// if(flag == 1){
//  digitalWrite(LED_BUILTIN,HIGH);
//  Serial.println("yoo");
// }else if (flag == 0){
//  digitalWrite(LED_BUILTIN,LOW);
//  Serial.println("booo");
// }
delay(100);
 
}
