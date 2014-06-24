class Solution {
public:
    string getPermutation(int n, int k) {
        string ret = "";
        int num[n];
        num[0] = 1;
        for (int i = 1; i <= n; i++) 
            num[i] = num[i - 1] * i;
        bool vis[n];
        memset(vis, false, sizeof(vis));
        k--;
        int i, j, tmp;
        for (i = 0; i < n; i++) {
            tmp = k / num[n - 1 - i];
            for (j = 0; j < n; j++) {
                if (!vis[j]) {
                    if (tmp == 0)   break;
                    tmp--;
                }
            }
            ret.push_back(j + 1 + '0');
            vis[j] = true;
            k %= num[n - 1 - i];
        }
        return ret;        
    }
};