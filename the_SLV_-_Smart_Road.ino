/*************************************************************

  This is a simple demo of sending and receiving some data.
  Be sure to check out other examples!
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPLk8QzyZnb"
#define BLYNK_DEVICE_NAME "The SLV Smart Road"
#define BLYNK_AUTH_TOKEN "V7x28SbjavwU0O9dz32aNMgguwi9XHNw"


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
  // Change Web Link Button message to "Congratulations!"
  Blynk.setProperty(V3, "offImageUrl", "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations.png");
  Blynk.setProperty(V3, "onImageUrl",  "https://static-image.nyc3.cdn.digitaloceanspaces.com/general/fte/congratulations_pressed.png");
  Blynk.setProperty(V3, "url", "https://docs.blynk.io/en/getting-started/what-do-i-need-to-blynk/how-quickstart-device-was-made");
}

#include <SPI.h>
#include <RFID.h>

#define SDA_DIO 5

#define RESET_DIO 22

RFID RC522(SDA_DIO, RESET_DIO);



void setup()
{
  // Debug console
  Serial.begin(115200);
  pinMode(4, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(13, OUTPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); 
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 100), 8080);


  SPI.begin();
  RC522.init();
}
BLYNK_WRITE(V0) {
  int relay1 = param.asInt();
  if (relay1 == 1) {
    digitalWrite(2, HIGH);
  } else {
    digitalWrite(2, LOW);
  }
}
BLYNK_WRITE(V1) {
  int relay2 = param.asInt();
  if (relay2 == 1) {
    digitalWrite(13, HIGH);
  } else {
    digitalWrite(13, LOW);
  }
}
void loop()
{
  pinMode(2, OUTPUT);
  Blynk.run();

  if (RC522.isCard()) {
    RC522.readCardSerial(); 
    if (( RC522.serNum[1]  == 114 )) {
      Serial.print("An amount of Rs. 310 is deducted from your FAStag account XXXX0094 ");
      Serial.println();
      Blynk.virtualWrite(V5,"MH 01 HT 1001");
    }else{
      if (( RC522.serNum[1]  == 82 )) {
      Serial.print("An amount of Rs. 310 is deducted from your FAStag account XXXX0095 ");
      Serial.println();
      Blynk.virtualWrite(V5,"MH 47 BW 3204");
      }
     else{
     if (( RC522.serNum[1]  == 104)) {
      Serial.print("An amount of Rs. 310 is deducted from your FAStag account XXXX0096 ");
      Serial.println();
      Blynk.virtualWrite(V5,"MH 99 YZ 9999");
      }
     else{
      if (( RC522.serNum[1]  == 248 )) {
       Serial.print("An amount of Rs. 310 is deducted from your FAStag account XXXX0097 ");
       Serial.println();
       Blynk.virtualWrite(V5,"MH 12 ZZ 3456");
      }else{
       if (( RC522.serNum[1]  == 191 )) {
       Serial.print("An amount of Rs. 310 is deducted from your FAStag account XXXX0098 ");
       Serial.println();
       Blynk.virtualWrite(V5,"MH 98 YZ 7654");
      }
     else{
      Blynk.virtualWrite(V5,"Car Not Recognized");
        }
       }
      }
     }
    }
     for(int i=0;i<5;i++) 
     { 
      Serial.print(RC522.serNum[i],DEC); 
      Serial.print(" "); 
     } 
     Serial.println();
      }
}
