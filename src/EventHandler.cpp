#include "../headers/EventHandler.h"
#include "../headers/Board.h"
#include "../headers/MoveCalculator.h"
#include "../headers/Check.h"

#include <SDL2/SDL.h>
#include <utility>
#include <iostream>
#include <vector>

EventHandler::EventHandler(Board *b){
  board = b;
  move_calc = new MoveCalculator(b);
  check = new Check();
  is_light_turn = true;
  selected_piece = 'x';
  selected_ind = -1;
}
EventHandler::~EventHandler(){
  delete move_calc;
  delete check;
}

void EventHandler::reset(int &s_ind, char &s_piece, std::set<int> &possible_moves){
  s_ind = -1;
  s_piece = 'x';
  possible_moves.clear();
}

bool EventHandler::is_possible(std::set<int> &possible_moves, int field_ind){
  for (int p_move : possible_moves)
  {
    if (p_move == field_ind)
    {
      return true;
    }
  }
  return false;
}

void EventHandler::change_turn(){
  is_light_turn = !is_light_turn;
}

void EventHandler::handle_events(std::set<int> &possible_moves, bool &running){

  while (SDL_WaitEvent(&event)){

    if (event.type == SDL_QUIT){
      running = false;
      break;
    }

    if (event.type == SDL_MOUSEBUTTONDOWN){
      std::pair<int, int> coord;
      coord.first = event.button.x;
      coord.second = event.button.y;

      int field_ind = board->get_ind_from_coord(coord);
      char field_piece = board->get_piece_at(field_ind);

      if (selected_ind != -1){
        /*TASKS
          -new field is in possible_moves set?
          -was check given after move?
          -game over after last move?
        */
        if (selected_ind == field_ind){
          reset(selected_ind, selected_piece, possible_moves);
          break;
        }

        if (is_possible(possible_moves, field_ind)){ // Valid move
          board->move_piece(selected_ind, field_ind);
          if(selected_piece == 'k' || selected_piece == 'K'){
            check->update_king_pos(selected_piece, selected_ind);
          }
          change_turn();
        }

        reset(selected_ind, selected_piece, possible_moves);
        break;

      }else{
        /*TASKS
          -select piece
          -calculate possible moves
        */
        if (field_piece == 'x'){
          continue; // Empty field
        }
        
        if (is_light_turn && field_piece > 90){
          continue; // Light player chose on dark piece
        } else if (!is_light_turn && field_piece < 91){
          continue; // Dark player chose on light piece
        }
        selected_ind = field_ind;
        selected_piece = field_piece;
        move_calc->calculate_moves(selected_ind, selected_piece, possible_moves);
        break;
      }
    }
  }
}
