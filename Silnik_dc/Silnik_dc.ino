#include <Stepper.h>
#define ILOSC_KROKOW 32
  
Stepper Silnik(ILOSC_KROKOW,8,9,10,11);
int n=0;
int buttonstate =0;

void setup() {
  Serial.begin(9600);
pinMode(7,INPUT_PULLUP);  //Przysick 1
pinMode(6,INPUT_PULLUP);  // Przycisk 2
pinMode(5,INPUT_PULLUP);  // start
pinMode(4,OUTPUT);
digitalWrite(4,LOW);
}

void loop() {
  Silnik.setSpeed(500);         // ustawienie prędkości obrotu
  buttonstate=digitalRead(5);   

if(buttonstate==LOW){           // zliczanie ilości załączeń
  delay(20);
  n=n+1;
} 

while (digitalRead(5) == LOW){     //wlaczenie silnika
    digitalWrite(4,HIGH);          //dioda sygnalizuja wlaczenie
    digitalWrite(5,LOW);
    
  if(digitalRead(6) == LOW){       //krecenie w prawo
    Silnik.step(128);
  }
  if(digitalRead(7) == LOW){       //krecenie w lewo
    Silnik.step(-128);
  }
  else{
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
  }
}

Serial.println(n);
}
