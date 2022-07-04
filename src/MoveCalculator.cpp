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