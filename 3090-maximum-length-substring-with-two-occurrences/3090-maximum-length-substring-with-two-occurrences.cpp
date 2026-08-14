class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char, int> mp;
        int l = 0;
        int h = 0;
        int ans = 0;

        while (h < s.size()) {
            mp[s[h]]++;

            while (mp[s[h]] > 2) {
                mp[s[l]]--;
                l++;
            }

            ans = max(ans, h - l + 1);
            h++;
        }

        return ans;
    }
};