class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> ret;
        int start, end, cur = 0;
        while (cur < intervals.size() && intervals[cur].end < newInterval.start)
            ret.push_back(intervals[cur++]);
        if (intervals.size() == cur) {
            ret.push_back(newInterval);
            return ret;
        }
        if (newInterval.end < intervals[cur].start) {
            start = newInterval.start;
            end = newInterval.end;
        } 
        else {
            start = min(newInterval.start, intervals[cur].start);
            end = max(newInterval.end, intervals[cur++].end);
        }
        while (cur < intervals.size() && intervals[cur].start <= end)
            end = max(end, intervals[cur++].end);
        ret.push_back(Interval(start, end));
        while (cur < intervals.size()) {
            ret.push_back(intervals[cur++]);
        }
        return ret;        
    }
};