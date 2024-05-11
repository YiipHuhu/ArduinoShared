#define pare 3
#define alerta 5
#define livre 6
#define tmp 100
#define min 0
#define max 64

void setup(){
  pinMode(pare, OUTPUT);
  pinMode(alerta, OUTPUT);
  pinMode(livre, OUTPUT);
}

void loop(){
  for(int i = min; i < max ; i++){
    analogWrite(pare, i);
    delay(50);
  }
  for(int i = max; i >= min; i--){
    analogWrite(pare, i);
    delay(50);
  }
   for(int i = min; i < max ; i++){
    analogWrite(alerta, i);
    delay(50);
  }
  for(int i = max; i >= min; i--){
    analogWrite(alerta, i);
    delay(50);
  }
   for(int i = min; i < 255 ; i++){
    analogWrite(livre, i);
    delay(10);
  }
  for(int i = 255; i >= min; i--){
    analogWrite(livre, i);
    delay(15);
  }
}