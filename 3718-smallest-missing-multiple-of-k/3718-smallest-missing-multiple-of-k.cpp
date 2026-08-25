class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        for(int j=1;j<1000;j++){
            if(st.find(j)==st.end() && j%k==0){
                return j;
            }
        }
        return -1;
    }
};