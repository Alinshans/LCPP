// Title: Intersection of Two Arrays
// Language: C++
// Runtime: 28 ms
// Submitted: 2016/7/12

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s;
		set<int>::iterator it;
		for (int i = 0; i < nums1.size(); i++)
			if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end())
				s.insert(nums1[i]);
		nums1.clear();
		for (it = s.begin(); it != s.end(); it++)
			nums1.push_back(*it);
		return nums1;
	}
};
