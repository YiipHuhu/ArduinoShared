#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int distancia_carro = 10; 
const int TRIG = 13;
const int ECHO = 10;
const int ledGreen = 7;
const int ledRed = 8;
const int buzzer = 9;

float seno;
int frequencia;

void setup() {
  Serial.begin(9600);
  
  pinMode(TRIG,OUTPUT);
  pinMode(ECHO,INPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  lcd.begin(16, 2);
}

void loop() {
  int distancia = sensor_morcego(TRIG, ECHO);

  if (distancia <= distancia_carro) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Pare: ");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    Serial.print(distancia);
    lcd.print("cm");
    digitalWrite(ledGreen, LOW);
    digitalWrite(ledRed, HIGH);
    delay(30);
    digitalWrite(ledRed, LOW);
    delay(30);
    tocaBuzzer();
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Prossiga: ");
    lcd.setCursor(0, 1);
    lcd.print(distancia);
    Serial.print(distancia);
    lcd.print("cm");
    digitalWrite(ledGreen, HIGH);
    delay(50);
    digitalWrite(ledGreen, LOW);
    delay(50);
    digitalWrite(ledRed, LOW);
    noTone(buzzer);
  }

  delay(300);
}

int sensor_morcego(int pinotrig, int pinoecho) {
  digitalWrite(pinotrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinotrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinotrig, LOW);

  return pulseIn(pinoecho, HIGH) / 58;
}

void tocaBuzzer() {
  for (int x = 0; x < 180; x++) {
    seno = (sin(x * 3.1416 / 180));
    frequencia = 2000 + (int(seno * 1000));
    tone(buzzer, frequencia);
    delay(2);
  }
}