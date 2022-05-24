#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo servo ;

int L_RED = 2;
int L_BLUE = 3;
int L_GREEN = 4;
int LEDs[4] = {L_RED, L_BLUE, L_GREEN};

int tiempo_parpadeo = 1000;
int tiempo = 5; 
int tiempo_servo = 500; 

String nombre = "Cristopher Vanegas";

void setup() {
  Serial.begin(9600);
  Serial.println("Autor: " + nombre);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(1, 1);
  lcd.print("Estoy listo ;)");

  //servo.attach(10);

  for (int i = 2; i <= 6; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // parpadeo();
  // fade();
  // delay(100);
  mov_servo();
}

void parpadeo() {
  for (int x = 0; x <= 2; x++) {
    lcd.clear();
    if (x == 0) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ON = Rojo");
      digitalWrite(LEDs[x], HIGH);
      delay(tiempo_parpadeo);
      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("OFF = Rojo");
      digitalWrite(LEDs[x], LOW);
      delay(tiempo_parpadeo);
    }

    if (x == 1) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ON = Blue");
      digitalWrite(LEDs[x], HIGH);
      delay(tiempo_parpadeo);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("OFF = Blue");
      digitalWrite(LEDs[x], LOW);
      delay(tiempo_parpadeo);
    }

    if (x == 2) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("ON = Green");
      digitalWrite(LEDs[x], HIGH);
      delay(tiempo_parpadeo);

      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("OFF = Green");
      digitalWrite(LEDs[x], LOW);
      delay(tiempo_parpadeo);
    }
  }
}

void fade() {
  for (int x = 0; x <= 2; x++) {
    for (int i = 0; i <= 255; i++) {
      analogWrite(LEDs[x], i);
      delay(tiempo);
    }

    for (int i = 255; i >= 0; i--) {
      analogWrite(LEDs[x], i);
      delay(tiempo);
    }
  }
}

void obtener_pin_servo() {

  for (int x = 5; x < 13; x++) {
    servo.attach(x);
    Serial.println(x);

    for (int i = 0; i < 181; i++) {
      servo.write(i);
      delay(15);
    }
    delay(100);
  }
}

void mov_servo() {
  servo.attach(8); 
  servo.write(0); 
  delay(tiempo_servo);

  servo.write(90);
  delay(tiempo_servo);

  servo.write(180);
  delay(tiempo_servo);
}

// random(0, 255)


