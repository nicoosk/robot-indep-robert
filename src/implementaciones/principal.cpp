#include "main/controladores/motores/motores.h"
#include "main/controladores/motores/motores.cpp"
#include "main/controladores/servo-control/servo-control.h"
#include "main/controladores/servo-control/servo-control.cpp"
#include "main/controladores/ultrasonico/sensor-ultrasonico.h"
#include "main/controladores/ultrasonico/sensor-ultrasonico.cpp"
#include <Arduino.h>

int in1, in2, ena, in3, in4, enb, servo, trig, echo;

void construir(int in1, int in2, int ena, int in3, int in4, int enb, int servo, int trig, int echo ){
    ::in1 = in1;
    ::in2 = in2;
    ::ena = ena;
    ::in3 = in3;
    ::in4 = in4;
    ::enb = enb;
    ::servo = servo;
    ::trig = trig;
    ::echo = echo;

    inicializarMotorDelantero(::in1, ::in2, ::ena);
    inicializarMotorTrasero(::in3, ::in4, ::enb);
    inicializarServo(::servo);
    inicializarUltrasonico(::trig, ::echo);
    Serial.println("Funciones construidas.");
}

void avanzarHastaObstaculo(){
    acelerarMotorTrasero(in3, in4, enb);
    if (enviarPulso(trig, echo) < 30){
        detenerse();
        bool hayDerecha = verificarLaterales();
        if (hayDerecha){
            girarIzquierda(in1, in2, ena, in3, in4, enb);
        } else {
            girarDerecha(in1, in2, ena, in3, in4, enb);
        }
    }
}

void detenerse(){
    despotenciar(enb);
    Serial.println("Motor trasero detenido.")
}

bool verificarLaterales(){
    mirarDerecha();
    if (enviarPulso(trig, echo) < 30){
        return true;
    } else {
        Serial.println("Nada a la derecha.")
    }
    mirarIzquierda();
    if (enviarPulso(trig, echo) < 30){
        return false;
    } else {
        Serial.println("Nada a la izquierda.")
    }
}

