#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

using std::size_t;

class Renderer {
 public:
  Renderer(const size_t screen_width, const size_t screen_height,
           const size_t grid_width, const size_t grid_height);
  ~Renderer();

  void Render(Snake const snake, SDL_Point const &food, bool *wall, bool *poisoned);
  void UpdateWindowTitle(int score, int fps);
  void SetPauseTitle();

 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;

  const size_t screen_width;
  const size_t screen_height;
  const size_t grid_width;
  const size_t grid_height;
};

#endif