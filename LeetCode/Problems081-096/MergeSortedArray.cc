// Title: Merge Sorted Array
// Language: C++
// Runtime: 7 ms
// Submitted: 2018/3/29

// use std::merge
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp(m + n);
        std::merge(nums1.begin(), nums1.begin() + m, nums2.begin(), nums2.begin() + n, tmp.begin());
        nums1.swap(tmp);
    }
};

// don't use std::merge
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (m + n > 0) {
            if (m == 0) nums1[n - 1] = nums2[--n];
            else if (n == 0) nums1[m - 1] = nums1[--m];
            else nums1[m + n - 1] = (nums2[n - 1] < nums1[m - 1]) ? nums1[--m] : nums2[--n];
        }
    }
};
