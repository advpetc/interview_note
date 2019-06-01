//
// Created by ChenHaoyang on 2019-05-25.
//
vector<vector<char>> used, board;
bool exist(vector<vector<char>>& board, string word) {
    this -> board = board;
    this -> used = board;
    for (unsigned i = 0; i < board.size(); ++i)
        for (unsigned j = 0; j < board[0].size(); ++j)
            if (dfs(i, j, 0, word))
                return true;
    return false;
}

bool dfs(int i, int j, unsigned pos, string word) {
    if (pos == word.size())
        return true;
    if (i < 0 || i > board.size() - 1 || j < 0 || j > board.size() - 1)
        return false;
    bool ret = false;
    if (board[i][j] == word[pos]
        // use another 2d array if not allow to modify input
        && used[i][j] != '\0') {
        char t = board[i][j];
        used[i][j] = '\0';
        // board[i][j] = '\0';
        pos++;
        ret = (dfs(i + 1, j, pos, word) ||
               dfs(i - 1, j, pos, word) ||
               dfs(i, j + 1, pos, word) ||
               dfs(i, j - 1, pos, word));
        used[i][j] = t;
    }
    return ret;
}
