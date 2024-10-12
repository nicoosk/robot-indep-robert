#ifndef MOTORES_H
#define MOTORES_H

void inicializarMotorTrasero(int IN1, int IN2, int ENA);
void inicializarMotorDelantero(int IN3, int IN4, int ENB);
void positivoNegativo(int PIN1, int PIN2);
void negativoPositivo(int PIN1, int PIN2);
void neutro(int IN1, int IN2, int IN3, int IN4, int ENA, int ENB);
void potenciar(int INPUT);
void despotenciar(int INPUT);

#endif