#include <Servo.h> 
#include <SoftwareSerial.h>
SoftwareSerial BT(13, 12); //12--r,13--t
Servo myservo;
String comdata="";
void setup(){
   BT.begin(9600);
  Serial.begin(9600);
  myservo.attach(9);
myservo.write(0); 
}

void loop(){
comdata="";
 int flag=0;
  while(Serial.available()>0){
    comdata+= char(Serial.read());
    delay(2);
     flag=1;
  } 
   if(flag==1){
     int s0=(comdata[0]-'0');
    int s1=(comdata[1]-'0');
    int s2=(comdata[2]-'0');
    int s3=(comdata[3]-'0');
    int s=s0*1000+s1*100+s2*10+s3;
     Serial.println(s);
    if(s==1011){
      myservo.write(80);
      delay(100);
    }
   
    else if(s==1010){
       myservo.write(0);
       delay(1000);
    }
 }}

 /* myservo.write(180);
  Serial.println(myservo.read());
  delay(1000);
  myservo.write(0);
  Serial.println(myservo.read());
  delay(1000);*/

