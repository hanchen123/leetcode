class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        sort(num.begin(), num.end());  
        vector<vector<int> > ret;  
        int len = num.size();  
        for(int i =0; i< len-2; i++) {  
            int target = 0-num[i];  
            int start = i+1, end =len-1;  
            while(start < end) {  
                if(num[start] + num[end] == target) {  
                    vector<int> tmp;  
                    tmp.push_back(num[i]);  
                    tmp.push_back(num[start]);  
                    tmp.push_back(num[end]);  
                    ret.push_back(tmp);  
                    start++; 
                    end--;  
                    while(start<end && num[start] == num[start-1])  start++;  
                    while(start<end && num[end] == num[end+1])  end--;  
                }  
                else if(num[start] + num[end] < target)  
                    start++;  
                else  
                    end--;  
            }  
            if(i < len-2)  
                while(num[i] == num[i+1]) i++;  
        }  
        return ret;          
    }
};