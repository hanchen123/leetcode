class Solution {
public:
    int maxArea(vector<int> &height) {
        int start =0;  
        int end = height.size() - 1;  
        int ret = INT_MIN;  
        while(start < end) {  
            int tmp = min(height[end], height[start]) * (end - start);  
            ret = max(ret, tmp);  
            if(height[start] <= height[end])  
                start++;  
            else  
                end--;  
        }  
        return ret;          
    }
};