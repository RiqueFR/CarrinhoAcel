#define enA 5
#define enB 6
#define pinMotor1 9
#define pinMotor2 10
#define pinMotor3 11
#define pinMotor4 12

int cont2 = 0;

int converteData(float data) {
  if (data < 0)data = -data;
  return 255 * data;
}

void setup() {
  int i;
  pinMode(pinMotor1, OUTPUT);
  pinMode(pinMotor2, OUTPUT);
  pinMode(pinMotor3, OUTPUT);
  pinMode(pinMotor4, OUTPUT);
  Serial.begin(38400);
}

void loop() {
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*Comunicacao para receber direcao e angulacao*/
  float val = 0;
  int cont = 0, numC = 0;
  bool ehposs = false;
  char let = 'N';
  // put your main code here, to run repeatedly:

  numC = Serial.available();
  if (numC) {
    char c[numC];
    while (cont <= numC) {
      c[cont] = (char)Serial.read();
      cont++;
    }
    let = c[0];
    cont = 0;
    if (c[0] == 'X' || c[0] == 'Y' || c[0] == 'N') {
      if (c[1] == '-') {
        val += c[2] - '0';
        val += (c[4] - '0') / 10.0;
        val += (c[5] - '0') / 100.0;
        val *= -1;
      } else {
        val += c[1] - '0';
        val += (c[3] - '0') / 10.0;
        val += (c[4] - '0') / 100.0;
      }
      if (val >= -1 && val <= 1) {
        ehposs = true;
      } else {
        ehposs = false;
      }
    }
  }
  delay(50);
  if(ehposs) {
    Serial.println(let);
    Serial.println(val);
  }
  float data = val;
  char direcao = let;
  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  /*Uso de condicoes para direcoes e convertData para tratamento da angulacao para velocidade*/
  if (ehposs) {
    Serial.println(converteData(data));
    if (direcao == 'X' && data < 0) {
      //INVERTE DIRECAO RODA DIREITA
      digitalWrite(pinMotor1, LOW);
      digitalWrite(pinMotor2, HIGH);
      digitalWrite(pinMotor3, HIGH);
      digitalWrite(pinMotor4, LOW);
      analogWrite(enA, converteData(data));
      analogWrite(enB, converteData(data));
    } else if (direcao == 'X' && data > 0) {
      //INVERTE DIRECAO RODA ESQUERDA
      digitalWrite(pinMotor1, HIGH);
      digitalWrite(pinMotor2, LOW);
      digitalWrite(pinMotor3, LOW);
      digitalWrite(pinMotor4, HIGH);
      analogWrite(enA, converteData(data));
      analogWrite(enB, converteData(data));
    } else if (direcao == 'Y' && data < 0) {//frente
      digitalWrite(pinMotor1, LOW);
      digitalWrite(pinMotor2, HIGH);
      digitalWrite(pinMotor3, LOW);
      digitalWrite(pinMotor4, HIGH);
      analogWrite(enA, converteData(data));
      analogWrite(enB, converteData(data));
    } else if (direcao == 'Y' && data > 0) {
      //INVERTE DIRECAO DAS RODAS
      digitalWrite(pinMotor1, HIGH);
      digitalWrite(pinMotor2, LOW);
      digitalWrite(pinMotor3, HIGH);
      digitalWrite(pinMotor4, LOW);
      analogWrite(enA, converteData(data));
      analogWrite(enB, converteData(data));
    } else {
      digitalWrite(pinMotor1, LOW);
      digitalWrite(pinMotor2, LOW);
      digitalWrite(pinMotor3, LOW);
      digitalWrite(pinMotor4, LOW);
    }
  }
}
