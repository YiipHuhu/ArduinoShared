// C++ code
//
#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
#include <math.h>
#define vermelho 8
#define amarelo 10
#define verde 7

void setup()
{            
  Serial.begin(9600);  
  pinMode(A0, INPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(amarelo, OUTPUT);
  pinMode(verde, OUTPUT);
  lcd.begin(16, 2);
} 

void loop() 
{             
  int val;
  float temp;
  val = analogRead(0);
  temp = log(((10240000/val) - 10000));
  temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * temp * temp ))* temp );
  temp = temp - 273.15;
  Serial.print(temp);
  Serial.println("°C");
  lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Temperatura: ");
    lcd.setCursor(0, 1);
    lcd.print(temp);
        lcd.print(" C");
  delay(1000);

    if (temp < 15) {
      digitalWrite(vermelho, LOW);
      digitalWrite(amarelo, LOW);
      digitalWrite(verde, HIGH);
      
    } else {
      if (temp > 17) {
      digitalWrite(vermelho, HIGH);
      digitalWrite(amarelo, LOW);
      digitalWrite(verde, LOW);
      } else {
      digitalWrite(vermelho, LOW);
      digitalWrite(amarelo, HIGH);
      digitalWrite(verde, LOW);
        }
      }
    }

