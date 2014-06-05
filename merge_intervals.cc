bool cmp(Interval A, Interval B) {
    if (A.start != B.start)
        return A.start < B.start;
    return A.end < B.end;
}   

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.size() == 0)
            return intervals;
        sort(intervals.begin(), intervals.end(), cmp);
        vector<Interval> ret;
        int start = intervals[0].start;
        int end = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= end)
                end = max(end, intervals[i].end);
            else {
                ret.push_back(Interval(start, end));
                start = intervals[i].start;
                end = intervals[i].end;
            }
        }
        if (start <= end)
            ret.push_back(Interval(start, end));
        return ret;        
    }
};