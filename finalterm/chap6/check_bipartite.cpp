#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    int n, m;
    vector<vector<int>> adj;
    vector<int> color;
    queue<int> q;
    cin >> n >> m;
    adj.resize(n + 1, vector<int>());
    color.resize(n + 1, -1); // -1, 0, 1
    
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            q.push(i);
            while (!q.empty())
            {
                int u = q.front();
                q.pop();
                for (auto v : adj[u])
                {
                    if (color[v] == -1)
                    {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    else if (color[v] == color[u])
                    {
                        cout << 0 << "\n";
                        return 0;
                    }
                }
            }
        }
    }
    cout << 1 << "\n";
    return 0;
}