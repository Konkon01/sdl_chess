#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include "Board.h"
#include "MoveCalculator.h"
#include <SDL2/SDL.h>
#include <vector>

class EventHandler {
private:
  SDL_Event event;
  Board* board;
  MoveCalculator* move_calc;
  bool is_light_turn;
  char selected_piece;
  int selected_ind;

  void reset(int &s_ind, char &s_piece, std::vector<int> &possible_moves);
  bool is_possible(std::vector<int> &possible_moves, int field_ind);
  void change_turn();
public:
  EventHandler(Board* b);
  ~EventHandler();
  void handle_events(std::vector<int> &possible_moves, bool &running);
};

#endif