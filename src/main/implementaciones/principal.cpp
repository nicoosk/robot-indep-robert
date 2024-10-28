#include "../controladores/motores/motores.h"
#include "../controladores/motores/motores.cpp"
#include "../controladores/servo-control/servo-control.h"
#include "../controladores/servo-control/servo-control.cpp"
#include "../controladores/ultrasonico/sensor-ultrasonico.h"
#include "../controladores/ultrasonico/sensor-ultrasonico.cpp"
#include "freno.cpp"
#include "girar.cpp"
#include <Arduino.h>

int in1 = 8;
int in2 = 7;
int ena = 11;
int in3 = 4;
int in4 = 2;
int enb = 3;
int pinServo = 5;
int trig = 12;
int echo = 13;

void construir(int in1, int in2, int ena, int in3, int in4, int enb, int pinServo, int trig, int echo){
    ::in1 = in1;
    ::in2 = in2;
    ::ena = ena;
    ::in3 = in3;
    ::in4 = in4;
    ::enb = enb;
    ::pinServo = pinServo;
    ::trig = trig;
    ::echo = echo;

    inicializarMotorDelantero(::in1, ::in2, ::ena);
    inicializarMotorTrasero(::in3, ::in4, ::enb);
    inicializarServo(::pinServo);
    inicializarUltrasonico(::trig, ::echo);
    Serial.println("Funciones construidas.");
}

int verificarLaterales(){
    mirarDerecha();
    delay(1000);
    if (enviarPulso(trig, echo) < 30){
        return 0;
    } else {
        Serial.println("Nada a la derecha.");
    }
    mirarIzquierda();
    delay(1000);
    if (enviarPulso(trig, echo) < 30){
        return 1;
    } else {
        Serial.println("Nada a la izquierda.");
    }
    return -1;
}

void avanzarHastaObstaculo() {
    mirarFrente();
    acelerarMotorTrasero(in3, in4, enb);
    if (enviarPulso(trig, echo) < 30) {
        detenerse(in3, in4, enb);
        delay(1000);
        int lateral = verificarLaterales();
        delay(1000);
        if (lateral == 0) {
            girarDerecha(in1, in2, ena, in3, in4, enb);
        } else if (lateral == 1) {
            girarIzquierda(in1, in2, ena, in3, in4, enb);
        } else if (lateral == -1) {
            // ir en dirección aleatoria
            irAleatorio(in1, in2, ena, in3, in4, enb);
        } 
    }
    mirarFrente();
    delay(200);
}



