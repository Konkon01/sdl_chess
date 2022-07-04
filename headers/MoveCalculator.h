#ifndef MOVECALCULATOR_H
#define MOVECALCULATOR_H
#include <vector>

class MoveCalculator {

public:
  void calculate_moves(int f_ind, char f_piece, std::vector<int> &p_moves);
};

#endif