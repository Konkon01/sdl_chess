#include "../headers/MoveCalculator.h"
#include <iostream>
#include <set>

MoveCalculator::MoveCalculator(Board *b)
{
  board = b;
}

void MoveCalculator::calculate_moves(int f_ind, char f_piece, std::set<int> &p_moves)
{
  if (f_piece == 'P' || f_piece == 'p')
  {
    calculate_pawn(f_ind, f_piece, p_moves);
  }
  else if (f_piece == 'R' || f_piece == 'r')
  {
    calculate_rook(f_ind, f_piece, p_moves);
  }
  else if (f_piece == 'H' || f_piece == 'h')
  {
    calculate_horse(f_ind, f_piece, p_moves);
  }
  else if (f_piece == 'B' || f_piece == 'b')
  {
    calculate_bishop(f_ind, f_piece, p_moves);
  }
  else if (f_piece == 'Q' || f_piece == 'q')
  {
    calculate_queen(f_ind, f_piece, p_moves);
  }
  else if (f_piece == 'K' || f_piece == 'k')
  {
    calculate_king(f_ind, f_piece, p_moves);
  }
}

void MoveCalculator::calculate_pawn(int f_ind, char f_piece, std::set<int> &p_moves)
{
  std::pair<int, int> coords = board->get_2D_ind_from_ind(f_ind);
  if (f_piece == 'P')
  { // LIGHT
    if (board->board[f_ind - 8] == 'x')
    {
      p_moves.insert(f_ind - 8);
    }

    if (coords.second == 6 && board->board[f_ind - 16] == 'x')
    { // First move of pawn
      p_moves.insert(f_ind - 16);
    }

    char l_piece = board->board[f_ind - 9];
    char r_piece = board->board[f_ind - 7];

    if (l_piece != 'x' && !is_same_team(f_piece, l_piece))
    {
      p_moves.insert(f_ind - 9);
    }
    if (r_piece != 'x' && !is_same_team(f_piece, r_piece))
    {
      p_moves.insert(f_ind - 7);
    }
  }
  else
  {
    if (board->board[f_ind + 8] == 'x')
    {
      p_moves.insert(f_ind + 8);
    }

    if (coords.second == 1 && board->board[f_ind + 16] == 'x')
    { // First move of pawn
      p_moves.insert(f_ind + 16);
    }

    char l_piece = board->board[f_ind + 7];
    char r_piece = board->board[f_ind + 9];

    if (l_piece != 'x' && !is_same_team(f_piece, l_piece))
    {
      p_moves.insert(f_ind + 7);
    }
    if (r_piece != 'x' && !is_same_team(f_piece, r_piece))
    {
      p_moves.insert(f_ind + 9);
    }
  }
}
void MoveCalculator::calculate_rook(int f_ind, char f_piece, std::set<int> &p_moves)
{
  left_to_right(f_ind, f_piece, p_moves);
  up_to_down(f_ind, f_piece, p_moves);
}

void MoveCalculator::calculate_horse(int f_ind, char f_piece, std::set<int> &p_moves)
{
  if (f_ind - 17 >= 0 && ((board->board[f_ind - 17] == 'x') || !is_same_team(f_piece, board->board[f_ind - 17])))
  {
    p_moves.insert(f_ind - 17);
  }
  if (f_ind - 15 >= 0 && ((board->board[f_ind - 15] == 'x') || !is_same_team(f_piece, board->board[f_ind - 15])))
  {
    p_moves.insert(f_ind - 15);
  }
  if (f_ind - 10 >= 0 && ((board->board[f_ind - 10] == 'x') || !is_same_team(f_piece, board->board[f_ind - 10])))
  {
    p_moves.insert(f_ind - 10);
  }
  if (f_ind - 6 >= 0 && ((board->board[f_ind - 6] == 'x') || !is_same_team(f_piece, board->board[f_ind - 6])))
  {
    p_moves.insert(f_ind - 6);
  }
  if (f_ind + 6 < 64 && ((board->board[f_ind + 6] == 'x') || !is_same_team(f_piece, board->board[f_ind + 6])))
  {
    p_moves.insert(f_ind + 6);
  }
  if (f_ind + 10 < 64 && ((board->board[f_ind + 10] == 'x') || !is_same_team(f_piece, board->board[f_ind + 10])))
  {
    p_moves.insert(f_ind + 10);
  }
  if (f_ind + 15 < 64 && ((board->board[f_ind + 15] == 'x') || !is_same_team(f_piece, board->board[f_ind + 15])))
  {
    p_moves.insert(f_ind + 15);
  }
  if (f_ind + 17 < 64 && ((board->board[f_ind + 17] == 'x') || !is_same_team(f_piece, board->board[f_ind + 17])))
  {
    p_moves.insert(f_ind + 17);
  }
}

