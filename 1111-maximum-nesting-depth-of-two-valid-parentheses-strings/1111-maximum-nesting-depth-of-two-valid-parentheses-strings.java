class Solution {
    public int[] maxDepthAfterSplit(String seq) {
        int n = seq.length();
        Stack<Integer> st = new Stack<>();
        int j = 0;
        int[] ans = new int[n];
        while (j < n) {
            if (seq.charAt(j) == '(') {
                if (st.isEmpty()) {
                    st.push(0);
                    ans[j] = st.peek();
                } else {
                    st.push((st.peek() == 0) ? 1 : 0);
                    ans[j]=st.peek();
                }
            }
            else{
                ans[j]=st.pop();
            }
            j++;
        }
        return ans;
    }
}