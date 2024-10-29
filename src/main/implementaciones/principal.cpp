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

void verificarLaterales(){
    mirarDerecha();
    delay(1000);
    float distanciaDerecha = enviarPulso(trig, echo);
    delay(500);

    mirarIzquierda();
    delay(1000);
    float distanciaIzquierda = enviarPulso(trig, echo);
    delay(500);


    Serial.print("Distancia derecha: ");
    Serial.print(distanciaDerecha);
    Serial.println(" cm");

    Serial.print("Distancia Izquierda: ");
    Serial.print(distanciaIzquierda);
    Serial.println(" cm");

    if (distanciaDerecha < 30 && distanciaIzquierda > 30){
        Serial.println("Moviendo a la derecha.");
        girarDerecha(in1, in2, ena, in3, in4, enb);
    } else if (distanciaIzquierda < 30 && distanciaDerecha > 30){
        Serial.println("Moviendo a la izquierda.");
        girarIzquierda(in1, in2, ena, in3, in4, enb);
    } else if (distanciaDerecha < 30 && distanciaIzquierda < 30){
        Serial.println("Bloqueado. Retrocediendo...");
        // retrocederMotorTrasero(in3, in4, enb);
        delay(1000);
        despotenciar(enb);
        delay(500);
        irAleatorio(in1, in2, ena, in3, in4, enb);
    } else {
        Serial.println("No hay obstáculo cerca, girando aleatorio.");
        irAleatorio(in1, in2, ena, in3, in4, enb);
    }
}

void avanzarHastaObstaculo() {
    neutro(in1, in2, ena);
    neutro(in3, in4, enb);
    mirarFrente();
    acelerarMotorTrasero(in3, in4, enb);
    if (enviarPulso(trig, echo) < 40) {
        detenerse(in3, in4, enb);
        delay(500);
        // verificarLaterales();
    }
    // mirarFrente();
    delay(200);
}



