#include <iostream>
#include <vector>
  
void display_board(std::vector<char> board) {
  for(int i=0; i<board.size(); i++) {
    if((i+1)%3 != 1) {
      std::cout << "|";
    };
    if(board[i] == ' ' || board[i] == 'X' || board[i] == 'O') {
      std::cout << board[i];
    } else {
      std::cout << i;
    };
    if((i+1)%3 == 0 && (i+1) != 9) {
      std::cout << "\n";
      for(int j=0; j<6; j++) {
        std::cout << "_";
      };
      std::cout << "\n";
    };
  }
}
std::vector<char> seed_board() {
  std::vector<char> board;
  board.assign(9, ' ');
  return(board);
}
int get_move(char player) {
  std::cout << "Player " << player << " please make a move: ";
  int move;
  std::cin >> move;
  return(move);
}
bool check_move(int move, std::vector<char> board) {
  if(board[move-1] != ' ' || move < 1 || move > 9) {
    return(false);
  };
  return true;
}
std::vector<char> update_board(char player, int move, std::vector<char> board) {
  board[move-1] = player;
  return(board);
}
std::vector<std::vector<int>> win_patterns = {
  {0,1,2}, {3,4,5}, {6,7,8},
  {0,3,6}, {1,4,7}, {2,5,8},
  {0,4,8}, {2,4,6}
};
bool is_won(std::vector<int> moves) {
  for(int i=0; i<win_patterns.size(); i++) {
    int match_count=0;
    for(int j=0; j<win_patterns[i].size(); j++) {
      for(int k=0; k<moves.size(); k++) {
        if(win_patterns[i][j] == moves[k]) {
          match_count++;
          break;
        };
      }; 
      if(match_count == j) {
        break;
      } else if(match_count == 3) {
        return(true);
      };
    }
  }
  return(false);
}
std::vector<int> extract_moves(std::vector<char> board, char player) {
  std::vector<int> moves;
  for(int i=0; i<board.size(); i++) {
    if(board[i] == player) {
      moves.push_back(i);
    };
  };
  return(moves);
}
bool is_tie(std::vector<char> board) {
  for(int i=0; i<board.size(); i++) {
    if(board[i] != 'X' && board[i] != 'O') {
      return(false);
    };
  };
  return(true);
}
char game_status(std::vector<char> board, char player) {
  std::vector<int> moves = extract_moves(board, player);
  if(is_won(moves)) {
    return('w');
  } else if(is_tie(board)) {
    return('-');
  } else {
    return(' ');
  };
}
void announce_result(char player, char result) {
  if (result == 'w') {
    std::cout << "Player " << player << " win!\n";
  } else if (result == '-') {
    std::cout << "It's a tie!\n";
  };
}