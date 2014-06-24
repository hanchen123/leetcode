class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        bool row[9][10], col[9][10], part[9][10];
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(part, false, sizeof(part));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (row[i][ board[i][j] - '0' ] || col[j][ board[i][j] - '0' ] || part[(i / 3) * 3 + (j / 3)][ board[i][j] - '0' ])
                        return false;
                    row[i][ board[i][j] - '0' ] = true;
                    col[j][ board[i][j] - '0' ] = true;
                    part[(i / 3) * 3 + (j / 3)][ board[i][j] - '0' ] = true;
                }
            }
        }
        return true;
    }
};