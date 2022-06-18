#include "../headers/Game.h"
#include "../headers/Window.h"

#include <SDL2/SDL.h>

Game::Game(){
  window = Window::get_window();
  is_running = true;
}

void Game::limit_frame_rate(Uint32 &starting_t){
  if(1000 / starting_t > SDL_GetTicks() - starting_t){
    SDL_Delay(1000/starting_t - SDL_GetTicks() + starting_t);
  }
}

void Game::start_game(){

  Uint32 starting_tick;

  while(is_running){ 

    starting_tick = SDL_GetTicks();

    while(SDL_PollEvent(&event)){
      if(event.type == SDL_QUIT){
        is_running = false;
      }
    }
    limit_frame_rate(starting_tick);
  }

  Window::destroy_window();
  SDL_Quit();
}