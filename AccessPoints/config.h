#ifndef CONFIG_H
#define CONFIG_H

// Current Level
// 0=Easy,1=Medium,2=Hard
const int LEVEL PROGMEM = 2;

// Max connections to access point at the same time
const unsigned int MAX_CONNECTIONS = 5;

// Max channel for access point (11=US,13=Europe,14=Japan)
const unsigned int MAX_CHANNEL = 11;

// Level names
const char* DIFFICULTY[] PROGMEM = {
  "SMPentestWifiChallengeEasy",
  "SMPentestWifiChallengeMedium",
  "SMPentestWifiChallengeHard",
};

// Level Passwords
const char* PSWDS[] PROGMEM = {
  "EasyPass",
  "MediumPass",//password is still easily crackable, but it's in a random wordlist on the raspberry pi
  "HardPass"//Password is crackable using aircrack, but the SSID is hidden
};

const char* PAGES[] PROGMEM = {
  "<h1>This will display on http://192.168.4.1 after cracking the captured handshake and connecting to the device</h1>",
  "<h1>This will display on http://192.168.4.2 after cracking the captured handshake and connecting to the device</h1>",
  "<h1>This will display on http://192.168.4.3 after cracking the captured handshake and connecting to the device</h1>"
};

#endif
