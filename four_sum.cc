class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        if (num.size() < 4) 
            return ret;
        sort(num.begin(), num.end());
        for (int i = 0; i < num.size() - 3; i++) {
            if (i > 0 && num[i] == num[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < num.size() - 2; j++) {
                if (j != i + 1 && num[j] == num[j - 1]) 
                    continue;
                int start = j + 1;
                int end = num.size() - 1;
                while (start < end) {
                    int tmp = num[i] + num[j] + num[start] + num[end];
                    if (tmp == target) {
                        vector<int> vt;
                        vt.push_back(num[i]);
                        vt.push_back(num[j]);
                        vt.push_back(num[start]);
                        vt.push_back(num[end]);
                        ret.push_back(vt);
                        start++;
                        end--;  
                        while(start < end && num[start] == num[start-1])  start++;  
                        while(start < end && num[end] == num[end+1])  end--;  
                    } 
                    else if (tmp < target) 
                        start++;
                    else 
                        end--;
                }
            }
        }
        return ret;
    }
};