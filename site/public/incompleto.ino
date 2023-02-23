// define as portas analógicas de 0 a 3 como as bananas 0 a 3
int banana0 = ;
int banana1 = ;
int banana2 = ;
int banana3 = ;

// a rotina de setup corre uma vez no início do programa e sempre que o botão reset é pressionado
void setup() {
  Serial.begin(9600);  

  // define as bananas como portas INPUT_PULLUP e o OUTPUT
  ?
  ?
  ?
  ?
  ?
}

// a rotina loop corre infinitamente até que o o botão reset seja pressionado
void loop() {
  //  obter leituras dos pinos analógicos
  ?
  ?
  ?
  ?
  ?
  ?

  // converter as leituras analógicas (valores de 0 a 1023) para tensões (0 a 5V):
  float voltage0 = reading0 * (5.0 / 1023.0);
  float voltage1 = reading1 * (5.0 / 1023.0);
  float voltage2 = reading2 * (5.0 / 1023.0);
  float voltage3 = reading3 * (5.0 / 1023.0);

  // verificação das tensões para ver qual banana foi pressionada e tocar o som e acender o led para cada uma
  if (   ?    ) {
    ?
    ?
  }
  else if (   ?    ) {
    ?
    ?
  }
  else if (   ?    ) {
    ?
    ?
  }
  else if (   ?    ) {
    ?
    ?
  }
  else {
    ?
    ?
  }

  // print da leitura da banana0:
  Serial.println(voltage0);
}
