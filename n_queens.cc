class Solution {  
public:  
    vector<vector<string> > solveNQueens(int n) {  
        vector<vector<string> > ret;
        this->Excute(ret, 0, n);  
        return ret;  
    }  
private:
    int row[100];  
    int col[100];  
    void Excute(vector<vector<string> > &ret, int r, int n) {  
        int i, j;  
        if(r == n) {  
            vector<string> tmp;  
            for(i = 0; i < n; i++) {  
                string str(n, '.');  
                str[row[i]] = 'Q';  
                tmp.push_back(str);  
            }  
            ret.push_back(tmp);  
        }  
        for(i = 0; i < n; i++) {  
            if(col[i] == 0) {  
                for(j = 0; j < r; j++)  
                    if(abs(j - r) == abs(i - row[j]))
                        break;  
                if(j == r) {  
                    row[r] = i;  
                    col[i] = 1;  
                    Excute(ret, r+1, n);  
                    col[i] = 0;  
                    row[r] = 0;  
                }  
            }  
        }  
          
    }  
};  