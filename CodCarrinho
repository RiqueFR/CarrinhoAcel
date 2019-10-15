const int rodadir[3] = {/*PINOS PONTE H PARA DIREITA*/}
const int rodaesq[3] = {/*PINOS PONTE H PARA ESQUERDA*/}


int convertData(float data){
  if(data<0)data = -data;
  return vel = 255 * data;
}

void setup() {
  // put your setup code here, to run once:
  for(i=0;i<3;i++){
    pinMode(/*rodadireita*/[i], OUTPUT);
  }
  for(i=0;i<3;i++){
    pinMode(/*rodaesquerda*/, OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  if(Serial.available > 0){
    float data = Serial.read();
    char direcao = Serial.read();
  }
  // put your main code here, to run repeatedly:
  if(direcao == "X" && data > 0){
    //INVERTE DIRECAO RODA DIREITA
    digitalWrite(rodaesq[0], LOW);
    digitalWrite(rodaesq[1], HIGH);
    digitalWrite(rodadir[0], HIGH);
    digitalWrite(rodadir[1], LOW);
    analogWrite(convertData(data), /*Pino roda esquerda*/);
    analogWrite(convertData(data), /*Pino roda direita*/);
  }
  if(direcao == "X" && data < 0){
    //INVERTE DIRECAO RODA ESQUERDA
    digitalWrite(rodaesq[0], HIGH);
    digitalWrite(rodaesq[1], LOW);
    digitalWrite(rodadir[0], LOW);
    digitalWrite(rodadir[1], HIGH);
    analogWrite(convertData(data), /*Pino roda esquerda*/);
    analogWrite(convertData(data), /*Pino roda direita*/);
  }
  if(direcao == "Y" && data > 0){
    digitalWrite(rodaesq[0], LOW);
    digitalWrite(rodaesq[1], HIGH);
    digitalWrite(rodadir[0], LOW);
    digitalWrite(rodadir[1], HIGH);
    analogWrite(convertData(data), /*Pino roda esquerda*/);
    analogWrite(convertData(data), /*Pino roda direita*/);
  }
  if(direcao == "Y" && data < 0){
    //INVERTE DIRECAO DAS RODAS
    digitalWrite(rodaesq[0], HIGH);
    digitalWrite(rodaesq[1], LOW);
    digitalWrite(rodadir[0], HIGH);
    digitalWrite(rodadir[1], LOW);
    analogWrite(convertData(data), /*Pino roda esquerda*/);
    analogWrite(convertData(data), /*Pino roda direita*/
  }
}
