//int pins[] = {9, 10, 12, 13};


int enb = 5;
int in4= 10;
int in3 = 9;

void setup() {
  Serial.begin(9600);
  // for (int i = 0; i < 5; i++){
  //   pinMode(pins[i], OUTPUT);
  // }

  // for (int i = 0; i < 5; i++){
  //   digitalWrite(pins[i], LOW);
  // }
  
  pinMode(enb, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  analogWrite(enb, 0);
  digitalWrite(in4, LOW);
  digitalWrite(in3, LOW);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);

  testMotor2(in3, in4, enb);
}

void testMotor1(int ENA, int IN1, int IN2){
  Serial.println("Testing motor N°1.");
  delay(3000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  delay(3000);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  delay(3000);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  Serial.println("Testing successfull.");
}

void testMotor2(int IN3, int IN4, int ENB){
  Serial.println("Testing motor N°2.");
  goForward(IN3, IN4);
  accelerate(ENB);
  goReverse(IN3, IN4);
  accelerate(ENB);
  Serial.println("Testing successfull.");
}

void goReverse(int negative, int positive){
  digitalWrite(negative, HIGH);
  digitalWrite(positive, LOW);
}

void goForward(int negative, int positive){
  digitalWrite(negative, LOW);
  digitalWrite(positive, HIGH);   
}

void accelerate(int pin){
  Serial.println("Accelerating...");
  analogWrite(pin, 255);
  delay(2000);
  analogWrite(pin, 0);
  Serial.println("Done.");
  delay(2000);

}

void testingPin(int pin){
  Serial.println("Testing pin: ");
  Serial.println(pin);
  digitalWrite(pin, HIGH);
  Serial.println("Pin mode: ON");
  delay(2000);
  digitalWrite(pin, LOW);
  Serial.println("Pin mode: OFF");
}

