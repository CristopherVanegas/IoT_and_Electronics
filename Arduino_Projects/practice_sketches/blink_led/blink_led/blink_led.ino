int led = 13; 

void setup() {
  pinMode(led, OUTPUT); 
  digitalWrite(led, LOW); 
}

void loop() {
  digitalWrite(led, HIGH); 
  delay(2000);
  digitalWrite(led, LOW); 
  delay(2000); 

}
