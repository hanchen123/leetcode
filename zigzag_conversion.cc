class Solution {
public:
    string convert(string s, int nRows) {
        if(nRows <= 1) 
            return s;  
        string ret;  
        if(s.size() == 0) 
            return ret;  
        for(int i = 0; i < nRows; i++) {  
            for(int j = 0, idx = i; idx < s.size(); j++, idx = (2*nRows - 2)*j + i) {  
                ret.append(1, s[idx]);  
            if(i == 0 || i == nRows-1)   
                continue;  
            if(idx + (nRows- i-1)*2 < s.size())  
                ret.append(1, s[idx + (nRows - i - 1)*2]);  
            }  
        }  
        return ret;         
    }
};