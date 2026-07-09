class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(int j = 0;j<n;j++){
            mp[nums[j]]=j;

        }
        for(int j=0;j<n;j++){
            if(mp.find(target-nums[j])!=mp.end() && mp[target-nums[j]]!=j){
                return {j,mp[target-nums[j]]};
            }
        }
        return {-1,-1};
    }
};