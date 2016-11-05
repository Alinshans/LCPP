// Title: Container With Most Water
// Language: C++
// Runtime: 22 ms
// Submitted: 2016/11/4

class Solution {
public:
	int maxArea(vector<int>& height) {
		int ans = 0, low;
		for (int i = 0, j = height.size() - 1; i < j;) {
			if (height[i] < height[j])
				low = height[i++];
			else
				low = height[j--];
			ans = max(ans, low * (j - i + 1));
		}
		return ans;
	}
};
