#ifndef BOARD_H
#define BOARD_H
#include <utility>

class Board {
  friend class Renderer;
  friend class MoveCalculator;

  char board[64];
public:
  Board();
  
  std::pair<int, int> get_coord_from_ind(int i);
  int get_ind_from_coord(std::pair<int, int> coord);
  char get_piece_at(int ind);
  void move_piece(int from, int to);
};

#endif