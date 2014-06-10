class Solution {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() <= 1)
            return 0;
        int curmin = prices[0];
        int ret = 0;
        for (int i = 1; i < prices.size(); i++) {
            ret = max(ret, prices[i] - curmin);
            curmin = min(curmin, prices[i]);
        }
        return ret;
    }
};