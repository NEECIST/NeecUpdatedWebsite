// Definição dos leds de saida como sendo o pin nrº 9, 10 e 11
const int pinoLedVermelho = 9;
const int pinoLedAmarelo = 10;
const int pinoLedVerde = 11;

// Definição do sensor de luz como sendo o pin nrº 0 dos analógicos
const int pinoLDR = A0;

// Esta função setup() será executada apenas uma vez quando o arduino é ligado, sendo utilizada para configurar 
// quaisquer parametros que sejam necessários para o circuito
void setup() {
  // Definir os pins  como um OUTPUT
  // (faz sentido, visto que vamos ligá-lo a um LED)
  pinMode(pinoLedVermelho, OUTPUT);
  pinMode(pinoLedAmarelo, OUTPUT);
  pinMode(pinoLedVerde, OUTPUT);
}

// Esta função loop() irá ser executada, como o nome indicia, em continuamente e sempre a repetir-se. Está é a 
// função principal de qualquer programa de Arduino.
void loop() {
  // Leitura da luminosidade do LDR
  //O valor lido será (idealmente) entre 0 e 1023
  int valorLDR = analogRead(pinoLDR);

  // Mapear o valor lido para a quantidade de LEDs que serão acesos
  // Ou seja neste caso para um valor lido de 0 irá mapear o 1, para um valor lido
  // de 1000 para cima irá mapear o 3 e no intermédio irá mapear 2
  int quantidadeLeds = map(valorLDR, 0, 1000, 1, 3);

  // Controlar os LEDs com base na intensidade de luz medida
  digitalWrite(pinoLedVermelho, quantidadeLeds >= 1);
  digitalWrite(pinoLedAmarelo, quantidadeLeds >= 2);
  digitalWrite(pinoLedVerde, quantidadeLeds >= 3);

  delay(100); // Pequeno atraso para evitar flutuações rápidas
}
