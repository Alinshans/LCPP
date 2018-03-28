// Title: Minimum Window Substring
// Language: C++
// Runtime: 11 ms
// Submitted: 2018/3/28

class Solution {
public:
    string minWindow(string s, string t) {
        std::vector<int> map(128, 0);
        for (auto&& c : t) map[c]++;
        int begin = 0, end = 0, min = INT_MAX, first = 0;
        int cnt = t.size(), len = s.size();
        while (end < len) {
            if (map[s[end++]]-- > 0) --cnt;
            while (cnt == 0) {
                if (end - begin < min) {
                    min = end - begin;
                    first = begin;
                }
                if (map[s[begin++]]++ == 0) ++cnt;  // make it invaild
            }
        }
        return min == INT_MAX ? "" : s.substr(first, min);
    }
};
