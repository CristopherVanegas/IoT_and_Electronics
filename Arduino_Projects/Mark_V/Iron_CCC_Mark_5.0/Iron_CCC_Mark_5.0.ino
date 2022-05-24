#include <Servo.h>
Servo servo;
Servo servo_gatillo; 

int PULSADOR = 2; 

void setup() {
  Serial.begin(9600);
  Serial.println("Hola!..");
  Serial.println("Tiempo sin verte compañero ;)"); 

  pinMode(PULSADOR, INPUT); 
  servo.attach(7); 
  servo_gatillo.attach(8); 
  
  servo.write(100);             // Apagado 
  servo_gatillo.write(0);       // Apagado 
}

void loop() {
  if(lectura_pulsador() == HIGH) {
    servo_init(); 
  } 

  else if(lectura_pulsador() == LOW) {
    servo_end(); 
  } 
}

void servo_end() { 

  /*
   * Cañon en estado oculto --- "Servo apagado" --- Mira no apuntando...
   */
  
  servo.write(180);
  servo_gatillo.write(0);

}

void servo_init() { 

  /* 
   *  Cañon en estado activo --- " Servo activo " --- Mira apuntando... 
   */
   
  servo.write(100);
  servo_gatillo.write(90);
}

int lectura_pulsador() {

  /*
   * ESTA FUNCIÓN RETORNA EL VALOR QUE TENGA EL PULSADOR EN UN DETERMINADO MOMENTO... 
  */

  int valor = digitalRead(PULSADOR);
  return valor; 
}

void servo_gatillo_up() { 
  
  /*
   * DEFINIR EN QUÉ ANGULO EL SERVO SUBE...
  */

  servo_gatillo.write(90);  
}

void servo_gatillo_down() {
  /*
   * DEFINIR EN QUÉ ANGULO EL SERVO BAJA... 
  */

  servo_gatillo.write(0); 
}
