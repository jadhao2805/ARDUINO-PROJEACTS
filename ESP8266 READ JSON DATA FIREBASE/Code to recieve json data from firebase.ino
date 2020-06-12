
#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
// Set these to run example.
#define FIREBASE_HOST "https://botlocation-88e65.firebaseio.com/"
#define FIREBASE_AUTH "2ll4TLrulTrTrTOm81aKdFCsI4W1P94BcFbrZMdz"
#define WIFI_SSID "iPhone"
#define WIFI_PASSWORD "98228748"
FirebaseData firebaseData;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

}

void loop() {
  // put your main code here, to run repeatedly:

Serial.println("Serial.Available");
DynamicJsonBuffer jsonBuffer;
JsonObject& root=jsonBuffer.parseObject(Serial);
root.printTo(Serial);



}
