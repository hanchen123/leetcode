class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        memset(row, false, sizeof(row));
        memset(col, false, sizeof(col));
        memset(part, false, sizeof(part));
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    row[i][ board[i][j] - '0' ] = true;
                    col[j][ board[i][j] - '0' ] = true;
                    part[(i / 3) * 3 + (j / 3)][ board[i][j] - '0' ] = true;
                }
                else 
                    pos[count++] = i * 9 + j;
            }
        }
        this->Excute(board, 0);
        return;        
    }
private:
    bool row[9][10], col[9][10], part[9][10];
    int pos[81], count;
    bool Excute(vector<vector<char> > &board, int step) {
        if (step == count) 
            return true;
        int r = pos[step] / 9;
        int c = pos[step] % 9;
        int p = (r / 3) * 3 + (c / 3);
        for (int i = 1; i <= 9; i++) {
            if (row[r][i] || col[c][i] || part[p][i]) 
                continue;
            row[r][i] = col[c][i] = part[p][i] = true;
            board[r][c] = (char)(i + '0');
            if (Excute(board, step + 1) == true) 
                return true;
            board[r][c] = '.';
            row[r][i] = col[c][i] = part[p][i] = false;
        }
        return false;
    }    
};