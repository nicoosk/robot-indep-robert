#include <Arduino.h>
#include "sensor-ultrasonico.h"

int TRIG_PIN, ECHO_PIN;

void inicializarUltrasonico(int trig, int echo){
  TRIG_PIN = trig;
  ECHO_PIN = echo;
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

float calcularDistancia(){
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duracion = pulseIn(ECHO_PIN, HIGH);
  float distancia = duracion * 0.034 / 2;
  return distancia;

}
