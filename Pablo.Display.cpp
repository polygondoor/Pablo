/*
 * Handles the OLED display objects
 */

#include "Arduino.h"
#include "Pablo.h"

U8G2_SSD1306_128X64_NONAME_F_HW_I2C OLEDScreen(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);   // All Boards without Reset of the Display

// See Fonts available here:
// https://github.com/olikraus/u8g2/wiki/fntlistall 

void Pablo::setupDisplay(){

  // Initialise the OLED display
  OLEDScreen.begin();

  OLEDScreen.clearBuffer();

  OLEDScreen.setFont(u8g2_font_fub25_tr);
  OLEDScreen.drawStr(18,35,"Pablo");
  OLEDScreen.setFont(u8g2_font_etl14thai_t);
  OLEDScreen.drawStr(35,55,"Hello :)");

  OLEDScreen.sendBuffer();

  delay(1000);

}

/*
 *
 *  SCREEN HANDLING
 *
 */
char buf[4];
void Pablo::report() {

  OLEDScreen.clearBuffer();

  OLEDScreen.setFont(u8g2_font_profont12_mf);

  OLEDScreen.drawStr(36,10,"< speed >");
  OLEDScreen.drawStr(39,38,"/ dist \\");
  OLEDScreen.drawStr(50,48,"+");

  sprintf (buf, "%d", rotary_increment);
  OLEDScreen.drawStr(55,18, buf );

  OLEDScreen.setFont(u8g2_font_courB12_tn);
  
  sprintf (buf, "%d", setting_right_wheel_distance);
  OLEDScreen.drawStr(66, 56, buf) ;
  sprintf (buf, "%d", setting_right_wheel_speed);
  OLEDScreen.drawStr(103, 13, buf) ;
  sprintf (buf, "%d", setting_left_wheel_speed);
  OLEDScreen.drawStr(3, 13, buf) ;
  sprintf (buf, "%d", setting_left_wheel_distance);
  OLEDScreen.drawStr(3, 56, buf) ;

  // mat working on mouse over for 1 encoder
  if (rotaryMode == 0) {
    OLEDScreen.drawFrame(64, 43, 63, 20);

  } else if (rotaryMode == 1) {
    OLEDScreen.drawFrame(100,0, 28, 20);

  } else if (rotaryMode == 2) {
    OLEDScreen.drawFrame(0,0,28,20);

  } else if (rotaryMode == 3) {
    OLEDScreen.drawFrame(0, 43 , 63, 20);
  }

  OLEDScreen.sendBuffer();
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


