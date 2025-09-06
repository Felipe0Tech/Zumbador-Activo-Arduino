
# Zumbador Activo con Arduino

Un zumbador activo con arduino y 3 leds, uno rojo otro amarillo y otro verde, también  un potenciómetro.La idea es que cuando el potenciómetro llega 1000 se enciende el led rojo y pita el zumbador activo.

![Static Badge](https://img.shields.io/badge/F%C3%A1cil-Arduino-blue)

## Información detallada
En el proyecto se necesita: 1 led rojo, 1 led amarillo, 1led verde, 3 resistencias de 220 Ω, un Arduino uno o Nano, un  potenciómetro, una protoboard y cables.


## En que consiste

- 3 leds que se enciende sugún el potenciómetro tenga un valor u otro

- Si el potenciómetro llega a mil pita

-Si está entre 999 y 500 el led amarillo se enciende pero el zumbador deja de pitar

-Si está en menos de 499 se enciende el led verde

##### El potenciómetro llega de 0 a 1024 sugún lo gires
<img src="https://imgs.search.brave.com/PfjO1pN9aH7QRsy-cDRt9IMZ_epd_vl_MAk5Rs75BOQ/rs:fit:860:0:0:0/g:ce/aHR0cHM6Ly91cGxv/YWQud2lraW1lZGlh/Lm9yZy93aWtpcGVk/aWEvY29tbW9ucy9i/L2I1L1BvdGVudGlv/bWV0ZXIuanBn" widht= "200" height= "150">

## Conexión

#### Conexión de alimentación
El Arduino Uno alimenta el protoboard:

El cable rojo conecta el pin de 5V del Arduino con la línea de alimentación positiva (+) del protoboard.

El cable negro conecta el pin de GND del Arduino con la línea de alimentación negativa (-) del protoboard.
Conexión de componentes
Los siguientes componentes están conectados al Arduino y al protoboard:

#### Zumbador (Buzzer):

El pin positivo (+) del zumbador está conectado al pin digital 8 del Arduino mediante un cable amarillo.

El pin negativo (-) del zumbador está conectado a la línea de tierra negativa (-) del protoboard.

#### LEDs (diodos emisores de luz):

LED rojo: El ánodo (la pata larga) está conectado al pin digital 10 del Arduino a través de un cable azul claro. El cátodo (la pata corta) se conecta a la línea de tierra negativa (-) del protoboard a través de una resistencia.

LED amarillo: El ánodo está conectado al pin digital 9 del Arduino a través de un cable marrón. El cátodo se conecta a la línea de tierra negativa (-) del protoboard a través de una resistencia.

LED verde: El ánodo está conectado al pin digital 7 del Arduino a través de un cable rosa. El cátodo se conecta a la línea de tierra negativa (-) del protoboard a través de una resistencia.

#### Potenciómetro:

El pin del extremo izquierdo está conectado a la línea de alimentación positiva (+) del protoboard.

El pin del extremo derecho está conectado a la línea de tierra negativa (-) del protoboard.

El pin central (el pin de señal) está conectado al pin analógico A5 del Arduino a través de un cable púrpura.


<img src="https://i.imgur.com/JfypFuZ.png" widht= "200" height= "150">


## Código
Puedes descargarlo<a href="https://drive.google.com/file/d/1kcB8YXb6BuCgXnxCgHKuIih2Ee5wUlQX/view?usp=sharing">aquí</a>


El código del proyecto es este:

```bash
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
```
## Cosas que has aprendido

Conectar el zumbador, conectar leds y como funciona un potenciómetro

## Autor

- [@Felipe Tech](https://github.com/Felipe0Tech)




 

