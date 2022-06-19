#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>

class Game {
private:
  SDL_Window* window;

  bool is_running;

public:
  Game();
  void start_game();
};

#endif