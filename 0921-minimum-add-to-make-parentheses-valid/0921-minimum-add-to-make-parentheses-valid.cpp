class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int opp = 0;
        for(auto it:s){
            if(it=='('){
                st.push(it);
            }
            else{
                if(st.empty()){
                    opp++;
                }
                else{
                    st.pop();
                }
            }
        }
        return st.size()+opp;
    }
};