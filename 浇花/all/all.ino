#include <Servo.h> 
Servo myservo;
#define relay 4//继电器
char val;
#define PIN_AO 2
#define feng 6
#define feng0 5
String comdata="";
void setup()
{ myservo.attach(10);
  Serial.begin(9600);
  pinMode(relay,OUTPUT); 
   pinMode(PIN_AO,INPUT);
   pinMode(feng,OUTPUT);   
   pinMode(feng0,OUTPUT); 
   pinMode(11,OUTPUT); 
   pinMode(12,OUTPUT); 
}

void loop()
{
int temp0=0;
    comdata="";
      while (Serial.available() > 0)  
    {
        comdata += char(Serial.read());
        delay(2);
        temp0=1;
    } 
    if(temp0==1)
    {
    int s0=(comdata[0]-'0');
    int s1=(comdata[1]-'0');
    int s2=(comdata[2]-'0');
    int s3=(comdata[3]-'0');
    int s=s0*1000+s1*100+s2*10+s3;
        Serial.println(s);
         if(s==1500)
         {
analogWrite(5,0);
analogWrite(6,0);
         }
   if(s==1502)
   {
digitalWrite(5,100);
digitalWrite(6,0);
   }
   if(s==1501)
   { 
  analogWrite(5,180);
  analogWrite(6,0);
 
   }
 if(s==1503)
   {
analogWrite(5,255);
analogWrite(6,0);
   }
if(s==1504)
digitalWrite(feng,HIGH);
 if(s==1301) 
 turang();
 if(s==1302)
digitalWrite(relay,HIGH);
 if(s==1303)
digitalWrite(relay,LOW);

  if(s==1401){
      myservo.write(120);
      delay(100);
    }else if(s==1402){
       myservo.write(0);
       delay(1000);
    }
     if(s==1601)
   {
digitalWrite(11,HIGH);
delay(800);
digitalWrite(12,HIGH);
   }
    if(s==1602)
   {
digitalWrite(11,LOW);
delay(800);
digitalWrite(12,LOW);
   }

    }
 delay(1000);
}  
void turang()
{
  Serial.print("AO=");  
    if(analogRead(PIN_AO)>365)
    {
         digitalWrite(relay,HIGH);
        
    }
      if(analogRead(PIN_AO)<250)
   {
         digitalWrite(relay,LOW);
   }      
  Serial.print(analogRead(PIN_AO));
 }


