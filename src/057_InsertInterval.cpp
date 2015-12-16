#include <vector>

using std::vector;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class InsertInterval {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int i = 0, j = intervals.size() - 1;
        while (i <= j) {
            int m = i + (j - i) / 2;
            if (intervals[m].end < newInterval.start) {
                i = m + 1;
            } else if (newInterval.start < intervals[m].end) {
                j = m - 1;
            } else {
                i = m;
                break;
            }
        }
        if (i == intervals.size()) {
            intervals.push_back(newInterval);
        } else {
            if (newInterval.end < intervals[i].start) {
                intervals.insert(intervals.begin() + i, newInterval);
            } else {
                if (newInterval.start < intervals[i].start)
                    intervals[i].start = newInterval.start;
                if (intervals[i].end < newInterval.end)
                    intervals[i].end = newInterval.end;
                int k = i + 1;
                while (k < intervals.size() && intervals[k].start <= newInterval.end) {
                    if (newInterval.end < intervals[k].end)
                        intervals[i].end = intervals[k].end;
                    ++k;
                }
                intervals.erase(intervals.begin() + i + 1, intervals.begin() + k);
            }
        }
        return intervals;
    }
};
