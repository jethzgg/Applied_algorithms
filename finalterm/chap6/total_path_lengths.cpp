#include <iostream>
#include <vector>
#define MAX 100000

using namespace std;

int n;
vector<vector<int>> a(MAX + 1);
vector<int> subtree_size(MAX + 1, 1);
vector<int> visited(MAX + 1, 0);
vector<long long> answer(MAX + 1, 0);

void dfs(int u, int depth)
{
    visited[u] = 1;
    answer[1] += depth;
    for (auto v : a[u])
    {
        if (visited[v] == 0)
        {
            dfs(v, depth + 1); // change here
            subtree_size[u] += subtree_size[v];
        }
    }
}

void dfs2(int u)
{
    visited[u] = 1;
    for (auto v : a[u])
    {
        if (visited[v] == 0)
        {
            // Cần tính answer[v] TRƯỚC khi gọi đệ quy xuống v
            answer[v] = answer[u] - 1 * subtree_size[v] + 1 * (n - subtree_size[v]); // 1 : weight
            dfs2(v);
        }
    }
}

int main()
{
    cin >> n;
    
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    
    dfs(1, 0);
    for (int i = 1; i <= n; i++) visited[i] = 0;
    dfs2(1);

    for (int i = 1; i <= n; i++) cout << answer[i] << " ";
    cout << "\n";
    
    return 0;
}