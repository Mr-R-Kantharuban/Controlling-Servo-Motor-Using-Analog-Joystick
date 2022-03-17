include<Servo.h>
Servo ser;
int VRx = A0;
int VRy = A1;
int SW = 9;
int xPosition = 0;
int yPosition = 0;
int SW_state = 0;
int mapXX = 0;
int mapYY = 0;

int count=0;
int pos;
const int rs = 12, en = 11, d4 = 2, d5 = 4, d6 = 5, d7 = 6;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT);
  pinMode(VRx, INPUT);
  pinMode(VRy, INPUT);
  pinMode(SW, INPUT_PULLUP); 
  ser.attach(3);
    Serial.begin(9600); 
    ser.write(0);
    lcd.begin(16, 2);
  
}
void loop()
{
 joy();
 delay(20);
 


}
void joy()
{
   xPosition = analogRead(VRx);
  yPosition = analogRead(VRy);
  SW_state = digitalRead(SW);
  mapXX = map(xPosition, 0, 1023, 13,193 );
  mapYY = map(yPosition, 0, 1023, 13, 193);
  int mapX=mapXX-105;
  int mapY=mapYY-102;
  
  Serial.print("X: ");
  Serial.print(mapX);
  Serial.print(" | Y: ");
  Serial.println(mapY);

  if(mapX<1&&mapX>-1&&mapY<3&&mapY>1)
 {
  

 ser.write(90);
 delay(15);
 } 
 else if(mapX<10&&mapX>-10&&mapY<3&&mapY>-91)
 {
  
  

 ser.write(0);
 delay(15);
 }
 else if(mapX<10&&mapX>-10&&mapY<91&&mapY>2)
 {

 ser.write(180);
 delay(15);
  
  delay(1000);
}}
