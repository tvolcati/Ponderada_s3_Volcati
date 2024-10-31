// declara os pinos dos LEDs
uint8_t RED = 4;
uint8_t YELLOW = 5;
uint8_t GREEN = 6;

// inicia uma variável de parada e uma variácel de estado
unsigned long last_stop = 0;
uint8_t state = 0;

void setup(){
  Serial.begin(9600);
  pinMode(RED, OUTPUT);
  pinMode(YELLOW, OUTPUT);
  pinMode(GREEN, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(GREEN, LOW);
  // define como saída os terminais de LED e desliga todos os LEDs ao iniciar
}

void loop(){
  unsigned long current_millis = millis(); //toda vez que roda o loop ele atualiza os millis atuais

  switch (state){
    case 0:
      if (current_millis - last_stop >= 6000){ //verifica se ja passou 6 segundos
        last_stop = current_millis; //diz que a ultima parada foi no momento atual
        state = 1; //troca para o próximo estado
        digitalWrite(RED, LOW); //desliga o LED vermelho
      } else{
        digitalWrite(RED, HIGH); //enquanto não tiver passado 6 segundos, mantém o RED ligado
      }
      break;

    case 1:
      if (current_millis - last_stop >= 2000){
        last_stop = current_millis;
        state = 2;
        digitalWrite(YELLOW, LOW);
      }else{
        digitalWrite(YELLOW, HIGH);
      }
      break;

    case 2:
      if (current_millis - last_stop >= 6000){
        last_stop = current_millis;
        state = 3;
        digitalWrite(GREEN, LOW);
      }else{
        digitalWrite(GREEN, HIGH);
      }
    break;

    case 3:
      if (current_millis - last_stop >= 2000){
        last_stop = current_millis;
        state = 0; // volta para o primeiro estado, tornando um loop
        digitalWrite(YELLOW, LOW);
      }else{
        digitalWrite(YELLOW, HIGH);
      }
      break;

    
  }
}