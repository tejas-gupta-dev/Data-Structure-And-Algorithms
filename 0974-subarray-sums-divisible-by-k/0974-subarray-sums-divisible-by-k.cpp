class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = 1;

        int curr = 0;
        int ans = 0;

        for (int j = 0; j < nums.size(); j++) {
            curr += nums[j];

            int rem = ((curr % k) + k) % k;   // Handle negative remainder

            if (mp.find(rem) != mp.end()) {
                ans += mp[rem];
            }

            mp[rem]++;
        }

        return ans;
    }
};