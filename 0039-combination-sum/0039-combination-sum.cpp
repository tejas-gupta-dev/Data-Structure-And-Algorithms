class Solution {
public:
    void gen(vector<vector<int>>& ans, vector<int>& candidates,
             int tar, int j, vector<int> temp) {

        if (tar == 0) {
            ans.push_back(temp);
            return;
        }

        if (j >= candidates.size() || tar < 0)
            return;

    
        vector<int> take = temp;
        take.push_back(candidates[j]);
        gen(ans, candidates, tar - candidates[j], j, take);

        gen(ans, candidates, tar, j + 1, temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        gen(ans, candidates, target, 0, temp);
        return ans;
    }
};