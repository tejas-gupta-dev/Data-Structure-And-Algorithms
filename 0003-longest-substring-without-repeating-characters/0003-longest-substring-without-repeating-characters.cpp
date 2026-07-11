class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int n=s.length();
        unordered_map<char,int> mp;
        int maxlen=0;
        int currlen=0;
        while(j<n){
            if(mp.find(s[j])!=mp.end()){
                i = max(i, mp[s[j]] + 1);
            }
            mp[s[j]]=j;
            currlen=j-i+1;
            maxlen=max(maxlen,currlen);
            j++;
        }
        return maxlen;
    }
};