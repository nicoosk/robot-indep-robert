// principal.cpp
#include "../controladores/motores/motores.h"
#include "../controladores/motores/motores.cpp"
#include "../controladores/servo-control/servo-control.h"
#include "../controladores/servo-control/servo-control.cpp"
#include "../controladores/ultrasonico/sensor-ultrasonico.h"
#include "../controladores/ultrasonico/sensor-ultrasonico.cpp"
#include "principal.h"
#include "../pid/medir-distancia.h"
#include "../pid/medir-distancia.cpp"
#include <Arduino.h>

// Variables para controlar Robert
float ajuste = 0;
float distanciaIzquierda = 0;
float distanciaDerecha = 0;
float distanciaFrontal= 0;
bool acelerar = true;


void avanzar() {
    acelerarMotorTrasero();

    ajuste = calcularAjuste();

    Serial.print("Ajuste: ");
    Serial.println(ajuste);
    delay(200);

    if (ajuste > 0){
        Serial.println("Virando a la derecha...");
        cambiarDireccionDerecha();
    } else if (ajuste < 0){
        Serial.println("Virando a la izquierda...");
        cambiarDireccionIzquierda();
    } 
    despotenciar(ena);
}

void verificarFrontal(){
    if (distanciaFrontal < 50){
        detenerse();
        delay(300);
        elegirOpcion();
    }
}

void elegirOpcion(){
    if (distanciaDerecha < 60 && distanciaIzquierda > 60){
        girarIzquierda();
    } else if (distanciaDerecha > 60 && distanciaIzquierda < 60) {
        girarDerecha();
    } else if (distanciaDerecha < 60 && distanciaIzquierda < 60) {
        girar180();
    }
}

float calcularAjuste(){
    distanciaIzquierda = medirIzquierda();
    Serial.print("Distancia izquierda: ");
    Serial.println(distanciaIzquierda);
    delay(200);
    distanciaDerecha = medirDerecha();
    Serial.print("Distancia derecha: ");
    Serial.println(distanciaDerecha);
    
    delay(200);
    distanciaFrontal = medirFrente();
    Serial.print("Distancia frontal: ");
    Serial.println(distanciaFrontal);
    delay(200);

    // Ajuste PID para mantener el auto al centro del pasillo
    ajuste = controlPID(distanciaIzquierda, distanciaDerecha);
    return ajuste;
}
