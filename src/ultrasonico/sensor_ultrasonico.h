#ifndef SENSOR_ULTRASONICO_H
#define SENSOR_ULTRASONICO_H

void inicializarUltrasonico(int trig, unsigned long echo);
void estadoInicial(int trig, unsigned long echo);
void enviarPulso(int trig);
float calcularDistancia(unsigned long echo);

#endif