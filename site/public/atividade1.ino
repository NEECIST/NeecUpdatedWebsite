// Definição do led de saida como sendo o pin nrº 7
int led = 7;

// Definição do sensor de luz como sendo o pin nrº 0 dos analógicos
int ldrPin = A0;


// Esta função setup() será executada apenas uma vez quando o arduino é ligado, sendo utilizada para configurar 
// quaisquer parametros que sejam necessários para o circuito
void setup()
{
  // Definir o pin  como um OUTPUT
  // (faz sentido, visto que vamos ligá-lo a um LED)
  pinMode(led, OUTPUT);
}


// Esta função loop() irá ser executada, como o nome indicia, em continuamente e sempre a repetir-se. Está é a 
// função principal de qualquer programa de Arduino.
void loop()
{
  // Ler o valor do LDR
  int ldrValor = analogRead(ldrPin); //O valor lido será entre 0 e 1023
  
  // Definição da condição de mudança
  // Se o valor lido no sensor for maior que 500, liga o led
  if (ldrValor>= 500) digitalWrite(led,HIGH);
  // se não, apaga o led
  else digitalWrite(led,LOW);
}
