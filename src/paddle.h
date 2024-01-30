#ifndef H_PADDLE
#define H_PADDLE

#include "ball.h"
#include "raylib.h"

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

#endif // H_PADDLE