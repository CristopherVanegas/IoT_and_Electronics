#include <Wire.h>
#define ms_pushbutton 3 
#define led 13 

int requestedSizeVal = 1; 


void setup() {
  Wire.begin(); 
  Serial.begin(9600); 
  Serial.println("Prueba I2C - Dos Arduinos"); 
  Serial.println(" >>>  Master"); 

  pinMode(ms_pushbutton, INPUT); 
  pinMode(led, OUTPUT); 
  digitalWrite(led, LOW); 
}

void loop() { 
  /////////// master sends a signal to slave /////////// 
  if (digitalRead(ms_pushbutton) == 0) {
    Wire.beginTransmission(5); 
    Wire.write(0); 
    Wire.endTransmission(); 

    delay(100); 
  }
    
  /////////// only do this if the 'ms_pushbutton' is pressed ///////////
  else if (digitalRead(ms_pushbutton) == 1) { 
    /////////// master sends a signal to slave /////////// 
    Wire.beginTransmission(5); 
    Wire.write(1); 
    Wire.endTransmission(); 
      
    /////////// master request 'val' from slave /////////// 
    Wire.requestFrom(5, requestedSizeVal); 

    /////////// master wait for the answer /////////// 
    while(Wire.available()) { 
      int data = Wire.read(); 
      digitalWrite(led, data); 
    }
  } 
  
  delay(50); 
} 
