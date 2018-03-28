// Title: Merge Intervals
// Language: C++
// Runtime: 16 ms
// Submitted: 2018/3/28

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if (intervals.size() == 0) return {};
        std::sort(intervals.begin(), intervals.end(), [&](auto& a, auto& b){ return a.start < b.start; });
        std::vector<Interval> res;
        res.push_back(intervals[0]);
        for (auto&& interval : intervals) {
            if (interval.start > res.back().end) res.emplace_back(interval);
            else res.back().end = std::max(res.back().end, interval.end);
        }
        return res;
    }
};
