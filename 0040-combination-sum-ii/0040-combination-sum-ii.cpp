class Solution {
public:
    void gen(vector<vector<int>>& ans, vector<int>& candidates,
             int tar, int j, vector<int>& temp) {

        if (tar == 0) {
            ans.push_back(temp);
            return;
        }

        if (j >= candidates.size() || tar < 0)
            return;

        temp.push_back(candidates[j]);
        gen(ans, candidates, tar - candidates[j], j + 1, temp);
        temp.pop_back();

        while (j + 1 < candidates.size() &&
               candidates[j] == candidates[j + 1])
            j++;

        
        gen(ans, candidates, tar, j + 1, temp);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> temp;
        gen(ans, candidates, target, 0, temp);

        return ans;
    }
};