// Broche de la LED

const int Led_1 = A2
const int Led_2 = A3;
const int Led_3 = A4;
const int Led_4 = A5;
const int Led_5 = 2;
const int Led_6 = 3;
const int Led_7 = 4;
const int Led_8 = 5;
const int Led_9 = 6;
const int Led_10 = 7;
const int Led_11 = 8;
const int Led_12 = 9;
const int Led_13 = 10;
const int Led_14 = 11;

int detecteur_haut = A1;
int detecteur_bas = A0;

int detecteur_haut_state = LOW;
int detecteur_bas_state = LOW;

const int temps_delai_marche = 250;
const int temps_desactivation = 7000;
const int temps_toutes_marches_allumees = 30000;

const int Liste_des_leds[] = {Led_1, Led_2, Led_3, Led_4, Led_5, Led_6, Led_7, Led_8, Led_9, Led_10, Led_11, Led_12, Led_13, Led_14};
const int nombre_de_leds = sizeof(Liste_des_leds) / sizeof(Liste_des_leds[0]);

void setup() {

  pinMode(detecteur_haut, INPUT);

  pinMode(detecteur_bas, INPUT);

  //Serial.begin(9600);

  for (int i = 0; i < nombre_de_leds; i++) {

    pinMode(Liste_des_leds[i], OUTPUT);

  }

}

void loop() {
  detecteur_bas_state = digitalRead(detecteur_bas);
  delay(100);
  detecteur_haut_state = digitalRead(detecteur_haut);
  delay(100);

  // Affichez l'état des capteurs PIR sur le moniteur série
  // Serial.print("Detecteur haut : ");
  // Serial.println(detecteur_haut_state);
  // Serial.print("Detecteur bas : ");
  // Serial.println(detecteur_bas_state);

  // Eteindre les LEDs

  for (int i = 0; i < nombre_de_leds; i++) {
    digitalWrite(Liste_des_leds[i], HIGH);
  }

  if (detecteur_bas_state == HIGH) {
    Serial.print("Detecteur bas Activé ");
    // Allume les LED une par une avec un délai
    for (int i = 0; i < nombre_de_leds; i++) {
      digitalWrite(Liste_des_leds[i], LOW);
      delay(temps_delai_marche);
    }

    // Pause les LEDs pendant un délai
    delay(temps_toutes_marches_allumees);

    // Eteins les LEDs avec le même délai qu'elles ont été allumées
    for (int i = 0; i < nombre_de_leds; i++) {
      digitalWrite(Liste_des_leds[i], HIGH);
      delay(temps_delai_marche);
    }
    // Désactive capteur pendant un délai donné
    delay(temps_desactivation);
    Serial.print("Fin de séquence bas ");
  } 

  else if (detecteur_haut_state == HIGH) {
    Serial.print("Detecteur haut Activé ");
    // Allume les LED une par une avec un délai

    for (int i = nombre_de_leds - 1; i >= 0; i--) {
      digitalWrite(Liste_des_leds[i], LOW);
      delay(temps_delai_marche);
    }

    // Pause les LEDs pendant un délai
    delay(temps_toutes_marches_allumees);

    // Eteins les LEDs avec le même délai qu'elles ont été allumées
    for (int i = nombre_de_leds - 1; i >= 0; i--) {
      digitalWrite(Liste_des_leds[i], HIGH);
      delay(temps_delai_marche);
    }

    // Désactive capteur pendant un délai donné
    delay(temps_desactivation);
    Serial.print("Fin Séquence haut");
  }
}