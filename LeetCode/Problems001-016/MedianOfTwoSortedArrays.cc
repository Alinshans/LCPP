// Title: Median of Two Sorted Arrays
// Language: C++
// Runtime: 46 ms
// Submitted: 2016/11/2

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		const int s = nums1.size() + nums2.size();
		vector<int> v(s);
		merge(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), v.begin());
		if (s & 1)
			return static_cast<double>(v[(v.size() - 1) >> 1]);
		return static_cast<double>(v[(v.size() >> 1) - 1] + v[v.size() >> 1]) / 2.0;
	}
};
