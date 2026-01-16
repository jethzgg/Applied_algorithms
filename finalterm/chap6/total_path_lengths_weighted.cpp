#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 100000

using namespace std;

int n;
vector<vector<pair<int, int>>> a(MAX + 1);
vector<int> subtree_size(MAX + 1, 1);
vector<int> visited(MAX + 1, 0);
vector<long long> answer(MAX + 1, 0);

void dfs(int u, int depth)
{
    visited[u] = 1;
    answer[1] += depth;
    for (auto path : a[u])
    {
        int v = path.first;
        int w = path.second;
        if (visited[v] == 0)
        {
            dfs(v, depth + subtree_size[v] * w);
            subtree_size[u] += subtree_size[v];
        }
    }
}

void dfs2(int u)
{
    visited[u] = 1;
    for (auto path : a[u])
    {
        int v = path.first;
        int w = path.second;
        if (visited[v] == 0)
        {
            // Cần tính answer[v] TRƯỚC khi gọi đệ quy xuống v
            answer[v] = answer[u] - w * subtree_size[v] + w * (n - subtree_size[v]); // 1 : weight
            dfs2(v);
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
        a[u].push_back({v, w});
        a[v].push_back({u, w});
    }
    
    dfs(1, 0);
    for (int i = 1; i <= n; i++) visited[i] = 0;
    dfs2(1);

    cout << *max_element(answer.begin(), answer.end()) << "\n";
    
    return 0;
}