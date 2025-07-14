#include <Servo.h> //Librería para servomotores

Servo Servo_1;  //Nombre o referencia del servomotor a controlar
char Dato;  //Resive cada uno de los números que conforman el ángulo
String arreglo ="";  //Concatena los caracteres que recibe "Dato"
int Angulo = 0; //Variable que contendrá el ángulo de gito del servomotor

void setup() {
  Servo_1.attach(10);  //Pin de señal PWM a servomotor 
  Serial.begin(9600);  //Velocidad de comunicación
}

void loop() {  //Inicio del programa
  if(Serial.available()>0)  //Verifica disponibilidad del puerto
  {
    Dato = Serial.read();
    if( Dato != ',')
    {
      arreglo+= Dato;
    }
    else
    {
      Angulo = arreglo.toInt();
      arreglo = "";
    }
  }
  Servo_1.write(360-Angulo);
  delay(1);
}
