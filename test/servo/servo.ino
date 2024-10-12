#include <Servo.h>  

int servo_pin = 9;
Servo servo;  

void setup() {
  servo.attach(servo_pin);  
}

void loop() {
  servo.write(0);    
  delay(1000);         
 
  servo.write(90);   
  delay(1000);        
  servo.write(180);  
  delay(1000);   
}