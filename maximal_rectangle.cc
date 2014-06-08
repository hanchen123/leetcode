class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        int m = matrix.size();
        if (m == 0)
            return 0;
        int n = matrix[0].size();
        vector<vector<int> > height;
        vector<int> tmp;
        for (int i = 0; i < n + 1; i++) 
            tmp.push_back(0);
        for (int i = 0; i < m; i++) 
            height.push_back(tmp);
        int maxR = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '0')
                    height[i][j] = 0;
                else 
                    height[i][j] = i == 0 ? 1 : height[i - 1][j] + 1;
            }
        }
        for(int i = 0; i < m; i++) {
            int R = this->largestRectangleArea(height[i]);
            if (R > maxR)
                maxR = R;
        }
        return maxR;        
    }
private:
    int largestRectangleArea(vector<int> &height) {
        stack<int> st;   
        int ret = 0;  
        for (int i = 0; i < height.size(); i++) {  
            if (st.empty() || height[i] > height[st.top()]) 
                st.push(i);  
            else {  
                int tmp = st.top();  
                st.pop();  
                ret = max(ret, height[tmp]*(st.empty()? i : i-st.top()-1));  
                    i--;  
            }  
        }  
        return ret;         
    }
};