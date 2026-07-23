class Solution {
public:
    void gen(vector<string>& ans,int max, int op,int cl,string re){
        if(re.size()==2*max){
            ans.push_back(re);
            return;
        }
        if(op<max){
            gen(ans, max, op+1, cl, re+'(');
        }
        if(cl<op){
            gen(ans, max, op, cl+1, re+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        gen(ans,n,0,0,"");
        return ans;
    }
};