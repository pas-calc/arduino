#include <PascalTimer.h>   // important to add this library, too !
#include <PascalChklong.h>

int button = 5;
int led    = 13;

PascalChklong buttonlong(ispressed);

void setup()
{
//  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
  digitalWrite(button, HIGH); // very important: PULLUP

//  buttonlong.useled = false;  // optional, if useled=false then this led can be used on 'ispressed_long' ( see -> loop() )

  Serial.begin(9600);
  Serial.println("[PascalChklong] : ButtonCheck\n");
  digitalWrite(led, HIGH);
  delay(500);
  
  //buttonlong.reset(); // not neccessary, will be done on first check
}


boolean ispressed()
{
  return !digitalRead(button);
}


boolean ispressed_long()
{
  return buttonlong.get_check_bool(HIGH, 50);
}


void loop()
{
  if (ispressed_long()){
    //digitalWrite(led, HIGH);
    Serial.println("> hi");
    delay(500);
    //digitalWrite(led, LOW);
    Serial.println("ready");
  }
  delay(10);
}

