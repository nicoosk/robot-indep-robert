#include "implementaciones/principal.cpp"
#include "pid/medir-distancia.h"
#include "pid/medir-distancia.cpp"

extern int in1;
extern int in2;
extern int ena;
extern int in3;
extern int in4;
extern int enb;
extern int pinServo;
extern int trig;
extern int echo;

void setup(){
    construir(in1, in2, ena, in3, in4, enb, pinServo, trig, echo);
    Serial.begin(9600);
}

void loop() {
    
    // Si detecta una pared al frente, girar 360 grados
    if (distanciaFrontal < 5.0) {
        girar360Grados();
    } 
    // Si no hay pared en uno de los costados, girar 90 grados hacia ese lado
    else if (distanciaIzquierda > 10.0) {
        girar90Grados("izquierda");
    } else if (distanciaDerecha > 10.0) {
        girar90Grados("derecha");
    } 
    // Mantenerse al centro del pasillo
    else {
        avanzar(ajuste);
    }
}