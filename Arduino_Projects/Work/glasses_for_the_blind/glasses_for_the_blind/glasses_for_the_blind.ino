int trigger = 3;
int echo = 2;
int buzzer = 9;

long t;
long distance;
float v = 0.0343;


void setup() {
  Serial.begin(9600);
  Serial.println("Hey!");
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(buzzer, LOW);

}

void loop() {
  HC_SR04();
}

void HC_SR04() {
  digitalWrite(trigger, LOW);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  t = pulseIn(echo, HIGH);
  t = t / 2;

  distance = v * t;

  Serial.print("The distance is: ");
  
  if (distance > 256) {
    distance = 255;
    Serial.println("The distance exceed the limit 255");
  } else {
    Serial.println(distance);
    delay(100);
  }

  alert(distance); 
} 

void alert(int distance) { 
  int t = 500; 
  if (distance < 100) {
    analogWrite(buzzer, 55); 
    delay(t); 
    digitalWrite(buzzer, LOW); 
    delay(t);
  }
}
