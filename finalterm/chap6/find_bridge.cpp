#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<pair<int, int>> bridges;
vector<int> num;
vector<int> low;
int current_num = 0;

void dfs(int v, int parent)
{
    current_num++;
    num[v] = current_num;
    low[v] = current_num;
    for (auto i : adj[v])
    {
        if (i == parent) continue;
        if (num[i] == 0)
        {
            dfs(i, v);
            low[v] = min(low[v], low[i]);
        }
        else
        {
            low[v] = min(low[v], num[i]);
        }
        if (low[i] > num[v]) bridges.push_back(make_pair(v, i));
    }
}

int main()
{
    cin >> n;
    adj.resize(n + 1, vector<int>());
    num.resize(n + 1, 0);
    low.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (auto i : bridges)
    {
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}