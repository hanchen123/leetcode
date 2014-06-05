class Solution {
public:
    int removeDuplicates(int A[], int n) {
        if (n <= 2) return n;
        int len = 0;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (A[i] == A[len]) {
                if(count >= 2) 
                    continue;
                else {
                    A[++len] = A[i];
                    count++;
                }
            }
            else {
                A[++len] = A[i];
                count = 1;
            }
        }
        return len + 1;        
    }
};