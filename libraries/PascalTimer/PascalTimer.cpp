/*
 * PascalTimer.h - Library for simple Timer
 * Created by Pascal Klein, Jule 5, 2013.
 */

#include "Arduino.h"
#include "PascalTimer.h"


PascalTimer::PascalTimer(unsigned long intv)
{
  interval = intv;
  state    = LOW;
  enabled  = true;
  force    = false;
  reset();
}


unsigned long PascalTimer::get_dt()
{
  return millis() - _lastupdate;
}


boolean PascalTimer::istimer(boolean resetontimer)
{
  if (((get_dt() >= interval) || (force)) && (enabled))
  {
    force = false;
    state = !state;
    if (resetontimer)
      reset();
    return true;
  }
  return false;
}


void PascalTimer::reset()
{
  enabled     = true;
  _lastupdate = millis();
}
