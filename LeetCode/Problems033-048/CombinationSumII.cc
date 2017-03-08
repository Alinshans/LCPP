// Title: Combination Sum II 
// Language: C++
// Runtime: 9 ms
// Submitted: 2017/3/8

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> c;
        dfs(candidates, target, res, c, 0);
        return res;
    }
    void dfs(const vector<int>& c, int t, vector<vector<int>>& r, vector<int>& cs, int first) {
        if(t == 0){
            r.push_back(cs);
            return;
        }
        for(auto i = first; i < c.size() && t >= c[i]; ++i) {
            if(i == first || c[i] != c[i-1]) {
                cs.push_back(c[i]);
                dfs(c,t-c[i],r,cs,i+1);
                cs.pop_back();
            }
        }
    }
};
