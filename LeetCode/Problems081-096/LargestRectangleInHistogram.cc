// Title: Largest Rectangle in Histogram
// Language: C++
// Runtime: 21 ms
// Submitted: 2018/3/29

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size();
        stack<int> index;
        int largest = 0;
        for (int i = 0; i < n; ++i) {
            while (!index.empty() && heights[index.top()] > heights[i]) {
                int h = heights[index.top()];
                index.pop();
                int l = index.empty() ? -1 : index.top();
                largest = std::max(largest, h * (i - l - 1));
            }
            index.push(i);
        }
        return largest;
    }
};
