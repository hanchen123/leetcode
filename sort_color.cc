class Solution {
public:
    void sortColors(int A[], int n) {
        int red = 0, blue = n-1;   
        int i = 0;   
        while(i < blue+1) {   
            if(A[i] == 0) {   
                swap(A[i], A[red]);   
                red++;   
                i++;   
                continue;   
            }   
            else if(A[i] == 2) {   
                swap(A[i], A[blue]);   
                blue--;    
                continue;   
            }   
            i++;  
        }
    }           
};