#include "../headers/MoveCalculator.h"

MoveCalculator::MoveCalculator(Board *b){
  board = b;
}

void MoveCalculator::calculate_moves(int f_ind, char f_piece, std::vector<int> &p_moves){
  if(f_piece == 'P' || f_piece == 'p'){
    calculate_pawn(f_ind, f_piece, p_moves);

  }else if(f_piece == 'R' || f_piece == 'r'){
    calculate_rook(f_ind, f_piece, p_moves);

  }else if(f_piece == 'H' || f_piece == 'h'){
    calculate_horse(f_ind, f_piece, p_moves);

  }else if(f_piece == 'B' || f_piece == 'b'){
    calculate_bishop(f_ind, f_piece, p_moves);

  }else if(f_piece == 'Q' || f_piece == 'q'){
    calculate_queen(f_ind, f_piece, p_moves);

  }else if(f_piece == 'K' || f_piece == 'k'){
    calculate_king(f_ind, f_piece, p_moves);
  }
}

void MoveCalculator::calculate_pawn(int f_ind, char f_piece, std::vector<int> &p_moves){}
void MoveCalculator::calculate_rook(int f_ind, char f_piece, std::vector<int> &p_moves){}
void MoveCalculator::calculate_horse(int f_ind, char f_piece, std::vector<int> &p_moves){}
void MoveCalculator::calculate_bishop(int f_ind, char f_piece, std::vector<int> &p_moves){}
void MoveCalculator::calculate_queen(int f_ind, char f_piece, std::vector<int> &p_moves){}
void MoveCalculator::calculate_king(int f_ind, char f_piece, std::vector<int> &p_moves){}
  
bool MoveCalculator::is_same_team(char p1, char p2){
  return (p1 < 91 && p2 < 91) || (p1 > 91 || p2 > 91);
}

void MoveCalculator::left_to_right(int f_ind, char f_piece, std::vector<int> &p_moves){
  //ROOK and QUEEN
}
void MoveCalculator::upper_left_to_lower_right(int f_ind, char f_piece, std::vector<int> &p_moves){
  //BISHOP and QUEEN
}
void MoveCalculator::up_to_down(int f_ind, char f_piece, std::vector<int> &p_moves){
  //ROOK and QUEEN
}
void MoveCalculator::lower_left_to_upper_right(int f_ind, char f_piece, std::vector<int> &p_moves){
  //BISHOP and QUEEN
}
