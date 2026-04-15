/**
 * Exemplo que liga o LED se o estadoMaquina for 1 e pisca o LED se o estadoMaquina for 0.
 */
#include <Arduino.h>
#include <LED.h>

Led ledA(45);
bool estadoMaquina = 0;
bool variavelDeControle = false; //Um estado lógico que define se determinada ação ser executada ou não.

void setup()
{
}

void loop()
{
  if(!variavelDeControle)
  {
    if(estadoMaquina)
    {
      ledA.ligar();
      variavelDeControle = true;
    } else
    {
      ledA.piscar();
      variavelDeControle = true;
    }
  }
  ledA.update();
}
