/**
 * Exemplo que mostra como alternar o estado atual de um LED.
 */
#include <Arduino.h>
#include <LED.h>

Led ledA(45);

void setup()
{
}

void loop()
{
  bool estadoLedA = digitalRead(45); //Lê o estado do LED.
  if(estadoLedA == LOW)
  {
    ledA.alternar();
  }
  ledA.update();
}
