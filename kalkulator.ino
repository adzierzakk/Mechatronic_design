

void setup() {
  Serial.begin(9600);
}

void loop() {
  float liczba1, liczba2;
  double wynik;
  String znak;
  Serial.println("Podaj pierwsza liczbe");
  while(Serial.available() <= 0) {
    
  }
  liczba1 = float(Serial.readStringUntil('\n').toInt());
  Serial.print("Podales liczbe ");
  Serial.println(liczba1);
  Serial.println("Podaj druga liczbe");
  while(Serial.available() <= 0) {
    
  }
  liczba2 = float(Serial.readStringUntil('\n').toInt());
  Serial.print("Podales liczbe ");
  Serial.println(liczba2);
  Serial.println("Jakie dzialanie chcesz wykonac?");
  Serial.println("Wpisz '+' dla dodawania");
  Serial.println("Wpisz '-' dla odejmowania");
  Serial.println("Wpisz 'x' dla mnozenia");
  Serial.println("Wpisz '/' dla dzielenia.");
while(Serial.available() <= 0) {
    
  }
  znak = Serial.readStringUntil('\n');
  switch (znak[0]){
    case '+':
      Serial.print("Wynik dodawania wynosi ");
      Serial.println(liczba1+liczba2);
    break;

    case '-':
      Serial.print("Wynik odejmowania wynosi ");
      Serial.println(liczba1-liczba2);
    break;

    case 'x':
      Serial.print("Wynik mnozenia wynosi ");
      Serial.println(liczba1*liczba2);
    break;

    case '/':
      if(liczba2==0) {
        Serial.println("Nie wolno dzielic przez 0!");
        break;
      }
      Serial.print("Wynik dzielenia wynosi ");
      wynik=liczba1/liczba2;
      Serial.println(wynik);
    break;

    default:
      Serial.println("Cos poszlo nie tak. Sprobuj jeszcze raz.");
    break;
  }
  delay(5000);
}
