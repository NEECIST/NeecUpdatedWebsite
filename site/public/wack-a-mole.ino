//Pins dos leds
const int red_leds[3] = {1, 2, 3};
const int yellow_leds[3] = {4, 5, 6};
const int green_leds[3] = {7, 8, 9};

//Pins dos butões
const int buttons[3]= {10, 11, 12};                       //10 - vermelho ; 11 - amarelo ; 12 - verde

int active_led;                                           //Indica o led ativo
int active_color;                                         //0 para vermelho, 1 para amarelo, 2 para verde
unsigned long aux_time = 0;                               //Variavel auxiliar que guarda o tempo de jogo da ultima jogada
const long gap_time = 4000;                               //Tempo para jogar ( vai diminuindo )

int score = 0;                                            //Pontuação do jogo


void setup() {
  
  // put your setup code here, to run once:
  for(int i = 0; i < 3 ; i++){                            //Inicialização dos pins
    pinMode(red_leds[i] , OUTPUT);
    pinMode(green_leds[i] , OUTPUT);
    pinMode(yellow_leds[i] , OUTPUT);
    pinMode(buttons[i] , INPUT_PULLUP);
  }

  Serial.begin(9600);                                     

}

void loop() {
  // put your main code here, to run repeatedly:

  int dificuldade;
  unsigned long time = milis(); 

  if( dificuldade == 3)                                     //Aumentar Dificuldade
    dificuldade = 0;  


  if(time - aux_time > gap_time){
    
    aux_time = time;

    digitalWrite(active_led , LOW);                         //Desligar o led anterior

    active_color = random( 0 , 2);                          //Escolher cor random para o novo led {0 - vermelho ; 1 - amarelo ; 2 - verde}

    if( active_color == 0){                                 //Dependendo da cor, escolher um dos leds aleatoriamente
      active_led = red_leds[random( 0 , 3 )];
    }
    else if( active_color == 1){
      active_led = yellow_leds[random( 0 , 3 )];
    }
    else if( active_color == 2){
      active_led = green_leds[random( 0 , 3 )];
    }
    else{
      //O QUE FAZER AQUI QUANDO O UTILIZADOR PERDE
    }

    digitalWrite(active_led , HIGH);                        //Ligar o led aleatoriamente escolhido

  }

 for( int i = 0 ; i < 3 ; i++){
      if(digitalRead(buttons[i] == LOW){ //Verificar se o botão é pressionado
        if( i == active_color){
          Serial.println("HIT");
          aux_time = milis();  //Atualizar aux_time
          if( dificuldade  == 3 ){ //Aumentar dificuldade a cada 4 jogadas
              if(gap_time != 500) 
    gap_time -= 500;}
          dificuldade++;
          score ++;  //Atualizar Score
          break;  //Sair do ciclo
      }
      else{  //Perde
          Serial.println("MISS");
          Serial.println(score);
          //O QUE FAZER AQUI QUANDO O USER PERDE????
}}}}
