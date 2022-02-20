#include <Servo.h>
// C++ code
//

const int b0 = 2;
const int b1 = 3;
const int b2 = 4;
const int b3 = 5;
const int b4 = 6;
const int b5 = 7;
const int b6 = 8;
const int b7 = 9;
const int servoPin = 10;
Servo myServo;

void setup()
{
  myServo.write(0);
  pinMode(A0, INPUT);
  pinMode(b0, OUTPUT);
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(b4, OUTPUT);
  pinMode(b5, OUTPUT);
  pinMode(b6, OUTPUT);
  pinMode(b7, OUTPUT);
  pinMode(servoPin, OUTPUT);
  Serial.begin(9600);

}
void writeToB(unsigned long temp)
{

Serial.println(temp);

if ((temp>>7) & 0x01){digitalWrite(b7,HIGH);}
else digitalWrite(b7,LOW);
if ((temp>>6) & 0x01){digitalWrite(b6,HIGH);}
else digitalWrite(b6,LOW);
if ((temp>>5) & 0x01){digitalWrite(b5,HIGH);}
else digitalWrite(b5,LOW);
if ((temp>>4) & 0x01){digitalWrite(b4,HIGH);}
else digitalWrite(b4,LOW);
if ((temp>>3) & 0x01){digitalWrite(b3,HIGH);}
else digitalWrite(b3,LOW);
if ((temp>>2) & 0x01){digitalWrite(b2,HIGH);}
else digitalWrite(b2,LOW);
if ((temp>>1) & 0x01){digitalWrite(b1,HIGH);}
else digitalWrite(b1,LOW);
if (temp & 0x01){digitalWrite(b0,HIGH);}
else digitalWrite(b0,LOW);
}

void resetB()
{
digitalWrite(b7,LOW);
digitalWrite(b6,LOW);
digitalWrite(b5,LOW);
digitalWrite(b4,LOW);
digitalWrite(b3,LOW);
digitalWrite(b2,LOW);
digitalWrite(b1,LOW);
digitalWrite(b0,LOW);
}

long my_map(long x, long in_min, long in_max, long out_min, long out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}


void loop()
{
 unsigned long voltage = analogRead(0);

  myServo.attach(servoPin);
  myServo.write(my_map(voltage, 0, 1023, 0, 180));
  delay(15);
}
