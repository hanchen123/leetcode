class Solution {
public:
    int singleNumber(int A[], int n) {
        int ret = 0;
        for (int i = 0; i < 32; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) 
                count += ((A[j] >> i) & 1); 
            ret |= ((count % 3) << i);   
        }
        return ret;        
    }
};