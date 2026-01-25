#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> num;
vector<int> low;
vector<int> articulations;
vector<pair<int, int>> bridges;

int current_num = 0;

void dfs(int u, int parent)
{
    current_num++;
    num[u] = current_num;
    low[u] = current_num;
    int childs = 0;
    for (auto v : adj[u])
    {
        if (v == parent) continue;
        if (num[v] == 0)
        {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            childs++;
            if (low[v] > num[u]) bridges.push_back(make_pair(u, v));
            if (parent != 0 && low[v] >= num[u] && 
                find(articulations.begin(), articulations.end(), u) == articulations.end())
            {
                articulations.push_back(u);
            }
        }
        else
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (parent == 0 && childs >= 2 && 
    find(articulations.begin(), articulations.end(), u) == articulations.end())
    {
        articulations.push_back(u);
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1, vector<int>());
    num.resize(n + 1, 0);
    low.resize(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= n; i++)
    {
        if (num[i] == 0) dfs(i, 0);
    }

    cout << articulations.size() << " " << bridges.size() << "\n";
    return 0;
}