class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for (int i = 0; i < n; i++) {
            if (vis[i] != -1) continue;

            queue<pair<int, int>> q;
            q.push({i, 0});
            vis[i] = 0;

            while (!q.empty()) {
                int node = q.front().first;
                int val = q.front().second;
                q.pop();

                for (auto it : graph[node]) {
                    int nval = (val == 1) ? 0 : 1;

                    if (vis[it] == val)
                        return false;

                    if (vis[it] == -1) {
                        vis[it] = nval;
                        q.push({it, nval});
                    }
                }
            }
        }

        return true;
    }
};