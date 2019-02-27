/* * Arduino Joystick Library
 * https://github.com/MHeironimus/ArduinoJoystickLibrary/
 */
 
#include <Joystick.h>
Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD, 18, 0,
 false, false, false, false, false, false, false, false, false, false, false);

byte ButtonPins[] = {2,3,4,5,6,7,8,9,10,11,12,13,A0,A1,A2,A3,A4,A5};
byte ButtonCount = sizeof(ButtonPins) / sizeof(ButtonPins[0]);
int ReportDelay = 700;
unsigned long ReportRate;

void setup() {
  Serial.begin(9600) ;
  Joystick.begin();
  
  // setup I/O for pins
  for(int i=0;i<ButtonCount;i++) {
    pinMode(ButtonPins[i],INPUT_PULLUP);
  }
}

void loop() {
  ReportRate = micros() ;
  // read buttons
  for(int i=0;i<ButtonCount;i++) {
    if(digitalRead(ButtonPins[i])==LOW) {
      Joystick.setButton (i,1);
    } else {
      Joystick.setButton (i,0);
    }
  }

  //report
  Joystick.sendState();
  delayMicroseconds(ReportDelay);
  //ReportRate Display
  Serial.print(micros() - ReportRate) ;
  Serial.println(" micro sec per loop") ;
}
