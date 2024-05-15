//#include<wifi.h>

//const int SN = 0;
//const int SUS = 2;
//const int B1 = 16;
//const int B2 = 17;

// Definindo os pinos para os sensores e bombas
const int SN = A2; // Sensor de Nível de Água (SN)
const int SUS = A3; // Sensor de Umidade do Solo (SUS)
const int B1 = 3;   // Bomba do Reservatório (B1)
const int B2 = 2;   // Bomba do Tanque (B2)

void setup() {
  // Inicializando os pinos como entradas ou saídas
  pinMode(SN, INPUT);
  pinMode(SUS, INPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);

  // Inicializando a comunicação serial
  Serial.begin(9600);
}

void loop() {
  // Lendo os valores dos sensores
  int NAL = analogRead(SN);   // Nível de Água Leitura (NAL)
  int UUS = analogRead(SUS);  // Umidade do Solo Leitura (UUS)

  // Verificando se o nível de água está baixo
  if (NAL < 500) {
    // Acionando a bomba 1 (B1)
    digitalWrite(B1, HIGH);
    Serial.println("Nível de água baixo - Acionando bomba 1 (B1)");
  } else {
    // Desligando a bomba 1 (B1)
    digitalWrite(B1, LOW);
  }

  // Verificando se a umidade do solo está baixa
  if (UUS < 500) {
    // Acionando a bomba 2 (B2)
    digitalWrite(B2, HIGH);
    Serial.println("Umidade do solo baixa - Acionando bomba 2 (B2)");
  } else {
    // Desligando a bomba 2 (B2)
    digitalWrite(B2, LOW);
  }

  // Aguardando um curto período de tempo antes de repetir
  delay(1000);
}
