#define enA 5
#define enB 6
#define pinMotor1 9
#define pinMotor2 10
#define pinMotor3 11
#define pinMotor4 12

/*Função que faz o controle de velocidade dos motore, para que quando 
mais inclinada a luva estiver, mais rápido o carrinho ande.*/
int converteData(float data) {
    if (data < 0) data = -data;
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
    //Comunicação para receber direção e angulação
    float val = 0;
    int cont = 0, numC = 0;
    bool ehposs = false;
    char let = 'N';

    /*Verifica se o serial está disponível para leitura dos dados enviado pela luva, 
    quantos bytes possuem, e armazena essa quantdade em "numC"*/
    numC = Serial.available();
    if (numC) {
        //Faz a leitura dos dados;
        char c[numC];
        while (cont <= numC) {
            c[cont] = (char)Serial.read();
            cont++;
        }
        let = c[0];
        cont = 0;

        /*A luva envia uma string do tipo "X- 0.48", por exemplo, 
        então devemos tratar esse dado e transformá-lo em um decimal.*/
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
            //Filtra o valor recebido, para caso a luva transmita um dado diferente do esperado
            if (val >= -1 && val <= 1) {
                ehposs = true;
            } else {
                ehposs = false;
            }
        }
    }

    delay(50);
    float data = val;
    char direcao = let;
    /*Uso de condições para direções e convertData para tratamento da angulacao para velocidade*/
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
        } else if (direcao == 'Y' && data < 0) {
            //INVERTE DIRECAO RODA FRENTE
            digitalWrite(pinMotor1, LOW);
            digitalWrite(pinMotor2, HIGH);
            digitalWrite(pinMotor3, LOW);
            digitalWrite(pinMotor4, HIGH);
            analogWrite(enA, converteData(data));
            analogWrite(enB, converteData(data));
        } else if (direcao == 'Y' && data > 0) {
            //INVERTE DIRECAO DAS RODAS RÉ
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