#pragma once

#include "paddle.hpp"

class Computer : public Paddle {
 public:
  void Update(int ball_y);
};
