/*
 * PascalFunc.h - Library for functions
 * Created by Pascal Klein, Nov 4, 2013.
 */

#ifndef PascalFunc_h
#define PascalFunc_h

#include "Arduino.h"

void pulse(byte pin, unsigned int times = 3, unsigned int tlen = 200)
{
  for (unsigned int x = 0; x < times; x++)
  {
    digitalWrite(pin, HIGH);
    delay(tlen);
    digitalWrite(pin, LOW);
    delay(tlen);
  }
}

#endif
