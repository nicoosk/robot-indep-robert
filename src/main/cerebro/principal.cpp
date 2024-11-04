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


void avanzar() {
    // acelerarMotorTrasero();
    ajuste = calcularAjuste();

    Serial.print("Ajuste: ");
    Serial.println(ajuste);
    delay(2000);
    if (ajuste > 0){
        cambiarDireccionDerecha();
    } else if (ajuste < 0){
        cambiarDireccionIzquierda();
    } 
}

bool verificarFrontal(){
    if (distanciaFrontal < 10){
        // detenerse();
        delay(1000);
    }
    
}

float calcularAjuste(){

    Serial.println("Midiendo lado izquierdo...");
    delay(1000);
    distanciaIzquierda = medirIzquierda();
    Serial.print("Distancia izquierda: ");
    Serial.println(distanciaIzquierda);
    delay(500);
    Serial.println("Midiendo lado derecho...");
    delay(1000);
    distanciaDerecha = medirDerecha();
    Serial.print("Distancia derecha: ");
    Serial.println(distanciaDerecha);
    delay(500);
    Serial.println("Midiendo al frente...");
    delay(1000);
    distanciaFrontal = medirFrente();
    Serial.print("Distancia frontal: ");
    Serial.println(distanciaFrontal);
    delay(500);

    // Ajuste PID para mantener el auto al centro del pasillo
    ajuste = controlPID(distanciaIzquierda, distanciaDerecha);
    return ajuste;
}
