// Title: Remove Element
// Language: C++
// Runtime: 4 ms
// Submitted: 2016/7/2

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		vector<int>::iterator it;
		for (it = nums.begin(); it != nums.end();)
		{
			if (*it == val)  it = nums.erase(it);
			else ++it;
		}
		return nums.size();
	}
};
