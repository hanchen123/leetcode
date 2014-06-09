class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (word.length() == 0) 
            return true;
        row = board.size();
        if (row == 0) 
            return false;
        col = board[0].size();
        if (col == 0) 
            return false;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (board[i][j] == word[0]) {
                    board[i][j] = '*';
                    if (this->Excute(board, word, 1, i, j)) 
                        return true;
                    board[i][j] = word[0];
                }
            }
        }
        return false;
    }
private:
    int row, col;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    bool isedge(int x, int y) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    bool Excute(vector<vector<char> > &board, string &word, int step, int x, int y) {
        if (step == word.length()) 
            return true;
        int tx, ty;
        for (int i = 0; i < 4; i++) {
            tx = x + dx[i];
            ty = y + dy[i];
            if (isedge(tx, ty) && board[tx][ty] == word[step]) {
                board[tx][ty] = '*';
                if (Excute(board, word, step + 1, tx, ty)) {
                    board[tx][ty] = word[step];
                    return true;
                }
                board[tx][ty] = word[step];
            }
        }
        return false;
    }
};