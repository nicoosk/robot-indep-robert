#ifndef SENSOR_ULTRASONICO_H
#define SENSOR_ULTRASONICO_H

void inicializarUltrasonico(int trig, int echo);
void estadoInicial(int trig, int echo);
void enviarPulso(int trig);
float calcularDistancia(int echo);

#endif