/*
 * This code is to try the transistor in the second module for the Servo.
 * Transistor PIN 4
*/

#include <Servo.h>
Servo servo_9;

#define led 5
#define t_base 4

void setup() {
  Serial.begin(9600);
  Serial.println("Hello! \nI'm setting up the IOs!");
  
  pinMode(led, OUTPUT);
  pinMode(t_base, OUTPUT);
  digitalWrite(led, 0);
  digitalWrite(t_base, 0);
  servo_9.attach(9);
  
  Serial.println("Ready!!!");
  digitalWrite(t_base, 1);

}

void loop() {
  l_blink(500);
  servo_9.write(180);
  delay(1000);
  servo_9.write(0);
  delay(1000);
  
}

void l_blink(int time_v) {
  boolean val = false;
  digitalWrite(led, !val);
  digitalWrite(t_base, val);
  servo_9.write(0);
  delay(time_v);
  
  digitalWrite(led, val);
  digitalWrite(t_base, !val);
  servo_9.write(180);
  delay(time_v);  
}
