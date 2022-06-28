#ifndef GAME_H
#define GAME_H
#include <SDL2/SDL.h>
#include "../headers/Board.h"
#include "../headers/Renderer.h"
#include "../headers/EventHandler.h"

class Game {
private:
  SDL_Window* window;
  Board* board;
  EventHandler* event_handler;
  Renderer* renderer;

  void clean_up();

public:
  Game();
  void start_game();
};

#endif