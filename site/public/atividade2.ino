
// Definição do sinal dos butões
bool inA;
bool inB;

// Definição dos botões
int pbA = 2;
int pbB = 3;

// Definição do led de saida
int led = 7;

void setup()
{
  // Initialização dos botões
	
  pinMode(pbA, INPUT);
  pinMode(pbB, INPUT);
  
  // Initialização do led
  
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW); 

}

void loop()
{
  // Leitura dos botões
  int inA = digitalRead(pbA);
  int inB = digitalRead(pbB);
  
  bool resultado = false;

  /*
    NOT : !
    AND : &
    OR  : |
    XOR : ^
  */
  
  // Botão A [E](and) botão B
  // Botão A • Botão B
  //resultado = inA & inB;
  
  // Botão A [OU](or) botão B
  // Botão A + Botão B
  //resultado = inA | inB;
  
  // Botão A [OU Exclusivo](xor) botão B
  // Botão A ⊕ Botão B
  //resultado = inA ^ inB;
  
  // NOT(Botão A [E](and) botão B)
  // !(Botão A • Botão B)
  //resultado = !(inA & inB);
  
  digitalWrite(led, resultado);
  delay(500);
}
