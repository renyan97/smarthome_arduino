#include <dht11.h>
dht11 DHT11;              //温湿度输入
#define DHT11PIN 4     //温湿度输入
#define MQ5_AO 0        //MQ5传感器模拟输入
#define MQ5_DO 3 
#define MQ9_AO 1        //MQ9传感器模拟输入
#define MQ9_DO 4 
#define huoyan_AO 2    //火焰传感器模拟输入
#define remin_AO 3    //火焰传感器模拟输入
#define guangzhao_AO 4    //火焰传感器模拟输入
void setup() {  
  pinMode(MQ5_AO, INPUT);  
   pinMode(MQ9_AO, INPUT);  
   pinMode(huoyan_AO, INPUT);  
   pinMode(remin_AO, INPUT);
   pinMode(guangzhao_AO, INPUT);
   pinMode(8,OUTPUT);
  Serial.begin(9600);  
}  
void loop() { 
  int chk = DHT11.read(DHT11PIN);
  Serial.println(analogRead(MQ5_AO));
  Serial.println(analogRead(MQ9_AO)); 
  Serial.println(analogRead(huoyan_AO));      
  Serial.println(analogRead(remin_AO)); 
  Serial.println(analogRead(guangzhao_AO)); 
  Serial.println((float)DHT11.humidity, 2); 
  Serial.println((float)DHT11.temperature, 2);  
  if(analogRead(guangzhao_AO)>600)
  {
    digitalWrite(8,HIGH);
    delay(3000);
    digitalWrite(8,LOW);
    }
  delay(30000);   
} 
