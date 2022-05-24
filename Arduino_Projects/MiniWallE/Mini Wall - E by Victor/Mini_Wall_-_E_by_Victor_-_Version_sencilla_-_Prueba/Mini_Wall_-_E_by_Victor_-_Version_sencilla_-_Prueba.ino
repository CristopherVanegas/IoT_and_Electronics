#include <Servo.h>
Servo servoMotor;

const int forward_1 = 6; 
const int backward_1 = 7;
const int forward_2 = 8; 
const int backward_2 = 9;

int EchoPin = 12;
int TriggerPin = 11;

long distancia;
long tiempo;

void setup()
{
  Serial.begin(9600);
  Serial.println("Listo");

  pinMode(forward_1, OUTPUT);
  pinMode(backward_1, OUTPUT);
  pinMode(forward_2, OUTPUT);
  pinMode(backward_2, OUTPUT);

  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT); 
  
  digitalWrite(TriggerPin, LOW);

  servoMotor.attach(10);
  servoMotor.write(0);
}

void loop()
{
  condicion();
}

void condicion()
{ // Motor

  /*
   * COMIENZA LEYENDO LA DISTANCIA, SI ES MAYOR A 30 EMPEZARÁ A RODAR 
  */ 
  if (sensor() > 30)
  {
    Serial.println("");
    Serial.println("....................");
    Serial.println("");
    Serial.print(" Distancia "); // --> Corregir si da error
    Serial.println(distancia);
    Serial.println(" Motores adelante ");  
    Serial.println("");
    Serial.println("....................");
    Serial.println("");
    delay(30);
    
    motor_adelante();
  }

  /* 
   * SI ES MENOR IGUAL A 30 EJECUTARÁ OTRAS ACCIONES COMO EL RADAR 
   * PARA DECIDIR EN QUÉ ANGULO MOVERSE... 
  */ 
  else if (distancia <= 30)
  {
    motor_apagado();

    for (int i = 0; i < 181; i++)
    {
      servoMotor.write(i);
      
      //sensor();
      Serial.println("");
      Serial.println("....................");
      Serial.println("");
      Serial.print(" Distancia "); // --> Corregir si da error
      Serial.println(sensor()); 
      Serial.println(" Motores Apagados ");
      Serial.println("");
      Serial.println("....................");
      Serial.println("");

      
      //delay(10); 
      
      if (sensor() > 30) // --> 31
      {
        /*
         * AQUÍ NO SE HACE MÁS QUE ROMPER EL CICLO O BUCLE PARA QUE REGRESE AL 
         * CONDICIONAL QUE EVALÚA LA DISTANCIA Y DA LA ORDEN PARA RODAR ADELANTE...
        */
        break;
      }
    }
  }
}

int sensor()
{
  digitalWrite(TriggerPin, LOW);
  digitalWrite(TriggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  tiempo = (pulseIn(EchoPin, HIGH) / 2);
  distancia = int(tiempo * 0.0343);

  Serial.print("Distancia: ");
  Serial.println(distancia); 
  
  return distancia; 
}

void motor_adelante()
{
  digitalWrite(backward_1, LOW);
  digitalWrite(forward_1, HIGH);
  digitalWrite(backward_2, LOW);
  digitalWrite(forward_2, HIGH);
}

void motor_apagado()
{
  digitalWrite(backward_1, LOW);
  digitalWrite(forward_1, LOW);
  digitalWrite(backward_2, LOW);
  digitalWrite(forward_2, LOW);
}



