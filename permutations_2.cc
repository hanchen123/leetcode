class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector<vector<int> > ret;  
        vector<int> tmp; 
        int len = num.size();
        if(len == 0) return ret;  
        vector<int> visited(len, 0); 
        sort(num.begin(), num.end());
        this->Excute(num, 0, visited, tmp, ret);  
        return ret;  
    }  
private:
    void Excute(vector<int> & num, int step, vector<int>& visited, vector<int>& tmp, vector<vector<int> >& ret) {  
        if(step == num.size()) {  
            ret.push_back(tmp);  
            return;  
        }  
        for(int i = 0; i < num.size(); i++) {  
            if(visited[i] == 0) { 
                if(i > 0 && num[i] == num[i-1] && visited[i-1] == 0)  
                    continue;
                visited[i] = 1;  
                tmp.push_back(num[i]);  
                Excute(num, step+1, visited, tmp, ret);  
                tmp.pop_back();  
                visited[i] = 0;  
            }  
        }        
    }
};