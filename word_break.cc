class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if (s == "")
            return true;
        int len = s.length();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 0; i < len; i++) {
            if (dp[i] == false)
                continue;
            for (int j = 1; i + j <= len; j++)
                if (dict.find(s.substr(i, j)) != dict.end())
                    dp[i + j] = true;
        }
        return dp[len];
    }
};