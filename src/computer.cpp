#include "computer.hpp"

void Computer::Update(int ball_y) {
  if (y + height / 2 > ball_y) {
    y = y - speed;
  }
  if (y + height / 2 <= ball_y) {
    y = y + speed;
  }
  LimitMovement();
}