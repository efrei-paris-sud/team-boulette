const int L1 = 2; // broche 2 du micro-contrôleur se nomme maintenant : L1
const int buzzer = 3;
const int finger = 4;
void setup() //fonction d'initialisation de la carte

{
  //contenu de l'initialisation
  pinMode(L1, OUTPUT); //L1 est une broche de sortie
  pinMode (buzzer, OUTPUT);
  pinMode (finger, INPUT);
  Serial.begin(9600);
}
void loop() //fonction principale, elle se répète (s’exécute) à l'infini
{
  Alarm();
  int retard= Snooze();
  delay(84570000-retard);
}



int Snooze() {
  int i = 0, j = 0;
  int retard = 0;
  bool touched = 0;
  for (j = 0; j < 3; j++) {
    for (i = 0; i < 15; i++) {
      if (digitalRead(finger) == HIGH) {
        Serial.println("Sensor is touched");
        touched = 1;
      }
      else {

      }
      delay(2000);
    }
    if (!touched) {
      Alarm();
      retard = retard+ 600*30; // retard du au temps de fonctionnement de l'alarme
    }
    Serial.println(j);
  }
  return retard;
}

void Alarm () {
  int i = 0;
  for (i = 0; i < 5; i++) {
    digitalWrite(L1, HIGH);//light L1
    tone(buzzer, 100); //turn on buzzer
    delay(500); // await 0,5 second
    digitalWrite(L1, LOW); // turn off L1
    noTone(buzzer);//turn off buzzer
    delay(500); // wait 0.5 second
  }
}
