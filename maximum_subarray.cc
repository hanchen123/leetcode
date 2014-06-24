class Solution {
public:
    int maxSubArray(int A[], int n) {
        if (n == 0) 
            return 0;
        int ret = A[0];
        int cur_max = A[0];
        for (int i = 1; i < n; i++) {
            cur_max = max(cur_max + A[i], A[i]);
            ret = max(ret, cur_max);
        }
        return ret;
    }
};