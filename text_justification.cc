class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;   
        if(words.size() == 0) 
            return ret;     
        int i = 0;   
        while(i < words.size()) {   
            int start = i;   
            int sum = 0;   
            while(i < words.size() && sum + words[i].size() <= L) {   
                sum += words[i].size() + 1;   
                i++;   
            }   
            int end = i - 1;    
            int spcount = end - start;   
            int avgsp = 0, restsp = 0;   
            if(spcount > 0) {   
                int rest = L - sum + spcount + 1;
                avgsp = rest/spcount;   
                restsp = rest%spcount;   
            }      
            string tmp;      
            for(int j = start; j < end; j++) {   
                tmp += words[j];   
                if(i == words.size()) 
                    tmp.append(1, ' ');   
                else {   
                    tmp.append(avgsp, ' '); 
                    if(restsp > 0) {   
                        tmp.append(1, ' ');   
                        restsp--;   
                    }   
                }   
            }   
            tmp += words[end];   
            if(tmp.size() < L)   
                tmp.append(L - tmp.size(), ' ');   
            ret.push_back(tmp);      
        }   
        return ret;         
    }
};