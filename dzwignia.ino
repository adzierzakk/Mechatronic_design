#include <Servo.h>
int okres=100;
float uchyb, wzmocnienie=2, odleglosc, zadana=100, sterujacy, zapisana_pozycja_serwomechanizmu=0;
Servo serwomechanizm;
void setup() {
  // put your setup code here, to run once:
  serwomechanizm.attach(9);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  odleglosc=0.01723 * readUltrasonicDistance(7,7);
  uchyb=zadana-odleglosc;
  sterujacy=uchyb*wzmocnienie;
  zapisana_pozycja_serwomechanizmu+=sterujacy;
  serwomechanizm.write(zapisana_pozycja_serwomechanizmu);
  delay(okres);
}

long readUltrasonicDistance (int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
  
}
