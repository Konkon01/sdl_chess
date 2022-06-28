#include "../headers/EventHandler.h"
#include "../headers/Board.h"
#include <SDL2/SDL.h>

EventHandler::EventHandler(Board* b){
  board = b;
}

SDL_Event& EventHandler::get_event(){
  return event;
}

void EventHandler::handle_events(std::vector<int> &possible_moves){
  /*Going to implement it later*/
}
