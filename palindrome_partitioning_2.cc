class Solution {
public:
    int minCut(string s) {
        int len = s.size();  
        int ret[len+1];  
        bool pal[len][len];  
        for(int i = 0; i <= len; i++)   
            ret[i] = len-i;  
        for(int i = 0; i < len; i++)  
            for(int j = 0; j < len; j++)  
                pal[i][j] = false;  
        for(int i = len-1; i >= 0; i--) {  
            for(int j = i; j < len; j++) {  
                if(s[i] == s[j] && (j-i<2 || pal[i+1][j-1])){  
                    pal[i][j] = true;  
                    ret[i] = min(ret[i],ret[j+1]+1);  
                }  
            }  
        }  
        return ret[0]-1;        
    }
};