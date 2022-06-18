#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>

#define FRAME_RATE 30

class Game {
private:
  SDL_Window* window;
  SDL_Event event;
  bool is_running;

  void limit_frame_rate(Uint32 &starting_t);

public:
  Game();
  void start_game();
};

#endif