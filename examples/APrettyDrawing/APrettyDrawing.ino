/*
 * This example uses a loop to repeat several lines in a radial pattern.
 */
#include <Pablo.h>

Pablo pablo;
float d = 100.0; // this variable determines the distance of the each stem on the seed head

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  // Display a message and wait for start button
  pablo.message("  Press Start");
  pablo.waitForStartButton();

  pablo.message(" A Seed Head! ");
  // Start drawing
  for (int i = 0; i < 50; i++) {
    // arc
    pablo.turn_wheels_mm(d/2, d);
    pablo.turn_wheels_mm(-d/2, -d);

    // straight line
    pablo.turn_wheels_mm(d, d);
    pablo.turn_wheels_mm(-d, -d);

    // arc in other direction
    pablo.turn_wheels_mm(d, d/2);
    pablo.turn_wheels_mm(-d, -d/2);

    // rotate a bit
    pablo.turn_wheels_mm(-20, 20);

    // reduce length of stem
    d = d * 0.98;
  }

}