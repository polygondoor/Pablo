#include "Arduino.h"
#include "Pablo.h"

Pablo::Pablo()
{
  _pabloVersion = PABLO_V1;
}

Pablo::Pablo(int pabloVersion){
  _pabloVersion = pabloVersion;
}

void Pablo::init(String botName, String botMessage){
  _botMessage = botMessage;
  _botName = botName;
  init();
}

void Pablo::init(String botName){
  _botName = botName;
  init();
}

void Pablo::init(){

  // Use different button position based on whether old or new Pablo
  // This is because the button key pad may be upside down
  if (_pabloVersion == PABLO_V2 ) {

    buttonIncThousands= 22; // K0: 22
    buttonIncHundreds = 23; // K1: 23
    buttonIncTens     = 24; // K2: 24
    buttonIncOnes    = 25;  // K3: 25

    buttonDrawingMode = 29; // K4: 26
    buttonUnused = 27;      // K5: 27
    buttonPresets = 28;     // K6: 28
    buttonStart = 26;       // K7: 29

  } else {

    buttonIncThousands= 22;  // K0: 22
    buttonIncHundreds = 23;  // K1: 23
    buttonIncTens     = 24;  // K2: 24
    buttonIncOnes     = 25;  // K3: 25

    buttonDrawingMode = 26;  // K4: 26
    buttonUnused = 27;       // K5: 27
    buttonPresets = 28;      // K6: 28
    buttonStart = 29;        // K7: 29

  }


  // sort out pinmodes for the motor driver
  pinMode(2,  OUTPUT);
  pinMode(3,  OUTPUT);
  pinMode(4,  OUTPUT);
  pinMode(5,  OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(7,  OUTPUT);
  pinMode(8,  OUTPUT);
  pinMode(9,  OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(6,  HIGH);
  digitalWrite(9,  HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);

  setupMotors();
  setupDisplay();
  setupRotaryEncoder();
  setupButtons();

}

void Pablo::run(){

  // stay here as long as we are not in custom mode
  while ( drawingMode == 0 ) {
    default_mode();
  } 
  
}

/*
 * Waits for start button to be pressed
 */
bool Pablo::waitForStartButton(){

  // dis-engage the motors;
  stepper_l -> disableOutputs();
  stepper_r -> disableOutputs();

  while ( digitalRead(buttonStart) == HIGH ) {
    delay(100);
  }

  // engage the motors;
  stepper_l -> enableOutputs();
  stepper_r -> enableOutputs();

  return true;
}

void Pablo::readModeButton(){
  
  if ( digitalRead(buttonDrawingMode) == LOW ) {
    // mode button pressed

    if ( buttonDrawingMode_state == 0) {
      // if we get here then it is a fresh push
      
      buttonDrawingMode_state = 1;
      drawingMode ++;
      if (drawingMode > 1) drawingMode = 0;
    } 

  } else {
    // mode button unpressed, 
    buttonDrawingMode_state = 0;
  }
  
}

