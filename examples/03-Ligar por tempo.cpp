/**
 * Exemplo que mostra um LED que liga por um determinado tempo em milissegundos.
 */
#include <Arduino.h>
#include <LED.h>

Led ledA(45);
int valor = 0;

void setup()
{
}

void loop()
{
  if(valor < 1)
  {
    ledA.ligar(5000);
    valor++;
  }
  ledA.update();
}
