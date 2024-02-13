#include <raylib.h>

#include "ball.hpp"
#include "computer.hpp"
#include "paddle.hpp"

Color Green = Color{38, 185, 154, 255};
Color Dark_Green = Color{20, 160, 133, 255};
Color Light_Green = Color{129, 204, 184, 255};
Color Yellow = Color{243, 213, 91, 255};

int player_score = 0;
int computer_score = 0;

Ball ball;
Paddle player;
Computer computer;

int main() {
  const int screen_width = 1080;
  const int screen_height = 640;

  InitWindow(screen_width, screen_height, "Pong Game!");
  SetTargetFPS(60);

  ball.radius = 15;
  ball.x = int(screen_width / 2);
  ball.y = int(screen_height / 2);
  ball.speed_x = 7;
  ball.speed_y = 7;
  ball.color = Yellow;

  player.width = 15;
  player.height = 120;
  player.x = screen_width - player.width - 10;
  player.y = int(screen_height / 2) - player.height / 2;
  player.speed = 6;
  player.color = WHITE;

  computer.width = 15;
  computer.height = 120;
  computer.x = computer.width - 5;
  computer.y = int(screen_height / 2) - computer.height / 2;
  computer.speed = 6;
  computer.color = WHITE;

  while (WindowShouldClose() == false) {
    BeginDrawing();

    // Update
    ball.Update(&player_score, &computer_score);
    player.Update();
    computer.Update(ball.y);

    // Check for collisions
    if (player.CheckCollision(&ball)) {
      ball.speed_x *= -1;
    }
    if (computer.CheckCollision(&ball)) {
      ball.speed_x *= -1;
    }

    // Drawing
    ClearBackground(Dark_Green);
    DrawRectangle(screen_width / 2, 0, screen_width / 2, screen_height, Green);
    DrawCircle(screen_width / 2, screen_height / 2, 150, Light_Green);
    DrawLine(screen_width / 2, 0, screen_width / 2, screen_height, Light_Green);
    DrawRectangle(0, 0, 120, 35, WHITE);
    DrawFPS(10, 10);

    ball.Draw();
    player.Draw();
    computer.Draw();

    DrawText(TextFormat("%i", computer_score), screen_width / 4 - 20, 20, 50, WHITE);
    DrawText(TextFormat("%i", player_score), 3 * screen_width / 4 - 20, 20, 50, WHITE);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}