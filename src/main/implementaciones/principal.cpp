#include "../controladores/motores/motores.h"
#include "../controladores/motores/motores.cpp"
#include "../controladores/servo-control/servo-control.h"
#include "../controladores/servo-control/servo-control.cpp"
#include "../controladores/ultrasonico/sensor-ultrasonico.h"
#include "../controladores/ultrasonico/sensor-ultrasonico.cpp"
#include "freno.cpp"
#include "girar.cpp"
#include <Arduino.h>

// Asignación de pines
int in1 = 8;
int in2 = 7;
int ena = 11;
int in3 = 4;
int in4 = 2;
int enb = 3;
int pinServo = 5;
int trig = 12;
int echo = 13;



// Variables para controlar Robert
int ajuste = 0;
float distanciaIzquierda = 0;
float distanciaDerecha = 0;
float distanciaFrontal= 0;

// Inicializar pines
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

void avanzar(int ajuste) {
    ajuste = calcularAjuste();
    acelerarMotorTrasero(in3, in4, enb);

    if (distanciaIzquierda < 50 && distanciaDerecha > 50){
        // TODO
    } else if (distanciaDerecha < 50 && distanciaIzquierda > 50){
        // TODO
    } else if (distanciaDerecha < 50 && distanciaIzquierda < 50){
        // TODO
    } else {
        // TODO
    }
}

int calcularAjuste(){
    // Medimos las distancias con cada sensor
    distanciaIzquierda = medirIzquierda(trig, echo);
    distanciaDerecha = medirDistancia(trig, echo);
    distanciaFrontal = medirDistancia(trig, echo);

    // Ajuste PID para mantener el auto al centro del pasillo
    ajuste = controlPID(distanciaIzquierda, distanciaDerecha);
    return ajuste;
}
