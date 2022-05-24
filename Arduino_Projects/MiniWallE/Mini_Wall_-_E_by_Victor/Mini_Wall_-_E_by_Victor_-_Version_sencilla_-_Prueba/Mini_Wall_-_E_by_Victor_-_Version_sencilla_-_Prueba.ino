/*
 * ESTA VERSIÓN PROVEE UN CÓDIGO FUNCIONAL PARA EL CIRCUITO HECHO A MODO DE
 * PROTOTIPO EN EL MINI WALL - E 
 * 
 * THIS IS A BRANCH THAT WILL BE ONLY MERCH WITH THE MASTER WHEN IT'S CONFIRMED... 
*/

#include <Servo.h>
Servo servoMotor;

const int forward_1 = 6; 
const int backward_1 = 7;

/* 
 * ESAS DOS LÍNEAS SON ELIMINADAS PORQUE EN EL PROTOTIPO NO FUNCIONA UNO DE LOS MOTORES... 
*/ 

//const int forward_2 = 8; 
// const int backward_2 = 9; 

int EchoPin = 12;
int TriggerPin = 11;

void setup()
{
  Serial.begin(9600);
  Serial.println("Listo");

  pinMode(forward_1, OUTPUT);
  pinMode(backward_1, OUTPUT); 

  /*
   * ESTAS LÍNEAS SON ELIMINADAS PORQUE NO ESTÁN ADAPTADAS EN EL PROTOTIPO...  
  */

  // pinMode(forward_2, OUTPUT);
  // pinMode(backward_2, OUTPUT);

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
                        // SE INICIAN PRIMERO LOS MOTORES // 
  /*
   * COMIENZA LEYENDO LA DISTANCIA, SI ES MAYOR A 30 EMPEZARÁ A RODAR 
  */ 
  if (sensor() > 30)
  {
    Serial.println("");
    Serial.println("....................");
    Serial.println("");
    Serial.print(" Distancia "); // --> Corregir si da error
    Serial.println(sensor());
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
  else if (sensor() <= 30)
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
  long distancia;
  long tiempo; 

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

  /*
   * ESTAS LÍNEAS SON ELIMINADAS PORQUE NO ESTÁN ADAPTADAS EN EL PROTOTIPO...  
  */ 

  // digitalWrite(backward_2, LOW);
  // digitalWrite(forward_2, HIGH);
}

void motor_apagado()
{
  digitalWrite(backward_1, LOW);
  digitalWrite(forward_1, LOW); 

  /*
   * ESTAS LÍNEAS SON ELIMINADAS PORQUE NO ESTÁN ADAPTADAS EN EL PROTOTIPO...  
  */
 
  // digitalWrite(backward_2, LOW);
  // digitalWrite(forward_2, LOW);
}
