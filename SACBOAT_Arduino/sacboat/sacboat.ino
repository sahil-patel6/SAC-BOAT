//initialization of pins
#include <SoftwareSerial.h>
const int frontLeftMotor = 6;
const int frontRightMotor = 7;
const int backLeftMotor = 8;
const int backRightMotor = 9;

const int frontLeftPropeler = 2;
const int frontRightPropeler = 3;
const int backLeftPropeler = 4;
const int backRightPropeler = 5;

const int vacuum = 0;
const int vacuum1 = 1;
const int belt = 12;
const int belt1 = 13;

SoftwareSerial module(10, 11); // RX | TX

void setup() {
  // put your setup code here, to run once:
  pinMode(frontLeftMotor, OUTPUT);
  pinMode(frontRightMotor, OUTPUT);
  pinMode(backLeftMotor, OUTPUT);
  pinMode(backRightMotor, OUTPUT);

  pinMode(frontLeftPropeler, OUTPUT);
  pinMode(frontRightPropeler, OUTPUT);
  pinMode(backLeftPropeler, OUTPUT);
  pinMode(backRightPropeler, OUTPUT);

  pinMode(vacuum, OUTPUT);
  pinMode(vacuum1, OUTPUT);
  pinMode(belt, OUTPUT);
  pinMode(belt1, OUTPUT);

  module.begin(9600);
  Serial.begin(9600);
}

bool isVacuum = false;

bool isBelt = false;

void loop() {
  char code;
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
      case 'W':
        Serial.print("Going Forward P");
        module.print("Going Forward P");
        digitalWrite(frontLeftPropeler, 0);
        digitalWrite(frontRightPropeler, 1);
        digitalWrite(backLeftPropeler, 1);
        digitalWrite(backRightPropeler, 0);
        break;

      case 'S':
        Serial.print("Going Backward P");
        module.print("Going Backward P");
        digitalWrite(frontLeftPropeler, 1);
        digitalWrite(frontRightPropeler, 0);
        digitalWrite(backLeftPropeler, 0);
        digitalWrite(backRightPropeler, 1);
        break;

      case 'C':
        Serial.print("Stopping P");
        module.print("Stopping P");
        digitalWrite(frontLeftPropeler, 0);
        digitalWrite(frontRightPropeler, 0);
        digitalWrite(backLeftPropeler, 0);
        digitalWrite(backRightPropeler, 0);
        break;
      case 'A':
        Serial.print("Going Left P");
        module.print("Going Left P");
        digitalWrite(frontLeftPropeler, 0);
        digitalWrite(frontRightPropeler, 0);
        digitalWrite(backLeftPropeler, 1);
        digitalWrite(backRightPropeler, 0);
        break;
      case 'D':
        Serial.print("Going Right P");
        module.print("Going right P");
        digitalWrite(frontLeftPropeler, 0);
        digitalWrite(frontRightPropeler, 1);
        digitalWrite(backLeftPropeler, 0);
        digitalWrite(backRightPropeler, 0);
        break;
      case 'Q':
        Serial.print("Going Backward Left P");
        module.print("Going Backward Left P");
        digitalWrite(frontLeftPropeler, 0);
        digitalWrite(frontRightPropeler, 0);
        digitalWrite(backLeftPropeler, 0);
        digitalWrite(backRightPropeler, 1);
        break;
      case 'E':
        Serial.print("Going Backward Right P");
        module.print("Going Backward Right P");
        digitalWrite(frontLeftPropeler,  0);
        digitalWrite(frontRightPropeler, 1);
        digitalWrite(backLeftMotor, 0);
        digitalWrite(backRightMotor, 0);
        break;
      case 'v':
        if (!isVacuum) {
          Serial.print("Turning on Vacuum!!");
          module.print("Turning on Vacuum!!");
          digitalWrite(vacuum,  0);
          digitalWrite(vacuum1, 1);
          isVacuum = true;
        } else {
          Serial.print("Turning off Vacuum!!");
          module.print("Turning off Vacuum!!");
          digitalWrite(vacuum,  0);
          digitalWrite(vacuum1, 0);
          isVacuum = false;
        }
        break;
      case 'b':
        if (!isBelt) {
          Serial.print("Turning on Belt!!");
          module.print("Turning on Belt!!");
          digitalWrite(belt,  1);
          digitalWrite(belt1, 0);
          isBelt = true;
        } else {
          Serial.print("Turning off Belt!!");
          module.print("Turning off Belt!!");
          digitalWrite(belt,  0);
          digitalWrite(belt1, 0);
          isBelt = false;
        }
        break;
      default:
        module.println("An error Occured");
    }
  }
  delay(1000);
}
