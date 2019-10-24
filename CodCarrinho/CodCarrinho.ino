<<<<<<< HEAD
const int rodadir[2] = {9,10};
const int rodaesq[2] = {5,6};
int cont2 = 0;

int convertData(float data) {
  if (data < 0)data = -data;
  return 256 * data;
}

void setup() {
  int i;
  for (i = 0; i < 2; i++) {
    pinMode(rodadir[i], OUTPUT);
=======
const int rodadir[3] = {/*PINOS PONTE H PARA DIREITA*/};
const int rodaesq[3] = {/*PINOS PONTE H PARA ESQUERDA*/};
int cont2=0;

int convertData(float data) {
  if (data < 0)data = -data;
  return vel = 255 * data;
}

void setup() {
  for (i = 0; i < 3; i++) {
    pinMode(rodadir[i], OUTPUT);
  }
  for (i = 0; i < 3; i++) {
>>>>>>> f94799bb7291e9a0df3d4ff8c1dc1647a4d2fdce
    pinMode(rodaesq[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*Comunicacao para receber direcao e angulacao*/
  float val = 0;
  int cont = 0, numC = 0;
  numC = Serial.available();
  char c[numC];
  while (cont <= numC) {
    c[cont] = (char)Serial.read();
    cont++;
  }
  Serial.println(c[0]);
  if (c[1] == '-') {
    val += c[2] - '0';
    val += (c[4] - '0') / 10.0;
    val += (c[5] - '0') / 100.0;
    val *= -1;
  } else {
    val += c[1] - '0';
    val += (c[3] - '0') / 10.0;
    val += (c[4] - '0') / 100.0;
<<<<<<< HEAD
  }
  Serial.println(val);
  delay(50);
  float data = val;
  char direcao = c[0];
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*Uso de condicoes para direcoes e convertData para tratamento da angulacao para velocidade*/
  if (direcao == "X" && data > 0) {
    //INVERTE DIRECAO RODA DIREITA
    analogWrite(rodaesq[0], LOW);
    analogWrite(rodaesq[1], convertData(data));
    analogWrite(rodadir[0], convertData(data));
    analogWrite(rodadir[1], LOW);
  } else if (direcao == "X" && data < 0) {
    //INVERTE DIRECAO RODA ESQUERDA
    analogWrite(rodaesq[0], convertData(data));
    analogWrite(rodaesq[1], LOW);
    analogWrite(rodadir[0], LOW);
    analogWrite(rodadir[1], convertData(data));
  } else if (direcao == "Y" && data < 0) {//frente
    analogWrite(rodaesq[0], LOW);
    analogWrite(rodaesq[1], convertData(data));
    analogWrite(rodadir[0], LOW);
    analogWrite(rodadir[1], convertData(data));
  } else if (direcao == "Y" && data > 0) {
    //INVERTE DIRECAO DAS RODAS
    analogWrite(rodaesq[0], convertData(data));
    analogWrite(rodaesq[1], LOW);
    analogWrite(rodadir[0], convertData(data));
    analogWrite(rodadir[1], LOW);
  } else {
    analogWrite(rodaesq[0], LOW);
    analogWrite(rodaesq[1], LOW);
    analogWrite(rodadir[0], LOW);
    analogWrite(rodadir[1], LOW);
=======
>>>>>>> f94799bb7291e9a0df3d4ff8c1dc1647a4d2fdce
  }
  Serial.println(val);
  delay(50);
  float data = val;
  char direcao = c[0];
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*Uso de condicoes para direcoes e convertData para tratamento da angulacao para velocidade*/
if (direcao == "X" && data > 0) {
  //INVERTE DIRECAO RODA DIREITA
  digitalWrite(rodaesq[0], LOW);
  digitalWrite(rodaesq[1], HIGH);
  digitalWrite(rodadir[0], HIGH);
  digitalWrite(rodadir[1], LOW);
  analogWrite(convertData(data), /*Pino roda esquerda*/);
  analogWrite(convertData(data), /*Pino roda direita*/);
}
if (direcao == "X" && data < 0) {
  //INVERTE DIRECAO RODA ESQUERDA
  digitalWrite(rodaesq[0], HIGH);
  digitalWrite(rodaesq[1], LOW);
  digitalWrite(rodadir[0], LOW);
  digitalWrite(rodadir[1], HIGH);
  analogWrite(convertData(data), /*Pino roda esquerda*/);
  analogWrite(convertData(data), /*Pino roda direita*/);
}
if (direcao == "Y" && data < 0) {
  digitalWrite(rodaesq[0], LOW);
  digitalWrite(rodaesq[1], HIGH);
  digitalWrite(rodadir[0], LOW);
  digitalWrite(rodadir[1], HIGH);
  analogWrite(convertData(data), /*Pino roda esquerda*/);
  analogWrite(convertData(data), /*Pino roda direita*/);
}
if (direcao == "Y" && data > 0) {
  //INVERTE DIRECAO DAS RODAS
  digitalWrite(rodaesq[0], HIGH);
  digitalWrite(rodaesq[1], LOW);
  digitalWrite(rodadir[0], HIGH);
  digitalWrite(rodadir[1], LOW);
  analogWrite(convertData(data), /*Pino roda esquerda*/);
  analogWrite(convertData(data), /*Pino roda direita*/
}
}
