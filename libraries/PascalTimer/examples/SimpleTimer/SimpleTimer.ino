#include <PascalTimer.h>

PascalTimer simpletimer(2500);

void setup()
{
  Serial.begin(9600);
  Serial.println("[PascalTimer]: SimpleTimer\n");
}


void loop()
{
  if (simpletimer.istimer())
  {
    Serial.print("Timer event, ");
    Serial.print(simpletimer.state);
    Serial.print(", @ ");
    Serial.print(millis());
    Serial.println();
    delay(555); // this does not conflict
  }

  if (Serial.read()=='a')
    simpletimer.force=true;
}
