#include "../controladores/motores/motores.h"
#include "girar.h"
#include <Arduino.h>

extern int in1;
extern int in2;
extern int ena;
extern int in3;
extern int in4;
extern int enb;
extern int pinServo;
extern int trig;
extern int echo;

void girarDerecha(int in1, int in2, int ena, int in3, int in4, int enb){
    // Retrocede girando para cambiar dirección
    cambiarDireccionIzquierda(in1, in2, ena);
    retrocederMotorTrasero(in3, in4, enb);
    delay(500);
    despotenciar(enb);
    delay(500);

    // Va hacia la derecha
    cambiarDireccionDerecha(in1, in2, ena);
    acelerarMotorTrasero(in3, in4, enb);
    delay(500);
    despotenciar(enb);
    delay(500);
}

void girarIzquierda(int in1, int in2, int ena, int in3, int in4, int enb) {
    // Retrocede girando para cambiar dirección
    cambiarDireccionDerecha(in1, in2, ena);
    retrocederMotorTrasero(in3, in4, enb);
    delay(500);
    despotenciar(enb);
    delay(500);

    // Va hacia la izquierda
    cambiarDireccionIzquierda(in1, in2, ena);
    acelerarMotorTrasero(in3, in4, enb);
    delay(500);
    despotenciar(enb);
    delay(500);
}

void irAleatorio(int in1, int in2, int ena, int in3, int in4, int enb){
    randomSeed(analogRead(0)); // Añade esto en `setup()`
    // Generar un número aleatorio que sea 0 o 1
    int numeroAleatorio = random(0, 2); // Genera un número entre 0 (inclusive) y 2 (exclusive)

    if (numeroAleatorio == 0){
        girarDerecha(in1, in2, ena, in3, in4, enb);
    } else if (numeroAleatorio == 1){
        girarIzquierda(in1, in2, ena, in3, in4, enb);
    }
}