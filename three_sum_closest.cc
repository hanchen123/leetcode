class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        sort(num.begin(), num.end());  
        int ret, min = INT_MAX;  
        int len = num.size();  
        for(int i =0; i< len-2; i++) {  
            int start = i + 1, end = len - 1;  
            while(start < end) {  
                int sum = num[i] + num[start] + num[end];
                if(sum == target) {  
                    min = 0;
                    ret = sum;
                    break;
                }  
                else if(sum < target) {  
                    if(target - sum < min) {  
                        min = target - sum;  
                        ret = sum;  
                    }  
                    start++;            
                }  
                else {  
                    if(sum - target < min) {  
                        min = sum - target;  
                        ret = sum;  
                    }  
                    end--;   
                }  
                if(i < len-2)  
                    while(num[i] == num[i+1]) i++;  
            }  
        }
        return ret;          
    }
};