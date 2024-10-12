int ena = 3;
int in1 = 4;
int in2 = 2;


void setup() {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  neutro(in1, in2, ena);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);

  nega_posi(in1, in2);
  potenciar(ena);
  delay(2000);
  neutro(in1, in2, ena);
  delayMicroseconds(100);
  posi_nega(in1, in2);
  potenciar(ena);
  neutro(in1, in2, ena);
  delay(2000);

}

void nega_posi(int in1, int in2){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void posi_nega(int in1, int in2){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void neutro(int in1, int in2, int ena){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ena, LOW);
}

void potenciar(int ena){
  analogWrite(ena, 40);
  delay(1000);
  analogWrite(ena, 0);
}