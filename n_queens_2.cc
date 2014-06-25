class Solution {
public:
    int totalNQueens(int n) {
        this->Excute(0, n);  
        return count;          
    }
private:
    int row[100];  
    int col[100]; 
    int count = 0;
    void Excute(int r, int n) {  
        int i, j;  
        if(r == n) {  
            count++;
            return;
        }  
        for(i = 0; i < n; i++) {  
            if(col[i] == 0) {  
                for(j = 0; j < r; j++)  
                    if(abs(j - r) == abs(i - row[j]))
                        break;  
                if(j == r) {  
                    row[r] = i;  
                    col[i] = 1;  
                    Excute(r+1, n);  
                    col[i] = 0;  
                    row[r] = 0;  
                }  
            }  
        }  
    }  
};