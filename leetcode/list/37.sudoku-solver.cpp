class Solution {
#define D(r, c) (r / 3 * 3 + c / 3)
#define CC(c) (c != 8 ? c + 1 : 0)
#define RR(c, r) (c != 8 ? r : r + 1)

    private:
        bool row[9][9], col[9][9], square[9][9];

        /******************************************************************************
        * Function:         bool search
        * Description:      
        * Where:
        * Return:           
        * Error:            
        *****************************************************************************/
        bool search(vector<vector<char>>& board, int r, int c){
            if (r == 9) {
                return true;
            }

            if (board[r][c] != '.') {
                return search(board, RR(c, r), CC(c));
            }

            for (int val = 0; val < 9; ++val) {
                if (!row[r][val] && !col[c][val] && !square[D(r, c)][val]) {
                    board[r][c] = val + '1';
                    row[r][val] = true;
                    col[c][val] = true;
                    square[D(r, c)][val] = true;
                    // next run doesn't work
                    if (search(board, RR(c, r), CC(c)))
                        return false;
                    else {
                        board[r][c] = '.';
                        row[r][val] = false;
                        col[c][val] = false;
                        square[D(r, c)][val] = false;
                    }
                }
            }
            return false;
        }

    public:
        void solveSudoku(vector<vector<char>>& board) {
            for (int r = 0; r < 9; ++r) {
               for (int c = 0; c < 9; ++c) {
                   if (board[r][c] != '.') {
                        int val = board[r][c] - '1';
                        row[r][val] = true;
                        col[c][val] = true;
                        square[D(r, c)][val] = true;
                   }
               }
            }
            search(board, 0, 0);
        }
};
