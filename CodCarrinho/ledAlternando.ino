int i = 0, cont = 0, j = 0, k = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if(i <= 255 && cont == 0){
  	i++;
    if(k > 0){
    	k--;
    }
  }else if(i > 255 && cont == 0){
    cont = 1;
  }else if(cont == 1 && j <= 255){
    i--;
    j++;
  }else if(j > 255 && cont == 1){
    cont = 2;
  }else if(cont == 2 && k <= 255){
    j--;
    k++;
  }else if(cont == 2 && k > 255){
    cont = 0;
  }
  Serial.print("I: ");
  Serial.print(i);
  Serial.print(" J: ");
  Serial.print(j);
  Serial.print(" K: ");
  Serial.println(k);
  analogWrite(A0, i);
  analogWrite(A1, j);
  analogWrite(A2, k);
}
