#include <ESP8266WiFi.h>
#include "config.h"

// Connect to next wifi client in order to generate handshakes
void updateWifi(int level)
{
  String ap_ssid = String(DIFFICULTY[level]);
  String password = String(PSWDS[level]);

  Serial.println("Connecting to access point: " + ap_ssid + " with password: " + password);

  if(WiFi.status() == WL_CONNECTED)
  {
    Serial.println("Successfully connected to: " + ap_ssid);
  }

  WiFi.begin(ap_ssid, password);

  
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  Serial.println("Ready to start making connections");
}

void loop() {
  // put your main code here, to run repeatedly:
  int level = 0;

  while (level < 3)
  {
    updateWifi(level);
    delay(10000);
    level = level + 1;
  }
}
