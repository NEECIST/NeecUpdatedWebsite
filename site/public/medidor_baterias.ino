#define battPin A0


// valores para bateria (em volts) com capacidade mínima e máxima
const float lowBatt = 0.9;  //obtido através do datasheet
const float fullBatt = 1.7; //obtido experimentalmente


void setup() {
  
  Serial.begin(9600);
  pinMode(battPin, INPUT);
  
}

void loop() {

  float voltageSum = 0;     //somatório, usado na média
  int samples = 0;          //número de aquisições
  float voltageReading = 0; 

  //fazer 100 aquisições do sinal para obter o valor mais fiável
  for(samples = 0; samples < 100; samples++){
    voltageReading = (analogRead(battPin) * ( 5.0 / 1023.0) * 2); // regra de 3 simples e x2 para compensar divisor de tensão
    voltageSum += voltageReading; //adicionar ao somatório
  }

  float meanVoltage = voltageSum / samples; //fazer a média

  Serial.print("Battery: ");
  Serial.print(meanVoltage, 2);
  Serial.print(" V. |");

  float battPercentage = ((meanVoltage- lowBatt) / (fullBatt - lowBatt))* 100;    //calcular a percentagem de capacidade disponível
  Serial.print(battPercentage, 2);
  Serial.println(" % ");

  delay(1000);
}
