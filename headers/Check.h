#ifndef CHECK_H
#define CHECK_H
#include "Board.h"
#include <vector>
#include <set>
#include <unordered_map>

class Check {
  bool check;
  Board* board;
  std::vector<char> check_giving_pieces;
  std::vector<int> check_giving_indicies;
  std::set<int> possible_fields;

  std::unordered_map<char, int> king_positions;

  bool is_same_team(char p1, char p2);
  void check_for_horse(char opp_king, int opp_king_pos,
                        std::unordered_map<int, std::vector<int>>& check_vetors);
  
  void check_for_vertical(char opp_king, int opp_king_pos,
                        std::unordered_map<int, std::vector<int>>& check_vetors);

  void check_for_horizontal(char opp_king, int opp_king_pos,
                        std::unordered_map<int, std::vector<int>>& check_vetors);

  void check_for_diagonal(char opp_king, int opp_king_pos,
                        std::unordered_map<int, std::vector<int>>& check_vetors);


public:
  void look_for_check(char f_piece);
  void update_king_pos(char king, int position);
  const std::set<int>& get_possible_fields();
};

#endif