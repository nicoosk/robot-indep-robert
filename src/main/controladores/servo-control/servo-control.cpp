#include <Arduino.h>
#include "servo-control.h"
#include <Servo.h>

Servo servo;

void inicializarServo(int pin){
    servo.attach(pin);
    mirarFrente();
}

void mirarIzquierda(){
    servo.write(170);
}

void mirarFrente(){
    servo.write(80);
}

void mirarDerecha(){
    servo.write(1);
}