#include <Arduino.h>
#include "sensor_ultrasonico.h"

void inicializarUltrasonico(int trig, int echo){
    pinMode(trig, OUTPUT);
    pinMode(echo, INPUT);
}

void estadoInicial(int trig, int echo){
    digitalWrite(trig, LOW);
    digitalWrite(echo, LOW);
}

void enviarPulso(int trig){
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
}

float calcularDistancia(int echo){
    long duracion = pulseIn(echo, HIGH);
    if (duracion == 0){
        return -1;
    }
    return (duracion * 0.034) / 2;
}

