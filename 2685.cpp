class Solution {
public:
    vector<vector<int>> adj;
    vector<int> vis;

    void dfs(int node, int &nodes, int &degree) {
        vis[node] = 1;
        nodes++;

        degree += adj[node].size();

        for (int next : adj[node]) {
            if (!vis[next]) {
                dfs(next, nodes, degree);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        adj.resize(n);
        vis.assign(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {

                int nodes = 0;
                int degree = 0;

                dfs(i, nodes, degree);

                int edgeCount = degree / 2;
                int need = nodes * (nodes - 1) / 2;

                if (edgeCount == need)
                    ans++;
            }
        }

        return ans;
    }
};