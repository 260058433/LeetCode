#include <vector>
#include <algorithm>

using std::vector;
using std::sort;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class IntervalComp {
public:
    bool operator()(const Interval &i1, const Interval &i2) {
        if (i1.start < i2.start || (i1.start == i2.start && i1.end > i2.end))
            return true;
        else
            return false;
    }
};

class MergeIntervals {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        if (intervals.empty())
            return vector<Interval>();
        sort(intervals.begin(), intervals.end(), IntervalComp());
        vector<Interval> result;
        Interval cur = intervals[0];
        for (int i = 1; i < intervals.size(); ++i) {
            if (cur.start == intervals[i].start) {
                continue;
            } else if (intervals[i].start <= cur.end && cur.end < intervals[i].end) {
                cur.end = intervals[i].end;
            } else if (cur.end < intervals[i].start) {
                result.push_back(cur);
                cur = intervals[i];
            }
        }
        result.push_back(cur);
        return result;
    }
};
