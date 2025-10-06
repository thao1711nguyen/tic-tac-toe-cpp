#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

int main() {
  std::vector<char> board;
  seed_board(board);
  int count=0;
  bool is_end_game=false;
  char player;
  int move;
  while (count < 9 && !is_end_game) {
    display_board(board);
    if(count%2 == 0) {
      player = 'O';
    } else {
      player = 'X';
    };
    bool valid_move = false;
    while(!valid_move) {
      get_move(player, move);
      valid_move = check_move(move, board);
    };
    update_board(player, move, board);
    char result = game_status(board, player);
    if (result == 'w' || result == '-') {
      is_end_game = true;
      display_board(board);
      announce_result(player, result);
    }
    count++;
  }
}