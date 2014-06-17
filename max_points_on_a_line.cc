class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size() <= 1)
            return points.size();
        unordered_map<float, int> mp;
        unordered_map<float, int>::iterator it;
        int max = INT_MIN;         
        for (int i = 0; i < points.size(); i++) { 
            mp.clear();
            mp[0] = 0;
            int duplicate = 0;
            for (int j = 0; j < points.size(); j++) {
                if (j == i) continue;             
                if (points[j].x == points[i].x && points[j].y == points[i].y) {
                    duplicate++;
                    continue;
                }
                float key = (points[j].x - points[i].x) == 0 ? INT_MAX:(points[i].y - points[j].y)*1.0 / (points[i].x - points[j].x);                  mp[key]++;
                for (it = mp.begin(); it != mp.end(); ++it) {
                    if (it->second + duplicate >max) 
                        max = it->second + duplicate;    
                }
            }
        }
        return max;
    }
};