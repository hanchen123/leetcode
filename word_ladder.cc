class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> que;
        queue<int> dep;
        unordered_map<string, int> mp;
        que.push(start);
        dep.push(1);
        mp[start] = 1;
        string cur, nxt;
        int step;
        while (!que.empty()) {
            cur = que.front();
            que.pop();
            step = dep.front();
            dep.pop();
            if (cur == end)
                return step;
            for (int i = 0; i < cur.length(); i++)
                for (char j = 'a'; j <= 'z'; j++) {
                    if (cur[i] == j)
                        continue;
                    nxt = cur;
                    nxt[i] = j;
                    if (dict.count(nxt) && mp[nxt] == 0) {
                        mp[nxt] = 1;
                        que.push(nxt);
                        dep.push(step + 1);
                    }
                }
        }
        return 0;
    }
};