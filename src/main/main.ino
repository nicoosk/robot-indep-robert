#include "../controladores/motores/motores.h"
#include "../controladores/motores/motores.cpp"
#include "../controladores/servo-control/servo-control.h"
#include "../controladores/servo-control/servo-control.cpp"
#include <Arduino.h>

int in1 = 8;
int in2 = 7;
int ena = 11;

int in3 = 4;
int in4 = 2;
int enb = 3;

int pinServo = 5;

void setup(){
  inicializarMotorDelantero(in1, in2, ena);
  inicializarMotorTrasero(in3, in4, enb);
  inicializarServo(pinServo);
  neutro(in1, in2, ena);
  neutro(in3, in4, enb);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop(){
  neutro(in1, in2, ena);
  neutro(in3, in4, enb);

  testTrasero(in3, in4, enb);
  delay(1000);
  testDelantero(in1, in2, ena);
  delay(1000);

  neutro(in1, in2, ena);
  neutro(in3, in4, enb);

  testServo();
  delay(1000);
}

void testTrasero(int p1, int p2, int out){
  digitalWrite(LED_BUILTIN, HIGH);
  acelerarMotorTrasero(p1, p2, out);
  delay(1000);
  despotenciar(out);
  delay(2000);

  retrocederMotorTrasero(p1, p2, out);
  delay(1000);
  despotenciar(out);

  neutro(p1, p2, out);
  digitalWrite(LED_BUILTIN, LOW);
}

void testDelantero(int p1, int p2, int out){
  digitalWrite(LED_BUILTIN, HIGH);
  
  cambiarDireccionDerecha(p1, p2);
  potenciar(out);
  delay(100);
  despotenciar(out);
  delay(1000);

  cambiarDireccionIzquierda(p1, p2);
  potenciar(out);
  delay(100);
  despotenciar(out);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
}

void testServo(){
  digitalWrite(LED_BUILTIN, HIGH);
  
  mirarDerecha();
  delay(1000);
  mirarIzquierda();
  delay(1000);
  mirarFrente();

  digitalWrite(LED_BUILTIN, LOW);
}