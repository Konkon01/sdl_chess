#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <SDL2/SDL.h>

class EventHandler {
private:
  SDL_Event event;
public:

  SDL_Event& get_event();
  void handle_events();
};

#endif