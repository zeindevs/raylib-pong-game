#ifndef H_BALL
#define H_BALL

#include "raylib.h"

class Ball {
public:
  float x, y;
  int speed_x, speed_y;
  int radius;
  Color color;

  void Draw();
  void Update(int *player_score, int *computer_score);
  void ResetBall();
};

#endif // H_BALL