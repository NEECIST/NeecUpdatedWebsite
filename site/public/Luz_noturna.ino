int led = 6;
int sensorValue = 0; // Valor do sensor inicializado a 0
int pbA = 7; // Botão ligado ao pino 6
int brightnessLevel = 0; // Nível de brilho do LED

void setup() {
  pinMode(pbA, INPUT); // Usa o resistor pull-up interno
  Serial.begin(9600); // Configura a taxa de comunicação serial para 9600 bps
  pinMode(led, OUTPUT); // Define o pino 7 (LED) como saída
}

void loop() {
  sensorValue = analogRead(A0); // Lê o valor do sensor LDR no pino A0
  // Serial.print("LDR Value: ");
  // Serial.println(sensorValue); // Imprime o valor do sensor no monitor serial

  int buttonState = digitalRead(pbA); // Lê o estado do botão
  // Serial.print("Button State: ");
  // Serial.println(buttonState); // Imprime o estado do botão no monitor serial

  if (sensorValue > 500) { // Se o valor do sensor for superior a 500 (indicando pouca luz)
    if (buttonState == HIGH) {
      // Se o botão foi pressionado (transição de HIGH para LOW)
      brightnessLevel++; // Incrementa o nível de brilho
      if (brightnessLevel > 2) {
        brightnessLevel = 0; // Retorna ao nível de brilho mais baixo após o nível mais alto
      }
      delay(200); // Atraso para evitar múltiplas detecções de um único clique
    }

    // Ajusta o brilho do LED com base no nível de brilho selecionado
    if (brightnessLevel == 0) {
      analogWrite(led, 128); // Brilho médio-baixo (50% de 255)
      Serial.print("/*/");
    } else if (brightnessLevel == 1) {
      analogWrite(led, 192); // Brilho médio-alto (75% de 255)
    } else if (brightnessLevel == 2) {
      analogWrite(led, 255); // Brilho máximo (100% de 255)
    }
    Serial.print("Brilho State: ");
    Serial.println(brightnessLevel);
  } else {
    analogWrite(led, 0); // Desliga o LED se não estiver escuro
  }
}