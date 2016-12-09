/*
 * Handles the OLED display objects
 */

#include "Arduino.h"
#include "Pablo.h"

U8G2_SSD1306_128X64_NONAME_1_SW_I2C OLEDScreen(U8G2_R0, /* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

// See Fonts available here:
// https://github.com/olikraus/u8g2/wiki/fntlistall 

void Pablo::setupDisplay(){
  // Initialise the OLED display
  // Note: it is necessary to change a value in the Adafruit_SSD1306 library to set the screen size to 128x64
  OLEDScreen.begin();

  OLEDScreen.firstPage();
  do {
    OLEDScreen.setFont(u8g2_font_fub25_tr);
    OLEDScreen.drawStr(18,35,"Pablo");

    OLEDScreen.setFont(u8g2_font_etl14thai_t);
    OLEDScreen.drawStr(35,55,"Hello :)");

  } while ( OLEDScreen.nextPage() );

  /*

  // Write "Hello" in small
  OLEDScreen.setTextSize(2);
  OLEDScreen.setCursor(20, 45);
  OLEDScreen.print("Hello :)"); //this copies some text to the screens memory
  OLEDScreen.display();
  */

  delay(100000);
}

/*
 *
 *  SCREEN HANDLING
 *
 */

void Pablo::report() {
  /*
  OLEDScreen.clearDisplay();

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(36 , 0);
  OLEDScreen.print("< speed >");
  OLEDScreen.setCursor(39 , 28);
  OLEDScreen.print("/ dist \\");

  OLEDScreen.setCursor(50 , 18);
  OLEDScreen.print("+");
  OLEDScreen.setCursor(55 , 18);
  OLEDScreen.print(rotary_increment);

  OLEDScreen.setTextSize(2);

  // write core settings to screen
  OLEDScreen.setTextColor(1);
  OLEDScreen.setCursor(66, 46);
  OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory
  OLEDScreen.setCursor(103, 3);
  OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory
  OLEDScreen.setCursor(3, 3);
  OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
  OLEDScreen.setCursor(3, 46);
  OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory

  // mat working on mouse over for 1 encoder
  if (rotaryMode == 0) {
    OLEDScreen.drawRect(64, 43, 63, 20, 1);

  } else if (rotaryMode == 1) {
    OLEDScreen.drawRect(100,0, 28, 20, 1);

  } else if (rotaryMode == 2) {
    OLEDScreen.drawRect(0,0,28,20, 1);

  } else if (rotaryMode == 3) {
    OLEDScreen.drawRect(0, 43 , 63, 20, 1);
  }

  OLEDScreen.display();
  */
}

void Pablo::message(String text) {
  /*
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(20, 20);
  OLEDScreen.print(text); //this copies some text to the screens memory
  OLEDScreen.display();
  */
}

void Pablo::messageLarge(String text) {
  /*
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(2);
  OLEDScreen.setCursor(20, 20);
  OLEDScreen.print(text); //this copies some text to the screens memory
  OLEDScreen.display();
  */
}

void Pablo::message(int text) {
  /*
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(20, 20);
  OLEDScreen.print(text); //this copies some text to the screens memory
  OLEDScreen.display();
  */
}

void Pablo::displayStartMessage() {
  displayCountDown(3);
  delay(1000);
  displayCountDown(2);
  delay(1000);
  displayCountDown(1);
  delay(1000);

  /*
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(4);
  OLEDScreen.setCursor(40, 20);
  OLEDScreen.print(":)"); //this copies some text to the screens memory

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(0, 0);
  OLEDScreen.print(setting_left_wheel_speed); //this copies some text to the screens memory
  OLEDScreen.setCursor(110, 0);
  OLEDScreen.print(setting_right_wheel_speed); //this copies some text to the screens memory

  OLEDScreen.setCursor(0, 50);
  OLEDScreen.print(setting_left_wheel_distance); //this copies some text to the screens memory

  OLEDScreen.setCursor(110, 50);
  OLEDScreen.print(setting_right_wheel_distance); //this copies some text to the screens memory

  OLEDScreen.display();
  */
}

void Pablo::displayCountDown(int count) {
  /*
  OLEDScreen.clearDisplay();
  OLEDScreen.setTextSize(2);
  OLEDScreen.setCursor(10 , 5);
  OLEDScreen.print("STEP BACK");

  OLEDScreen.setTextSize(1);
  OLEDScreen.setCursor(10 , 40);
  OLEDScreen.print("Starting in: "); //this copies some text to the screens memory

  OLEDScreen.setTextSize(4);
  OLEDScreen.setCursor(94 , 30);
  OLEDScreen.print(count); //this copies some text to the screens memory
  OLEDScreen.display();
  */
}


