#include <Servo.h>
#define pushbutton 3
#define t_base 4

Servo servo; 
//short value = 0;

void setup() {
    pinMode(pushbutton, INPUT); 
    pinMode(t_base, OUTPUT);
    digitalWrite(t_base, 0);
    servo.attach(5);
}

void look() {
    servo.write(0);
    if(digitalRead(pushbutton) == HIGH){
        digitalWrite(t_base, 1); 
        servo.write(180);
    }
}