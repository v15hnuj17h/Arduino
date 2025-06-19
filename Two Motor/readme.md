# Arduino Motor Control Project

This project demonstrates basic motor control using an Arduino and an H-bridge motor driver (e.g., L298N). The robot can move forward, backward, turn left, turn right, and stop, using two DC motors.

## 🛠 Hardware Required

- Arduino Uno (or compatible board)
- L298N Motor Driver Module
- 2x DC Motors
- Power Supply (e.g., 9V battery or battery pack)
- Jumper Wires
- Breadboard (optional)

## ⚙️ Wiring

| Arduino Pin | Motor Driver Pin | Function       |
|-------------|------------------|----------------|
| 2           | IN1              | Motor A control |
| 3           | IN2              | Motor A control |
| 4           | IN3              | Motor B control |
| 5           | IN4              | Motor B control |
| 10          | ENA              | Motor A speed   |
| 11          | ENB              | Motor B speed   |

**Note:** Connect the motor driver `GND` to Arduino `GND`, and make sure the motors are powered adequately.

## 🚦 Functions

- `forward()`: Moves the robot forward.
- `backward()`: Moves the robot backward.
- `turnLeft()`: Turns the robot to the left.
- `turnRight()`: Turns the robot to the right.
- `stop()`: Stops the robot.

## 💡 Example Usage

To move the robot forward for 2 seconds:

```cpp
void loop() {
  forward();
  delay(2000);
  stop();
  delay(1000);
}
