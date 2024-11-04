#include "medir-distancia.h"
#include "../controladores/servo-control/servo-control.h"
#include "../controladores/ultrasonico/sensor-ultrasonico.h"
#include <Arduino.h>

// Variables para el control PID
float errorAnterior = 0;
float sumaError = 0;

// Las constantes del PID
const float Kp = 100.0;  // Constante proporcional
const float Ki = 50.0;  // Constante integral
const float Kd = 3.0;  // Constante derivativa

float medirIzquierda(){
  mirarIzquierda();
  delay(300);
  return calcularDistancia();
}

float medirDerecha(){
  mirarDerecha();
  delay(300);
  return calcularDistancia();
}

float medirFrente(){
  mirarFrente();
  delay(300);
  return calcularDistancia();
}


float controlPID(int distanciaIzquierda, int distanciaDerecha) {
  float error = distanciaIzquierda - distanciaDerecha;
  sumaError += error;
  float deltaError = error - errorAnterior;
  errorAnterior = error;

  // Fórmula del control PID
  float ajuste = (Kp * error) + (Ki * sumaError) + (Kd * deltaError);

  return ajuste;
}