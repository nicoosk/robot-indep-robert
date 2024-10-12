#ifndef MOTORES_H
#define MOTORES_H

void inicializarMotorTrasero(int IN1, int IN2, int ENA);
void inicializarMotorDelantero(int IN3, int IN4, int ENB);
void positivoNegativo(int P1, int P2);
void negativoPositivo(int P1, int P2);
void neutro(int P1, int P2, int OUT);
void potenciar(int OUT);
void despotenciar(int OUT);

void cambiarDireccionDerecha(int P1, int P2);
void cambiarDireccionIzquierda(int P1, int P2);
void acelerarMotorTrasero(int P1, int P2, int OUT);
void retrocederMotorTrasero(int P1, int P2, int OUT);

#endif