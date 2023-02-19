/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLFGBOoM9P"
#define BLYNK_TEMPLATE_NAME "SLV Beach Cleaner"
#define BLYNK_AUTH_TOKEN "3B88Zelmjn1-UvS6j9r6SicaEyLpIpO6"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial


#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = BLYNK_AUTH_TOKEN;


// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Suhaspai";
char pass[] = "shivam@123";



// This function is called every time the device is connected to the Blynk.Cloud
BLYNK_CONNECTED()
{
}


void setup()
{
  // Debug console
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); 
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 100), 8080);
  pinMode(27,OUTPUT);
  pinMode(14,OUTPUT);
}
BLYNK_WRITE(V0) {
  int motorLeft = param.asInt();
  if(motorLeft == 1){
   digitalWrite(27,LOW);
  }else{
   digitalWrite(27,HIGH);
  }
}
BLYNK_WRITE(V1) {
  int motorRight = param.asInt();
  if(motorRight == 1){
   digitalWrite(14,LOW);
  }else{
   digitalWrite(14,HIGH);
  }
}
void loop()
{
  Blynk.run();
} 
