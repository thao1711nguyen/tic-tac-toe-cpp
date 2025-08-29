void display_board(std::vector<char> board);
std::vector<char> seed_board();
int get_move(char player);
bool check_move(int move, std::vector<char> board);
std::vector<char> update_board(char player, int move, std::vector<char> board);
char game_status(std::vector<char> board, char player);
void announce_result(char player, char result);