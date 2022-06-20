#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include "../headers/Board.h"

class Game {
private:
  SDL_Window* window;
  SDL_Surface* surf;
  Board* board;

  void clean_up();

public:
  Game();
  void start_game();
};

#endif