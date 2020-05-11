/*
 * PascalTimer.h - Library for simple Timer
 * Created by Pascal Klein, Jule 5, 2013.
 */

#include "Arduino.h"
#include "PascalTimer.h"


PascalTimer::PascalTimer(int intv)
{
  interval = intv;
  state    = LOW;
  reset();
}


unsigned long PascalTimer::get_dt()
{
  return millis() - _lastupdate;
}


boolean PascalTimer::istimer(boolean resetontimer)
{
  if (get_dt() >= interval)
  {
    state = !state;
    if (resetontimer)
      reset();
    return true;
  }
  return false;
}


void PascalTimer::reset()
{
  _lastupdate = millis();
}
