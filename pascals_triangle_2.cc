class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret(rowIndex+2, 0);  
        ret[1]=1;  
        for(int i = 0; i < rowIndex; i++) {  
            for(int j = rowIndex + 1; j>0; j--)  
                ret[j] = ret[j-1] + ret[j];  
        }  
        ret.erase(ret.begin());  
        return ret;         
    }
};