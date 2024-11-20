#include "../motores/motores.cpp"
#include "../servo-control/servo-control.cpp"
#include "../ultrasonico/sensor-ultrasonico.cpp"
#include "../control-mq/sensor-mq.cpp"
#include <Arduino.h>

class Robot
{
private:
    Motor motorTrasero;
    Motor motorDelantero;
    ServoMotor servoMotor;
    Ultrasonico sensorUltrasonico;
    SensorMQ sensorMQ;

    const int ciclo = 1;
    int contador = 0;

public:
    // Constructor que inicializa los componentes del robot
    Robot(int in1, int in2, int ena, int in3, int in4, int enb, int pinServo, int trig, int echo, int analogMQ)
        : motorTrasero(in1, in2, ena),
          motorDelantero(in3, in4, enb),
          servoMotor(pinServo),
          sensorUltrasonico(trig, echo),
          sensorMQ(analogMQ) {}

    // Métodos de control del robot
    void potenciarDireccion(int OUT){
        analogWrite(OUT, 1);
    }

    void cambiarDireccionDerecha(){
        motorDelantero.positivoNegativo();
        potenciarDireccion(motorDelantero.getEN());
        delay(100);
        motorDelantero.despotenciar(motorDelantero.getEN());
        motorDelantero.despotenciar(motorDelantero.getIN1());
        motorDelantero.despotenciar(motorDelantero.getIN2());
    }

    void cambiarDireccionIzquierda(){
        motorDelantero.negativoPositivo();
        potenciarDireccion(motorDelantero.getEN());
        delay(100);
        motorDelantero.despotenciar(motorDelantero.getEN());
        motorDelantero.despotenciar(motorDelantero.getIN1());
        motorDelantero.despotenciar(motorDelantero.getIN2());
    }

    void mantenerDireccionDerecha(){
        motorDelantero.positivoNegativo();
        potenciarDireccion(motorDelantero.getEN());
        delay(100);
        motorDelantero.despotenciar(motorDelantero.getEN());
    }

    void mantenerDireccionIzquierda(){
        motorDelantero.negativoPositivo();
        potenciarDireccion(motorDelantero.getEN());
        delay(100);
        motorDelantero.despotenciar(motorDelantero.getEN());
    }

    void acelerarMotorTrasero(){
        motorTrasero.positivoNegativo();
        motorTrasero.potenciar();
    }

    void retrocederMotorTrasero(){
        motorTrasero.negativoPositivo();
        motorTrasero.retroceder();
    }

    void detenerse(){
        retrocederMotorTrasero();
        delay(500);
        motorTrasero.despotenciar(motorTrasero.getEN());
    }

    void girarDerecha(){
        // Retrocede girando para cambiar dirección
        cambiarDireccionIzquierda();
        delay(500);
        retrocederMotorTrasero();
        delay(1000);
        motorTrasero.despotenciar(motorTrasero.getEN());
        motorDelantero.despotenciar(motorDelantero.getEN());
        motorDelantero.despotenciar(motorDelantero.getIN1());
        motorDelantero.despotenciar(motorDelantero.getIN2());
        delay(800);

        // Va hacia la derecha
        cambiarDireccionDerecha();
        delay(500);
        acelerarMotorTrasero();
        delay(1000);
        motorTrasero.despotenciar(motorTrasero.getEN());
        motorDelantero.despotenciar(motorDelantero.getEN());
        motorDelantero.despotenciar(motorDelantero.getIN1());
        motorDelantero.despotenciar(motorDelantero.getIN2());
        delay(800);
    }

    void girarIzquierda(){
        // Retrocede girando para cambiar dirección
        cambiarDireccionDerecha();
        delay(500);
        retrocederMotorTrasero();
        delay(1000);
        motorTrasero.despotenciar(motorTrasero.getEN());
        motorDelantero.despotenciar(motorDelantero.getEN());
        motorDelantero.despotenciar(motorDelantero.getIN1());
        motorDelantero.despotenciar(motorDelantero.getIN2());
        delay(800);

        // Va hacia la izquierda
        cambiarDireccionIzquierda();
        delay(500);
        acelerarMotorTrasero();
        delay(1000);
        motorTrasero.despotenciar(motorTrasero.getEN());
        motorDelantero.despotenciar(motorDelantero.getEN());
        motorDelantero.despotenciar(motorDelantero.getIN1());
        motorDelantero.despotenciar(motorDelantero.getIN2());
        delay(800);
    }

    void girar180(){
        girarDerecha();

        contador += 1;
        if (contador == ciclo)
        {
            Serial.print("Contador : ");
            Serial.println(contador);
            Serial.println("Se vuelve a ejecutar para girar en 180°.");
            girar180();
        }
        else if (contador > ciclo)
        {
            Serial.println("Giro completado.");
            Serial.print("Contador : ");
            Serial.println(contador);
            Serial.println("Por lo tanto, estableciendo valor a 0.");
            contador = 0;
        }
    }

    void irAleatorio(){
        randomSeed(analogRead(0));
        int numeroAleatorio = random(0, 2);

        if (numeroAleatorio == 0)
        {
            girarDerecha();
        }
        else if (numeroAleatorio == 1)
        {
            girarIzquierda();
        }
    }

    
    void moverServo(int angulo){
        servoMotor.moverA(angulo);
    }

    long obtenerDistancia(){
        return sensorUltrasonico.obtenerDistancia();
    }

    int leerSensorMQ(){
        return sensorMQ.obtenerLectura();
    }
};