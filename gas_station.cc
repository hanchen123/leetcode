class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        vector<int> dif(gas.size());
        for(int i = 0; i < gas.size(); ++i)
            dif[i] = gas[i] - cost[i];
        int allrest = 0, sum = 0, start = 0;
        for(int i = 0; i < gas.size(); ++i) {
            allrest += dif[i];
            sum += dif[i];
            if(sum < 0) {
                start = i+1;
                sum = 0;
            }
        }
        if(allrest < 0)
            return -1;
        else
            return start;       
    }
};