// Definir número de linhas e colunas para a matriz de LEDs
const int rows = 2;
const int cols = 5;

// Definir os pinos dos LEDs e do botão
const int ledPins[rows][cols] = {
  {2, 3, 4, 5, 6},      // Linha 1 dos LEDs (conectados às portas 2-6 do Arduino)
  {11, 10, 9, 8, 7}     // Linha 2 dos LEDs (conectados às portas 11-7 do Arduino)
};

const int buttonPin = 12;  // Pino do botão (conectado à porta 12 do Arduino)

// Matriz 2D para representar os estados dos LEDs (ligado/desligado)
bool ledState[rows][cols] = {false};

// Posição e estado do Dino
int dinoRow = 0;        // Dino começa na linha 0
int dinoCol = 3;        // Dino começa na coluna 3
bool dinoAlive = true;  // Flag que indica se o Dino está vivo

// Cactos
int cacti[cols];        // Array que armazena a posição dos cactos em cada coluna
int cactusBuffer = 0;   // Buffer para gerar novos cactos

// Variáveis de controle do jogo
int gameState = false;  // Estado inicial do jogo (false = não iniciado)
int jumpState = false;  // Estado do pulo (false = não pulando)
int jumpTimer = 0;      // Temporizador para controlar a duração do pulo

void setup() {
  Serial.begin(9600);  // Iniciar comunicação serial para debug

  // Inicializar os pinos dos LEDs como OUTPUT (saída)
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      pinMode(ledPins[i][j], OUTPUT);
      digitalWrite(ledPins[i][j], LOW); // Apagar todos os LEDs inicialmente
    }
  }

  // Inicializar o pino do botão como INPUT (entrada)
  pinMode(buttonPin, INPUT);

  // Inicializar array de cactos (todos inicialmente desligados)
  for (int col = 0; col < cols; col++) {
    cacti[col] = 0;
  }
}

// Função para acender um LED em uma determinada linha e coluna
void turnOnLED(int row, int col) {
  if (row >= 0 && row < rows && col >= 0 && col < cols) {
    digitalWrite(ledPins[row][col], HIGH);
    ledState[row][col] = true;
  }
}

// Função para apagar um LED em uma determinada linha e coluna
void turnOffLED(int row, int col) {
  if (row >= 0 && row < rows && col >= 0 && col < cols) {
    digitalWrite(ledPins[row][col], LOW);
    ledState[row][col] = false;
  }
}

// Função para acender todos os LEDs (usado quando o Dino colide)
void turnOnLEDS() {
  for (int col = cols; col >= 0; col--) {
    turnOnLED(0, col);
    turnOnLED(1, col);
    delay(100);  // Pequena pausa para efeito visual
  }
}

// Função para apagar todos os LEDs
void turnOffLEDS() {
  for (int col = 0; col < cols; col++) {
    turnOffLED(0, col);
    turnOffLED(1, col);
  }
}

// Função para atualizar o estado dos LEDs na matriz
void refreshLEDS() {
  turnOffLEDS();  // Apagar todos os LEDs antes de atualizar

  // Desenhar o Dino na posição atual
  turnOnLED(dinoRow, dinoCol);

  // Desenhar os cactos nas posições atuais
  for (int col = 0; col < cols; col++) {
    if (cacti[col] > 0 ) {  // Se houver um cacto na coluna, acender o LED correspondente
      turnOnLED(0, col);
    }
  }
}

// Função que controla o pulo do Dino
void jump() {
  if (digitalRead(buttonPin) == HIGH && !jumpState) { // Se o botão for pressionado e o Dino não estiver a pular
    jumpState = true;   // Ativar estado de pulo
    jumpTimer = 1;      // Iniciar temporizador do pulo
    dinoRow++;          // Mover Dino para a linha de cima
  } else if (jumpState) { // Se o Dino estiver a pular
    if (dinoRow != 0) {  // Se o Dino estiver no chão
      if (jumpTimer > 0) {
        jumpTimer--;     // Contar o tempo de pulo
      } else {
        jumpState = false;  // Se o tempo de pulo acabar, desativar o pulo
        dinoRow--;          // Mover Dino de volta para o chão
      }
    }
  }
}

// Função que verifica se o Dino colidiu com um cacto
void checkCollision() {
  if (dinoRow == 0) {  // Verifica colisão apenas se o Dino estiver no chão
    for (int col = 0; col < cols; col++) {
      if (cacti[col] > 0 && col == dinoCol) {  // Se houver um cacto na mesma posição que o Dino
        turnOnLEDS();  // Acender todos os LEDs (indica colisão)
        while (true) {}  // Parar o jogo (loop infinito)
      }
    }
  }
}

// Função para animar o movimento dos cactos
void animateCacti() {
  for (int col = cols - 1; col > 0; col--) {
    cacti[col] = cacti[col - 1];  // Mover cactos para a esquerda
  }
  cacti[0] = 0;  // Limpar a primeira coluna

  // Gerar novos cactos com base no buffer
  if (cactusBuffer == 0) {
    cacti[0] = 1;  // Criar um novo cacto
    cactusBuffer = random(2, 5);  // Definir buffer para o próximo cacto
  } else cactusBuffer--;  // Diminuir o buffer até o próximo cacto
}

// Função principal do jogo (loop do jogo)
void loop() {
  jump();          // Controlar o pulo do Dino
  animateCacti();  // Mover os cactos
  checkCollision();// Verificar colisões

  refreshLEDS();   // Atualizar os LEDs na matriz
  delay(400);      // Aguardar antes da próxima atualização (controla a velocidade do jogo)
}
