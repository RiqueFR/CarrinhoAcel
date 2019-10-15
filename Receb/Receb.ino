int cont2 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);    
  delay(100);
}

void loop() {
  float x,val = 0;
  char let;
  int cont = 0, i,numC = 0;
  // put your main code here, to run repeatedly:
  numC = Serial.available();
  char c[numC];
  while(cont <= numC) {
    c[cont] = (char)Serial.read();
    cont++;
  }
  cont = 0;
  cont2++;
  Serial.print(cont2);
  Serial.println(c[0]);
  if(c[1] == '-') {
    val += c[2] - '0';
    val += (c[4]-'0')/10.0;
    val += (c[5]-'0')/100.0;
    val *= -1;
  } else {
    val += c[1] - '0';
    val += (c[3]-'0')/10.0;
    val += (c[4]-'0')/100.0;
  }
  Serial.println(val);
  delay(50);
}
