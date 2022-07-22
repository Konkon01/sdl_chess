#ifndef RENDERER_H
#define RENDERER_H
#include "Board.h"
#include "Piece.h"

#include <SDL2/SDL.h>
#include <set>
#include <vector>

class Renderer
{
  SDL_Renderer *rend;
  Board *board;
  std::vector<Piece *> pieces;

  int get_piece_index(char piece_char);
  bool is_possible_move(int p_ind, std::set<int> &possible_moves);

public:
  Renderer(SDL_Window *&w, Board *b);
  ~Renderer();

  void render_board(std::set<int> &possible_moves);
};

#endif