class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();  
        int pal[len][len];  
        memset(pal, 0, sizeof(pal));  
        int max = 0, start = 0, end = 0;  
        for(int i = 0; i < s.size(); i++) {  
            for(int j = 0; j <= i; j++) {  
                pal[j][i] = (s[j] == s[i] && (i - j < 2 || pal[j+1][i-1]));  
                if(pal[j][i] && max < (i - j + 1)) {  
                    max = i - j + 1;  
                    start = j;  
                    end = i;  
                }  
            }  
        }  
        return s.substr(start, end - start + 1);        
    }
};