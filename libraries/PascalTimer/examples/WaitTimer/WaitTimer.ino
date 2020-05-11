#include <PascalTimer.h>

PascalTimer waittimer(3000);

void setup()
{
  Serial.begin(9600);
  Serial.println("[PascalTimer]: WaitTimer\n");
}


void flush_serial()
{
  while (Serial.available())
  {
    Serial.read();
    delay(1);
  }
}


void loop()
{
  Serial.print("Press any key ... ");
  flush_serial();
  waittimer.reset();
  while (!waittimer.istimer())
  {
    if (Serial.available())
    {
      Serial.println("ok.");
      delay(1000);
      return;
    }
    delay(1); // stability
  }
  Serial.println("error.");
  delay(5000);
}

