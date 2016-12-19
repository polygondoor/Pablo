#include <Pablo.h>

Pablo pablo;

void setup() {
  pablo.init();
}

int distance = 30;

void loop() {
  pablo.run();

  pablo.message("  Press Start");
  pablo.waitForStartButton();

  /*
   * It is very easy, and incredibly useful, to change the value of a variable.
   * The belwo line, for example, change 'distance' to be a little smaller.
   * This line is not algebra! It doesn't make sense as algebra.
   * But it makes sense to the computer.
   * All it is saying is: "make the new value of distance be equal to the old value less 10"
   */
  distance = distance - 10;

  /*
   * Now, each time someone presses 'start' on Pablo, it will move 10mm less far.
   * Eventually, it will move backwards!
   */
  pablo.turn_wheels_mm(distance, distance);

}