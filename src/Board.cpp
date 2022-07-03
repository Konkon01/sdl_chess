#include "../headers/Board.h"
#include "../headers/Field.h"

#include <utility>

Board::Board(){
    /*         STARTING CHESSBOARD
     'r', 'h', 'b', 'q', 'k', 'b', 'h', 'r',
     'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
     'x', 'x', 'x', 'x', 'x', 'x', 'x', 'x',
     'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
     'R', 'H', 'B', 'Q', 'K', 'B', 'H', 'R'
     */
    board[0] = 'r';
    board[1] = 'h';
    board[2] = 'b';
    board[3] = 'q';
    board[4] = 'k';
    board[5] = 'b';
    board[6] = 'h';
    board[7] = 'r';
    for(int i = 8; i <= 15; i++){
      board[i] = 'p';
    }
    for(int i = 16; i <= 47; i++){
      board[i] = 'x';
    }
    for(int i = 48; i <= 55; i++){
      board[i] = 'P';
    }
    board[56] = 'R';
    board[57] = 'H';
    board[58] = 'B';
    board[59] = 'Q';
    board[60] = 'K';
    board[61] = 'B';
    board[62] = 'H';
    board[63] = 'R';
}

std::pair<int, int> Board::get_coord_from_ind(int i){
  std::pair<int, int> coord;
  
  //Upper left corner of the rectangle
  coord.first = (i % 8) * FIELD_WIDTH;
  coord.second = (i / 8) * FIELD_HEIGHT;
  
  return coord;
}

int Board::get_ind_from_coord(std::pair<int, int> coord){
  
  int x = coord.first / FIELD_WIDTH;
  int y = coord.second / FIELD_HEIGHT;

  return y * 8 + x;
}

char Board::get_piece_at(int ind){
  return board[ind];
}

void Board::move_piece(int from, int to){
  board[to] = board[from];
  board[from] = 'x';
}