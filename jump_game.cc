class Solution {
public:
    bool canJump(int A[], int n) {
        int step = 0;  
        for(int start = 0; start <= step && start< n; start++) {  
            if(A[start] + start > step)  
                step = A[start] + start;  
            if(step >= n-1) 
                return true;  
        }  
        return false;          
    }
};