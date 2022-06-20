#include "../headers/Game.h"
#include "../headers/Window.h"
#include "../headers/EventHandler.h"
#include "../headers/Board.h"

#include <SDL2/SDL.h>
#include <iostream>

Game::Game(){
  SDL_Init(SDL_INIT_EVERYTHING);
  window = Window::get_window();
  board = new Board();
}

void Game::clean_up(){
  delete board;
  Window::destroy_window();
  SDL_Quit();
}

void Game::start_game(){

  Uint32 starting_tick;


  EventHandler event_handler(board);
  SDL_Event event = event_handler.get_event();

  while (SDL_WaitEvent(&event)){
    if (event.type == SDL_QUIT){
      break;
    }
    else{
      event_handler.handle_events();
    }
  }

  clean_up();
}