#include <iostream>
#include "controller.h"
#include "game.h"
#include "renderer.h"

using std::cout;
using std::size_t;


int main() {
  constexpr size_t kFramesPerSecond{60};
  constexpr size_t kMsPerFrame{1000 / kFramesPerSecond};
  constexpr size_t kScreenWidth{640};
  constexpr size_t kScreenHeight{640};
  constexpr size_t kGridWidth{32};
  constexpr size_t kGridHeight{32};

  Renderer renderer(kScreenWidth, kScreenHeight, kGridWidth, kGridHeight);
  Controller controller;
  Game game(kGridWidth, kGridHeight);
  game.Run(controller, &renderer, kMsPerFrame);
  cout << "Game has terminated successfully!\n";
  cout << "Score: " << game.GetScore() << "\n";
  cout << "Size: " << game.GetSize() << "\n"; 
  return 0;
}