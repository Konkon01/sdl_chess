#include "../headers/Game.h"
#include "../headers/Window.h"
#include "../headers/EventHandler.h"

#include <SDL2/SDL.h>

Game::Game(){
  SDL_Init(SDL_INIT_EVERYTHING);
  window = Window::get_window();
  is_running = true;
}

void Game::start_game(){

  Uint32 starting_tick;

  while(is_running){ 

    EventHandler event_handler;
    SDL_Event event = event_handler.get_event();

    while(SDL_WaitEvent(&event)){
      if(event.type == SDL_QUIT){
        is_running = false;
      } else {
        event_handler.handle_events();
      }
    }
  }

  Window::destroy_window();
  SDL_Quit();
}