void MoveCalculator::calculate_bishop(int f_ind, char f_piece, std::set<int> &p_moves)
{
  upper_left_to_lower_right(f_ind, f_piece, p_moves);
  lower_left_to_upper_right(f_ind, f_piece, p_moves);
}

void MoveCalculator::calculate_queen(int f_ind, char f_piece, std::set<int> &p_moves)
{
  left_to_right(f_ind, f_piece, p_moves);
  upper_left_to_lower_right(f_ind, f_piece, p_moves);
  up_to_down(f_ind, f_piece, p_moves);
  lower_left_to_upper_right(f_ind, f_piece, p_moves);
}

void MoveCalculator::calculate_king(int f_ind, char f_piece, std::set<int> &p_moves)
{
  std::set<int> opp_moves; 
  for (int i = 0; i < 64; i++)
  {
    char current_p = board->board[i];
    if (current_p != 'x' && current_p != 'k' && current_p != 'K' && !is_same_team(board->board[i], f_piece))
    {
      calculate_moves(i, board->board[i], opp_moves);
    }
  }
  
  if((board->board[f_ind - 9] == 'x' && !in_opp_moves(f_ind - 9, opp_moves)) ||
      (board->board[f_ind - 9] != 'x' && !is_same_team(f_piece, board->board[f_ind - 9]))){
    p_moves.insert(f_ind - 9);
  }
  if((board->board[f_ind - 8] == 'x' && !in_opp_moves(f_ind - 8, opp_moves)) ||
      (board->board[f_ind - 8] != 'x' && !is_same_team(f_piece, board->board[f_ind - 8]))){
    p_moves.insert(f_ind - 8);
  }
  if((board->board[f_ind - 7] == 'x' && !in_opp_moves(f_ind - 7, opp_moves)) ||
      (board->board[f_ind - 7] != 'x' && !is_same_team(f_piece, board->board[f_ind - 7]))){
    p_moves.insert(f_ind - 7);
  }
  if((board->board[f_ind - 1] == 'x' && !in_opp_moves(f_ind - 1, opp_moves)) ||
      (board->board[f_ind - 1] != 'x' && !is_same_team(f_piece, board->board[f_ind - 1]))){
    p_moves.insert(f_ind - 1);
  }
  if((board->board[f_ind + 1] == 'x' && !in_opp_moves(f_ind + 1, opp_moves)) ||
      (board->board[f_ind + 1] != 'x' && !is_same_team(f_piece, board->board[f_ind + 1]))){
    p_moves.insert(f_ind + 1);
  }
  if((board->board[f_ind + 7] == 'x' && !in_opp_moves(f_ind + 7, opp_moves)) ||
      (board->board[f_ind + 7] != 'x' && !is_same_team(f_piece, board->board[f_ind + 7]))){
    p_moves.insert(f_ind + 7);
  }
  if((board->board[f_ind + 8] == 'x' && !in_opp_moves(f_ind + 8, opp_moves)) ||
      (board->board[f_ind + 8] != 'x' && !is_same_team(f_piece, board->board[f_ind + 8]))){
    p_moves.insert(f_ind + 8);
  }
  if((board->board[f_ind + 9] == 'x' && !in_opp_moves(f_ind + 9, opp_moves)) ||
    (board->board[f_ind + 9] != 'x' && !is_same_team(f_piece, board->board[f_ind + 9]))){
    p_moves.insert(f_ind + 9);
  }
}

bool MoveCalculator::is_same_team(char p1, char p2)
{
  return (p1 < 91 && p2 < 91) || (p1 > 91 && p2 > 91);
}

bool MoveCalculator::in_opp_moves(int ind, std::set<int> &opp_moves){
  for(int i : opp_moves){
    if(i == ind){
      return true;
    }
  }
  return false;
}

