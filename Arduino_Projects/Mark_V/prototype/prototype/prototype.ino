#include<Servo.h>
#define LED 5
#define base_transistor 24
Servo servo;

void setup() {
  Serial.begin(9600);
  Serial.println("Ready... ");
  pinMode(LED, OUTPUT);
  pinMode(base_transistor, OUTPUT);
  digitalWrite(base_transistor, 0);
  servo.attach(9);
}

void signal_m() {
  while(Serial.available()) {
    int result = Serial.read();
    switch(result) {
      case '1':
        digitalWrite(LED, 1);
        //servo_on(90);
        servo.write(90);
        //delay(15);
        break;

      case '0':
        digitalWrite(LED, 0);
        //servo_off();
        servo.write(0); 
        //delay(15);
        break;
    }
  }

  lectura();
  delay(15);
}

void lectura() {
  Serial.println(digitalRead(24));
}
void loop() {
  signal_m();
}
