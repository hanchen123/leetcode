class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        vector<vector<int> > ret;  
        vector<int> tmp;  
        int sum = 0;
        sort(candidates.begin(), candidates.end());
        this->Excute(candidates, sum, 0, target, tmp, ret);  
        return ret;  
    }  
private:
    void Excute(vector<int> &candidates, int &sum, int step, int target, vector<int> &tmp, vector<vector<int> >& ret) {      
        if(sum > target)  
            return;  
        if(sum == target) {
            ret.push_back(tmp);
            return;
        }
        for(int i = step; i < candidates.size(); i++) { 
            sum += candidates[i];
            tmp.push_back(candidates[i]);  
            Excute(candidates, sum, i, target, tmp, ret);  
            tmp.pop_back();  
            sum -= candidates[i];
        }  
    }  
}; 