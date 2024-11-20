#include "controladores/robot/robot.cpp"
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
int analogMQ = A0;

Robot robert(in1, in2, ena, in3, in4, enb, pinServo, trig, echo, analogMQ);

void setup() {

}

void loop() {

}