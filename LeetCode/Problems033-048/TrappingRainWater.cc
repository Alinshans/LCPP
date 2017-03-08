// Title: Trapping Rain Water
// Language: C++
// Runtime: 15 ms
// Submitted: 2017/3/8

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() < 3) return 0;
        auto l = height.begin(), r = height.end() - 1;
        int water = 0, level = 0;
        while(l != r + 1){
            int low = *l < *r ? *l++ : *r--;
            level = max(level, low);
            water += level - low;
        }
        return water;
    }
};
