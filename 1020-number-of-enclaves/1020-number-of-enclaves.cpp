class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,vector<vector<int>>& vis){
        vis[row][col]=1;
        int drow[]={0,+1,0,-1};
        int n = grid.size();
        int m = grid[0].size();
        int dcol[]={-1,0,+1,0};
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]==1 && !vis[nrow][ncol]){
                dfs(nrow,ncol,grid,vis);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int j=0;j<n;j++){
            if(grid[j][0]==1 && !vis[j][0]){
                dfs(j,0,grid,vis);
            }
            if(grid[j][m-1]==1 && !vis[j][m-1]){
                dfs(j,m-1,grid,vis);
            }
        }
        for(int j=0;j<m;j++){
            if(grid[0][j]==1 && !vis[0][j]){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j]==1 && !vis[n-1][j]){
                dfs(n-1,j,grid,vis);
            }
        }
        int count=0;
        for(int j=0;j<n;j++){
            for(int k=0;k<m;k++){
                if(grid[j][k]==1 && !vis[j][k]){
                    count++;
                }
            }
        }
        return count;
    }
};