#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include "config.h"
#include "LED.h"

ESP8266WebServer server(80);

// Go to http://192.168.4.LEVEL+1 in a web browser to see the flag
/*
 * easy = 192.168.4.1
 * medium = 192.168.4.2
 * hard = 192.168.4.3
 * */

 void handleRoot() {
  String html = String(PAGES[LEVEL]);
  
  server.send(200, "text/html", html);
  Serial.println("server handlroot executed");
 }

LED led;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting AP... ");

  WiFi.softAPdisconnect(true);

  // Go into AP mode
  WiFi.mode(WIFI_AP_STA);

  delay(100);

  String ap_ssid = String(DIFFICULTY[LEVEL]);
  String password = String(PSWDS[LEVEL]);

  //Set IP Address, Gateway, and Subnetmask
  WiFi.softAPConfig(IPAddress(192, 168, 10, LEVEL+1), IPAddress(192, 168, 10, LEVEL+1), IPAddress(255, 255, 255, 0));

  boolean result = WiFi.softAP(ap_ssid, password, MAX_CHANNEL, LEVEL == 2, MAX_CONNECTIONS);

  delay(100);

  if(result == true)
  {
    Serial.println("Ready, AP " + ap_ssid + " started");
    Serial.println("IP Address: " + WiFi.softAPIP().toString());
  }
  else
  {
    Serial.println("Failed to start AP");
  }

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
  delay(100);

  led.begin();

  //Set LEDs Green=Easy, Blue=Medium, Red=Hard
  switch (LEVEL) {
    case 0:
      led.setColor(0,1,0);
      break;
    case 1:
      led.setColor(0,0,1);
      break;
    case 2:
      led.setColor(1,0,0);
      break;
    default:
      led.setColor(0,0,0);
      break;
  }
}

void loop(void) {
  MDNS.update();
  server.handleClient();
}
