#include <Arduino.h>
#include <LedControl.h>
#define buzzerPin A1
#define Level1 128
#define Level2 192
#define Level3 224
#define Level4 240
#define Level5 248
#define Level6 252
#define Level7 254
#define Level8 255
byte smile[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
byte sad[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};
float sum = 0;
LedControl lc=LedControl(12,11,10,1); 


void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setColumn(0,i,character[i]);
  }
}

void setup() {
pinMode(A1, OUTPUT);
pinMode(A2, OUTPUT);
digitalWrite(A2,LOW);


lc.shutdown(0,false); 
lc.setIntensity(0,15); 
//lc.setColumn(0,0,Level8); 
tone(buzzerPin, 300, 1000);
Serial.begin(9600);
}

void loop() {

for (size_t i = 0; i < 10; i++)
{
      sum += digitalRead(8);
}
sum = sum /10.0;
Serial.println(sum);
if (sum <= 0.128){
     lc.setIntensity(0,2);
     lc.setColumn(0,0,Level1); 
      lc.setColumn(0,7,Level1); 
}else if(sum <= 0.256) {
      lc.setIntensity(0,4);
     lc.setColumn(0,0,Level2); 
     lc.setColumn(0,7,Level2); 
}else if (sum <= 0.384) {
      lc.setIntensity(0,6);

     lc.setColumn(0,0,Level3); 
     lc.setColumn(0,7,Level3); 
   
}else if (sum <= 0.512 ){
      lc.setIntensity(0,8);

     lc.setColumn(0,0,Level4); 
     lc.setColumn(0,7,Level4); 
    
}else if (sum <= 0.640){
   
      lc.setIntensity(0,10);

     lc.setColumn(0,0,Level5);   
      lc.setColumn(0,7,Level5);   
}else if (sum <= 0.768){
      lc.setIntensity(0,12);

     lc.setColumn(0,0,Level6); 
  lc.setColumn(0,7,Level6); 
}else if (sum <= 0.896){

      lc.setIntensity(0,14);
     lc.setColumn(0,0,Level7); 
     lc.setColumn(0,7,Level7); 
}else if (sum <= 1.0){
 lc.setIntensity(0,16);
     lc.setColumn(0,0,Level8); 
      lc.setColumn(0,7,Level8); 

}else{
     
      lc.setIntensity(0,16);
     lc.setColumn(0,0,Level8); 
  lc.setColumn(0,7,Level8); 
}

}
