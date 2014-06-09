class Solution {
public:
    void solve(vector<vector<char>> &board) {
        row = board.size();
        if (row <= 2)
            return;
        col = board[0].size();
        if (col <= 2)
            return;
        vector<int> tmp;
        tmp.clear(), vis.clear();
        for (int i = 0; i < col; i++)
            tmp.push_back(0);
        for (int i = 0; i < row; i++)
            vis.push_back(tmp);
        vector<Node> ret;
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                ret.clear();
                if (vis[i][j] == 0 && board[i][j] == 'O' && this->Excute(board, ret, i, j)) {
                    for (int k = 0; k < ret.size(); k++)
                        board[ ret[k].x ][ ret[k].y ] = 'X';
                }
            }
        return;
    }
private:
    int row, col;
    vector<vector<int>> vis;
    int dx[4] = {-1, 0, 0, 1};
    int dy[4] = {0, -1, 1, 0};
    
    struct Node {
        int x, y;
        Node(){}
        Node(int a, int b) {
            x = a, y = b;
        }
    };
    
    bool isedge(int x, int y) {
        return (x >= 0 && x < row && y >= 0 && y < col);
    }
    bool Excute(vector<vector<char>> &board, vector<Node> &ret, int x, int y) {
        bool flag = true;
        vis[x][y] = 1;
        Node t;
        int tx, ty;
        ret.push_back(Node(x, y));
        queue<Node> que;
        que.push(Node(x, y));
        while (!que.empty()) {
            t = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                tx = t.x + dx[i];
                ty = t.y + dy[i];
                if (!isedge(tx, ty)) {
                    flag = false;
                    continue;
                }
                if (!vis[tx][ty] && board[tx][ty] == 'O') {
                    vis[tx][ty] = 1;
                    ret.push_back(Node(tx, ty));
                    que.push(Node(tx, ty));
                }
            }
        }
        return flag;
    }
};