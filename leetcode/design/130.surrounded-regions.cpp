class Solution {
public:
    void solve(vector<vector<char>>& board)
    {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if ((i == 0 || j == 0 || i == board.size() - 1
                        || j == board[0].size() - 1)
                    && board[i][j] == 'O')
                    dfs(i, j, board);
            }
        }
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == '$')
                    board[i][j] = 'O';
            }
        }
    }

    /*! \brief flooding fill
     *
     *  convert all the O that won't be converted to X
     *
     * \param i x index
     * \param j y index
     * \param board input board
     * \return void
     */
    void dfs(int i, int j, vector<vector<char>>& board)
    {
        if (board[i][j] == 'O') {
            board[i][j] = '$';
            if (i > 0 && board[i - 1][j] == 'O')
                dfs(i - 1, j, board);
            if (j > 0 && board[i][j - 1] == 'O')
                dfs(i, j - 1, board);
            if (i < board.size() - 1 && board[i + 1][j] == 'O')
                dfs(i + 1, j, board);
            if (j < board[0].size() - 1 && board[i][j + 1] == 'O')
                dfs(i, j + 1, board);
        }
    }
};