void MoveCalculator::left_to_right(int f_ind, char f_piece, std::set<int> &p_moves)
{
  // ROOK and QUEEN
  std::pair<int, int> coords = board->get_2D_ind_from_ind(f_ind);

  int tempX = coords.first - 1;
  while (tempX >= 0 && board->board[coords.second * 8 + tempX] == 'x')
  {
    p_moves.insert(coords.second * 8 + tempX);
    tempX--;
  }
  if (tempX != -1 && !is_same_team(board->board[coords.second * 8 + tempX], f_piece))
  {
    p_moves.insert(coords.second * 8 + tempX);
  }

  tempX = coords.first + 1;
  while (tempX < 8 && board->board[coords.second * 8 + tempX] == 'x')
  {
    p_moves.insert(coords.second * 8 + tempX);
    tempX++;
  }
  if (tempX != 8 && !is_same_team(board->board[coords.second * 8 + tempX], f_piece))
  {
    p_moves.insert(coords.second * 8 + tempX);
  }
}
void MoveCalculator::upper_left_to_lower_right(int f_ind, char f_piece, std::set<int> &p_moves)
{
  // BISHOP and QUEEN
  std::pair<int, int> coords = board->get_2D_ind_from_ind(f_ind);
  int tempX = coords.first - 1;
  int tempY = coords.second - 1;
  while (tempX >= 0 && tempY >= 0 && board->board[tempY * 8 + tempX] == 'x')
  {
    p_moves.insert(tempY * 8 + tempX);
    tempX--;
    tempY--;
  }
  if (tempX != -1 && tempY != -1 && !is_same_team(board->board[tempY * 8 + tempX], f_piece))
  {
    p_moves.insert(tempY * 8 + tempX);
  }

  tempX = coords.first + 1;
  tempY = coords.second + 1;

  while (tempX < 8 && tempY < 8 && board->board[tempY * 8 + tempX] == 'x')
  {
    p_moves.insert(tempY * 8 + tempX);
    tempX++;
    tempY++;
  }
  if (tempX != 8 && tempY != 8 && !is_same_team(board->board[tempY * 8 + tempX], f_piece))
  {
    p_moves.insert(tempY * 8 + tempX);
  }
}
void MoveCalculator::up_to_down(int f_ind, char f_piece, std::set<int> &p_moves)
{
  // ROOK and QUEEN
  std::pair<int, int> coords = board->get_2D_ind_from_ind(f_ind);

  int tempY = coords.second - 1;
  while (tempY >= 0 && board->board[tempY * 8 + coords.first] == 'x')
  {
    p_moves.insert(tempY * 8 + coords.first);
    tempY--;
  }
  if (tempY != -1 && !is_same_team(board->board[tempY * 8 + coords.first], f_piece))
  {
    p_moves.insert(tempY * 8 + coords.first);
  }

  tempY = coords.second + 1;
  while (tempY < 8 && board->board[tempY * 8 + coords.first] == 'x')
  {
    p_moves.insert(tempY * 8 + coords.first);
    tempY++;
  }
  if (tempY != 8 && !is_same_team(board->board[tempY * 8 + coords.first], f_piece))
  {
    p_moves.insert(tempY * 8 + coords.first);
  }
}
void MoveCalculator::lower_left_to_upper_right(int f_ind, char f_piece, std::set<int> &p_moves)
{
  // BISHOP and QUEEN
  std::pair<int, int> coords = board->get_2D_ind_from_ind(f_ind);
  int tempX = coords.first - 1;
  int tempY = coords.second + 1;

  while (tempX >= 0 && tempY < 8 && board->board[tempY * 8 + tempX] == 'x')
  {
    p_moves.insert(tempY * 8 + tempX);
    tempX--;
    tempY++;
  }
  if (tempX != -1 && tempY != 8 && !is_same_team(board->board[tempY * 8 + tempX], f_piece))
  {
    p_moves.insert(tempY * 8 + tempX);
  }

  tempX = coords.first + 1;
  tempY = coords.second - 1;

  while (tempX < 8 && tempY >= 0 && board->board[tempY * 8 + tempX] == 'x')
  {
    p_moves.insert(tempY * 8 + tempX);
    tempX++;
    tempY--;
  }
  if (tempX != 8 && tempY != -1 && !is_same_team(board->board[tempY * 8 + tempX], f_piece))
  {
    p_moves.insert(tempY * 8 + tempX);
  }
}
