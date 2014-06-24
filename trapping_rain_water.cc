class Solution {
public:
    int trap(int A[], int n) {
        if(n < 2) 
            return 0;  
        int *maxL = new int[n], *maxR = new int[n];  
        int maxV = A[0];  
        maxL[0] = 0;  
        for(int i = 1; i < n-1; i++) {  
            maxL[i] = maxV;  
            maxV = max(maxV, A[i]);        
        }  
        maxV = A[n-1];  
        maxR[n-1] = 0;  
        int minV = 0;  
        int ret = 0;
        for(int i = n-2; i > 0; i--) {  
            maxR[i] = maxV;  
            minV = min(maxL[i], maxR[i]) -A[i];  
            if(minV > 0)  
                ret += minV;  
            maxV = max(maxV, A[i]);  
        }  
        delete maxL, maxR;  
        return ret;          
    }
};