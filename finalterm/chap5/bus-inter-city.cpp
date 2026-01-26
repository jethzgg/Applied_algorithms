#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

int n, m;
vector<int> c, d, visited, dp;
vector<vector<int>> adj;
vector<long long> dis;
vector<vector<pair<int, int>>> adj1;

void bfs(int i, int limit)
{
    fill(visited.begin(), visited.end(), 0);
    queue<pair<int, int>> q;
    q.push({i, 0});
    visited[i] = 1;
    
    while (!q.empty())
    {
        int u = q.front().first;
        int depth = q.front().second;
        q.pop();
        
        if (u != i)
        {
            adj1[i].push_back({u, c[i]});
        }
        
        if (depth >= limit) continue;
        
        for (auto v : adj[u])
        {
            if (!visited[v])
            {
                visited[v] = 1;
                q.push({v, depth + 1});
            }
        }
    }
}

void dijkstra(int s)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    dis[s] = 0;
    pq.push({0, s});

    for (int i = 0; i < n; i++)
    {
        int u = -1;

        while (!pq.empty()) {
            u = pq.top().second;
            pq.pop();
            if (!visited[u]) break;
        }

        if (u == -1 || dis[u] == INT_MAX) break;

        visited[u] = 1;

        for (auto edge : adj1[u])
        {
            int v = edge.first;
            int w = edge.second;

            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    c.resize(n + 1, 0);
    d.resize(n + 1, 0);
    dp.resize(n + 1, 0);
    visited.resize(n + 1, 0);
    adj.resize(n + 1, vector<int>());
    adj1.resize(n + 1, vector<pair<int, int>>());
    dis.resize(n + 1, INT_MAX);

    for (int i = 1; i <= n; i++)
    {
        cin >> c[i] >> d[i];
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        bfs(i, d[i]);
    }
    fill(visited.begin(), visited.end(), 0);
    dijkstra(1);
    cout << dis[n] << "\n";
    return 0;
}