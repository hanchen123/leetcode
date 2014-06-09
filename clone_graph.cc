class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == NULL)
            return NULL;
        UndirectedGraphNode *ret = new UndirectedGraphNode(node->label);
        map<UndirectedGraphNode *, UndirectedGraphNode *> mp;
        mp[node] = ret;
        queue<UndirectedGraphNode *> que;
        que.push(node);
        UndirectedGraphNode *tmp1 = NULL, *tmp2 = NULL;
        while (!que.empty()) {
            tmp1 = que.front();
            que.pop();
            for (int i = 0; i < (tmp1->neighbors).size(); i++) {
                tmp2 = (tmp1->neighbors)[i];
                if (mp.find(tmp2) == mp.end()) {
                    mp[tmp2] = new UndirectedGraphNode(tmp2->label);
                    que.push(tmp2);
                }
                (mp[tmp1]->neighbors).push_back(mp[tmp2]);
            }
        }
        return ret;        
    }
};