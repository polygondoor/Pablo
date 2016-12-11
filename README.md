## Synopsis

Pablo is an Arduino based drawing machine. This library allows the user to drive Pablo by manipulating a hardware UI interface, but also to write code in the Arduino software development environment, that will then be executed on the drawing machine.

## Code Example

Pablo's basic command is `pablo.turn_wheels_mm(50, 100);` This command will result in the left wheel turning 50mm and the right wheel turning 100mm (this will create an arc).

A full example Arduino *.ino sketch wwill look something like this:

```cpp
#include <Pablo.h>

Pablo pablo;

void setup() {
  pablo.init();
}

void loop() {
  pablo.run();

  // Displays a message on Artbot's little screen
  pablo.message("  Press Start");

  // Wait for the start button to be pressed
  pablo.waitForStartButton();

  // Turn both wheels in the same directiom
  pablo.turn_wheels_mm(100, 100);

  pablo.message(" Fin!");
  delay(5000);

}
```


## Motivation

A short description of the motivation behind the creation and maintenance of the project. This should explain **why** the project exists.

## Installation

Provide code examples and explanations of how to get the project.

## API Reference

Depending on the size of the project, if it is small and simple enough the reference docs can be added to the README. For medium size to larger projects it is important to at least provide a link to where the API reference docs live.

## Tests

Describe and show how to run the tests with code examples.

## Contributors

Let people know how they can dive into the project, include important links to things like issue trackers, irc, twitter accounts if applicable.

## License

A short snippet describing the license (MIT, Apache, etc.)