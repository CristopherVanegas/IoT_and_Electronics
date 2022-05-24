#include <Servo.h>


Servo servoMotor;
const int EchoPin = 11;
const int TriggerPin = 12;
float distancia;
long tiempo;
const int forward_1 = 5;
const int backward_1 = 6;
const int forward_2 = 10;
const int backward_2 = 9;

void setup() {


  Serial.begin(9600);
  Serial.println( "Listo" );

  servoMotor.attach(3);
  pinMode(forward_1, OUTPUT);
  pinMode(backward_1, OUTPUT);
  pinMode(forward_2, OUTPUT);
  pinMode(backward_2, OUTPUT);


  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);

  digitalWrite(TriggerPin, LOW);
  servoMotor.write(120);
}



void loop()  {
motor_adelante();

  sensor();

  if  ( distancia < 30 ) {
    digitalWrite(backward_1, LOW);
    digitalWrite(forward_1, LOW);
    digitalWrite(backward_2, LOW);
    digitalWrite(forward_2, LOW);
    delay(1000);

    servoMotor.write(30);
    delay(2000);
    sensor();
    
    if (distancia > 30) {
      Derecha();
      motor_adelante();
      
    } else if (distancia <= 30) {
    servoMotor.write(180);
    sensor();

    if (distancia > 30) {
      Izquierda();
    
      motor_adelante();
      

  }else if(distancia < 30){
    Fin(); 
  }
  }
  } else if(distancia > 30){
  motor_adelante();
}
}


void Fin(){
      digitalWrite(backward_1, LOW);
    digitalWrite(forward_1, LOW);
    digitalWrite(backward_2, LOW);
    digitalWrite(forward_2, LOW);
    delay(1000);

}
  void sensor() {
    digitalWrite(TriggerPin, LOW);
    digitalWrite(TriggerPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(TriggerPin, LOW);

    tiempo = (pulseIn(EchoPin, HIGH) / 2);
    distancia = float(tiempo * 0.0343);

    Serial.print("Distancia: ");
    Serial.println(distancia);
    return;
  }





  void motor_adelante(){
    servoMotor.write(120);
    digitalWrite(backward_1, LOW);
    digitalWrite(forward_1, HIGH);
    digitalWrite(backward_2, HIGH);
    digitalWrite(forward_2, LOW);
    sensor();
    delay(500);

    if (distancia < 30) {
      loop();
    }
  }


  void Derecha() {

    digitalWrite(backward_1, LOW);
    digitalWrite(forward_1, HIGH);
    digitalWrite(backward_2, LOW);
    digitalWrite(forward_2, HIGH);
    sensor();
    delay(800);
    loop();
  }

  void Izquierda() {
    digitalWrite(backward_1, HIGH);
    digitalWrite(forward_1, LOW);
    digitalWrite(backward_2, HIGH);
    digitalWrite(forward_2, LOW);
    sensor();
    delay(800);
    loop();
  }
