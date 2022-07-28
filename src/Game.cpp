#include "../headers/Game.h"
#include "../headers/EventHandler.h"
#include "../headers/Board.h"
#include "../headers/Renderer.h"
#include "../headers/Field.h"

#include <SDL2/SDL.h>
#include <iostream>
#include <set>

Game::Game(){
  SDL_Init(SDL_INIT_EVERYTHING);
  window = SDL_CreateWindow("Chess Game",
                            SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED,
                            FIELD_WIDTH * 8,
                            FIELD_HEIGHT * 8,
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

  std::set<int> possible_moves;
  renderer->render_board(possible_moves);

  bool running = true;
  while (running)
  {
    event_handler->handle_events(possible_moves, running);
    renderer->render_board(possible_moves);
  }
  clean_up();
}