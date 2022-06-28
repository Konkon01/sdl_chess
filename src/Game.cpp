#include "../headers/Game.h"
#include "../headers/Window.h"
#include "../headers/EventHandler.h"
#include "../headers/Board.h"
#include "../headers/Renderer.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <vector>


#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 720

Game::Game(){
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("Chess Game",
                          SDL_WINDOWPOS_CENTERED,
                          SDL_WINDOWPOS_CENTERED,
                          SCREEN_WIDTH,
                          SCREEN_HEIGHT,
                          SDL_WINDOW_SHOWN);
  board = new Board();
  event_handler = new EventHandler(board);
  renderer = new Renderer(window, board);
}

void Game::clean_up(){
  delete board;
  delete event_handler;
  delete renderer;
  SDL_DestroyWindow(window);
  SDL_Quit();
}

void Game::start_game(){

  Uint32 starting_tick;

  SDL_Event event = event_handler->get_event();

  while (SDL_WaitEvent(&event)){
    std::vector<int> possible_moves;
    if (event.type == SDL_QUIT){
      break;
    
    }else{
      event_handler->handle_events(possible_moves);

    }
    renderer->render_board(possible_moves);
  }

  clean_up();
}