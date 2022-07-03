#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include "Board.h"
#include <SDL2/SDL.h>
#include <vector>

class EventHandler {
private:
  SDL_Event event;
  Board* board;
  bool is_running;
public:
  EventHandler(Board* b);
  SDL_Event& get_event();
  void handle_events(std::vector<int> &possible_moves, bool &running);
};

#endif