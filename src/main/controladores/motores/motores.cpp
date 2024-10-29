#include <Arduino.h>
#include "motores.h"

void inicializarMotorTrasero(int IN1, int IN2, int ENA){
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(ENA, OUTPUT);
}

void inicializarMotorDelantero(int IN3, int IN4, int ENB){
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENB, OUTPUT);
}

void positivoNegativo(int P1, int P2){
    digitalWrite(P1, HIGH);
    digitalWrite(P2, LOW);
}

void negativoPositivo(int P1, int P2){
    digitalWrite(P1, LOW);
    digitalWrite(P2, HIGH);
}

void neutro(int P1, int P2, int OUT){
    digitalWrite(P1, LOW);
    digitalWrite(P2, LOW);
    analogWrite(OUT, 0);
}

void potenciar(int OUT){
    analogWrite(OUT, 150);
}

void despotenciar(int OUT){
    analogWrite(OUT, 0);
}

void retroceder(int OUT){
    analogWrite(OUT, 200);
}

void cambiarDireccionDerecha(int P1, int P2, int OUT){
    positivoNegativo(P1, P2);
    potenciar(OUT);
    delayMicroseconds(50);
    despotenciar(OUT);
}

void cambiarDireccionIzquierda(int P1, int P2, int OUT){
    negativoPositivo(P1, P2);
    potenciar(OUT);
    delayMicroseconds(50);
    despotenciar(OUT);
}

void acelerarMotorTrasero(int P1, int P2, int OUT){
    positivoNegativo(P1, P2);
    potenciar(OUT);
}

void retrocederMotorTrasero(int P1, int P2, int OUT){
    negativoPositivo(P1, P2);
    retroceder(OUT);
}