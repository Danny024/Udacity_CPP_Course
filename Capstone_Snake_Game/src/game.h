#ifndef GAME_H
#define GAME_H

#include <random>
#include "SDL.h"
#include "controller.h"
#include "renderer.h"
#include "snake.h"

using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::size_t;


class Game {
 public:
  Game(size_t grid_width, size_t grid_height);
  void Run(Controller const &controller, Renderer *renderer,
           size_t target_frame_duration);
  int GetScore() const;
  int GetSize() const;
  // methods for pausing/resuming the game
  void EnablePause();

 friend class Controller;

 protected:
  bool _wall; // wall around the game screen

 private:
  Snake snake;
  SDL_Point food;
  // Renderer _renderer;
  // pause state
  // true if game is paused
  bool _paused;
  bool _poisoned;

  random_device dev;
  mt19937 engine;
  uniform_int_distribution<int> random_w;
  uniform_int_distribution<int> random_h;

  int score{0};

  void PlaceFood();
  void Update(Renderer *renderer);
  void PauseGame();
  void ResumeGame();

};

#endif