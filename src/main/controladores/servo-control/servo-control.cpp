#include <Servo.h>
#include <Arduino.h>

class ServoMotor {
private:
    Servo servo;
    int pin;

public:
    // Constructor para inicializar el pin del servo
    ServoMotor(int servoPin) {
        pin = servoPin;
        servo.attach(pin);
    }

    // Método para mover el servo a un ángulo específico
    void moverA(int angulo) {
        servo.write(angulo);
    }

    // Método para desactivar el servo si es necesario
    void desactivar() {
        servo.detach();
    }
};