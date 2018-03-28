// Title: Sort Colors
// Language: C++
// Runtime: 4 ms
// Submitted: 2018/3/28

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int n0 = -1, n1 = -1, n2 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0)
            {
                nums[++n2] = 2; nums[++n1] = 1; nums[++n0] = 0;
            }
            else if (nums[i] == 1) 
            {
                nums[++n2] = 2; nums[++n1] = 1;
            }
            else if (nums[i] == 2) 
            {
                nums[++n2] = 2;
            }
        }
    }
};
