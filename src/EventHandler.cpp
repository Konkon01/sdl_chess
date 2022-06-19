#include "../headers/EventHandler.h"
#include <SDL2/SDL.h>

SDL_Event& EventHandler::get_event(){
  return event;
}


