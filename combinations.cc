class Solution {
public:
    vector<vector<int> > combine(int n, int k) {  
        vector<vector<int> > ret;  
        vector<int> tmp;  
        this->Excute(n,k,1, tmp, ret);  
        return ret;  
    }  
private:
    void Excute(int n, int k, int step, vector<int>& tmp, vector<vector<int> >& ret) {      
        if(tmp.size() == k) {  
            ret.push_back(tmp);  
            return;  
        }  
        for(int i = step; i<= n; i++) {  
            tmp.push_back(i);  
            Excute(n, k, i+1, tmp, ret);  
            tmp.pop_back();  
        }  
    }  
};