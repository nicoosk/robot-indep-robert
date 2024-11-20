#include <Arduino.h>

class Motor {
private:
    int pinIN1;
    int pinIN2;
    int pinEN;
    
public:
    // Constructor para inicializar los pines
    Motor(int IN1, int IN2, int EN) {
        pinIN1 = IN1;
        pinIN2 = IN2;
        pinEN = EN;

        pinMode(pinIN1, OUTPUT);
        pinMode(pinIN2, OUTPUT);
        pinMode(pinEN, OUTPUT);
    }

    int getEN() const {
        return pinEN;
    }

    int getIN1() const {
        return pinIN1;
    }

    int getIN2() const {
        return pinIN2;
    }

    // Métodos para el control básico del motor
    void positivoNegativo() {
        digitalWrite(pinIN1, HIGH);
        digitalWrite(pinIN2, LOW);
    }

    void negativoPositivo() {
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, HIGH);
    }

    void neutro() {
        digitalWrite(pinIN1, LOW);
        digitalWrite(pinIN2, LOW);
        analogWrite(pinEN, 0);
    }

    void potenciar(int potencia = 220) {
        analogWrite(pinEN, potencia);
    }

    void despotenciar(int pin) {
        analogWrite(pin, 0);
        digitalWrite(pin, LOW);
    }

    void retroceder(int potencia = 255) {
        analogWrite(pinEN, potencia);
    }
};

