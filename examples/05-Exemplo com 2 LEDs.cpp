/**
 * Exemplo que pergunta o número do alerta (de 0 a 3) e com base no número do alerta faz uma ação com o LED A e uma outra ação com o LED B.
 */
#include <Arduino.h>
#include <LED.h>

Led ledB(48);
Led ledA(40);
int alerta = 4; // Valor de 0 a 3.
bool variavelDeControle;

void setup()
{
}

void loop()
{
  if (variavelDeControle == false)
  {
    switch (alerta)
    {
    case 0:
      ledA.piscar(1, 10);
      ledB.piscar(2, 20);
      variavelDeControle = true; // Para não dar o comando denovo antes da ação ser concluída.
      break;
    case 1:
      ledA.ligar();
      ledB.desligar();
      variavelDeControle = true;
      break;
    case 2:
      ledA.desligar();
      ledB.piscar(2);
      variavelDeControle = true;
      break;
    case 3:
      ledA.ligar(5000);
      ledB.piscar(1, 5);
      variavelDeControle = true;
      break;
    default:
      ledA.desligar();
      ledB.desligar();
      break;
    }
  }

  ledA.update();
  ledB.update();
}
