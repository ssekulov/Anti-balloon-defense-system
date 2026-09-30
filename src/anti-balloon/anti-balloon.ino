#include <Servo.h>

const int servoPinX = 9;
const int servoPinY = 10;
const int servoPinS = 11;
const int motorPin = 12;
int xAngle;
int yAngle;
const int shootAngle = 130;

Servo servoX; // X axis
Servo servoY; // Y axis
Servo servoS; // Feeder microservo

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  digitalWrite(motorPin, LOW);

  servoX.attach(servoPinX);
  servoY.attach(servoPinY);
  servoS.attach(servoPinS);
  servoX.write(90); // LIMITATION : 0 - 180 degrees, 
  servoY.write(35); // LIMITATION : 0 - 70 degrees
  servoS.write(0); 
}

void loop() {
  if (Serial.available() > 0){
    xAngle = Serial.parseInt();
    yAngle = Serial.parseInt();
    yAngle = constrain(yAngle, 0, 70);

    while (Serial.available() > 0) {
      Serial.read(); 
    }

    servoX.write(xAngle);
    delay(50);
    servoY.write(yAngle);
    delay(50);

    digitalWrite(motorPin, 1);
    delay(1000);
    servoS.write(shootAngle);
    delay(300);
    servoS.write(0);
    delay(300);
    digitalWrite(motorPin, 0);
  }
}