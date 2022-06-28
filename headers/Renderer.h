#ifndef RENDERER_H
#define RENDERER_H
#include "Board.h"

#include <SDL2/SDL.h>
#include <vector>

class Renderer {
  SDL_Renderer* rend;
  Board* board;
public:
  Renderer(SDL_Window* &w, Board* b);
  ~Renderer();

  void render_board(std::vector<int> &possible_moves);
};

#endif