#ifndef LED_h
#define LED_h

#include <Arduino.h>

/**
 * @class Led
 * @brief Classe para controle não bloqueante de um LED.
 * Permite ligar, deligar, ligar por tempo determinado,
 * piscar continuamente e piscar por quantidade definida.
 *
 * @note O método update() deve ser chamado continuamente dentro do loop().
 */
class Led
{
private:
    uint8_t pino;
    bool estado; // atributo
    bool desligarPorTempo = false;
    uint32_t desligarNoMomento;

    uint32_t tempoAnteriorPiscar;
    uint32_t tempoEspera;
    bool estadoPiscar;
    uint16_t repeticoes;

    /**
     * @brief Processa a lógica de piscada do LED
     */
    void funcaoPiscar();

    /**
     * @brief Processa o desligamento temporizado.
     */
    void funcaoDesligamento();

public:
    /**
     * @brief Constroi um objeto Led.
     * @param pin Número do pino digital onde o LED está conectado.
     */
    Led(uint8_t pin);

    /**
     * @brief Liga o LED continuamente.
     */
    void ligar();

    /**
     * @brief Liga o LED por um tempo determinado.
     * @param tempoLigado_ms Tempo, em milissegundos, que o LED ficará ligado.
     */
    void ligar(uint32_t tempoLigado_ms);

    /**
     * @brief Desliga o LED e cancela os modos automáticos.
     */
    void desligar();

    /**
     * @brief Inicia a piscada continua em 1 Hz.
     */
    void piscar();

    /**
     * @brief Pisca o LED em uma determinada velocidade em HZ.
     * @param frequencia Determina quantas vezes por segundo o LED deve piscar.
     */
    void piscar(float frequencia);

    /**
     * @brief Pisca o LED uma quantidade definida de vezes.
     * @param frequencia Frequência da piscada em Hz.
     * @param repeticoes Quantidade de piscadas completas.
     */
    void piscar(float frequencia, uint16_t repeticoes);

    /**
     * @brief Retorna o estado em que o LED está no momento.
     */
    bool getEstado();

    /**
     * @brief Retorna o pino em que o LED está no momento.
     */
    uint8_t getPino();

    /**
     * @brief Define manualmente o estado atual do LED.
     * @param estado true para ligado, e false para desligado.
     */
    void setEstado(bool estado);

    /**
     * @brief Alterna o estado atual do LED.
     */
    void alternar();

    /**
     * @brief Atualiza o código continuamente verificando mudanças.
     */
    void update();
};

#endif
