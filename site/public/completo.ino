// define as portas analógicas de 0 a 3 como as bananas 0 a 3
int banana0 = A0;
int banana1 = A1;
int banana2 = A2;
int banana3 = A3;

// a rotina de setup corre uma vez no início do programa e sempre que o butão reset é pressionado
void setup() {
  Serial.begin(9600);
  
  // define as bananas como portas INPUT_PULLUP e o OUTPUT
  pinMode(banana0, INPUT_PULLUP);
  pinMode(banana1, INPUT_PULLUP);
  pinMode(banana2, INPUT_PULLUP);
  pinMode(banana3, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  pinMode(10, OUTPUT);
}

// a rotina loop corre infinitamente até que o o botão reset seja pressionado
void loop() {
  //  obter leituras dos pinos analógicos
  float reading0 = analogRead(banana0);
  float reading1 = analogRead(banana1);
  float reading2 = analogRead(banana2);
  float reading3 = analogRead(banana3);
  
  // converter as leituras analógicas (valores de 0 a 1023) para tensões (0 a 5V):
  float voltage0 = reading0 * (5.0 / 1023.0);
  float voltage1 = reading1 * (5.0 / 1023.0);
  float voltage2 = reading2 * (5.0 / 1023.0);
  float voltage3 = reading3 * (5.0 / 1023.0);
  
  // verificação das tensões para ver qual banana foi pressionada e tocar o som e acender o led para cada uma
  if(voltage0 < 4.9){
    digitalWrite(2, HIGH);
    tone(10, 264, 0.1);
  }
  else if(voltage1 < 4.9){
    digitalWrite(2, HIGH);
    tone(10, 297, 0.1);
  }
  else if(voltage2 < 4.9){
    digitalWrite(2, HIGH);
    tone(10, 330, 0.1);
  }
  else if(voltage3 < 4.9){
    digitalWrite(2, HIGH);
    tone(10, 352, 0.1);
  }
  else{
    digitalWrite(2, LOW);
    noTone(10);
  }

  // print da leitura da banana0:
  Serial.println(voltage0);
}