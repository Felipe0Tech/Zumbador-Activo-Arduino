int dt = 200; // Retraso de 200 ms
int potPin = A0; // Pin analógico para el potenciómetro
int buzzPin = 8; // Pin digital para el buzzer
int redPin = 9; // Pin digital para el LED rojo
int yellowPin = 10; // Pin digital para el LED amarillo
int greenPin = 11; // Pin digital para el LED verde

void setup() {
  // Iniciar comunicación serie
  Serial.begin(9600);
  // Configurar los pines como salida
  pinMode(buzzPin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Leer el valor del potenciómetro (0 a 1023)
  int valorPort = analogRead(potPin);
  
  // Mostrar el valor en el monitor serie
  Serial.println(valorPort);
  
  // Comprobar el valor del potenciómetro y controlar los LEDs y el buzzer
  if (valorPort > 1000) {
    digitalWrite(buzzPin, HIGH); // Encender buzzer
    digitalWrite(redPin, HIGH); // Encender LED rojo
    digitalWrite(yellowPin, LOW); // Apagar LED amarillo
    digitalWrite(greenPin, LOW); // Apagar LED verde
  } else if (valorPort >= 500 && valorPort <= 999) {
    digitalWrite(buzzPin, LOW); // Apagar buzzer
    digitalWrite(redPin, LOW); // Apagar LED rojo
    digitalWrite(yellowPin, HIGH); // Encender LED amarillo
    digitalWrite(greenPin, LOW); // Apagar LED verde
  } else if (valorPort < 500) {
    digitalWrite(buzzPin, LOW); // Apagar buzzer
    digitalWrite(redPin, LOW); // Apagar LED rojo
    digitalWrite(yellowPin, LOW); // Apagar LED amarillo
    digitalWrite(greenPin, HIGH); // Encender LED verde
  }
  
  // Retraso para no saturar el monitor serie
  delay(dt);
}