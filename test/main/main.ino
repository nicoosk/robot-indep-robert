int trigPin = 12;
int echoPin = 13;

void setup(){
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop(){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Medir el tiempo que tarda en regresar el pulso
    long duracion = pulseIn(echoPin, HIGH);

    // Calcular la distancia en centímetros
    long distancia = duracion * 0.034 / 2;

    // Mostrar distancia en el monitor serial
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");

    delay(500); 
}