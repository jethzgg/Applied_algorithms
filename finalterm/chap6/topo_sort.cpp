#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> visited;
vector<int> order;
int hasCycle = 0;

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
    if (hasCycle)
    {
        cout << -1 << "\n";
    }
    else
    {
        for (auto i : order)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}