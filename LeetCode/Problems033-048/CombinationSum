// Title: Combination Sum 
// Language: C++
// Runtime: 12 ms
// Submitted: 2017/3/8

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> c;
        dfs(candidates, target, ans, c, 0);
        return ans;
    }
    void dfs(const vector<int>& c, int t, vector<vector<int>>& r, vector<int>& cs, int first) {
        if(t == 0){
            r.push_back(cs);
            return;
        }
        for(auto i = first; i < c.size() && t >= c[i]; ++i){
            cs.push_back(c[i]);
            dfs(c, t - c[i], r, cs, i);
            cs.pop_back();
        }
    }
};
