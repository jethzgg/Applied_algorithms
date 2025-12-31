#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> num;
vector<int> low;
stack<int> SCC;
vector<int> onStack;

int current_num = 0, cnt = 0;

void dfs(int u)
{
    current_num++;
    num[u] = current_num;
    low[u] = current_num;
    SCC.push(u);
    onStack[u] = 1;
    for (auto v : adj[u])
    {
        if (num[v] == 0)
        {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if (onStack[v] == 1)
        {
            low[u] = min(low[u], num[v]);
        }
    }
    if (low[u] == num[u])
    {
        cnt++;
        while (!SCC.empty())
        {
            int v = SCC.top();
            SCC.pop();
            onStack[v] = false;
            //cout << v << " "
            if (v == u) 
            {
                //cout << "\n";
                break;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    adj.resize(n + 1, vector<int>());
    num.resize(n + 1, 0);
    low.resize(n + 1, 0);
    onStack.resize(n + 1, 0);
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (num[i] == 0) {
            dfs(i);
        }
    }
    cout << cnt << "\n";
    return 0;
}