#include "LED.h"

Led ::Led(uint8_t pin) : // : os dois pontos começam a lista de inicialização
    pino(pin),
    estado(LOW),
    desligarPorTempo(false),
    desligarNoMomento(0),
    tempoAnteriorPiscar(0),
    tempoEspera(0),
    estadoPiscar(false),
    repeticoes(0)
{
    pinMode(pino, OUTPUT);
}

void Led ::ligar()
{
    estadoPiscar = false;
    desligarPorTempo = false;
    estado = HIGH;
}

void Led ::ligar(uint32_t tempoLigado_ms)
{
    estadoPiscar = false;
    estado = HIGH;
    desligarPorTempo = true;
    desligarNoMomento = millis() + tempoLigado_ms;
}

void Led ::desligar()
{
    estadoPiscar = false;
    desligarPorTempo = false;
    estado = LOW;
}

void Led ::alternar()
{
    estadoPiscar = false;
    desligarPorTempo = false;
    estado = !estado;
}

void Led ::update()
{
    if (desligarPorTempo)
        funcaoDesligamento();

    if (estadoPiscar)
        funcaoPiscar();

    digitalWrite(pino, estado);
}

bool Led ::getEstado()
{
    return estado;
}

uint8_t Led ::getPino()
{
    return pino;
}

void Led ::setEstado(bool estado)
{
    estadoPiscar = false;
    desligarPorTempo = false;
    this->estado = estado; // this-> identifica qm é o atributo. E o estado sem o this é o parametro
}

void Led ::piscar()
{
    estadoPiscar = true;
    tempoEspera = 500;
    tempoAnteriorPiscar = millis();
    estado = HIGH;
}

void Led ::piscar(float frequencia)
{
    desligarPorTempo = false;
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
}

void Led ::piscar(float frequencia, uint16_t repeticoes)
{
    desligarPorTempo = false;
    estadoPiscar = true;
    tempoEspera = (1000.0f / (2.0f * frequencia));
    tempoAnteriorPiscar = millis();
    estado = HIGH;
    this->repeticoes = repeticoes * 2;
}

void Led ::funcaoPiscar()
{
    if (millis() - tempoAnteriorPiscar >= tempoEspera)
    {
        estado = !estado;
        tempoAnteriorPiscar = millis();
        if (repeticoes > 0)
        {
            repeticoes--;
            if (repeticoes == 0)
            {
                estadoPiscar = false;
                estado = LOW;
            }
        }
    }
}

void Led ::funcaoDesligamento()
{
    if (millis() >= desligarNoMomento)
    {
        estado = LOW;
        desligarPorTempo = false;
    }
}