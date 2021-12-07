#include "LED.h"

void LED::begin() {
  pinMode(5, OUTPUT);//D1
  pinMode(4, OUTPUT);//D2
  pinMode(0, OUTPUT);//D3

  setColor(1,1,1);
}

void LED::setColor(int r, int g, int b) {
  int ledR = 0;
  int ledG = 0;
  int ledB = 0;

  ledR = r ? 1 : 0;
  ledG = g ? 1 : 0;
  ledB = b ? 1 : 0;

  digitalWrite(5, ledR);//D1
  digitalWrite(4, ledG);//D2
  digitalWrite(0, ledB);//D3
}
