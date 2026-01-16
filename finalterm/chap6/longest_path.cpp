#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 100000

using namespace std;

int n;
vector<int> visited(MAX + 1, 0);
vector<vector<pair<int,int>>> a(MAX + 1);
vector<int> distances(MAX + 1);

void bfs(int i)
{
    queue<int> q;
    if (visited[i] == 1) return;
    q.push(i);
    visited[i] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto path : a[u])
        {
            int v = path.first;
            int w = path.second;
            if (visited[v] == 0)
            {
                q.push(v);
                visited[v] = 1;
                distances[v] = distances[u] + w;
            }
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back(make_pair(v, w));
        a[v].push_back(make_pair(u, w));
    }
    for (int i = 1; i <= n; i++)
    {
        distances[i] = 0;
    }
    bfs(1);
    int Max = 0;
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (Max < distances[i])
        {
            Max = distances[i];
            start = i;
        }
        distances[i] = 0;
        visited[i] = 0;
    }
    bfs(start);
    Max = 0;
    for (int i = 1; i <= n; i++)
    {
        if (Max < distances[i])
        {
            Max = distances[i];
        }
    }
    cout << Max << "\n";
    return 0;
}
