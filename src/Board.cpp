#include "../headers/Board.h"

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
