class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > ret;  
        vector<int> tmp; 
        int len = num.size();
        if(len == 0) return ret;  
        vector<int> visited(len, 0);  
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
                visited[i] = 1;  
                tmp.push_back(num[i]);  
                Excute(num, step+1, visited, tmp, ret);  
                tmp.pop_back();  
                visited[i] = 0;  
            }  
        }        
    }
};