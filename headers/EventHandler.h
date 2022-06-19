#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include "Board.h"
#include <SDL2/SDL.h>

class EventHandler {
private:
  SDL_Event event;
  Board* board;
public:
  EventHandler(Board* b);
  SDL_Event& get_event();
  void handle_events();
};

#endif