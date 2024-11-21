#include <Arduino.h>

class SensorMQ {
private:
    int pinAnalog;

public:
    // Constructor para inicializar el pin del sensor MQ
    SensorMQ(int analogPin) {
        pinAnalog = analogPin;
        pinMode(pinAnalog, INPUT);
    }

    // Método para obtener la lectura del sensor
    int obtenerLectura() {
        return analogRead(pinAnalog);
    }
};