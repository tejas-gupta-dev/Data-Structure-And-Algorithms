class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int n=nums.size();
        int curr=0;
        int sum=0;
        for(int j = 0;j<n;j++){
            sum+=nums[j];
            if(mp.find(sum-k)!=mp.end()){
                curr+=mp[sum-k];
            }
            mp[sum]++;
        }
        return curr;
    }
};