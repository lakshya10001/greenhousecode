
#include <LiquidCrystal.h>


  LiquidCrystal lcd(13, 12, 11, 10,  9,  8);

const int L_Pin = 6;
const int M_Pin = 7;

void setup() 
{
  lcd.begin(20, 4); 
  lcd.setCursor(0,0); 
  lcd.print("    GREEN HOUSE    ");

  pinMode(L_Pin,OUTPUT);
  pinMode(M_Pin,OUTPUT);
}

void loop() 
{
 
  int S1=analogRead(A0);  
  int Temp=(S1*500)/1023; 
  lcd.setCursor(0,1);
  lcd.print(" T=");
  lcd.print(Temp);
  lcd.print("'C     ");

 
  int S2=analogRead(A1); 
  int LI=S2/1.9;
  lcd.setCursor(11,1);
  lcd.print(" L=");
  lcd.print(LI);
  lcd.print("Lx       ");
  

  int S3=analogRead(A2);  
  int SM=S3/10;
  lcd.setCursor(0,2);
  lcd.print(" S=");
  lcd.print(SM);
  lcd.print("%      ");


  int S4=analogRead(A3);  
  int H=S4/10;
  lcd.setCursor(11,2);
  lcd.print(" H=");
  lcd.print(H);
  lcd.print("%   ");
  
  if(LI<30)
  {
    digitalWrite(L_Pin,HIGH);
    lcd.setCursor(0,3);
    lcd.print(" Light:ON   ");
  }
  else
  {
    digitalWrite(L_Pin,LOW);
    lcd.setCursor(0,3);
    lcd.print(" Light:OFF   ");
  }

  if(SM<40)
  {
    digitalWrite(M_Pin,HIGH);
    lcd.setCursor(10,3);
    lcd.print(" Motor:ON    ");
  }  
  else
  {
    digitalWrite(M_Pin,LOW);
    lcd.setCursor(10,3);
    lcd.print(" Motor:OFF    ");
  }
}

