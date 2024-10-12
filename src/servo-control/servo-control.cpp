#include <Arduino.h>
#include "servo-control.h"
#include <Servo.h>

Servo servo;

void inicializarServo(int pin){
    servo.attach(pin);
}

void moverServo(int grados){
    servo.write(grados);
}