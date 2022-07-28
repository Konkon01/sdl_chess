#ifndef MOVECALCULATOR_H
#define MOVECALCULATOR_H
#include "../headers/Board.h"
#include <set>

class MoveCalculator{
  Board *board;

  void calculate_pawn(int f_ind, char f_piece, std::set<int> &p_moves);
  void calculate_rook(int f_ind, char f_piece, std::set<int> &p_moves);
  void calculate_horse(int f_ind, char f_piece, std::set<int> &p_moves);
  void calculate_bishop(int f_ind, char f_piece, std::set<int> &p_moves);
  void calculate_queen(int f_ind, char f_piece, std::set<int> &p_moves);
  void calculate_king(int f_ind, char f_piece, std::set<int> &p_moves);

  void basic_king_calculation(int f_ind, char f_piece, std::set<int> &p_moves);

  bool is_same_team(char p1, char p2);
  bool in_opp_moves(int ind, std::set<int> &opp_moves);

  void left_to_right(int f_ind, char f_piece, std::set<int> &p_moves);
  void upper_left_to_lower_right(int f_ind, char f_piece, std::set<int> &p_moves);
  void up_to_down(int f_ind, char f_piece, std::set<int> &p_moves);
  void lower_left_to_upper_right(int f_ind, char f_piece, std::set<int> &p_moves);

public:
  MoveCalculator(Board *b);

  void calculate_moves(int f_ind, char f_piece, std::set<int> &p_moves);
};

#endif