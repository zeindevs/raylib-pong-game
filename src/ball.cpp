#include "ball.hpp"

#include <raylib.h>

void Ball::Draw() { DrawCircle(x, y, radius, color); }

void Ball::Update(int *player_score, int *computer_score) {
  x += speed_x;
  y += speed_y;

  if (y + radius >= GetScreenHeight() || y - radius <= 0) {
    speed_y *= -1;
  }
  // Computer wins
  if (x + radius >= GetScreenWidth()) {
    *computer_score += 1;
    ResetBall();
  }
  if (x - radius <= 0) {
    *player_score += 1;
    ResetBall();
  }
}

void Ball::ResetBall() {
  x = int(GetScreenWidth() / 2);
  y = int(GetScreenHeight() / 2);

  int speed_choices[2] = {-1, 1};
  speed_x *= speed_choices[GetRandomValue(0, 1)];
  speed_y *= speed_choices[GetRandomValue(0, 1)];
}