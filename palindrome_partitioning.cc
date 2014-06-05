class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ret;  
        vector<string> tmp;  
        this->Excute(s, 0, tmp, ret);  
            return ret;  
        }  
private:
    void Excute(string &s, int step, vector<string>& tmp, vector<vector<string>>& ret) {      
        if(step == s.size()) {  
            ret.push_back(tmp);  
            return;  
        }  
        for(int i = step; i < s.size(); i++) {    
            if(isPalindrome(s, step, i)) {  
                tmp.push_back(s.substr(step, i-step+1));  
                Excute(s, i+1, tmp, ret);  
                tmp.pop_back();  
            }  
        }  
    }  
    bool isPalindrome(string& s, int start, int end) {  
        while(start < end) {  
            if(s[start] != s[end])  
                return false;  
            start++; end--;  
        }  
        return true;         
    }
};