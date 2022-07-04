#ifndef MOVECALCULATOR_H
#define MOVECALCULATOR_H
#include "../headers/Board.h"
#include <vector>

class MoveCalculator {
  Board *board;

  void calculate_pawn(int f_ind, char f_piece, std::vector<int> &p_moves);
  void calculate_rook(int f_ind, char f_piece, std::vector<int> &p_moves);
  void calculate_horse(int f_ind, char f_piece, std::vector<int> &p_moves);
  void calculate_bishop(int f_ind, char f_piece, std::vector<int> &p_moves);
  void calculate_queen(int f_ind, char f_piece, std::vector<int> &p_moves);
  void calculate_king(int f_ind, char f_piece, std::vector<int> &p_moves);
public:
  MoveCalculator(Board *b);

  void calculate_moves(int f_ind, char f_piece, std::vector<int> &p_moves);
};

#endif