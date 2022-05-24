#include <Wire.h> 
#include <Servo.h> 

Servo servo; 
const int ledPin = 13;  

void setup() {
  // Join I2C bus as slave with address 8 
  Wire.begin(0x8); 

  // Call ReceiveEvent when data received 
  Wire.onReceive(receiveEvent); 

  // setup pin 13 as output and turn LED off 
  pinMode(ledPin, OUTPUT); 
  digitalWrite(ledPin, LOW); 

  // Servo attached to pin 7 
  servo.attach(7); 
  
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read(); 
    digitalWrite(ledPin, c); 

    if (c == 1) {
      servo.write(180);
      
    } 

    else if (c == 0) {
      servo.write(0);
    }
  }
}

void loop() {
  delay(100);
}
