/*
 * PascalTimer.h - Library for simple Timer
 * Created by Pascal Klein, Jule 5, 2013.
 */

#ifndef PascalTimer_h
#define PascalTimer_h

#include "Arduino.h"

class PascalTimer
{
public:
  PascalTimer(int intv = 0);
  void reset();
  boolean istimer(boolean resetontimer = true);
  unsigned long get_dt();

  boolean       state;
  unsigned long interval;

private:
  unsigned long _lastupdate;
};

#endif
