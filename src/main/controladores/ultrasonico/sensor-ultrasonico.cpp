#include <Arduino.h>

class Ultrasonico {
private:
    int triggerPin;
    int echoPin;

public:
    // Constructor para inicializar los pines del sensor
    Ultrasonico(int trigPin, int echPin) {
        triggerPin = trigPin;
        echoPin = echPin;
        pinMode(triggerPin, OUTPUT);
        pinMode(echoPin, INPUT);
    }

    // Método para obtener la distancia medida por el sensor
    long obtenerDistancia() {
        digitalWrite(triggerPin, LOW);
        delayMicroseconds(2);
        digitalWrite(triggerPin, HIGH);
        delayMicroseconds(10);
        digitalWrite(triggerPin, LOW);

        long duracion = pulseIn(echoPin, HIGH);
        long distancia = duracion * 0.034 / 2; // Calcular distancia en cm
        return distancia;
    }
};