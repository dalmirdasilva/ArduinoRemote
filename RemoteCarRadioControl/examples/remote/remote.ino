#include <SoftwareSerial.h>
#include <LiquidCrystal.h>
#include <LCDKeypad.h>

SoftwareSerial serial(A3, A4);
LCDKeypad lcd;

void setup() {
  
  pinMode(A1, OUTPUT);
  digitalWrite(A1, HIGH);
  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH);
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);
  
  Serial.begin(9600);
  serial.begin(9600);
  Serial.println("init");
  
  lcd.begin(16, 2);
  lcd.clear();
  lcd.print("     Remote");
  lcd.setCursor(0, 1);
  lcd.print("   Control");
}

char action, lastAction = 'S';
void loop() {
  int bottom, buttonPressed;
  char cmd[2];
  cmd[1] = ';';
  buttonPressed = lcd.button();
  switch (buttonPressed) {
    case KEYPAD_DOWN:
      if (lastAction != 'B') {
        lastAction = 'B';
        cmd[0] = lastAction;
        serial.print(cmd);
      }
    break;
    case KEYPAD_LEFT:
      if (lastAction != 'L') {
        lastAction = 'L';
        cmd[0] = lastAction;
        serial.print(cmd);
      }
    break;
    case KEYPAD_RIGHT:
      if (lastAction != 'R') {
        lastAction = 'R';
        cmd[0] = lastAction;
        serial.print(cmd);
      }
    break;
    case KEYPAD_NONE:
      if (lastAction != 'S') {
        lastAction = 'S';
        cmd[0] = lastAction;
        serial.print(cmd);
      }
    break;
    default:
      if (lastAction != 'F') {
        lastAction = 'F';
        cmd[0] = lastAction;
        serial.print(cmd);
      }
  }
  
  if (action != lastAction) {
    lcd.clear();
    lcd.print("Action: ");
    switch(lastAction) {
      case 'L':
        lcd.print("LEFT");
      break;
      case 'R':
        lcd.print("RIGHT");
      break;
      case 'F':
        lcd.print("FORWARD");
      break;
      case 'B':
        lcd.print("BACKWARD");
      break;
      case 'S':
        lcd.print("STOP");
      break;
    }
    action = lastAction;
  }
}
