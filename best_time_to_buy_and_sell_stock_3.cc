class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int len = prices.size();
        if(len <= 1) 
            return 0;  
        vector<int> maxl(len, 0);  
        vector<int> maxr(len, 0);  
        int min = INT_MAX, max = INT_MIN;  
        for(int i = 0; i < len; i++) {  
            if(min > prices[i]) 
                min = prices[i];  
            int tmp = prices[i] - min;  
            if(tmp > max) max = tmp;  
                maxl[i] = max; 
        }  
        int max1 = INT_MIN, max2 = INT_MIN;  
        for(int i = len-1; i >= 0; i--) {  
            if(max1 < prices[i]) 
                max1 = prices[i];  
            int tmp = max1 - prices[i];  
            if(tmp > max2) max2 = tmp;  
                maxr[i] = max2; 
        }  
        int maxp = INT_MIN;  
        for(int i = 0; i < len-1; i++) {  
            int sum = maxl[i] + maxr[i+1];  
            maxp = sum > maxp? sum:maxp;  
        }  
        if(maxp < maxl[len-1])  
            maxp = maxl[len-1];  
        return maxp;         
    }
};