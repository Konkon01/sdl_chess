#include "../headers/Renderer.h"
#include "../headers/Piece.h"
#include "../headers/ErrorLoger.hpp"
#include "../headers/Window.h"

Renderer::Renderer(SDL_Window* &w, Board* b){
  rend = SDL_CreateRenderer(w, -1, 0);
  board = b;
}
Renderer::~Renderer(){
  SDL_DestroyRenderer(rend);
}

void Renderer::render_board(std::vector<int>possible_move_index){
  SDL_SetRenderDrawColor(rend, 0, 0, 0, 255);
  SDL_RenderClear(rend);
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      
      if(i % 2 == 0){
        (j % 2 == 0)? SDL_SetRenderDrawColor(rend, 238, 238, 213, 255) : 
                      SDL_SetRenderDrawColor(rend, 125, 148, 93, 255);
        
      } else {
        (j % 2 == 0)? SDL_SetRenderDrawColor(rend, 125, 148, 93, 255) : 
                      SDL_SetRenderDrawColor(rend, 238, 238, 213, 255);
      
      }
      SDL_Rect rect = {
        i * 80,
        j * 80,
        80,
        80
      };
      SDL_RenderFillRect(rend, &rect);
    }
  }
  SDL_RenderPresent(rend);
}
