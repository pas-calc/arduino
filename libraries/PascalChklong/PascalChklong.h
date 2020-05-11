/*
 * PascalChklong.h - Library for checking long press
 * Created by Pascal Klein, Jule 6, 2013.
 */

#ifndef PascalChklong_h
#define PascalChklong_h

#include "Arduino.h"
#include <PascalTimer.h> // needs to be added here AND in every sketch using 'import library'

#define STATE_LOW      0
#define STATE_HIGH     1
#define STATE_UNDEF    2

class PascalChklong
{
public:
  PascalChklong(boolean(*callback)());
  boolean get_check_bool(boolean want_state, int min_duration);      // Non-blocking
  boolean get_check_bool_wait(boolean want_state, int min_duration); // can be blocking
  void update();
  void reset();
  boolean getcurrval();
  void set_timeout(int t_ms);

  int     checkled;
  boolean useled;

private:
  byte bool2state(boolean boo);
  byte get_check(int min_duration);

  boolean     (*_callback)();
  boolean     currval;
  PascalTimer *callbacktimer;
  PascalTimer *errorchktimer;
};

#endif
