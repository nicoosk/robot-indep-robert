int ena = 9;
int in1 = 8;
int in2 = 7;  // Cambia a otro pin

void setup() {
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  neutro();
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  delay(1000);

  nega_posi();
  potenciar();
  delay(1000);
  neutro();
  delay(1000);

  posi_nega();
  potenciar();
  delay(1000);
  neutro();
  delay(1000);
}

void nega_posi() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
}

void posi_nega() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void neutro() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(ena, LOW);
}

void potenciar() {
  analogWrite(ena, 255);
  delay(100);
  analogWrite(ena, 0);
}
