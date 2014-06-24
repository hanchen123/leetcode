class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int idx = num.size() -1;   
        while(idx > 0) {   
            if(num[idx-1] < num[idx])   
                break;   
            idx--;   
        }   
        if(idx > 0) {   
            idx--;  
            int tmp1 = num.size() - 1;   
            while(tmp1 >= 0 && num[tmp1] <= num[idx])   
                tmp1--;   
            swap(num[idx], num[tmp1]);   
            idx++;   
        }   
        int tmp2 = num.size() - 1;   
        while(tmp2 > idx) {   
            swap(num[idx], num[tmp2]);   
            tmp2--;   
            idx++;   
        }            
    }
};