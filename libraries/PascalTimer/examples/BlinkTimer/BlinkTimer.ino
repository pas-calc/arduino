// 08 JAN 2014
// 10 JAN 2015 (one year :=) added dyn.interval )

#include <PascalTimer.h>

PascalTimer blinktimer(250);  // adjust time here

byte led = 4;

void setup()
{
  Serial.begin(9600);
  Serial.println("[PascalTimer]: BlinkTimer\n");
  pinMode(led, OUTPUT);
}


void loop()
{
  if (blinktimer.istimer()) // non-blocking :=)
  {
    digitalWrite(led, blinktimer.state);
    Serial.print("LED: ");
    Serial.print(blinktimer.state ? "on" : "off");
    Serial.println();
    
    // set Dynamic interval :: on: 100ms , off: 600ms
    blinktimer.interval = (blinktimer.state) ? 100 : 600;    
  }
}
