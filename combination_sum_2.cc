class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > ret;  
        vector<int> tmp;  
        int sum = 0;
        sort(num.begin(), num.end());
        this->Excute(num, sum, 0, target, tmp, ret);  
        return ret;  
    }  
private:
    void Excute(vector<int> &num, int &sum, int step, int target, vector<int> &tmp, vector<vector<int> >& ret) {      
        if(sum > target)  
            return;  
        if(sum == target) {
            ret.push_back(tmp);
            return;
        }
        for(int i = step; i < num.size(); i++) { 
            sum += num[i];
            tmp.push_back(num[i]);  
            Excute(num, sum, i+1, target, tmp, ret);  
            tmp.pop_back();  
            sum -= num[i];
            while(i < num.size()-1 && num[i] == num[i+1]) {
                i++;
            }
        }         
    }
};