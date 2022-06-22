#ifndef RENDERER_H
#define RENDERER_H
#include "Board.h"

#include <SDL2/SDL.h>
#include <vector>

class Renderer {
  SDL_Renderer* renderer;
  Board* board;
public:
  Renderer(SDL_Window* w, Board* b);

};

#endif