class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<string> ret;
        if (s == "")
            return ret;
        int len = s.length();
        vector<vector<int>> dp;
        vector<int> vt;
        for (int i = 0; i < len + 1; i++) 
            dp.push_back(vt);
        dp[0].push_back(0);
        for (int i = 0; i < len; i++) {
            if (dp[i].size() == 0)
                continue;
            for (int j = 1; i + j <= len; j++) {
                if (dict.find(s.substr(i, j)) != dict.end()) 
                    dp[i + j].push_back(i);
            }
        }
        string tmp = "";
        this->Excute(dp, ret, tmp, s, len);
        return ret;
    }
private:
    void Excute(vector<vector<int>> &dp, vector<string> &ret, string tmp, string &s, int cur) {
        if (cur == 0) {
            ret.push_back(tmp);
            return;
        }
        for (int i = 0; i < dp[cur].size(); i++) {
            if (cur == s.length()) 
                Excute(dp, ret, s.substr(dp[cur][i], cur - dp[cur][i]), s, dp[cur][i]);
            else 
                Excute(dp, ret, s.substr(dp[cur][i], cur - dp[cur][i]) + " " + tmp, s, dp[cur][i]);
        }
    }
};