/**
 * Exemplo exmplicando como fazer o led (ledA) de um pino específico (45) piscar com determinada frequência e determinado número de repetições.
 */
#include <Arduino.h>
#include <LED.h>

Led ledA(45);
bool exemplo = false;

void setup()
{
}

void loop()
{
  if (!exemplo)
  {
    ledA.piscar(2, 10);
    exemplo = true;
  }
  ledA.update();
}
