// C++ code
//
int control = 1;
void setup()
{
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
}

  
void loop()
{
int valor = analogRead(A1);
int tensao = map(valor, 49, 969, 0, 10000);
Serial.print("Valor lido = ");
             Serial.println(tensao);
             delay(500);
  
  if (tensao>1000){
    digitalWrite(7, 0);
    digitalWrite(6, 0);
    digitalWrite(5, 1);
    digitalWrite(4, 0);
    control = 1;
  }
  else if (tensao>250){
  	digitalWrite(7, 0);
    digitalWrite(6, 1);
    digitalWrite(5, 0);
      if(control==1){
      digitalWrite(4, 1);
      delay(3000);
      digitalWrite(4, 0);
      control = 0;
      }
  }
  else{
  	digitalWrite(7, 1);
    digitalWrite(6, 0);
    digitalWrite(5, 0);
    digitalWrite(4, 1);
    control = 1;
  }
  
}
