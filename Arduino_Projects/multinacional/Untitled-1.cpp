/*
La multinacional francesa Flante experta en maquinaria industrial 
te ha contratado para que automatices una máquina cortadora de papel. 
La condición  principal es que el operario de la máquina cuando vaya a realizar 
el corte siempre mantenga las dos manos ocupadas, esta es una regla de 
seguridad industrial para evitar accidentes. El operario debe oprimir los dos 
pulsadores uno con cada mano y la cuchilla cortadora debe bajar y hacer el corte. 
El siguiente montaje simula el control de la máquina, los dos pulsadores (S1 y S2)
y el LED rojo simula la cuchilla cortadora.
*/

int pulsador2=2;
int pulsador3=3;
int led4=4; 
  
void setup()
{
    Serial.begin(9600); 
    Serial.println("READY!");
    pinMode(pulsador2, INPUT);  
    pinMode(pulsador3, INPUT); 
    pinMode(led4,OUTPUT);
}
 
void loop()
{
  if ((digitalRead(pulsador2)==LOW) && (digitalRead(pulsador3)==LOW))
  {
      digitalWrite(led4,HIGH);
  }
  else
  {
      digitalWrite(led4,LOW); 
  } 

  test(); 
}

void test() {
    Serial.println(">>> Into Test Function"); 
    if (digitalRead(pulsador2)==LOW) {
        Serial.println("Pulsador 2 ON"); 
        delay(250); 
    }
    if (digitalRead(pulsador3)==LOW) {
        Serial.println("Pulsador 3 ON"); 
        delay(250); 
    }

    Serial.println(">>> Leaving Test Function"); 
    delay(250); 
} 