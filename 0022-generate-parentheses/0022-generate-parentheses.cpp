class Solution {
public:
void gen(vector<string> &ans,int max,int open,int close,string re){
    if(re.length()==(2*max)){
        ans.push_back(re);
        return;
    }
    if(open<max){
        gen(ans,max,open+1,close,re+"(");
    }
    if(close<open){
        gen(ans,max,open,close+1,re+")");
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        int max = n;
        gen(ans,max,0,0,"");
        return ans;
    }
};