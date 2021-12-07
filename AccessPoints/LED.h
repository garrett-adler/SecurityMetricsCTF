#ifndef LED_H
#define LED_H

#include <Arduino.h>

// ========== LED Class ========== //

class LED {
  public:
    void begin();
    void setColor(int r, int g, int b);
};

#endif /* ifndef LED_H */
