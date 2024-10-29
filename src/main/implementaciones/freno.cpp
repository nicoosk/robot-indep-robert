#include "../controladores/motores/motores.h"
#include "freno.h"
#include <Arduino.h>

void detenerse(int in3, int in4, int enb){
    retrocederMotorTrasero(in3, in4, enb);
    delay(500);
    despotenciar(enb);
}