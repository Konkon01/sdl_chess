#include "../headers/EventHandler.h"
#include "../headers/Board.h"
#include <SDL2/SDL.h>
#include <iostream>

EventHandler::EventHandler(Board* b){
  board = b;
}

SDL_Event& EventHandler::get_event(){
  return event;
}

void EventHandler::handle_events(std::vector<int> &possible_moves, bool &running){
  
  while(SDL_WaitEvent(&event)){
    
    if(event.type == SDL_QUIT){
      running = false;
      break;
    }
  }

}
