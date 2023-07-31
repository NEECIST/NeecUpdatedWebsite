// Definição dos botões como sendo os pins nrº 2 e 3
int botao_aumentar = 2;
int botao_diminuir = 3;

// Definição dos leds de saida como sendo os pins nrº 7, 8, 9, 10
int led4 = 7;
int led3 = 8;
int led2 = 9;
int led1 = 10;

int valor_atual[] = {0, 0, 0, 0};

// Esta função setup() será executada apenas uma vez quando o arduino é ligado, sendo utilizada para configurar 
// quaisquer parametros que sejam necessários para o circuito
void setup()
{
  // Definir os pins como INPUTS
  // (faz sentido, visto que vamos ligá-los a perifericos de input)
  pinMode(botao_aumentar, INPUT);
  pinMode(botao_diminuir, INPUT);
  
  // Definir os pins como um OUTPUT
  // (faz sentido, visto que vamos ligá-los a LEDs)
  pinMode(led4, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
}

void loop()
{
  // Alterar o estado dos leds para o valor correspondente a cada bit
  digitalWrite(led1, valor_atual[0]); 
  digitalWrite(led2, valor_atual[1]);
  digitalWrite(led3, valor_atual[2]);
  digitalWrite(led4, valor_atual[3]);
  
  delay(1000);
  // Leitura dos botões
  int inA = digitalRead(botao_aumentar);
  int inB = digitalRead(botao_diminuir);
  
  // Se o botão de incrementar foi clicado
  if(inA){
    // Se o bit mais a direita é igual a 1 então passa a 0 e continua
    if(valor_atual[0] == 1){
      valor_atual[0] = 0;
      // Caso contrario se for igual a 0 passa a ser 1 e sai
    }else{
      valor_atual[0] = 1;
      return;
    }
    // E assim sucessivamente

    if(valor_atual[1] == 1){
      valor_atual[1] = 0;
    }else{
      valor_atual[1] = 1;
      return;
    }
    
    if(valor_atual[2] == 1){
      valor_atual[2] = 0;
    }else{
      valor_atual[2] = 1;
      return;
    }
    
    if(valor_atual[3] == 1){
      valor_atual[3] = 0;
    }else{
      valor_atual[3] = 1;
      return;
    }
  }
}
