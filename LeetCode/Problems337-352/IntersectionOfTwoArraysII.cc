// Title: Intersection of Two Arrays II
// Language: C++
// Runtime: 28 ms
// Submitted: 2016/7/2

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		vector<int> sec;
		vector<int>::iterator it;
		sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		for (int i = 0; i < nums1.size(); i++)
		{
			if ((it = find(nums2.begin(), nums2.end(), nums1[i])) != nums2.end())
			{
				sec.push_back(nums1[i]);
				nums2.erase(it);
			}
		}
		return sec;
	}
};
