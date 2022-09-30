#include "../headers/Check.h"

#include <unordered_map>
#include <vector>

bool Check::is_same_team(char p1, char p2){
  return (p1 < 91 && p2 < 91) || (p1 > 90 && p2 > 90);
}

void Check::look_for_check(char f_piece){
  char opp_king = (f_piece < 91)? 'k' : 'K';
  auto opp_king_position = king_positions.find(opp_king);

  std::unordered_map<int, std::vector<int>> check_vetors;

  check_for_horse(opp_king, opp_king_position->second, check_vetors);
  check_for_horizontal(opp_king, opp_king_position->second, check_vetors);
  check_for_vertical(opp_king, opp_king_position->second, check_vetors);
  check_for_diagonal(opp_king, opp_king_position->second, check_vetors);

}

void Check::check_for_horse(char opp_king, int opp_king_pos,
                        std::unordered_map<int, std::vector<int>>& check_vetors){
                        
}
  
void Check::check_for_vertical(char opp_king, int opp_king_pos,
                      std::unordered_map<int, std::vector<int>>& check_vetors){

}

void Check::check_for_horizontal(char opp_king, int opp_king_pos,
                      std::unordered_map<int, std::vector<int>>& check_vetors){

}

void Check::check_for_diagonal(char opp_king, int opp_king_pos,
                      std::unordered_map<int, std::vector<int>>& check_vetors){

}

void Check::update_king_pos(char opp_king, int position){
  king_positions[opp_king] = position;
}

const std::set<int>& Check::get_possible_fields(){
  return possible_fields;
}
