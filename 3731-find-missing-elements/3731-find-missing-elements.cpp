class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int start=nums[0];
        int n=nums.size();
        int end=nums[n-1];
        unordered_set<int> mp;
        vector<int> ans;
        for(auto it:nums){
            mp.insert(it);
        }
        while(start<end){
            start++;
            if(mp.find(start)==mp.end()){
                ans.push_back(start);
            }
        }
        return ans;
    }
};