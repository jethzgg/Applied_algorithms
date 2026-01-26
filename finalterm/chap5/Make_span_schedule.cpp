#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> d;
vector<int> visited;
vector<int> order;
int hasCycle = 0;
int ans = 0;
vector<int> f;

void topo(int u)
{
    if (visited[u] == 2) return; // done

    if (visited[u] == 1)
    {
        hasCycle = 1;
        // cycle
        return;
    }

    visited[u] = 1;

    for (auto v : adj[u])
    {
        topo(v);
        if (hasCycle) return;
    }
    visited[u] = 2;
    order.push_back(u);
}

int main()
{
    cin >> n >> m;
    d.resize(n + 1, 0);
    f.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> d[i];
    }
    adj.resize(n + 1, vector<int>());
    visited.resize(n + 1, 0);
    // 2: done, 1: current, 0: have not visited yet
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) topo(i);
    }
    reverse(order.begin(), order.end());
    for (auto u : order)
    {
        f[u] += d[u];
        for (auto v : adj[u])
        {
            f[v] = max(f[v], f[u]);
        }
        ans = max(ans, f[u]);
    }
    cout << ans << "\n";
    return 0;
}


