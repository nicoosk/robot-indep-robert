#include <Arduino.h>
#include "motores.h"

int MOTOR_TRASERO_IN1;
int MOTOR_TRASERO_IN2;
int MOTOR_TRASERO_ENA;

int MOTOR_DELANTERO_IN3;
int MOTOR_DELANTERO_IN4;
int MOTOR_DELANTERO_ENB;

void inicializarMotorTrasero(int IN1, int IN2, int ENA){
    MOTOR_TRASERO_IN1 = IN1;
    MOTOR_TRASERO_IN2 = IN2;
    MOTOR_TRASERO_ENA = ENA;

    pinMode(MOTOR_TRASERO_IN1, OUTPUT);
    pinMode(MOTOR_TRASERO_IN2, OUTPUT);
    pinMode(MOTOR_TRASERO_ENA, OUTPUT);
}

void inicializarMotorDelantero(int IN3, int IN4, int ENB){
    MOTOR_DELANTERO_IN3 = IN3;
    MOTOR_DELANTERO_IN4 = IN4;
    MOTOR_DELANTERO_ENB = ENB;

    pinMode(MOTOR_DELANTERO_IN3, OUTPUT);
    pinMode(MOTOR_DELANTERO_IN4, OUTPUT);
    pinMode(MOTOR_DELANTERO_ENB, OUTPUT);
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
    analogWrite(OUT, 110);
}

void potenciarDireccion(int OUT){
    analogWrite(OUT, 255);
}

void despotenciar(int OUT){
    analogWrite(OUT, 0);
}

void retroceder(int OUT){
    analogWrite(OUT, 200);
}

void cambiarDireccionDerecha(){
    positivoNegativo(MOTOR_DELANTERO_IN3, MOTOR_DELANTERO_IN4);
    potenciarDireccion(MOTOR_DELANTERO_ENB);
    delayMicroseconds(5);
    despotenciar(MOTOR_DELANTERO_ENB);
}

void cambiarDireccionIzquierda(){
    negativoPositivo(MOTOR_DELANTERO_IN3, MOTOR_DELANTERO_IN4);
    potenciarDireccion(MOTOR_DELANTERO_ENB);
    delayMicroseconds(5);
    despotenciar(MOTOR_DELANTERO_ENB);
}

void cambiarDireccionFrente(){
    // TODO
}

void acelerarMotorTrasero(){
    positivoNegativo(MOTOR_TRASERO_IN1, MOTOR_TRASERO_IN2);
    potenciar(MOTOR_TRASERO_ENA);
}

void retrocederMotorTrasero(){
    negativoPositivo(MOTOR_TRASERO_IN1, MOTOR_TRASERO_IN2);
    retroceder(MOTOR_TRASERO_ENA);
}

void detenerse(){
    retrocederMotorTrasero();
    delay(500);
    despotenciar(MOTOR_TRASERO_ENA);
}

void girarDerecha(){
    // Retrocede girando para cambiar dirección
    cambiarDireccionIzquierda();
    retrocederMotorTrasero();
    delay(500);
    despotenciar(MOTOR_TRASERO_ENA);
    delay(500);

    // Va hacia la derecha
    cambiarDireccionDerecha();
    acelerarMotorTrasero();
    delay(500);
    despotenciar(MOTOR_TRASERO_ENA);
    delay(500);
}

void girarIzquierda() {
    // Retrocede girando para cambiar dirección
    cambiarDireccionDerecha();
    retrocederMotorTrasero();
    delay(500);
    despotenciar(MOTOR_TRASERO_ENA);
    delay(500);

    // Va hacia la izquierda
    cambiarDireccionIzquierda();
    acelerarMotorTrasero();
    delay(500);
    despotenciar(MOTOR_TRASERO_ENA);
    delay(500);
}

void irAleatorio(){
    randomSeed(analogRead(0)); // Añade esto en `setup()`
    // Generar un número aleatorio que sea 0 o 1
    int numeroAleatorio = random(0, 2); // Genera un número entre 0 (inclusive) y 2 (exclusive)

    if (numeroAleatorio == 0){
        girarDerecha();
    } else if (numeroAleatorio == 1){
        girarIzquierda();
    }
}