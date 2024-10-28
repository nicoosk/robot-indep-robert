#include "implementaciones/principal.cpp"

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
    avanzarHastaObstaculo();
}