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

void positivoNegativo(int PIN1, int PIN2){
    digitalWrite(PIN1, HIGH);
    digitalWrite(PIN2, LOW);
}

void negativoPositivo(int PIN1, int PIN2){
    digitalWrite(PIN1, LOW);
    digitalWrite(PIN2, HIGH);
}

void neutro(int IN1, int IN2, int IN3, int IN4, int ENA, int ENB){
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
}

void potenciar(int pin){
    analogWrite(pin, 255);
}

void despotenciar(int pin){
    analogWrite(pin, 0);
}