#include <iostream>
#include <queue>
#include <vector>
#define MAX 100000
const long long INF = 1e18;

using namespace std;

int n, m;
vector<vector<pair<int, int>>> a(MAX + 1);
vector<long long> d(MAX + 1, INF);
vector<int> visited(MAX + 1, 0);

void dijkstra(int s)
{
    priority_queue<pair<long long, int>, 
    vector<pair<long long, int>>, 
    greater<pair<long long, int>>> pq;
    d[s] = 0;
    pq.push({0, s});
    for (int i = 0; i < n; i++)
    {
        int u = -1;
        while (!pq.empty()) {
            u = pq.top().second;
            pq.pop();
            if (!visited[u]) break;
        }
        if (u == -1 || d[u] == INF) break;
        visited[u] = 1;
        for (auto edge : a[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main()
{
    if (!(cin >> n >> m)) return 0;
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({v, w});
    }
    int s;
    cin >> s;
    dijkstra(s);
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == INF) cout << -1 << " ";
        else cout << d[i] << " ";
    }
    cout << "\n";
    return 0;
}
