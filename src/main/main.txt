#include "controladores/motores/motores.h"
#include "controladores/motores/motores.cpp"
#include "controladores/servo-control/servo-control.h"
#include "controladores/servo-control/servo-control.cpp"
#include "controladores/ultrasonico/sensor_ultrasonico.h"
#include "controladores/ultrasonico/sensor_ultrasonico.cpp"
#include <Arduino.h>

int in1 = 8;
int in2 = 7;
int ena = 11;

int in3 = 4;
int in4 = 2;
int enb = 3;

int pinServo = 5;

int trig = 12;
int echo = 13;

long distancia;
long duracion;

void setup(){
  inicializarMotorDelantero(in1, in2, ena);
  inicializarMotorTrasero(in3, in4, enb);
  inicializarServo(pinServo);
  // inicializarUltrasonico(trig, echo);

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  neutro(in1, in2, ena);
  neutro(in3, in4, enb);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  // neutro(in1, in2, ena);
  // neutro(in3, in4, enb);

  // testTrasero(in3, in4, enb);
  // delay(1000);
  // testDelantero(in1, in2, ena);
  // delay(1000);

  // neutro(in1, in2, ena);
  // neutro(in3, in4, enb);

  // testServo();

  ver();
  // delay(500);
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

void ver(){
 // Asegurarse de que el pin TRIG esté en LOW al inicio
  digitalWrite(trig, LOW);
  delayMicroseconds(2);

  // Envío de un pulso TRIG de 10 microsegundos
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Lee el tiempo que el pulso ECHO tarda en regresar
  duracion = pulseIn(echo, HIGH);
  Serial.print("Duracion: ");
  Serial.println(duracion);
  // Cálculo de la distancia en centímetros
  distancia = duracion * 0.034 / 2;

  Serial.print("Distancia: ");
  Serial.println(distancia);
  
  // Imprimir la distancia en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Pequeño retardo antes de la siguiente medición
  delay(500);
}