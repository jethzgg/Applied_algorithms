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

vector<vector<int>> res;

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
        vector<int> res1;
        while (!SCC.empty())
        {
            int v = SCC.top();
            SCC.pop();
            onStack[v] = false;

            res1.push_back(v);
            // cout << v << " ";
            if (v == u) 
            {
                sort(res1.begin(), res1.end());
                res.push_back(res1);
                // cout << "\n";
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

    sort(res.begin(), res.end());
    for (auto i : res)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "\n";
    }
    return 0;
}
/*
9 13
1 3
1 5
1 6
2 1
2 3
3 5
4 1
4 2
4 6
5 8
7 9
9 5
9 8
*/