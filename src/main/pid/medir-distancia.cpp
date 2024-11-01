#include "medir-distancia.h"
#include "../controladores/servo-control/servo-control.h"
#include "../controladores/ultrasonico/sensor-ultrasonico.h"
#include <Arduino.h>

// Variables para el control PID
float errorAnterior = 0;
float sumaError = 0;

// Las constantes del PID
const float Kp = 1.0;  // Constante proporcional
const float Ki = 0.0;  // Constante integral
const float Kd = 0.5;  // Constante derivativa

float medirIzquierda(int trig, int echo){
  mirarIzquierda();
  delay(100);
  return calcularDistancia(trig, echo);
}

float medirDerecha(int trig, int echo){
  mirarDerecha();
  delay(100);
  return calcularDistancia(trig, echo);
}

float medirFrente(int trig, int echo){
  mirarFrente();
  delay(100);
  return calcularDistancia(trig, echo);
}


int controlPID(int trig, int echo) {
  float error = medirIzquierda(trig, echo) - medirDerecha(trig, echo);
  sumaError += error;
  float deltaError = error - errorAnterior;
  errorAnterior = error;

  // Fórmula del control PID
  float ajuste = (Kp * error) + (Ki * sumaError) + (Kd * deltaError);
  return (int)ajuste;
}