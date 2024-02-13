#pragma once

#include <raylib.h>

#include "ball.hpp"

class Paddle {
 public:
  float x, y;
  float width, height;
  int speed;
  Color color;

  void Draw();
  void Update();
  void LimitMovement();
  bool CheckCollision(Ball *ball);
};