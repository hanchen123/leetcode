class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        stack<int> st;  
        height.push_back(0);  
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