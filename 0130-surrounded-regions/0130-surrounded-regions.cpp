class Solution {
public:
    int n;
    int m;
    void dfs(vector<vector<int>>& vis, vector<vector<char>>& board, int j,
             int k) {
        int delrow[] = {0, -1, 0, 1};
        int delcol[] = {-1, 0, 1, 0};
        vis[j][k] = 1;
        for (int l = 0; l < 4; l++) {
            int nrow = j + delrow[l];
            int ncol = k + delcol[l];
            if (nrow < n && nrow >= 0 && ncol < m && ncol >= 0 &&
                !vis[nrow][ncol] && board[nrow][ncol] == 'O') {
                dfs(vis, board, nrow, ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int j = 0; j < n; j++) {
            if (board[j][0] == 'O' && !vis[j][0]) {
                dfs(vis, board, j, 0);
            }
            if (board[j][m - 1] == 'O' && !vis[j][m - 1]) {
                dfs(vis, board, j, m - 1);
            }
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O' && !vis[0][j]) {
                dfs(vis, board, 0, j);
            }
            if (board[n - 1][j] == 'O' && !vis[n - 1][j]) {
                dfs(vis, board, n - 1, j);
            }
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (board[j][k] == 'O' && !vis[j][k]) {
                    board[j][k] = 'X';
                }
            }
        }
    }
};