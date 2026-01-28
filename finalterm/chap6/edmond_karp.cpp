#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;
int n, m;
vector<vector<int>> capacity;
vector<vector<int>> adj;
int bfs(int source, int sink, vector<int>& parent)
{
    fill(parent.begin(), parent.end(), -1);
    parent[source] = source;
    queue<pair<int, int>> q;
    q.push({source, INT_MAX});
    while (!q.empty())
    {
        int u = q.front().first;
        int flow = q.front().second;
        q.pop();
        for (int v : adj[u])
        {
            if (parent[v] == -1 && capacity[u][v] > 0)
            {
                parent[v] = u;
                int new_flow = min(flow, capacity[u][v]);
                if (v == sink)
                    return new_flow;
                q.push({v, new_flow});
            }
        }
    }
    return 0;
}
int edmond_karp(int source, int sink)
{
    int max_flow = 0;
    vector<int> parent(n + 1);
    int new_flow;
    while ((new_flow = bfs(source, sink, parent)) > 0)
    {
        max_flow += new_flow;
        int cur = sink;
        while (cur != source)
        {
            int prev = parent[cur];
            capacity[prev][cur] -= new_flow;
            capacity[cur][prev] += new_flow;
            cur = prev;
        }
    }
    return max_flow;
}

int main()
{
    cin >> n >> m;
    capacity.resize(n + 1, vector<int>(n + 1, 0));
    adj.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        capacity[u][v] += c;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int source, sink;
    cin >> source >> sink;
    cout << edmond_karp(source, sink) << "\n";
    return 0;
}
