class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> mp;
        map<int, int>::iterator it;
        vector<int> ans;
        for (int i = 0; i < numbers.size(); i++) {
            it = mp.find(target - numbers[i]);
            if (it != mp.end()) {
                ans.push_back(it->second);
                ans.push_back(i + 1);
                return ans;
            }
            it = mp.find(numbers[i]);
            if (it == mp.end()) {
                mp[ numbers[i] ] = i + 1;
            }
        }
    }
};