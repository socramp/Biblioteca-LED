# 💡 Biblioteca LED

Biblioteca para controle não bloqueante de um LED utilizando Arduino/ESP32.  
Permite ligar, desligar, piscar com frequência, piscar por quantidade definida e controlar o estado do LED de forma eficiente e sem bloqueios.

---

## 🚀 Funcionalidades

- Ligar e desligar o LED
- Ligar por tempo determinado
- Piscar continuamente
- Piscar com frequência definida
- Piscar por quantidade de repetições
- Alternar estado do LED
- Controle não bloqueante com `millis()`

---

## 📁 Estrutura da Biblioteca

A biblioteca está organizada da seguinte forma:

```text
Biblioteca LED/
│
├── examples/              # Exemplos de uso da biblioteca
│   ├── 01-Piscar com freq e rep.cpp
│   ├── 02-Alternar estado do led.cpp
│   ├── 03-Ligar por tempo.cpp
│   ├── 04-Ligar ou piscar.cpp
│   └── 05-Exemplo com 2 LEDs.cpp
│
├── src/                   # Código fonte da biblioteca
│   ├── LED.cpp            # Implementação dos métodos
│   └── LED.h              # Definição da classe
│
├── library.json           # Configuração da biblioteca (PlatformIO)
├── LICENSE                # Licença do projeto
└── README.md              # Documentação