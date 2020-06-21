// Acelerômetro ADXL345
#include <Wire.h>

#define Register_ID 0
#define Register_2D 0x2D
#define Register_X0 0x32
#define Register_X1 0x33
#define Register_Y0 0x34
#define Register_Y1 0x35
#define Register_Z0 0x36
#define Register_Z1 0x37

/*Define uma tolerância na inclinação para que qualquer movimento
simples não seja interpretado como um comando.*/
#define TOL 0.3f

//Endereco I2C do sensor : 83 em decimal ou 0x53
int ADXAddress = 0x53;  //Endereço 7-bit do sensor I2C
int reading = 0;
int val = 0;
int X0, X1, X_out;
int Y0, Y1, Y_out;
int Z1, Z0, Z_out;
double Xg, Yg, Zg;

void RecebeAcel();

void setup() {
    Wire.begin();
    Serial.begin(38400);
    delay(100);
    Wire.beginTransmission(ADXAddress);  //Inicia a transmissão com o dispositivo I2C
    Wire.write(Register_2D);
    Wire.write(8);
    Wire.endTransmission();  //Finaliza transmissão
}

void loop() {
    /*Faz a leitura do acelerômetro e depois escreve na porta serial a leitura do mesmo, 
    isso já é o suficiente para que o bluetooth do carrinho consiga receber os dados.*/
    RecebeAcel();
    if (Xg > TOL || Xg < -TOL || Yg < -TOL || Yg > TOL) {
        if (Yg < -TOL && Yg >= -1) {  //Frente
            Serial.print("Y");
            Serial.println(Yg);
        } else if (Yg > TOL && Yg <= 1) {  //Tras
            Serial.print("Y");
            Serial.println(Yg);
        } else if (Xg > TOL && Xg <= 1) {  //Direita
            Serial.print("X");
            Serial.println(Xg);
        } else if (Xg < -TOL && Xg >= -1) {  //Esquerda
            Serial.print("X");
            Serial.println(Xg);
        }
    } else {
        Serial.print("N");
        Serial.println(0.0);
    }

    delay(100);
}

//Função que recebe e interpreta os dados do acelerômetro
void RecebeAcel() {
    //------------------X
    Wire.beginTransmission(ADXAddress);
    Wire.write(Register_X0);
    Wire.write(Register_X1);
    Wire.endTransmission();
    Wire.requestFrom(ADXAddress, 2);
    if (Wire.available() <= 2) {
        X0 = Wire.read();
        X1 = Wire.read();
        X1 = X1 << 8;
        X_out = X0 + X1;
    }

    //------------------Y
    Wire.beginTransmission(ADXAddress);
    Wire.write(Register_Y0);
    Wire.write(Register_Y1);
    Wire.endTransmission();
    Wire.requestFrom(ADXAddress, 2);
    if (Wire.available() <= 2) {
        Y0 = Wire.read();
        Y1 = Wire.read();
        Y1 = Y1 << 8;
        Y_out = Y0 + Y1;
    }
    //------------------Z
    Wire.beginTransmission(ADXAddress);
    Wire.write(Register_Z0);
    Wire.write(Register_Z1);
    Wire.endTransmission();
    Wire.requestFrom(ADXAddress, 2);
    if (Wire.available() <= 2) {
        Z0 = Wire.read();
        Z1 = Wire.read();
        Z1 = Z1 << 8;
        Z_out = Z0 + Z1;
    }

    Xg = X_out / 256.0;
    Yg = Y_out / 256.0;
    Zg = Z_out / 256.0;
}
