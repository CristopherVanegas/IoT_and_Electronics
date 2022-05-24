/*
 * COMMENT SECTION *

  This code is for my new Mark 5.1 
  The specs are:
                    > Arduino NANO.
                    > Just work in one arm.
                    > One servo for the shooter. 
                    > Two servos for the security. 
                    
                    > Details for lightning. 
*/

#include <Servo.h>
Servo servo_shooter;
Servo servo_security_1;
Servo servo_security_2; 

#define lights 5
#define pushButton 3


void setup() {
  Serial.begin(9600);
  Serial.println(">>> Setting up the IOs ");

  do {
    Serial.print(".");
    if(setting_up() == 1) {
      Serial.println("");
    }
  } while(setting_up() != 1); 
  
  Serial.println(">>> System Ready! "); 
}

int setting_up() {
  servo_shooter.attach(9);      // PWM
  servo_security_1.attach(10);  // PWM
  servo_security_2.attach(11);  // PWM 
  servo_shooter.write(0); 
  servo_security_1.write(0); 
  servo_security_2.write(0); 
  
  pinMode(lights, OUTPUT); 
  digitalWrite(lights, 0); 
  pinMode(pushButton, INPUT); 
  
  return 1;
}

void security() {
  short int value = 0;
  if(digitalRead(pushButton) == HIGH) {
    value += 1;
    if(value == 2) {
      servo_security_1.write(180);
      servo_security_2.write(180);
      Serial.println(">>> Security Opened!"); 
    } else {
      servo_security_1.write(0); 
      servo_security_2.write(0); 
      Serial.println(">>> Security Closed!"); 
    }
  }
}

void shotter_function() {
  if(digitalRead(pushButton) == HIGH) {
    servo_shooter.write(180); // check the exact degree to show the shotter. 
    Serial.println(">>> Shoot!"); 
    
  } else {  
    servo_shooter.write(0); // check the exact degree to hide the shotter. 
    Serial.println(">>> Hide!"); 
    
  }
}

void loop() {
  shotter_function();
  security(); 
  
}

