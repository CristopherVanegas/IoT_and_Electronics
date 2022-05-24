int led = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("Hey!");
  pinMode(led, OUTPUT);
  digitalWrite(led, 0);
}

void loop() {
  while (Serial.available() > 0) {
    char reading = Serial.read();

    switch (reading) {
      case '1':
        Serial.println(" 1 ");
        break;

      case '2':
        Serial.println(" 2 "); 
        break; 

      case 'a':
        Serial.println(" a ");
        break;

      case 'b':
        blinkLed();
        break;
    }

  }
}

void blinkLed() {
  int estado = 0;
  int threshold = 0; 
  
  while (threshold < 4) {
    estado = !estado;
    digitalWrite(led, estado); 
    threshold++; 
    delay(500);  
  } 
  Serial.print("Threshold: "); 
  Serial.println(threshold); 
}
