/*
 * PascalChklong.h - Library for checking long press
 * Created by Pascal Klein, Jule 6, 2013.
 */

#include "Arduino.h"
#include "PascalChklong.h"


PascalChklong::PascalChklong(boolean(*callback)())
{
  _callback     = callback;
  checkled      = 13;
  useled        = false; // default=false, set 28okt13
  currval       = false;
  callbacktimer = new PascalTimer(0);  // will be set later, when needed
  errorchktimer = new PascalTimer(50);
  reset();
}


void PascalChklong::reset()
{
  callbacktimer->reset();
  errorchktimer->reset();
}


void PascalChklong::update()
{
  if (errorchktimer->istimer())
  {
    // reset all, otherwise old states could be regarded as long pressed
    // this detects it it is first command in loop, thus no need to add a reset function before execution of the loop
    reset();
    update(); // to ensure to have right currval
    return;
  }

  boolean readval = (*_callback)();
  if (currval != readval)
  {
    currval = readval;   // update currval
    callbacktimer->reset();
  }

  errorchktimer->reset();
}


byte PascalChklong::bool2state(boolean boo)
{
  return boo ? STATE_HIGH : STATE_LOW;
}


byte PascalChklong::get_check(int min_duration)
{
  // tri-state output (HIGH / LOW: minduration passed, UNDEF: not passed)

  // first of all, collect the data, i.e. do the check
  // it might reset all; for sure: it puts values to get right 'current_val'
  update();

  // set min. delta-time
  callbacktimer->interval = min_duration;

  if (callbacktimer->istimer(false))  // enough time passed, don't reset (istimer(FALSE))
    return bool2state(currval);
  else
    return STATE_UNDEF;
}


boolean PascalChklong::get_check_bool(boolean want_state, int min_duration) // Non-blocking
{
  boolean res = get_check(min_duration) == bool2state(want_state);

  if (useled)
  {
    pinMode(checkled, OUTPUT);
    digitalWrite(checkled, (currval == want_state) && (!res));
  }
  return res;
}


boolean PascalChklong::get_check_bool_wait(boolean want_state, int min_duration) // can be blocking
{
  // wait on spec

  PascalTimer checktimer(min_duration);

  while (true)
  {
    if (!get_check_bool(want_state, 0))
      return false;  // changed to the bad

    if (checktimer.istimer())
      return true;  // passed

    delay(10);      // stability
  }
}


boolean PascalChklong::getcurrval()
{
  return currval;
}


void PascalChklong::set_timeout(int t_ms)
{
  errorchktimer->interval = t_ms;
}
