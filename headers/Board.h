#ifndef BOARD_H
#define BOARD_H
#include <utility>

class Board {
  friend class Renderer;

  char board[64];
public:
  Board();
  
  std::pair<int, int> get_coord_from_ind(int i);
  int get_ind_from_coord(std::pair<int, int> coord);
};

#endif