// main.ino
#include "cerebro/principal.h"
#include "cerebro/principal.cpp"

int in1 = 8;
int in2 = 7;
int ena = 11;
int in3 = 4;
int in4 = 2;
int enb = 3;
int pinServo = 5;
int trig = 12;
int echo = 13;

// control
bool hayObstaculoFrontal = false;
bool irDerecha = false;

void setup() {
    Serial.begin(9600);
    inicializarMotorDelantero(in1, in2, ena);
    inicializarMotorTrasero(in3, in4, enb);
    inicializarServo(pinServo);
    inicializarUltrasonico(trig, echo);

}

void loop() {
  avanzar();
  verificarFrontal();
//   prueba();
}

void prueba(){
  acelerarMotorTrasero();
  delay(500);
  despotenciar(enb);
  delay(500);
  retrocederMotorTrasero();
  delay(500);
  despotenciar(enb);
  delay(500);

  cambiarDireccionDerecha();
  delay(500);
  cambiarDireccionIzquierda();
  delay(500);

  mirarDerecha();
  delay(500);
  mirarIzquierda();
  delay(500);
  mirarFrente();
  delay(500);

  float distancia = calcularDistancia();
  Serial.print("Distancia: ");
  Serial.println(distancia);
}