// Declaración de dependencias
#include "../implementaciones/principal.cpp"
#include "controladores/servo-control/servo-control.h"
#include "controladores/servo-control/servo-control.cpp"
#include "controladores/ultrasonico/sensor-ultrasonico.h"
#include "controladores/ultrasonico/sensor-ultrasonico.cpp"

// Declaración de variables con pines

// Pines motor delantero
int in1 = 8;
int in2 = 7;
int ena = 11;

// Pines motor trasero
int in3 = 4;
int in4 = 2;
int enb = 3;

// Pin de servo
int pinServo = 5;

// Pin de ultrasonico
int trig = 12;
int echo = 13;


void setup(){
    construir(in1, in2, ena, in3, in4, enb, pinServo, trig, echo);
}

void loop() {
    avanzarHastaObstaculo();
}