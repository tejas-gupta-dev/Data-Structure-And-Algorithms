class Solution {
public:
    vector<vector<int>> dp;
    int gen(int n, vector<int>& prices,int j,int buy){
        if(j==n){
            return 0;
        }
        if(dp[j][buy]!=-1){
            return dp[j][buy];
        }
        long long profit=0;
        if(buy){
            profit = max(-prices[j]+gen(n,prices,j+1,0),0+gen(n,prices,j+1,1));
        }
        else{
            profit = max(prices[j]+gen(n,prices,j+1,1),gen(n,prices,j+1,0));
        }
        return dp[j][buy]= profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<int>(2,-1));
        return gen(n,prices,0,1);
    }
};