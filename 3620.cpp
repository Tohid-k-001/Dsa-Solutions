#include <iostream>
#include <queue>
#include <stack>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();

        int mx = 0;
        for (auto &e : edges)
            mx = max(mx, e[2]);

        auto check = [&](int limit) -> bool {

            vector<vector<pair<int,int>>> g(n);
            vector<int> indegree(n, 0);

            for (auto &e : edges) {
                int u = e[0];
                int v = e[1];
                int w = e[2];

                if (w < limit)
                    continue;

                if ((u != 0 && !online[u]) || (v != n - 1 && !online[v]))
                    continue;

                g[u].push_back({v, w});
                indegree[v]++;
            }

            queue<int> q;
            for (int i = 0; i < n; i++)
                if (indegree[i] == 0)
                    q.push(i);

            vector<int> topo;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                topo.push_back(u);

                for (auto &x : g[u]) {
                    if (--indegree[x.first] == 0)
                        q.push(x.first);
                }
            }

            const long long INF = 4e18;
            vector<long long> dist(n, INF);
            dist[0] = 0;

            for (int u : topo) {
                if (dist[u] == INF)
                    continue;

                for (auto &x : g[u]) {
                    int v = x.first;
                    int w = x.second;

                    if (dist[v] > dist[u] + w)
                        dist[v] = dist[u] + w;
                }
            }

            return dist[n - 1] <= k;
        };

        int lo = 0;
        int hi = mx;
        int ans = -1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (check(mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return ans;
    }
};