// Title: Sqrt(x)
// Language: C++
// Runtime: 32 ms
// Submitted: 2018/3/28

// binary search
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        std::uint64_t l = 1;
        std::uint64_t r = 46340;  // sqrt(2147483647)
        while(1) {
            auto m = l + (r - l) / 2;
            if (m * m > x) r = m - 1;
            else {
                if ((m + 1) * (m + 1) > x) return m;
                l = m + 1;
            }
        }
    }
};

// newton
class Solution {
public:
    int mySqrt(int x) {
        if(x < 2) return x;
        std::uint64_t r = x;
        while (r * r > x)
            r = (r + x / r) / 2;
        return r;
    }
};
