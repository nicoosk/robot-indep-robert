// Definición de pines para el sensor ultrasónico
const int trigPin = 12;
const int echoPin = 13;

// Variable para almacenar la distancia calculada
long distancia;

void setup() {
  // Inicialización de pines
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Inicialización del monitor serie
  Serial.begin(9600);
}

void loop() {
  // Asegurarse de que el pin TRIG esté en LOW al inicio
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Envío de un pulso TRIG de 10 microsegundos
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Lee el tiempo que el pulso ECHO tarda en regresar
  long duracion = pulseIn(echoPin, HIGH);

  // Cálculo de la distancia en centímetros
  distancia = duracion * 0.034 / 2;

  // Imprimir la distancia en el monitor serie
  Serial.print("Distancia: ");
  Serial.print(distancia);
  Serial.println(" cm");

  // Pequeño retardo antes de la siguiente medición
  delay(500);
}