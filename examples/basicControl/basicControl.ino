#include <Pablo.h>

Pablo pablo;

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  // Display a message and wait for start button
  pablo.message("  Press Start");
  pablo.waitForStartButton();

  pablo.message(" Drawing! ");
  // Turn the left wheel 50mm, and the right wheel 100mm
  pablo.turn_wheels_mm(50, 100);

}
