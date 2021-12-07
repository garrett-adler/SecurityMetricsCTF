#ifndef CONFIG_H
#define CONFIG_H

// Number of APs
const int AccessPointCount PROGMEM = 3;

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
  "MediumPass",
  "HardPass"
};

#endif
