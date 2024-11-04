// principal.h
#ifndef PRINCIPAL_H
#define PRINCIPAL_H

extern int in1;
extern int in2;
extern int ena;
extern int in3;
extern int in4;
extern int enb;
extern int pinServo;
extern int trig;
extern int echo;

bool verificarFrontal();
void avanzar();
float calcularAjuste();

#endif