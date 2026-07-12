class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<pair<int, int>,int>> q;
        int vis[n][m];
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(grid[j][k]==2){
                    q.push({{j, k},0});
                    vis[j][k]=2;
                }
                else{
                    vis[j][k]=0;
                }
            }
        }
        int tm=0;
        int drow[]={-1, 0,1,0};
        int dcol[]={0, 1,0,-1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int t=q.front().second;
            q.pop();
            tm=max(tm, t);
            for(int h=0;h<4;h++){
                int nrow=row+drow[h];
                int ncol=col+dcol[h];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow, ncol},t+1});
                    vis[nrow][ncol]=2;
                }
            }
        }
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(vis[j][k]!=2 && grid[j][k]==1){
                    return -1;
                }
            }
        }
        return tm;
    }
};
