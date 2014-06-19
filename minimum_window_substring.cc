class Solution {
public:
    string minWindow(string S, string T) {
        string ret;
        if(S.size() == 0 || S.size() < T.size()) 
            return ret;  
        int Tcount[256]; 
        memset(Tcount, 0, 256*sizeof(Tcount[0]));
        int Scount[256];  
        memset(Scount, 0, 256*sizeof(Scount[0]));  
        for(int i =0; i < T.size(); i++)  
            Tcount[T[i]]++;                 
        int min = INT_MAX, ret_start = 0;  
        int start = 0;  
        int count = 0;   
        for(int end = 0; end< S.size(); end++) {  
            if(Tcount[S[end]] > 0) {  
                Scount[S[end]]++;  
                if(Scount[S[end]] <= Tcount[S[end]])  
                    count ++;                      
            }  
            if(count == T.size()) {                 
                while(Scount[S[start]] > Tcount[S[start]] || Tcount[S[start]] == 0) {  
                    Scount[S[start]]--;  
                    start ++;  
                }                      
                if(min > (end - start +1)) {  
                    min = end - start +1;  
                    ret_start = start;  
                }  
            }                 
        }  
        if(min == INT_MAX) return ret; 
        ret = S.substr(ret_start, min);
        return ret;         
    }
};