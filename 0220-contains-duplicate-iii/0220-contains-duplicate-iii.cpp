class Solution {
public:
    bool isp(long long num, int valueDiff, set<long long> &st) {
        auto it = st.lower_bound(num - valueDiff);

        if (it != st.end() && *it <= num + valueDiff)
            return true;

        return false;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> st;

        int n = nums.size();
        int i = 0;

        for (int j = 0; j < n; j++) {

            if (isp(nums[j], valueDiff, st))
                return true;

          
            st.insert(nums[j]);

            if (j - i >= indexDiff) {
                st.erase(nums[i]);
                i++;
            }
        }

        return false;
    }
};