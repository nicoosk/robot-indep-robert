#include <Arduino.h>
#include "sensor_ultrasonico.h"

void inicializarUltrasonico(int trig, int echo){
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void estadoInicial(int trig){
    digitalWrite(trig, LOW);
}

void enviarPulso(int trig, int echo){
    digitalWrite(trig, LOW);
    delayMicroseconds(2);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);

    long duracion = pulseIn(echo, HIGH);


    float distancia = duracion * 0.034 / 2;

    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

}

float calcularDistancia(int echo){
    long duracion = pulseIn(echo, HIGH);
    return duracion * 0.034 / 2;;
}

