#include "../headers/Renderer.h"


Renderer::Renderer(SDL_Window* w, Board* b){
  renderer = SDL_CreateRenderer(w, -1, SDL_RENDERER_ACCELERATED);
  board = b;
}
