void display_board(const std::vector<char>& board);
void seed_board(std::vector<char>& board);
void get_move(const char& player, int& move);
bool check_move(const int& move, const std::vector<char>& board);
void update_board(const char& player, const int& move, std::vector<char>& board);
char game_status(const std::vector<char>& board, const char& player);
void announce_result(const char& player, const char& result);