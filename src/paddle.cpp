#include "paddle.h"
#include "ball.h"
#include "raylib.h"

void Paddle::Draw() {
  DrawRectangleRounded(Rectangle{x, y, width, height}, 0.8, 0, color);
}

void Paddle::Update() {
  if (IsKeyDown(KEY_UP)) {
    y = y - speed;
  }
  if (IsKeyDown(KEY_DOWN)) {
    y = y + speed;
  }
  LimitMovement();
}

void Paddle::LimitMovement() {
  if (y <= 0) {
    y = 0;
  }
  if (y + height >= GetScreenHeight()) {
    y = GetScreenHeight() - height;
  }
}

bool Paddle::CheckCollision(Ball *ball) {
  return CheckCollisionCircleRec(Vector2{ball->x, ball->y}, ball->radius,
                                 Rectangle{x, y, width, height});
}