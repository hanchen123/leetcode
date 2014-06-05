class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ret;  
        vector<int> tmp;      
        if(S.size() ==0) 
            return ret;  
        ret.push_back(tmp);  
        sort(S.begin(), S.end());  
        this->Excute(S, 0, ret, tmp);  
        return ret;
    } 
private:
    void Excute(vector<int>& s, int step, vector<vector<int> >& ret, vector<int>& tmp) {  
        for(int i = step;i < s.size(); i++) {  
            tmp.push_back(s[i]);  
            ret.push_back(tmp);  
            if(i< s.size()-1)  
                Excute(s, i+1, ret, tmp);  
            tmp.pop_back();  
        }          
    }
};