#ifndef H_COMPUTER
#define H_COMPUTER

#include "paddle.h"

class Computer : public Paddle {
public:
  void Update(int ball_y);
};

#endif // H_COMPUTER