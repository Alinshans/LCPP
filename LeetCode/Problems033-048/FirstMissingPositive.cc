// Title: First Missing Positive 
// Language: C++
// Runtime: 6 ms
// Submitted: 2017/3/8

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        const auto& s = nums.size();
        for(auto i = 0; i < s; ++i){
            while (nums[i] > 0 && nums[i] <= s && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for(auto i = 0; i < s; ++i){
            if(nums[i] != i + 1) return i + 1;
        }
        return s + 1;
    }
};
