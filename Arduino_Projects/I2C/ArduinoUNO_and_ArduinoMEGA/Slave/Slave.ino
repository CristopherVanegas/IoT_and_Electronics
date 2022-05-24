#include <Wire.h>
#define pushbutton 3 
int val; 

void setup() {
  Wire.begin(5); 
  Serial.begin(9600); 
  Serial.println("Prueba I2C - Dos Arduinos"); 
  Serial.println(" >>> Slave"); 

  pinMode(pushbutton, INPUT); 
} 

void receiveEvent(int howMany) { 
  while(Wire.available()) { 
    int data = Wire.read(); 
    
    if(data == 0) {
      Serial.print(" >>>> No new data for now\n"); 
    } 
    
    else if(data == 1) { 
      Serial.print(" >>>> New data for now\n"); 
      Wire.onRequest(requestEvent);    
    } 
  } 
} 

void requestEvent() { 
  val = digitalRead(pushbutton);
  Wire.write(val);   
} 

void loop() {  
  Wire.onReceive(receiveEvent); 
  delay(50); 
}
