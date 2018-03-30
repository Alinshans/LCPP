// Title: Decode Ways
// Language: C++
// Runtime: 4 ms
// Submitted: 2018/3/30

class Solution {
public:
    bool valid(char c) {
        return '1' <= c && c <= '9';
    }
    bool valid(char a, char b) {
        return a == '1' || (a == '2' && '0' <= b && b <= '6');
    }
    int numDecodings(string s) {
        int len = s.size();
        if (len == 0 || s[0] == '0') return 0;
        int res = 0, pre = 1, cur = 1;
        for (int i = 1; i < len; ++i) {
            res = 0;
            if (!valid(s[i]) && !valid(s[i-1], s[i])) return 0;
            if (valid(s[i])) res = cur;
            if (valid(s[i-1], s[i])) res += pre;
            pre = cur;
            cur = res;
        }
        return cur;
    }
};
