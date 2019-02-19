#include <SoftwareSerial.h>
SoftwareSerial BT(13, 12); //12--r,13--t
int led2=2;
int led4=4;
int led7=7;
int led8=8;
int led3=3;
int led5=5;
int led6=6;
int led9=9;
int led10=10;
int led11=11;
char val;
String comdata="";
int error=0;
void setup() {
  Serial.println("BT is ready");
  BT.begin(9600);
  Serial.begin(9600);
  // put your setup code here, to run once:
 pinMode(led2,OUTPUT);
  pinMode(led4,OUTPUT);
   pinMode(led7,OUTPUT);
    pinMode(led8,OUTPUT);
     pinMode(led3,OUTPUT);
      pinMode(led5,OUTPUT);
       pinMode(led6,OUTPUT);
        pinMode(led9,OUTPUT);
         pinMode(led10,OUTPUT);
          pinMode(led11,OUTPUT);
          pinMode(0,OUTPUT);
          pinMode(1,OUTPUT);
          
}

void loop() {
 
    //sevenLed0(500);//7彩
 
  /*for(int i=1000;i=i-100;i>=300)
  aLed0(i,255,0,0);
  while(1)
  aLed0(200,255,0,0);*///交替红灯
 /*for(int i=1000;i=i-100;i>=300)
  aLed1(i,255,0,0,255,169,0);
  while(1)
  aLed1(200,255,0,0,255,169,0);*///交替彩灯
  //randomLed(); delay(1000);
   
  Led();
 
}
void  Led()
{ int temp0=0;
    comdata="";
      while (BT.available() > 0)  
    {
        comdata += char(BT.read());
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
        switch(s){
          case 1010:
          {mainLed(2,0);
           
           break;}
          case 1011:{mainLed(2,1);
        
           break;}
           case 1020:
          {mainLed(4,0);
          
           break;}
          case 1021:{mainLed(4,1);
           
           break;}
           case 1030:
          {mainLed(7,0);
           break;}
          case 1031:{mainLed(7,1);
           break;}
           case 1040:
          {mainLed(8,0);
           break;}
          case 1041:{mainLed(8,1);
           break;}
            case 1100:{eLed2();
           break;}
            case 1101:{eLed0(255,255,255);
           break;}
            case 1102:{eLed1(255,255,255);
           break;}
            case 1103:{ randomLed();
           break;}
           case 1104:{ eLed0(255,165,0);
           break;}
            case 1105:{ eLed1(255,165,0);
           break;}
           case 1106:{  redLed(); 
           break;
             }
           case 1107:{eLed0(255,20,147);
             break;
              }
           case 1108:{eLed1(255,20,147);
             break;
              }
              case 1109:{eLed0(255,204,204);
             break;
              }
            case 1110:{eLed1(255,204,204);
             break;
              }
            case 1111:{
              music0();
             break;
              }  
             case 1112:{
              music1();
             break;
              }
             case 1113:{
              music2();
             break;
              }
             case 1114:{
             mainLed(2,1);
             delay(800);
             mainLed(4,1);
              delay(800);
             mainLed(7,1);
              delay(800);
             mainLed(8,1);
             break;
              }
              case 1115:{
              mainLed(2,0);
               delay(800);
              mainLed(4,0);
               delay(800);
              mainLed(7,0);
               delay(800);
              mainLed(8,0);
          
             break;
              }
          default:{Serial.println("无效指令");
          break;}
          }
    }
 }
  void music2()
 {
    while(1)
  {
       color0(random(0,random(0,255)) ,random(0,random(0,255)),random(0,random(0,255)));
       delay(500);
       color0(0,0,0);
       color1(random(0,random(0,255)) ,random(0,random(0,255)),random(0,random(0,255)));
       delay(500);
       color1(0,0,0); 
        if(char(BT.read())=='t')
      {
        eLed2();
      break;
    }
  }
   }
 void music1()
 {
    while(1)
  {
       color0(random(0,random(0,255)) ,random(0,random(0,255)),random(0,random(0,255)));
       delay(1000);
       color0(0,0,0);
       color1(random(0,random(0,255)) ,random(0,random(0,255)),random(0,random(0,255)));
       delay(1000);
       color1(0,0,0); 
        if(char(BT.read())=='t')
      {
        eLed2();
      break;
    }
  }
   }
void music0()
 {
  int s=7;
  while(s)
  {
       color0(random(0,random(0,255)) ,random(0,random(0,255)),random(0,random(0,255)));
       delay(1000);
       color0(0,0,0);
       color1(random(0,random(0,255)) ,random(0,random(0,255)),random(0,random(0,255)));
       delay(1000);
       color1(0,0,0);
       s--;
  }
  delay(1000);
 eLed0(255,165,0);
 delay(2000);
 eLed0(255,0,0);
 delay(2000);
  }
void randomLed()//随机彩色灯
{
      color0(random(0,random(0,255)) ,random(0,random(0,255)),random(0,random(0,255)))  ;
      color1(random(0,random(0,255)),random(0,random(0,255)),random(0,random(0,255)))  ;
}
void mainLed(int p,int temp)//主灯
{
  if(temp==0)
  digitalWrite(p,LOW);
  if(temp==1)
  digitalWrite(p,HIGH);
}
void aLed1(int t,int r0,int g0,int b0,int r1,int g1,int b1)//双交替灯
{
  color0(r0,g0,b0);
  color1(r1,g1,b1);
  delay(t);
  color0(0,0,0);
  color1(0,0,0);
  color1(r0,g0,b0);
  color0(r1,g1,b1);
  delay(t);
  }
void aLed0(int t,int r,int g,int b)//单交替灯
{
  color0(r,g,b);
  color1(0,0,0);
  delay(t);
  color1(r,g,b);
  color0(0,0,0);
  delay(t);
  }
void eLed2() //关闭
{
  color0(0,0,0);
  color1(0,0,0);
 
  }
  void eLed0(int r,int g,int b)//全灯 
{
  color0(r,g,b);
  color1(r,g,b);
 
  }
    void eLed1(int r,int g,int b)//半灯 
{
  color0(r,g,b);
  color1(0,0,0);
 
  }
void sevenLed0(int t)
{
color0(255,0,0);
color1(255,0,0);
delay(t);
color0(255,69,0);
color0(255,69,0);
delay(t);
color0(255,255,0);
color1(255,255,0);
delay(t);
color0(0,255,0);
color1(0,255,0);
delay(t);
color0(0,0,255);
color1(0,0,255);
delay(t);
color0(0,255,255);
color1(0,255,255);
delay(t);
color0(255,0,255);
color1(255,0,255);
delay(t);
  }
void color0(int r,int g,int b)//色彩
{
  analogWrite(led3,constrain(r,0,255));
   analogWrite(led5,constrain(g,0,255));
    analogWrite(led6,constrain(b,0,255));
  }
  void color1(int r,int g,int b)//色彩
{
  analogWrite(led9,constrain(r,0,255));
   analogWrite(led10,constrain(g,0,255));
    analogWrite(led11,constrain(b,0,255));
  }
void redLed()
{   
      while(1)
      {
      color0(255,0,0);
      color1(255,0,0);
      delay(500);
      color0(0,0,0);
      color1(0,0,0);
      delay(500); 
      if(char(Serial.read())=='t')
      {
        eLed2();
      break;
    }}
 }
