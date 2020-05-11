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
  PascalTimer(unsigned long intv = 0);
  void reset();
  boolean istimer(boolean resetontimer = true);
  unsigned long get_dt();

  boolean       state;
  unsigned long interval;
  boolean       enabled;  // new, 27AUG2013
  boolean       force;    // new, 11JAN2015

private:
  unsigned long _lastupdate;
};

#endif
