class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        unordered_map<string, int> mp;
        que.push_back(start);
        dep.push_back(1);
        vt.push_back(vector<int>());
        vt.back().push_back(-1);
        int step = 0, curstep, finalstep = 0;
        while (step < que.size()) {
            string nxt, str = que[step];
            curstep = dep[step];
            if (finalstep != 0 && curstep == finalstep)
                break;
            for (int i = 0; i < str.length(); i++)
                for (char j = 'a'; j <= 'z'; j++) {
                    if (str[i] == j)
                        continue;
                    nxt = str;
                    nxt[i] = j;
                    if (nxt == end) {
                        finalstep = curstep + 1;
                        vector<string> tmp;
                        tmp.push_back(end);
                        this->findstrings(tmp, step);
                        continue;
                    }
                    if (dict.count(nxt)) {
                        if (mp[nxt] == 0) {
                            que.push_back(nxt);
                            dep.push_back(curstep + 1);
                            vt.push_back(vector<int>());
                            vt.back().push_back(step);
                            mp[nxt] = vt.size() - 1;
                        }
                        else if (dep[ mp[nxt] ] == curstep + 1)
                            vt[ mp[nxt] ].push_back(step);
                    }
                }
            step++;
        }
        return ret;
    }
private:
    vector<string> que;
    vector<int> dep;
    vector<vector<int>> vt;
    vector<vector<string>> ret;
    void findstrings(vector<string> &tmp, int step) {
        if (step == -1) {
            ret.push_back(vector<string>());
            for (int i = tmp.size() - 1; i >= 0; i--)
                ret.back().push_back(tmp[i]);
            return;
        }
        for (int i = 0; i < vt[step].size(); i++) {
            tmp.push_back(que[step]);
            findstrings(tmp, vt[step][i]);
            tmp.pop_back();
        }
    }
};