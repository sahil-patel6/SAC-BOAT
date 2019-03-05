//initialization of pins
#include <SoftwareSerial.h>
const int frontLeftMotor = 6;
const int frontRightMotor = 7;
const int backLeftMotor = 8;
const int backRightMotor = 9;

SoftwareSerial module(10, 11); // RX | TX

void setup() {
  // put your setup code here, to run once:
  pinMode(frontLeftMotor, OUTPUT);
  pinMode(frontRightMotor, OUTPUT);
  pinMode(backLeftMotor, OUTPUT);
  pinMode(backRightMotor, OUTPUT);
  module.begin(9600);
  Serial.begin(9600);
}
void loop() {
  char code;
  // put your main code here, to run repeatedly:
  if (module.available() > 0) {
    code = module.read();
    // w = go forward
    // s = go backward
    // c = stop
    // a = forward left
    // d = forward right
    // q = backward left
    // e = backward right
    switch (code) {
      case 'w':
        Serial.print("Going Forward");
        module.print("Going Forward");
        digitalWrite(frontLeftMotor, 0);
        digitalWrite(frontRightMotor, 1);
        digitalWrite(backLeftMotor, 1);
        digitalWrite(backRightMotor, 0);
        break;

      case 's':
        Serial.print("Going Backward");
        module.print("Going Backward");
        digitalWrite(frontLeftMotor, 1);
        digitalWrite(frontRightMotor, 0);
        digitalWrite(backLeftMotor, 0);
        digitalWrite(backRightMotor, 1);
        break;

      case 'c':
        Serial.print("Stopping");
        module.print("Stopping");
        digitalWrite(frontLeftMotor, 0);
        digitalWrite(frontRightMotor, 0);
        digitalWrite(backLeftMotor, 0);
        digitalWrite(backRightMotor, 0);
        break;
      case 'a':
        Serial.print("Going Left");
        digitalWrite(frontLeftMotor, 0);
        digitalWrite(frontRightMotor, 0);
        digitalWrite(backLeftMotor, 1);
        digitalWrite(backRightMotor, 0);
        break;
      case 'd':
        Serial.print("Going Left");
        digitalWrite(frontLeftMotor, 0);
        digitalWrite(frontRightMotor, 1);
        digitalWrite(backLeftMotor, 0);
        digitalWrite(backRightMotor, 0);
        break;
      case 'q':
        Serial.print("Going Backward LEft");
        module.print("Going Backward Left");
        digitalWrite(frontLeftMotor, 0);
        digitalWrite(frontRightMotor, 0);
        digitalWrite(backLeftMotor, 0);
        digitalWrite(backRightMotor, 1);
        break;
     case 'e':
        Serial.print("Going Backward Right");
        module.print("Going Backward Right");
        digitalWrite(frontLeftMotor,  1);
        digitalWrite(frontRightMotor, 0);
        digitalWrite(backLeftMotor, 0);
        digitalWrite(backRightMotor, 0);  
        break;
      default:
        module.println("An error Occured");
    }
  }
  delay(1000);
}
